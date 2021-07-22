.PHONY:run
run: build
	@echo "============build-ends============"
	python3 driver.py
	@echo "============run-ends============"

.PHONY:build
build: bitwiseops.c
	gcc -o bitwisepy_linux.so -shared -fPIC bitwiseops.c

.PHONY:clean
clean:
	rm -rf *.*~ *~ *.so *.a *.o *.out
