#include <stdio.h>

void llenarMatriz(int matriz[][3]) {
    printf("Ingrese la combinacion de 9 elementos:\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int matriz[][3]) {
    printf("\nMatriz:\n\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int comprobar(int matriz[][3]) {
    int sumaDiagonalPrincipal = 0, sumaDiagonalSecundaria = 0;

    for (int i = 0; i < 3; i++) {
        sumaDiagonalPrincipal += matriz[i][i];
        sumaDiagonalSecundaria += matriz[i][2 - i];
    }

    int sumasFilas[3] = {0};
    int sumasColumnas[3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumasFilas[i] += matriz[i][j];
            sumasColumnas[j] += matriz[i][j];
        }
    }

    int sumaEsperada = sumaDiagonalPrincipal;

    for (int i = 0; i < 3; i++) {
        if (sumasFilas[i] != sumaEsperada || sumasColumnas[i] != sumaEsperada) {
            return 0;
        }
    }

    return (sumaDiagonalPrincipal == sumaDiagonalSecundaria && sumaDiagonalPrincipal == sumaEsperada);
}

int main() {
    int matriz[3][3];

    llenarMatriz(matriz);
    imprimirMatriz(matriz);

    int magica = comprobar(matriz);

    printf("\nLa suma de la fila 1 es: %d\n", matriz[0][0] + matriz[0][1] + matriz[0][2]);
    printf("La suma de la fila 2 es: %d\n", matriz[1][0] + matriz[1][1] + matriz[1][2]);
    printf("La suma de la fila 3 es: %d\n", matriz[2][0] + matriz[2][1] + matriz[2][2]);
    printf("La suma de la columna 1 es: %d\n", matriz[0][0] + matriz[1][0] + matriz[2][0]);
    printf("La suma de la columna 2 es: %d\n", matriz[0][1] + matriz[1][1] + matriz[2][1]);
    printf("La suma de la columna 3 es: %d\n", matriz[0][2] + matriz[1][2] + matriz[2][2]);
    printf("La suma de la diagonal es: %d\n", matriz[0][0] + matriz[1][1] + matriz[2][2]);
    printf("La suma de la diagonal secundaria es: %d\n", matriz[0][2] + matriz[1][1] + matriz[2][0]);

    if (magica) {
        printf("\nLa matriz es magica\n");
    } else {
        printf("\nLa matriz no es magica\n");
    }

    return 0;
}

