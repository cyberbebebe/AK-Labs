// SPDX-License-Identifier: GPL-2.0
#include "hello1.h"

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int count = 1;
module_param(count, uint, 0444);
MODULE_PARM_DESC(count, "Number of times to print 'Hello, world!' (default: 1)");

static int __init hello2_init(void)
{
        if (count == 0 || (count >= 5 && count <= 10)) {
                pr_warn("Count is %u, which is either 0 or between 5 and 10\n", count);
        } else if (count > 10) {
                pr_err("Count is %u, which is greater than 10\n", count);
                BUG_ON(1);  // Замість повернення -EINVAL
        }

        print_hello(count);
        pr_info("hello2 module loaded\n");
        return 0;
}

static void __exit hello2_exit(void)
{
        pr_info("hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
