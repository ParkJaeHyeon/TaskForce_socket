obj-m := socket.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
MY_CFLAGS += -g -DDEBUG


defual:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

debug:
	make -C $(KDIR) SUBDIRS=$(PWD) modules EXTRA_CFLAGS="$(MY_CFLAGS)"

clean:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o
	rm -rf *~
	rm -rf *.order
	rm -rf *.symvers
