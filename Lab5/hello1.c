// SPDX-License-Identifier: GPL-2.0
#include "hello1.h"

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static LIST_HEAD(event_list);

void print_hello(unsigned int count)
{
        int i;

        for (i = 0; i < count; i++) {
                struct hello_event *event;

                event = kmalloc(sizeof(*event), GFP_KERNEL);
                if (!event) {
                        pr_err("Failed to allocate memory for event\n");
                        return;
                }

                event->timestamp = ktime_get();
                pr_info("Hello, world!\n");
                event->print_time = ktime_get();
                list_add_tail(&event->list, &event_list);
        }
}
EXPORT_SYMBOL(print_hello);

static int __init hello1_init(void)
{
        pr_info("hello1 module loaded\n");
        return 0;
}

static void __exit hello1_exit(void)
{
        struct hello_event *event, *tmp;

        list_for_each_entry_safe(event, tmp, &event_list, list) {
                pr_info("Event timestamp: %lld ns, Print time: %lld ns\n",
                        ktime_to_ns(event->timestamp), ktime_to_ns(event->print_time));
                list_del(&event->list);
                kfree(event);
        }
        pr_info("hello1 module unloaded\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
