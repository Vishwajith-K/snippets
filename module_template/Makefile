help:
	@echo "Usage:"
	@echo "1) build"
	@echo -n -e "\t"
	@echo "make -C /lib/modules/\`uname -r\`/build M=\`pwd\` modules"
	@echo "2) remove any binary object files"
	@echo -n -e "\t"
	@echo "make clean"
clean:
	@rm -f *.ko *.mod *.mod.c *.mod.o *o *.order *.symvers .*.ko.cmd .*mod.cmd .*.mod.o.cmd .*.o.cmd
clean_e:
	@rm -f *.*~ *~
obj-m := module_template.o
