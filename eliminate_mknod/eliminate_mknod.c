#include <linux/init.h>		// mandatory
#include <linux/module.h>	// mandatory
#include <linux/fs.h>		// alloc_chrdev_region
#include <linux/device.h>	// for device related

// #define MY_DEV_FOLDER_NAME "just_d"
#define MY_DEV_CLASS_NAME "self"
#define MY_DEV_NAME "just"

// am not responsible for your license issues
// MODULE_LICENSE("Dual BSD/GPL");

static dev_t maj_min;
static struct class *cl;
static struct device *dev;

static int __init eliminate_mknod_init(void)
{
	int ret = 0;

	// get a major number dynamically
	// allot only one minor number starting from 1
	// with device/driver name being device name
	if ((ret = alloc_chrdev_region(&maj_min, 0, 1, MY_DEV_NAME)) < 0) {
		pr_info("Couldn't allocate major and minor number\n");
		goto out_maj_min_failed;
	}

	// A class must be created for a dev file to exist
	// class name will be visible in /sys/class directory
	// and so, all the devices of the class can be accessed from
	// the class directory
	if (IS_ERR(cl = class_create(THIS_MODULE, MY_DEV_CLASS_NAME))) {
		pr_info("Couldn't create class "MY_DEV_CLASS_NAME"\n");;
		ret = PTR_ERR(cl);
		goto out_cl_create_failed;
	}

	// under the cl calss with no parent device in sysfs
	// with maj_min, no callbacks and the device name
	if (IS_ERR(dev = device_create(cl, NULL, maj_min, NULL, MY_DEV_NAME))) {
		pr_info("Couldn't create device " MY_DEV_NAME "\n");
		ret = PTR_ERR(dev);
		goto out_dev_create_failed;
	}
	goto out_success;
 out_dev_create_failed:
	class_destroy(cl);
 out_cl_create_failed:
	unregister_chrdev_region(maj_min, 1);
 out_maj_min_failed:
 out_success:
	return ret;
}

static void __exit eliminate_mknod_exit(void)
{
	// kernel knows numbers not device names and all
	// device names exists only in user-space
	// maj_min for a class is enough to delete the device
	device_destroy(cl, maj_min);
	class_destroy(cl);
	unregister_chrdev_region(maj_min, 1);
}

module_init(eliminate_mknod_init);
module_exit(eliminate_mknod_exit);
