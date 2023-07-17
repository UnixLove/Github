#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init example_init(void) {
    printk(KERN_INFO "Example module has been loaded\n");
    return 0;
}

static void __exit example_exit(void) {
    printk(KERN_INFO "Example module has been unloaded\n");
}

module_init(example_init);
module_exit(example_exit);

/* 
* Simple kernel module template. Steps to loading the kernel module are as follows:
* 1. Write Kernel module.
* 2. Write Makefile:
* See https://www.kernel.org/doc/Documentation/kbuild/makefiles.txt
* Quik example: 
*
*     obj-m += example.o
*     all: 
*         make -C /lib/modules/$(shell uname -r)/builkd M=$(PWD) modules    
*     clean:
*         make -C /lib/modules/$(shell uname -r)/builkd M=$(PWD) clean
* 
* 3. Type "make" in the directory the make file and kernel module are stored in. Which will create multiple files, including a example.ko file.  
* 4. In order to load the module, type "sudo insmod example.ko" 
* 5. In order to remove the module, type "sudo rmmod example"
* 
* See https://www.kernel.org/doc/html/v4.14/kernel-hacking/hacking.html?highlight=loadable%20kernel%20modules
*/
