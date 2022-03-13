#-------------------------------------------------------------------------------
# Variables

-include make.inc

# By default, compile all 4 precisions.
single    ?= 1
double    ?= 1
complex   ?= 1
complex16 ?= 1

# By default, compile static library.
shared ?= 0

# Default library name.
lib_a  ?= libacme.a
lib_so ?= libacme.so

ifeq ($(shared),1)
	lib ?= $(lib_so)
	CFLAGS  += -fPIC
	FFLAGS  += -fPIC
	LDFLAGS += -fPIC
else
	lib ?= $(lib_a)
endif


#-------------------------------------------------------------------------------
# Include subdirectories. Each adds to $(lib_obj).

# lib_obj must be an immediate variable defined by := so that += works
# correctly in subdirs.
lib_obj :=

subdirs := \
	dir1/Makefile.inc \
	dir1/a/Makefile.inc \
	dir1/b/Makefile.inc \
	dir2/Makefile.inc \
	# end

include $(subdirs)


#-------------------------------------------------------------------------------
# Rules

# Disable all built-in rules.
.SUFFIXES:

.DELETE_ON_ERROR:

all: lib

lib: $(lib)

$(lib): $(lib_obj)

%.o: %.f90
	$(FC) $(FFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Special rule for C interface.
# In ScaLAPACK, BLACS makes .oo file, but adding _c suffix seems more standard.
%_c.o: %.c
	$(CC) $(CFLAGS) -DCallFromC -c -o $@ $<

%.a:
	ar cr $@ $^
	ranlib $@

%.so:
	$(FC) $(LDFLAGS) $^ $(LIBS) -shared -o $@

clean:
	-rm -f $(lib) $(lib_so) $(lib_a) $(lib_obj)


#-------------------------------------------------------------------------------
# For debugging.

echo:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "FFLAGS  = ${FFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "LIBS    = ${LIBS}"
	@echo
	@echo "lib     = ${lib}"
	@echo "lib_obj = ${lib_obj}"
	@echo "subdirs = ${subdirs}"
	@echo
	@echo "shared    = ${shared}"
	@echo "single    = ${single}"
	@echo "double    = ${double}"
	@echo "complex   = ${complex}"
	@echo "complex16 = ${complex16}"
