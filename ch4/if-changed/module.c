/*
 * ch4/helloworld_lkm/helloworld_lkm.c
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Linux Kernel Programming" 2E
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *  GitHub repository:
 *  https://github.com/PacktPublishing/Linux-Kernel-Programming_2E
 *
 * From: Ch 4: Writing your First Kernel Module - LKMs Part 1
 ****************************************************************
 * Brief Description:
 * Our very first kernel module, the 'Hello, world' of course! The
 * idea being to explain the essentials of the Linux kernel's LKM
 * framework.
 *
 * For details, please refer the book, Ch 4.
 */
#include <linux/init.h>
#include <linux/module.h>
#include "myadd.h"

MODULE_AUTHOR("<insert your name here>");
MODULE_DESCRIPTION("LKP2E book:ch4/helloworld_lkm: hello, world, our first LKM");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.2");

static int __init helloworld_lkm_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	printk(KERN_INFO "3+4=%d\n", myadd(3,4));
	return 0;		/* success */
}
static void __exit helloworld_lkm_exit(void)
{
	printk(KERN_INFO "Goodbye, world! Climate change has done us in...\n");
}
module_init(helloworld_lkm_init);
module_exit(helloworld_lkm_exit);
