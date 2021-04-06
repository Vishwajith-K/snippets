#include <linux/module.h>  // Needed by all modules
#include <linux/kernel.h>  // Needed for KERN_ALERT

int __init init_module(void)
{
	pr_info("Hello world\n");
	return 0;
}

void __exit cleanup_module(void)
{
	pr_info("Goodbye world\n");
}  

MODULE_LICENSE("GPL");
