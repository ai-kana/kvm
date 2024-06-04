NAME = kvm
BUILD = build
FLAGS = -Wall -Wextra
CC = cc
OUTPUT = kvm

.PHONY: clean

MEMORY_DEPS = $(BUILD)/heap.o $(BUILD)/stack.o $(BUILD)/allocation.o
EXE_DEPS = $(BUILD)/execution.o $(MEMORY_DEPS)
MATH_DEPS = $(BUILD)/add.o $(BUILD)/sub.o $(BUILD)/mul.o $(BUILD)/div.o
DEPS = $(BUILD)/logger.o $(EXE_DEPS) $(MATH_DEPS)

# Linking step
$(OUTPUT): $(BUILD)/main.o $(DEPS) 
	gcc $^ $(FLAGS) -std=c99 -g -o $@

# Build main
$(BUILD)/main.o: main.c main.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build logger
$(BUILD)/logger.o: logging/logger.c logging/logger.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build heap 
$(BUILD)/heap.o: memory/heap.c memory/heap.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build allocations
$(BUILD)/allocation.o: memory/allocation.c memory/allocation.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build stack 
$(BUILD)/stack.o: stack/stack.c stack/stack.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build add
$(BUILD)/add.o: arithmetic/add.c arithmetic/add.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build sub
$(BUILD)/sub.o: arithmetic/sub.c arithmetic/sub.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build mul
$(BUILD)/mul.o: arithmetic/mul.c arithmetic/mul.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build div
$(BUILD)/div.o: arithmetic/div.c arithmetic/div.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

# Build execution
$(BUILD)/execution.o: vm/execution.c vm/execution.h vm/opcodes.h vm/interupts.h
	mkdir -p $(BUILD)
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	rm -rf $(BUILD)
	rm -rf $(OUTPUT)
