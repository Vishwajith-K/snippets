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

**bell/**
- Often it's annoying to wait for a process to complete, what if get a sound
once the task is over? This tool helps us to achieve this
- usage guide: `wait_command && ./bell [bell count]` _or_ `wait_command; ./bell [bell count]`
- build guide: `gcc -O3 -o bell bell.c`
- extra tips: add location of `bell` executable to `PATH` environment variable;
create symbolic links to `bell` as `bell 3` is same as `bell3`
- sym link: ln -s -T bell bell3

**varargs/**
- How can same definition of `printf` take so many arguments of different types?
`printf` uses the concept of variable number of arguments and a token called
ellipsis `...`. Parsing variable number of arguments is not done (typically)
directly, rather `stdargs.h` header file is used.
- build guide: `gcc -o varargs varargs.c -lm`

**o_a_so/**
- Code tries to check whether the passed number is prime or not
- Value is returned to shell or whatsoever
- I used this to know about static linked libs, static linked objects
and that's the sole purpose to start this weird folder `object_archive_shared
object/`
- The folder has more folders and they may have babies again. So, corresponding
folder has a `README.md`
