#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void){
	printk("My name is woo jin chael\n");

	return 0;
}

static void __exit exit_hello(void){
	printk("linus version is 4.9.70\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");
