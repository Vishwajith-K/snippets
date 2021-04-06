**setjmp/**
- What's in C standard setjmp.h header?
- Why do we need it?
> read comments in the file  _or_ try `head setjmp_begin.c`, `head setjmp_app1.c`
- build guide: `gcc setjmp_begin.c` _or_ `gcc setjmp_app1.c`

**eliminate_mknod/**
- Linux device drivers related code
- for a given cdev, `mknod` is explicilty performed after obtaining major, minor
  but, kernel code itself offers apis to overcome this 2 step process
- build guide: `make`
- usage guide: `sudo insmod *.ko`, `sudo rmmod eli <TAB>`
  check `/sys/class` dir, `/dev` dir, `/proc/devies` file after insmod

**module_template/**
- Linux kernel related code
- template for a lkm;
- `cp` folder as required as required name, inorder to make use of template
- build guide: `make`
