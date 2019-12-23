#Clean old files.
rm lex.yy.c
rm y.tab.c

#Generate C source code from the analyzer frameworks.
flex alfa.l
bison -d -y -v alfa.y 

#Compile all the code.
make
