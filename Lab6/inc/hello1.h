#ifndef _HELLO1_H
#define _HELLO1_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/ktime.h>

struct hello_event {
    struct list_head list;
    ktime_t timestamp;
    ktime_t print_time;
};

void print_hello(unsigned int count);

#endif /* _HELLO1_H */
