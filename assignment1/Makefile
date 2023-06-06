include sources.mk

OVERIDES = xxx
CC = gcc
BASENAME = stats
TARGET = $(BASENAME).out
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = $(OVERIDES)

PREPS = $(SRCS:.c=.i)
ASMBS = $(PREPS:.i=.s)
OBJS = $(ASMBS:.s=.o)

%.i : %.c
	$(CC) -E $(CFLAGS) $< -o $@

%.s : %.i
	$(CC) -S $(CFLAGS) $< -o $@

%.o : %.s
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(ASMBS) $(PREPS) $(TARGET) $(BASENAME).map

$(TARGET) : $(OBJS) $(PREPS) $(ASMBS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
