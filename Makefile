CC = gcc
CFLAGS = -Wall -o
CPPFLAGS = -Iinclude

SRCDIR = src
INCLUDEDIR = include

TARGET = run
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $@ $(OBJECTS)

%.o: $(SRCDIR)/%.c
	$(CC) -c $(CPPFLAGS) -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean copy_data