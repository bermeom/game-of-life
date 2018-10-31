# Author: Miguel Angel Bermeo Ayebe
# ID Coder: 1
# This Makefile compile the project using the command: 
# $ make
# And create two folders,
#   'build' with .o files and 'bin' with executable file

# Source code directory 
SOURCE_DIR = src
 # Executable directory
BIN_DIR = bin
# .o directory
BUILD_DIR = build
CC = gcc
CFLAGS = -std=gnu99  -Wall -I/usr/include/ -I. 
LDFLAGS = -lncurses
EXECUTABLE = $(BIN_DIR)/gameOfLife  

SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
DEPS = $(wildcard $(SOURCE_DIR)/*.h)

OBJ =  $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o, $(SOURCES))

all: dir $(EXECUTABLE) $(SOURCES)

dir: 
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -g -c -o $@ $<

$(EXECUTABLE): $(OBJ)
	$(CC)  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXECUTABLE) 