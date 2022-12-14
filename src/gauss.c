#include "gauss.h"
#include <math.h>

int eliminate(Matrix *mat, Matrix *b) {
    int a, i, j, w;
    double value;
    double *tmp1;
    for (a = 0; a < (mat->c) - 1; a++) {
        value = fabs(mat->data[a][a]);
        w = a;

        //wybor elementu glownego
        for (i = a; i < mat->r; i++) {
            if (fabs(mat->data[i][a]) > value) {
                value = fabs(mat->data[i][a]);
                w = i;
            }
        }

        //zamiana kolumn
        if (w != a) {
            tmp1 = mat->data[a];
            mat->data[a] = mat->data[w];
            mat->data[w] = tmp1;

            tmp1 = b->data[a];
            b->data[a] = b->data[w];
            b->data[w] = tmp1;
        }

        //zerowanie kolumny
        for (i = a + 1; i < mat->r; i++) {
            value = (mat->data[i][a]) / (mat->data[a][a]);
            for (j = a; j < mat->c; j++) {
                mat->data[i][j] = mat->data[i][j] - value * (mat->data[a][j]);
            }
            b->data[i][0] = b->data[i][0] - value * (b->data[a][0]);
        }
    }
    return 0;
}  