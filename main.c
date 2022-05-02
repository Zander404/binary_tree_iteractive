#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"

int main() {
    ArvBin* arvore;
    arvore = cria_ArvBin();


    for(int x = 0; x<3;x++){
        insere_ArvBin(arvore, x);
    };

    printf("\n %i",consulta_ArvBin(arvore, 3));
    printf("\n %d",altura_ArvBin(arvore));





    return 0;
}