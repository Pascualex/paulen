num_tests=2
echo Compilando los analizadores...
gcc -Wall -o tests_TablaSimbolos tests_TablaSimbolos.c TablaSimbolos.c TablaSimbolos.h
echo Ejecutando tests:
success_count=0
for i in `seq 1 $num_tests`
do
    ./tests_TablaSimbolos ./tests/entrada_$i.txt ./tests/mi_salida_$i.txt
    diff -Bb ./tests/mi_salida_$i.txt ./tests/salida_$i.txt && success_count=`expr $success_count + 1` && echo " -> Test $i pasa" || echo " -> Test $i falla"
done
echo "$success_count de $num_tests tests ejecutados correctamente"