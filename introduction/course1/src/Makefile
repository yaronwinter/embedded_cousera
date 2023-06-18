#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
include sources.mk

# Compiler Flags and Defines
ifeq ($(PROG),STATS)
	BASENAME = stats
else
	BASENAME = course
endif

TARGET = $(BASENAME).out
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = $(INCLUDES) -DCOURSE1 -Werror -Wall -std=c99 -O0
CC = gcc

ASMB = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

%.asm : %.c
	$(CC) -S $<  $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS) $(ASMB)

.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMB) $(TARGET) $(BASENAME).map

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
