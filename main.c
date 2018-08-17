#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int **x;
    int **y;
    int **z;
    int nl, nc, i, j;
    nl=3;
    nc=4;
    
    //alocando a matriz x
    x=(int**)malloc(nl*sizeof(int*));
    for (i=0; i<nl; i++){
        x[i] = (int*)malloc(nc*sizeof(int));
    }
    
    //alocando a matriz y
    y=(int**)malloc(nc*sizeof(int*));
    for (i=0; i<nc; i++){
        y[i] = (int*)malloc(nl*sizeof(int));
    }

    //alocando a matriz z
    z=(int**)malloc(nl*sizeof(int*));
    for (i=0; i<nl; i++){
        z[i] = (int*)malloc(nc*sizeof(int));
    }

    //gerando a matriz x
    srand(time(0));
    for (i=0; i<nl; i++){
        for (j=0; j<nc; j++){
            x[i][j]=rand()%10;
        }
    }

    //gerando a matriz transposta y
    for (i=0; i<nc; i++){
        for (j=0; j<nl; j++){
            y[i][j]=x[j][i];
        }
    }
    
    //mostrando a matriz x
    printf("matriz original\n");
    for (i=0; i<nl; i++){
        for (j=0; j<nc; j++){
            printf("%d, ", x[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    //copia da matriz x para matriz z (utilizando memcpy(pra onde, de onde, quantidade)
    memcpy(z, x, nc*nl*sizeof(int));

     //mostrando a matriz z
    printf("matriz copia\n");
    for (i=0; i<nl; i++){
        for (j=0; j<nc; j++){
            printf("%d, ", z[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //mostrando a matriz y
    printf("matriz transposta\n");
    for (i=0; i<nc; i++){
        for (j=0; j<nl; j++){
            printf("%d, ", y[i][j]);
        }
        printf("\n");
    }
    return 0;
}
