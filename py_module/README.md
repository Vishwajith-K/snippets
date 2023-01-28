## What?

Tries to understand module creation, usage and invocation.


## How?

 - Open terminal/cmd and `cd` to this directory
 - This will run `main.py` as a script i.e., from top to bottom each line is compiled and run when control reaches the line

```bash
python main.py
```
 
 - Even below way does same thing except that, `python` internally writes a script and imports the mentioned module (here it's `main`) and invokes `main` part of the module. Note that you're not supposed to mention file name when using `-m` option.

```bash
python -m main
```

- Ideally if a module is imported it's `main` part isn't hit. Here, `temp_module`'s `main` isn't hit when its `import` line is hit in `main.py`


## Try:

 - import a module using `-m` switch and to run other `.py` script
 - command line arguments when `-m` switch is used
