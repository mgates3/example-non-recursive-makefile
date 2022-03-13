Demonstrates simple non-recursive Makefile.

This implementation includes a Makefile.inc from each subdirectory.
These are named Makefile.inc to clarify that they aren't standalone
Makefiles, but are meant to be included.

This was written in the context of ScaLAPACK, so some other issues that
affect parallel make are addressed:

- ScaLAPACK can compile select precisions (single, double, ...).
  See handling in make.inc.example, Makefile, and dir1/Makefile.inc.

- BLACS defines both Fortran and C interfaces from the same source (*.c) files.
  See handling in Makefile and dir2/Makefile.inc.



Mark Gates
Innovative Computing Laboratory
University of Tennessee, Knoxville
