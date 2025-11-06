# ALGO TWO PAPER
this repository is simply to hold all of my code for easy transport between VM and Windows machine. 
## Contact
- Author: Maxwell Castle
- Personal Email: maxwell.j.castle@gmail.com
- School Email: maxwelc2@umbc.edu
### Content
- ***minChange.cpp:*** will take an input (n) and output a list(s) from 1 - n of all possible permutations of that list. 
- ***JohnsonTrotter.cpp:*** exactly like the minChange algorithm however, works "better" on larger values of n.  
- ***combination.cpp:*** Takes two values. n, which is the size of the list you want, like in the other two scripts. and r which is the amount youd like to see in each subset of n. Will take these values and find the combination n choose r. 
- ***Makefile:*** A file to compile, run, and clean the code. 
    - *'make'* to compile the code.
    - *'make run-min'* to run the compiled minChange code.
    - *'make run-j'* to run the JohnsonTrotter code.
    - *'make run-com'* to run the combination algorithm. 
    - *'make clean'* to get rid of executables. 
    - *'make val-(min, j, com)'* will run valgrind on the executable of your choice due to the inclusion of vectors. 