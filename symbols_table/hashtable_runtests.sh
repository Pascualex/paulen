echo Compilando los tests de la tabla hash...
gcc -Wall -o tests_HashTable tests_HashTable.c HashTable.c HashTable.h
echo Ejecutando tests:
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./tests_HashTable