#include <stdio.h>
#include <stdlib.h>


struct bloc {
    int val;
    struct bloc *suivant;
};

void ajout_fin_cree(struct bloc **t, int val){
    struct bloc *new=malloc(sizeof(struct bloc));
    new->val = val;
    new->suivant = NULL;

    if(*t==NULL){
        *t=new;
        return;
    }

    struct bloc *courant = *t;
    while(courant->suivant!=NULL)
        courant = courant->suivant;

    courant->suivant = new;

}

void ajout_debut(struct bloc **t, int val){
    struct bloc *new=malloc(sizeof(struct bloc));
    new->val = val;
    new->suivant = *t;
    *t=new;
}

void ajout_indice(struct bloc **t, int val, int indice){
    struct bloc *new=malloc(sizeof(struct bloc));
    new->val = val;
    new->suivant = NULL;

    int i=0;
    struct bloc *courant = *t;
    while(courant!=NULL && i!=indice-1){
        courant = courant->suivant;
        i++;
    }

    new->suivant = courant->suivant;
    courant->suivant = new;
}

void supp_fin(struct bloc **t){
    struct bloc *courant=*t;
    while(courant->suivant->suivant!=NULL){
        courant = courant->suivant;
    }

    courant->suivant = NULL;
}

void suppr_debut(struct bloc **t){
    *t=(*t)->suivant;
}

void suppr_indice(struct bloc **t, int indice){
    int i=0;
    struct bloc *courant = *t;
    while(courant!=NULL && i!=indice-1){
        courant = courant->suivant;
        i++;
    }

    struct bloc *suppr = courant->suivant;
    courant->suivant = suppr->suivant;


}

void affichage(struct bloc *t){
    struct bloc *courant = *t;
    while(courant!=NULL){
        printf("%d-> ", t->val);
        courant = courant->suivant;
    }
}


int main(){

}
