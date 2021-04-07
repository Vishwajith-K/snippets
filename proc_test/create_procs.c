#include <linux/module.h>	// Needed by all modules
#include <linux/kernel.h>	// Needed for KERN_ALERT
#include <linux/proc_fs.h>	// for managing procfs stuff
#include <linux/uaccess.h>	// user space access

#define PROC_DIR_NAME "just_d"
#define PROC_FILE_NAME "just"

static struct proc_dir_entry *proc_dir, *proc_file;
static char buffer[100] = "This is test message\n";

static ssize_t proc_file_read(struct file *filp, char __user *ubuf,
			      size_t count, loff_t *ppos) 
{
	uint16_t buf_len;
	buf_len = strlen(buffer);
	if (*ppos > 0 || count < 100)
		return 0;
	if (copy_to_user(ubuf, buffer, buf_len))
		return -EFAULT;
	return (*ppos = buf_len);
}

static ssize_t proc_file_write(struct file *filp, const char __user *ubuf,
			       size_t count, loff_t *ppos) 
{
	if (*ppos > 0 || count >= 100)
		return -EFAULT;
	if(copy_from_user(buffer, ubuf, count))
		return -EFAULT;
	buffer[count] = '\0';
	return (*ppos = count);
}

static struct file_operations
proc_file_ops = {
 owner : THIS_MODULE,
 read : proc_file_read,
 write : proc_file_write
};

int __init init_module(void)
{
	proc_dir = proc_mkdir(PROC_DIR_NAME, NULL);
	if (!proc_dir) {
		pr_info(PROC_DIR_NAME" creation failed");
		goto proc_dir_failed;
	}
	proc_file = proc_create(PROC_FILE_NAME , 0666, proc_dir, &proc_file_ops);
	if (!proc_file) {
		printk(PROC_FILE_NAME" creation failed");
		goto proc_file_failed;
	}
	goto out_success;
 proc_file_failed:
	remove_proc_entry(PROC_DIR_NAME, NULL);
 proc_dir_failed:
 out_success:
	return 0;
}

void __exit cleanup_module(void)
{
	if (proc_file) proc_remove(proc_file);
	if (proc_dir) remove_proc_entry(PROC_DIR_NAME, NULL);
}  

MODULE_LICENSE("GPL");
