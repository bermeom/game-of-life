SOURCE_DIR = src
BUILD_DIR = build
CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
EXECUTABLE = $(BUILD_DIR)/gameOfLife  
#SOURCES = $(SOURCE_DIR)/%.c
SOURCES = $(wildcard $(SOURCE_DIR)/%.c)
DEPS = $(SOURCE_DIR)/%.h

#OBJ =  $(BUILD_DIR)/%.o 
OBJ =  $(patsubst $(SOURCE_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

all: dir $(EXECUTABLE)

dir: 
	mkdir -p $(BUILD_DIR)

$(OBJ): $(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJ)
	gcc  -o $@ $^  $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXECUTABLE) 
