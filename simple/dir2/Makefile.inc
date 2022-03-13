cdir := dir2

#-------------------------------------------------------------------------------
dir2_obj := \
    $(cdir)/bar.o

# C interface adds _c suffix.
# In ScaLAPACK, BLACS makes .oo file, but adding _c suffix seems more standard.
dir2_obj_c := $(dir2_obj:.o=_c.o)

#-------------------------------------------------------------------------------
lib_obj += $(dir2_obj) $(dir2_obj_c)
