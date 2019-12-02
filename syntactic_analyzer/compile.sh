#Clean old files.
rm lex.yy.c
rm y.tab.c

#Generate C source code from the analyzer frameworks.
flex $1.l
bison -d -y -v $1.y 

#Compile all the code.
gcc -Wall -o $1 lex.yy.c y.tab.c y.tab.h
