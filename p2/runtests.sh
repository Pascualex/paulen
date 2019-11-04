echo Compilando el analizador morfológico...
flex pruebaMorfo.l
gcc -o pruebaMorfo lex.yy.c
echo Ejecutando tests:
for i in `seq 1 3`
do
    ./pruebaMorfo ./tests/entrada$i.txt ./tests/misalida$i.txt
    cmp --silent ./tests/misalida$i.txt ./tests/salida$i.txt && echo " -> Test $i pasa" || echo " -> Test $i falla"
done