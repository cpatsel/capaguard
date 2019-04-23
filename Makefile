obj-m += capa_guard.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

install:
	./install.sh

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
