include sources.mk

CC = gcc
BASENAME = stats
TARGET = $(BASENAME).out
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = $(OVERIDES)
CPPFLAGS = -MF"$@" -MM

DEPS = $(SRCS:.c=.dep)
PREPS = $(SRCS:.c=.i)
ASMB = $(SRCS:.c=.asm)
OBJS = $(SRCS:.c=.o)

%.dep : %.c
	$(CC) -E $<  $(CFLAGS) $(CPPFLAGS)

%.i : %.c
	$(CC) -E $<  $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $<  $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-only
compile-only: $(PREPS) $(DEPS) $(ASMB) $(OBJS)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(PREPS) $(ASMB) $(DEPS) $(TARGET) $(BASENAME).map

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
