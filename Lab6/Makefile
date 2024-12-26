obj-m += hello1.o
obj-m += hello2.o

KDIR ?= /home/ubuntu/repos/linux-stable
CROSS_COMPILE ?= arm-linux-gnueabi-

ccflags-y := -I$(PWD)/inc -g

all:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) modules
        cp hello1.ko hello1.ko.unstripped
        cp hello2.ko hello2.ko.unstripped
        $(CROSS_COMPILE)strip -g hello1.ko
        $(CROSS_COMPILE)strip -g hello2.ko

clean:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) clean

%.s: %.c
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) $@
