#include <linux/init.h> // Needed for macros
#include <linux/module.h> // Needed for all modules
#include <linux/kernel.h> // Needed for KERN_INFO

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CYB3RMX");
MODULE_DESCRIPTION("A very simple kernel module sample.");

static int __init entry_test_module(void){
    printk(KERN_INFO "CYB3RMX Was here!!\n");
    return 0; // If not 0 module cant be loaded
}

static void __exit exit_test_module(void){
    printk(KERN_INFO "Clean up bro!\n");
}

module_init(entry_test_module);
module_exit(exit_test_module);