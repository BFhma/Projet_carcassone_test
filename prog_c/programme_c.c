#include <stdio.h>
#include <stdlib.h>

/* int* alloue_1(int n){
    int *tab;
    tab=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        tab[i]=0;
    }
    return tab;
}

void alloue_2(int n, int **tab){
    *tab=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        (*tab)[i]=0;
    }
}

int* modifie_taille(int n, int *tab){
    int *tmp=realloc(tab, n*sizeof(int));
    tab = tmp;
    return tab;
}




int main(){

    int n=5;
    int *tab = alloue_1(n);

    int n2=8;
    int *tab2;
    alloue_2(n2, &tab2);

    for(int i=0; i<n; i++){
        printf("%d ", tab[i]);
    }printf("\n");

    for(int i=0; i<n2; i++){
        printf("%d ", tab2[i]);
    }printf("\n");

    tab=modifie_taille(8,tab);
    for(int i=0; i<8; i++){
        printf("%d ", tab[i]);
    }printf("\n");
    

    free(tab);
    free(tab2);


    return 0;
} */




float** alloue_2d_1(int n, int m){
    float **tab2d=(float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        tab2d[i]=(float*)malloc(m*sizeof(float));
    }

    return tab2d;
}

void alloue_2d_2(int n, int m, float ***tab2d){

    *tab2d=(float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
        (*tab2d)[i]=(float*)malloc(m*sizeof(float));
    }

}

void affiche_matrice(float **tab2d, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%.2f   ", *(tab2d[i]+j)); //*(tab2d+i+j)
        }
        printf("\n");
    }
}

void remplir_matrice(float **tab2d, int n, int m){
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("tab2d[%d][%d] = ", i, j);
            scanf("%f", (tab2d[i]+j));
        }
    }
}

void multiplication_matrice(float **matrice1, int n1, int m1, float **matrice2, int n2, int m2, float ***matrice3){
    alloue_2d_2(n1, m2, matrice3);

    for(int i=0; i<n1; i++){
        for(int j=0; j<m2; j++){
            int a=0, b=0;
            float res=0;
            while(a<n2){
                res += matrice1[i][a] * matrice2[a][j];
                a++;
            }
            (*matrice3)[i][j] = res;
        }
    }
}

void transposee(float **matrice1, int n1, int m1, float ***matrice2){
    alloue_2d_2(m1, n1, matrice2);
    


    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            (*matrice2)[i][j] = matrice1[j][i];
        }
    }

   

}

int main(){

    float **matrice1;
    int n1=2, m1=3;
    alloue_2d_2(n1, m1, &matrice1);
    remplir_matrice(matrice1, n1, m1);
    affiche_matrice(matrice1, n1, m1);

/* 
    float **matrice2;
    int n2=3, m2=2;
    alloue_2d_2(n2, m2, &matrice2);
    remplir_matrice(matrice2, n2, m2);
    affiche_matrice(matrice2, n2, m2);

    printf("\n\n\n");
    float **matrice3;
    multiplication_matrice(matrice1, n1, m1,  matrice2, n2, m2, &matrice3);
    affiche_matrice(matrice3, n1, m2);

    printf("\n\n\n");
    affiche_matrice(matrice1, n1, m1); */
    float **matrice2;
    transposee(matrice1, n1, m1, &matrice2);
    printf("\n\n\n");
    affiche_matrice(matrice2, m1, n1);



    for(int i=0; i<n1; i++){
        free(matrice1[i]);
    }
    free(matrice1);


    /* for(int i=0; i<n2; i++){
        free(matrice2[i]);
    }
    free(matrice2);

    for(int i=0; i<n2; i++){
        free(matrice3[i]);
    }
    free(matrice3);
 */

    return 0;
}
















