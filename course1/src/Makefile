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

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb # armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
BASENAME = task
TARGET = $(BASENAME).out
COMMON_LDFLAGS = -Wl,-Map=$(BASENAME).map
COMMON_CFLAGS = $(INCLUDES) -D$(PLATFORM) -Werror -Wall -std=c99 -O0
CPPFLAGS = -MF"$@" -MM

ifeq ($(PLATFORM),HOST)
	CC = gcc
	SIZE_CC = size
	LDFLAGS  = $(COMMON_LDFLAGS)
	CFLAGS = $(COMMON_CFLAGS)
else
	CC = arm-none-eabi-gcc
	SIZE_CC = arm-none-eabi-size
	LDFLAGS  = $(COMMON_LDFLAGS) -T $(LINKER_FILE)
	CFLAGS = $(COMMON_CFLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16
endif

DEPS = $(SOURCES:.c=.dep)
PREPS = $(SOURCES:.c=.i)
ASMB = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

%.dep : %.c
	$(CC) -E $<  $(CFLAGS) $(CPPFLAGS)

%.i : %.c
	$(CC) -E $<  $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $<  $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS) $(PREPS) $(DEPS) $(ASMB)

.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PREPS) $(ASMB) $(DEPS) $(TARGET) $(BASENAME).map

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: size
size:
	$(SIZE_CC) -Atx $(TARGET)
	$(SIZE_CC) -Bx $(TARGET)
	$(SIZE_CC) -Bd $(TARGET)
