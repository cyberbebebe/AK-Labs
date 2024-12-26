obj-m += hello1.o
obj-m += hello2.o

KDIR ?= /home/ubuntu/repos/linux-stable
CROSS_COMPILE ?= arm-linux-gnueabi-

ccflags-y := -I$(PWD)/inc

all:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) clean