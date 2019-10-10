./compile.sh prueba1
./compile.sh prueba2
./compile.sh prueba3
./compile.sh prueba4

echo ===========================================
echo PRUEBA 1
echo Entrada: -9
echo Salida: -1 -2
echo -------------------------------------------
./prueba1 <<< "-9"
echo ===========================================
echo PRUEBA 2 - A
echo Entrada: 0
echo Salida: T F
echo -------------------------------------------
./prueba2 <<< "0"
echo ===========================================
echo PRUEBA 2 - B
echo Entrada: 1
echo Salida: F T
echo -------------------------------------------
./prueba2 <<< "1"
echo ===========================================
echo PRUEBA 3 - A
echo Entrada: 10 3
echo Salida: -10 7 5 50
echo -------------------------------------------
./prueba3 <<< "10 3"
echo ===========================================
echo PRUEBA 3 - B
echo Entrada: 3 7
echo Salida: -3 -4 1 3
echo -------------------------------------------
./prueba3 <<< "3 7"
echo ===========================================
echo PRUEBA 4 - A
echo Entrada: 1 3
echo Salida: F T F T T F F T
echo -------------------------------------------
./prueba4 <<< "1 3"
echo ===========================================
echo PRUEBA 4 - B
echo Entrada: 0 5
echo Salida: T T F F F T F T
echo -------------------------------------------
./prueba4 <<< "0 5"
echo ===========================================