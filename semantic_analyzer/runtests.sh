num_tests=14
echo Compilando el compilador...
sh compile.sh
echo Ejecutando tests:
success_count=0
for i in `seq 1 $num_tests`
do
    rm ./tests/mi_salida_$i.txt
    ./alfa ./tests/programa_$i.alfa ./tests/programa_$i.asm >> ./tests/mi_salida_$i.txt
    if [ -s "./tests/mi_salida_$i.txt" ]
    then
        a=0
    else
        nasm -g -o ./tests/programa_$i.o -f elf32 ./tests/programa_$i.asm
        gcc -m32 -o ./tests/programa_$i ./tests/programa_$i.o alfalib.o
        rm ./tests/programa_$i.o
        cat ./tests/entrada_$i.txt | ./tests/programa_$i >> ./tests/mi_salida_$i.txt
    fi
    diff -Bb ./tests/mi_salida_$i.txt ./tests/salida_$i.txt && success_count=`expr $success_count + 1` && echo " -> Test $i pasa" || echo " -> Test $i falla"
done
echo "$success_count de $num_tests tests ejecutados correctamente"