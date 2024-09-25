# Compiler
1) Preprocessing: gcc -E source.c -o source.i
2) Compiling: gcc -S source.i -o source.s
3) Assembling: gcc -c source.s -o source.o
4) Linking: gcc source.o -o executable
5) Loading/Running: ./executable