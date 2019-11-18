num_tests=1
echo Compilando los analizadores...
sh compile.sh alfa
echo Ejecutando tests:
success_count=0
for i in `seq 1 $num_tests`
do
    ./alfa ./tests/entrada_sin_$i.txt ./tests/mi_salida_sin_$i.txt
    diff -Bb ./tests/mi_salida_sin_$i.txt ./tests/salida_sin_$i.txt && success_count=`expr $success_count + 1` && echo " -> Test $i pasa" || echo " -> Test $i falla"
done
echo "$success_count de $num_tests tests ejecutados correctamente"