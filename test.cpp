#include "tad_vetor.h"
#include <string.h>
#include <iostream>

int main(){
	char str[100];
    Vetor v;
    Vetor v2;
    int* pos = NULL;
	Vetor* v1 = vet_criar();
	vet_anexar(v1, 10);  
	vet_anexar(v1, 20);
	vet_anexar(v1, 30);
	vet_anexar(v1, 345);
	vet_anexar(v1, 3454894);
	vet_anexar(v1, 54);
	vet_anexar(v1, 34);
	vet_toString(v1, str);
	printf("%s\n",str);
    vet_imprimir(v1);
    vet_removerElemento(v1, 20);
    printf("\n");
	vet_toString(v1, str);
    vet_imprimir(v1);
    printf("\n%d\n",vet_tamanho(v1));
    printf("%d\n",vet_posicao(v1,10 ));
	vet_elemento(v1,4,pos);
	printf("%d\n",pos);
}