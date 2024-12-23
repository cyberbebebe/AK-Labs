#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/ktime.h>

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of times to print 'Hello, world!' (default: 1)");

struct hello_event {
        struct list_head list;
        ktime_t timestamp;
};

static LIST_HEAD(event_list);

static int __init hello_init(void)
{
        int i;

        if (count == 0 || (count >= 5 && count <= 10)) {
                pr_warn("Count is %u, which is either 0 or between 5 and 10\n", count);
        } else if (count > 10) {
                pr_err("Count is %u, which is greater than 10\n", count);
                return -EINVAL;
        }

        for (i = 0; i < count; i++) {
                struct hello_event *event;

                event = kmalloc(sizeof(*event), GFP_KERNEL);
                if (!event) {
                        pr_err("Failed to allocate memory for event\n");
                        return -ENOMEM;
                }

                event->timestamp = ktime_get();
                list_add_tail(&event->list, &event_list);
                pr_info("Hello, world!\n");
        }

        return 0;
}

static void __exit hello_exit(void)
{
        struct hello_event *event, *tmp;

        list_for_each_entry_safe(event, tmp, &event_list, list) {
                pr_info("Event timestamp: %lld ns\n", ktime_to_ns(event->timestamp));
                list_del(&event->list);
                kfree(event);
        }
}

module_init(hello_init);
module_exit(hello_exit);