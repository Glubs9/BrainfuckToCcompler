# BrainfuckToCcompler
fun little project I did while learning c

# Motivation
I was learning c for fun and decided that this would be a good warmup project. 

# Disclaimer
This is the first major project I have done in c and I wasn't really trying to write good readable code with solid documentation. This is also my first time writing a compilre of any kind so even though this is basically just a text replace program it is still not fantastic (actually thinking about it now this could have been done in python in like 10 lines using text replace). sorry about the lack of comments.

# How to use
To build the program download all of the files and compile compile.c. If you then run the compiled file with a brainfuck file name as the argument it will compile and output the file as a c program, named a.c. If you then compile and run a.c it will run the brainfuck program.                                 
e.g:                   
\[in the folder where you downloaded the project]                  
gcc compile.c -o compile                  
./compile \[file_name]                       
gcc a.c -o a                     
./a      
