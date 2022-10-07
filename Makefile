TARGET_DIR = bin
COMPILER = gcc

.phony: all
all: array_int.c  interpret.c  main.c  maybe_int64.c  stack.c  stek_vm.c  util.c
	mkdir -p $(TARGET_DIR)
	$(COMPILER) -o $(TARGET_DIR)/run $+

.phony: clean
clean:
	rm -rf $(TARGET_DIR)