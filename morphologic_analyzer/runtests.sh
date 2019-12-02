num_tests=3
echo Compilando el analizador morfológico...
flex pruebaMorfo.l
gcc -o pruebaMorfo lex.yy.c
echo Ejecutando tests:
success_count=0
for i in `seq 1 $num_tests`
do
    ./pruebaMorfo ./tests/entrada$i.txt ./tests/misalida$i.txt
    diff -Bb ./tests/misalida$i.txt ./tests/salida$i.txt && success_count=`expr $success_count + 1` && echo " -> Test $i pasa" || echo " -> Test $i falla"
done
echo "$success_count de $num_tests tests ejecutados correctamente"