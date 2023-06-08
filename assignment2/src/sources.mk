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

COMMON_SOURCES = main.c \
                 memory.c

COMMON_INCLUDES = -I. \
				  -I../include/common

ARM_SOURCES = interrupts_msp432p401r_gcc.c \
			  startup_msp432p401r_gcc.c \
			  system_msp432p401r.c

ARM_INCLUDES = -I../include/CMSIS \
			   -I../include/msp432


# Add your Source files to this variable
ifeq ($(PLATFORM),HOST)
	SOURCES = $(COMMON_SOURCES)
	INCLUDES = $(COMMON_INCLUDES)
else
	SOURCES = $(COMMON_SOURCES) $(ARM_SOURCES)
	INCLUDES = $(COMMON_INCLUDES) $(ARM_INCLUDES)
endif
