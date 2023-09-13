#include <iostream>
#include <string.h>

typedef struct vetor {
	int* array;
	int qtde;
	int tam;
} Vetor;


// Criar uma nova sequência
/**
 * Cria e inicializa a struct Vetor.
 * RETORNO: endereço da struct Vetor criada e inicializada na memória HEAP
 */
Vetor* vet_criar(){
 Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->qtde = 0;
    v->tam = 5;
    v->array = (int*) calloc(v->tam,sizeof(int));
      return v;
}


// Desalocar
/**
 * Destruir/Desalocar/liberar o vetor na memória HEAP
 * Parâmetro v: Endereço da variável que armazena o ponteiro para a struct Vetor (ponteiro de ponteiro).
 */
void vet_desalocar(Vetor* endVetor){
   free(endVetor);
    endVetor = NULL;
}   

// Inserir um elemento no final da sequência
/**
 * Insere o elemento na última posição do vetor.
 * Parâmetro v: Ponteiro para a struct Vetor em que o elemento será inserido.
 * Parâmetro elemento: Elemento a ser inserido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário 
 */

bool vet_anexar(Vetor* v, int elemento){
if(v == NULL)return false;
    v->array[v->qtde] = elemento;
    if(v->qtde == v->tam){
        v->tam++;
    }
     v->qtde++;
     return true;
}

// Inserir um elemento em qualquer posição da sequência
/**
 * Insere um elemento em uma determinada posição.
 * Parâmetro v: Ponteiro para a struct Vetor em que o elemento será inserido.
 * Parâmetro elemento: Elemento a ser inserido.
 * Parâmetro posicao: Posição em que o elemento deve ser inserido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário
 */

bool vet_inserir(Vetor* v, int elemento, int posicao){
   if(posicao > v->tam) return false;
     v->array[posicao-1] = elemento;
     v->qtde++;
       return true;
}

// Substituir um elemento em uma determinada posição
/**
 * Substitui o valor de uma determinada posição do Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: Posição a ser alterada.
 * Parâmetro novoElemento: elemento a ser atribuido na posição.
 * RETORNO: true se a alteração foi realizada com sucesso e false caso contrário
 */

bool vet_substituir(Vetor* v, int posicao, int novoElemento){
    if(posicao > v->tam) return false;
     v->array[posicao-1] = novoElemento;
       return true;
} 

// Remover um elemento de uma determinada posição
/**
 * USANDO A ESTRATÉGIA DO SCANF
 * Remove o elemento de uma determinada posição do vetor .
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: posição a ser removida.
 * Parâmetro endereco: endereço a ser utilizado para a copiar o valor do elemento removido.
 * RETORNO: true se a inserção foi realizada com sucesso e false caso contrário
 */

bool vet_removerPosicao(Vetor* v, int posicao, int* endereco){
    if(posicao > v->tam) return false;
        endereco = &(v->array[posicao]);
        for (int i = posicao-1; i < v->tam; i++) {
          v->array[i] = v->array[i+1];
        }
        v->qtde--;
        return true;
}

// Remover um elemento de acordo com o seu valor. Caso haja valores repetidos remover apenas a primeira ocorrência.
/**
 * Remove um determinado elemento do vetor .
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro elemento: elemento a ser removido.
 * RETORNO: posição do elemento removido. Caso o elemento não seja encontrado, a função deve devolver -1
 */

int vet_removerElemento(Vetor* v, int elemento){
    int guardar = -1;
     for(int i = 0; i < v->qtde; i++){
         if(v->array[i] == elemento ){
            v->array[i] = -1;
            guardar = i;
         }
     }
       if(guardar == -1){
          return -1;
       }else{
         return guardar;
       }
}

// Recuperar quantos elementos estão armazenados na sequência.
/**
 * Devolve a quantidade de elementos do vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * RETORNO: quantidade de elementos do vetor
 */

int vet_tamanho(Vetor* v){
    return v->tam;  
}

// Recuperar qual elemento está armazenado em uma determinada posição
/**
 * USANDO A ESTRATÉGIA DO SCANF
 * Pesquisa o elemento armazenado em uma determinada posição do Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro posicao: posicao a ser encontrada.
 * Parâmetro saida: Endereço de memória onde a função deve armazenar o elemento encontrado.
 * RETORNO: Se a posição for válida, realiza a cópia no endereço recebido por parâmetro SAIDA e devolve true. 
 *          Caso contrário, devolve false
 */

bool vet_elemento(Vetor* v, int posicao, int* saida){
   if(posicao > v->tam) return false;
      for(int i = 0; i < v-> qtde; i++){
        if(i == posicao ){
           *saida = v->array[i];
           break;
        }
      }
     return true;
}

// Recuperar a posição em que um determinado elemento está armazenado. Caso haja valores repetidos, recuperar a primeira ocorrência.
/**
 * Pesquisa a posição de um determinado elemento no Vetor.
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro elemento: elemento a ser procurado.
 * RETORNO: Se encontrado, devolve a posição do elemento no vetor; caso contrário devolve -1
 */

int vet_posicao(Vetor* v, int elemento){
  for(int i = 0; i < v->qtde; i++){
         if(v->array[i] == elemento ){
            return i;
         }
     }
     return -1;
}

// Imprimir a sequência
/**
 * Imprimir os elementos do vetor
 * Parâmetro v: Ponteiro para a struct Vetor.
 */

void vet_imprimir(Vetor* v){
  for(int i = 0; i < v->qtde; i++){
      printf("%d", v->array[i]);
       if(i < v->qtde-1){
        printf(",");
       }
  }
}

// Devolve o vetor na forma de String
/**
 * Escreve no endereço recebido por parâmetro uma versão string do vetor
 * Parâmetro v: Ponteiro para a struct Vetor.
 * Parâmetro endereco: endereço da região de memória onde a função deverá copiar os caracteres.
 * RETORNO: true se a cópia foi realizada com sucesso e false caso contrário
 */

bool vet_toString(Vetor* v, char* enderecoString){
  if(v == NULL)return false;
  char str[100];
   strcat(str,"[");
      for(int i = 0; i < v->qtde; i++){
            char temp[10];
            sprintf(temp,"%d",v->array[i]);
            strcat(str,temp);
            if(i+1<v->qtde){
              strcat(str,",");
            }
      }
      strcat(str,"]");
      strcpy(enderecoString,str);
      return true;
}
