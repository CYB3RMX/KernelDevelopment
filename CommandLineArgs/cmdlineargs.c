#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

// Module metadata informations
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CYB3RMX");
MODULE_DESCRIPTION("Kernel module that receives command line arguments.");

// Variables
static short int veryshort = 1;
static int someint = 154;
static int testArray[2] = {-1, 1};
static int arr_argc = 0;

/* Defining function that handles command line arguments

module_param(foo, int, 0000)

foo => Parameters name
int => Data type
0000 => Permissions bits

S_IRUSR => Read permission (user)
S_IWUSR => Write permission (user)
S_IRGRP => Read permission (group)
S_IWGRP => Write permission (group)
S_IROTH => Read permission (other)

*/

module_param(veryshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
module_param(someint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param_array(testArray, int, &arr_argc, 0000);

static int __init entry_test_module(void)
{
    int i;
    printk(KERN_INFO "Test module starts\n==========\n");
    printk(KERN_INFO "Veryshort: %d\n", veryshort);
    for(i = 0; i < (sizeof(testArray) / sizeof(int)); i++){
        printk(KERN_INFO "testArray[%d] = %d\n", i, testArray[i]);
    }
    printk(KERN_INFO "Got %d arguments for testArray.\n", arr_argc);
    return 0;
}

static void __exit exit_test_module(void)
{
    printk(KERN_INFO "Exitting...\n");
}

module_init(entry_test_module);
module_exit(exit_test_module);