#include <stdio.h>
#include <stdbool.h>

#define N 10 // Taille du plateau

// Fonction pour afficher une suite de placement de dames
void printSolution(int cols[N]) {
    for (int i = 0; i < N; i++) {
        printf("%d ", cols[i]);
    }
    printf("\n");
}

// Fonction pour vérifier si une dame peut être placée dans la case (row, col)
bool isSafe(int cols[N], int row, int col) {
    // Vérifier la colonne
    for (int i = 0; i < col; i++) {
        if (cols[i] == row || cols[i] - i == row - col || cols[i] + i == row + col) {
            return false;
        }
    }
    return true;
}

// Fonction récursive pour trouver toutes les suites possibles de placement de dames
void solveNQueensUtil(int cols[N], int col) {
    // Si toutes les dames sont placées, afficher la solution
    if (col >= N) {
        printSolution(cols);
        return;
    }

    // Essayer de placer cette dame dans toutes les lignes
    for (int i = 0; i < N; i++) {
        if (isSafe(cols, i, col)) {
            // Placer une dame dans cette colonne
            cols[col] = i;

            // Récursion pour placer le reste des dames
            solveNQueensUtil(cols, col + 1);

            // Retirer la dame de cette colonne pour essayer la suivante
            cols[col] = -1;
        }
    }
}

// Fonction principale pour résoudre le problème des 10 dames
void solveNQueens() {
    int cols[N];
    // Initialiser toutes les colonnes à -1 pour indiquer qu'aucune dame n'est placée
    for (int i = 0; i < N; i++) {
        cols[i] = -1;
    }

    solveNQueensUtil(cols, 0);
}

int main() {
    solveNQueens();
    return 0;
}
