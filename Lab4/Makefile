obj-m += hello.o

KDIR ?= /home/ubuntu/repos/linux-stable
CROSS_COMPILE ?= arm-linux-gnueabi-

all:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
        make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE) clean