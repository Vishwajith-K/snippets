.PHONY:run
run: build
	python3 driver.py

.PHONY:build
build:
	gcc -o bitwisepy_linux.so -shared -fPIC bitwiseops.c

.PHONY:clean
clean:
	rm -rf *.*~ *~ *.so *.a *.o *.out
