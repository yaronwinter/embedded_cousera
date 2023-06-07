include sources.mk

#OVERIDES = xxx
CC = gcc
BASENAME = stats
TARGET = $(BASENAME).out
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = $(OVERIDES)
CPPFLAGS = -MF"$@" -MM

DEPS = $(SRCS:.c=.dep)
OBJS = $(SRCS:.c=.o)

%.dep : %.c
	$(CC) -E $<  $(CFLAGS) $(CPPFLAGS)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET) $(BASENAME).map

$(TARGET) : $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@
