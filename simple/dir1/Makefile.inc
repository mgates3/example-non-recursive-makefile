# cdir must be an immediate variable defined by :=
cdir := dir1

#-------------------------------------------------------------------------------
dir1_s_obj := \
    $(cdir)/sfoo.o \
    # end

dir1_d_obj := \
    $(cdir)/dfoo.o \
    # end

dir1_c_obj := \
    $(cdir)/cfoo.o \
    # end

dir1_z_obj := \
    $(cdir)/zfoo.o \
    # end

#-------------------------------------------------------------------------------
ifeq ($(single),1)
    lib_obj += $(dir1_s_obj)
endif

ifeq ($(double),1)
    lib_obj += $(dir1_d_obj)
endif

ifeq ($(complex),1)
    lib_obj += $(dir1_c_obj)
endif

ifeq ($(complex16),1)
    lib_obj += $(dir1_z_obj)
endif
