#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /**
  	 * Tutaj należy umieścić właściwą implemntację.
		 */
	int i;
	int j;
	int k;
	int n = mat->r;
	double m;

	for(i=0; i<n-1; i++){   //chodzenie po kolumnach
		if (mat->data[i][i] == 0){
			return 1;
		}
        for(j=i+1; j<n; j++){
           	m = mat->data[j][i] / mat->data[i][i];
            for(k=i+1; k<n; k++){
                mat->data[j][k] -= m * mat->data[i][k];
            }
            b->data[j][0] -= m * b->data[i][0];
        }
    }
	return 0;
}


