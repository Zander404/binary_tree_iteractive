#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"
#include <sys/time.h>


float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}



int main() {
    ArvBin *arvore;
    arvore = cria_ArvBin();

    struct timeval t0;
    struct timeval t1;
    float elapsed;

    for (int x = 0; x < 10000; x++) {
        insere_ArvBin(arvore, rand());
    };

    gettimeofday(&t0, 0);

    //Codigo executavel

    altura_ArvBin(arvore);



    gettimeofday(&t1, 0);

    elapsed = timedifference_msec(t0, t1);

    printf("Code executed in %f milliseconds.\n", elapsed);




    printf("\n %i",consulta_ArvBin(arvore, 3));
    printf("\n %d",altura_ArvBin(arvore));






    return 0;
}
