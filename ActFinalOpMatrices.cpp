#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenar(int matriz[][7], int filas, int columnas) {
    srand(time(NULL));
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 9 + 1;
        }
    }
}

void matrizMostrar(int matriz[][7], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int sumaDiag(int matriz[][7], int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas && i < columnas; i++) {
        suma += matriz[i][i];
    }
    return suma;
}

int sumaFila(int matriz[][7], int fila, int columnas) {
    int suma = 0;
    for (int j = 0; j < columnas; j++) {
        suma += matriz[fila][j];
    }
    return suma;
}

int sumaColumna(int matriz[][7], int columna, int filas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        suma += matriz[i][columna];
    }
    return suma;
}

int sumaImpar(int matriz[][7], int filas, int columnas) {
    int suma = 0;
    for (int i = 1; i < filas; i += 2) {
        for (int j = 0; j < columnas; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaPar(int matriz[][7], int filas, int columnas) {
    int suma = 0;
    for (int j = 0; j < columnas; j += 2) {
        for (int i = 0; i < filas; i++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangSup(int matriz[][7], int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = i; j < columnas; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int sumaTriangInf(int matriz[][7], int filas, int columnas) {
    int suma = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= i; j++) {
            suma += matriz[i][j];
        }
    }
    return suma;
}

int main() {
    int filas = 5;
    int columnas = 7;
    int matriz[filas][7];

    llenar(matriz, filas, columnas);
    printf("Matriz a usar:\n\n");
    matrizMostrar(matriz, filas, columnas);

    printf("\nLa suma de la diagonal es: %d\n", sumaDiag(matriz, filas, columnas));
    printf("La suma de la fila 1 es: %d\n", sumaFila(matriz, 0, columnas));
    printf("La suma de la columna 7 es: %d\n", sumaColumna(matriz, columnas - 1, filas));
    printf("---------------\n");
    printf("La suma de la fila 1 es: %d\n", sumaFila(matriz, 0, columnas));
    printf("La suma de la fila 3 es: %d\n", sumaFila(matriz, 2, columnas));
    printf("La suma de la fila 5 es: %d\n", sumaFila(matriz, 4, columnas));
    printf("La suma de las filas pares es: %d\n", sumaImpar(matriz, filas, columnas));
    printf("---------------\n");
    printf("La suma de la columna 2 es: %d\n", sumaColumna(matriz, 1, filas));
    printf("La suma de la columna 4 es: %d\n", sumaColumna(matriz, 3, filas));
    printf("La suma de la columna 6 es: %d\n", sumaColumna(matriz, 5, filas));
    printf("La suma de las columnas impares es: %d\n", sumaPar(matriz, filas, columnas));
    printf("---------------\n");
    printf("La suma de la diagonal es: %d\n", sumaDiag(matriz, filas, columnas));
    printf("La suma de la triangular superior es: %d\n", sumaTriangSup(matriz, filas, columnas));
    printf("---------------\n");
    printf("La suma de la diagonal es: %d\n", sumaDiag(matriz, filas, columnas));
    printf("La suma de la triangular inferior es: %d\n", sumaTriangInf(matriz, filas, columnas));

    return 0;
}

