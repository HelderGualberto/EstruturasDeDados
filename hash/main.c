#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "time.h"

int main()
{
    Hash* h = alocar_hash(11);
    int i,j;


        for(i=0;i<100;i++){
            inserir_hash(h,rand()/(float)RAND_MAX*100+0.5);
        }

        imprimir_hash(h);

    return 0;
}
