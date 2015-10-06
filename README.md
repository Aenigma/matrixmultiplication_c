# Matrix Multiplication and Sorting
Assignment for Frostburg State University's COSC450 - Programming Language
Principles and Paradigms to implement a matrix multiplication program in C.

# Building
Go to the directory of the project and run `make`

    cd path/to/project/
    make

# Running
At the project directory:

    ./build/bin/matrix -i COSC450_P1_Data.txt -o COSC450_P1_Output.txt

If input file and output file are not defined, it defaults to the paths you see
above.  

# Input File
The input file defines several numbers that are decoded into 2 matrices.

The number of rows in the first matrix must be a multiple of the constant, ROW,
in main.c. Here, it is 5.

The first matrix will be a ROW by count/2/ROW where count is the number of
elements in the input file. The second must be divisible, and will be a
count/2/ROW by ROW matrix.

So, the input file format must be divisible by ROW * 2 for this to be valid.

# Output File
The two matrices will be displayed. Each row will be separated by a comma and
newline.

Its product, a ROW by ROW matrix will be written.

The product will also be sorted and written.

The output file will always be overwritten
