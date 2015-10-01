# This is a GNU Make file which describes how to build the application's
# DLL/SO for both x86 Windows and Linux systems.
#
# Some of the compiler flags here are essential such as '-masm=intel' which
# allows the inline assembly to be in Intel syntax instead of AT&T syntax.
# Additionally '-DASM' compiles the program so that the portions using inline
# assembly are actually used instead of their C equivalents.
#
#
# To do a full compile, invoke 'make all'
# To build just the shared objects and DLLs, invoke 'make so'
# To build just the test executable, invoke 'make bins'
#

CC:=$(shell which cc)
CFLAGS=-Wall -pedantic -O3 -std=c99

SO_PREFIX=libmatrix
LIBS=

CFILES=lib/matrixmult.c lib/matrixreader.c lib/matrixwriter.c lib/sort.c main.c
OBJ=

OUT_DIR=build

BIN_DIR=$(OUT_DIR)/bin
SO_DIR=$(OUT_DIR)/so

.PHONY: all bins so clean fresh 

VPATH =lib

bins:
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -o $(BIN_DIR)/matrix

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

so:
	@mkdir -p $(SO_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -fPIC -shared -o $(SO_DIR)/$(SO_PREFIX).so

clean:
	@rm -r $(OUT_DIR)
	@rm -f *.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.s: %.c
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -S $<

fresh: | clean all
