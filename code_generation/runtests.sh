./compile.sh prueba1
./compile.sh prueba2
./compile.sh prueba3
./compile.sh prueba4
./compile.sh prueba5
./compile.sh prueba6
./compile.sh prueba7
./compile.sh prueba8

echo ===========================================
echo PRUEBA 1
echo Entrada: -9
echo Salida: -1 -2
echo -------------------------------------------
echo "-9" | ./prueba1
echo ===========================================
echo PRUEBA 2 - A
echo Entrada: 0
echo Salida: T F
echo -------------------------------------------
echo "0" | ./prueba2
echo ===========================================
echo PRUEBA 2 - B
echo Entrada: 1
echo Salida: F T
echo -------------------------------------------
echo "1" | ./prueba2
echo ===========================================
echo PRUEBA 3 - A
echo Entrada: 10 3
echo Salida: -10 7 5 50
echo -------------------------------------------
echo "10 3" | ./prueba3
echo ===========================================
echo PRUEBA 3 - B
echo Entrada: 3 7
echo Salida: -3 -4 1 3
echo -------------------------------------------
echo "3 7" | ./prueba3
echo ===========================================
echo PRUEBA 4 - A
echo Entrada: 1 3
echo Salida: F T F T T F F T
echo -------------------------------------------
echo "1 3" | ./prueba4
echo ===========================================
echo PRUEBA 4 - B
echo Entrada: 0 5
echo Salida: T T F F F T F T
echo -------------------------------------------
echo "0 5" | ./prueba4
echo ===========================================
echo PRUEBA 5
echo Entrada: Ninguna
echo Salida: 0 1 2 3 4 Fuera de rango
echo -------------------------------------------
echo "" | ./prueba5
echo ===========================================
echo PRUEBA 6
echo Entrada: Ninguna
echo Salida: 3
echo -------------------------------------------
echo "" | ./prueba6
echo ===========================================
echo PRUEBA 7
echo Entrada: Ninguna
echo Salida: 4
echo -------------------------------------------
echo "" | ./prueba7
echo ===========================================
echo PRUEBA 8
echo Entrada: Ninguna
echo Salida: 11
echo -------------------------------------------
echo "" | ./prueba8
echo ===========================================