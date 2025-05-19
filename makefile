CC = gcc
CFLAGS = -Wall -g
TARGET = task_manager
SOURCES = task_manager.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = task_manager.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean