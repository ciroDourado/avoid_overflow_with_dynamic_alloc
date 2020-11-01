# avoid_overflow_with_dynamic_alloc
The repository name explains by itself

The "ready_for_use" contains the functions implemented; just include the files to your project or program.

I've tryed to do something like the standard read functions from Rust, in C.
Being succinct, in Rust every input must be read/stored in an dynamically allocated variable, or Strings (types that live on the heap).
Any other usage from those text inputs must be processed, like parsed to an numeric encoding, or take some part from it (the Slices) and throw into the stack memory.
