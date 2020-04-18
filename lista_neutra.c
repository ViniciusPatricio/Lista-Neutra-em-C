#include "stdio.h"
#include "stdlib.h"

typedef struct Elemento_Lista TELE;
struct Elemento_Lista{
    void *carga_util;
    void *prox;
};
typedef struct Lista_Encadeada TLista;
struct Lista_Encadeada{
    int qtde;
    TELE *fim;
    TELE *inicio;
};

// *********************** FUNÇÕES DE CRIAÇÃO  *********************** //

TELE *criarElementoLista(void *carga){
    TELE *elemento_lista=malloc(sizeof(TELE));
    
    elemento_lista->carga_util=carga;
    elemento_lista->prox=NULL;

    return elemento_lista;
}

TLista *criarListaEncadeada(){
    TLista *lista=malloc(sizeof(TLista));
    
    lista->fim=NULL;
    lista->inicio=NULL;
    lista->qtde=0;
    
    return lista;
}

// *********************** FUNÇÕES DE INSERÇÃO  *********************** //

void inserirFim(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);

    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        lista->fim->prox=carga_util;
        lista->fim=carga_util;
    }
    lista->qtde++;
}

void inserirInicio(TLista *lista, void *carga){
    TELE *carga_util=criarElementoLista(carga);
    if(lista->inicio==NULL){
        lista->inicio=carga_util;
        lista->fim=carga_util;
    }else{
        carga_util->prox=lista->inicio;
        lista->inicio=carga_util;
    }
    lista->qtde++;
}

// *********************** FUNÇÕES DE REMOÇÂO  *********************** //

typedef void (*TDestroyMedida)(void*); // assinatura de uma função

void removerInicio(TLista *lista,TDestroyMedida destroy){ // removerInicio recebe uma lista e um função que remove uma medida genérica
    TELE *primeiro=lista->inicio;

    if(primeiro==NULL){
        printf("Não há elementos na lista\n");
    }else{
        if(lista->inicio==lista->fim){  // único elemento na lista;
            lista->fim=NULL; lista->inicio=NULL;
        }else{
            lista->inicio=primeiro->prox;
        }
        void *carga=primeiro->carga_util;
        free(primeiro);
        lista->qtde--;
        
    }
}

// *********************** MEDIDA CRIADA PARA EXEMPLO  *********************** //

typedef struct medida TMedida;
struct medida{
    int num;
};

TMedida *criarMedida(int num){
    TMedida *medida=malloc(sizeof(TMedida));
    medida->num=num;

    return medida;
}

void imprimirMedida(void *medida){
    TMedida *med=medida;
    printf("%d ",med->num);
}

void destruirTMedida(void *medida){
    TMedida *med=medida;
    free(med);
}

int main(){

    TLista *lista1=criarListaEncadeada();
    TLista *lista2=criarListaEncadeada();

    int i,num,tam;

    scanf("%d",&tam);

    for(i=0;i<tam;i++){
        scanf("%d",&num);
       TMedida *medida=criarMedida(num);
      
       inserirInicio(lista1,medida);
       inserirFim(lista2,medida);
    }
    TELE *cam1=lista1->inicio;
    TELE *cam2=lista2->inicio;
    
   
    printf("Inserindo no inicio: ");
    while(cam1!=NULL){
        imprimirMedida(cam1->carga_util);
        cam1=cam1->prox;
    }
    
    printf("\ninserir no fim: ");
    while(cam2!=NULL){
        imprimirMedida(cam2->carga_util);
        cam2=cam2->prox;
    }

    removerInicio(lista1,destruirTMedida);
    removerInicio(lista2,destruirTMedida);

    cam1=lista1->inicio;
    cam2=lista2->inicio;

    printf("\nREMOVENDO OS PRIMEIROS ELEMENTOS\n");
    printf("Inserindo no inicio: ");
    while(cam1!=NULL){
        imprimirMedida(cam1->carga_util);
        cam1=cam1->prox;
    }

   
    printf("\ninserir no fim: ");
    while(cam2!=NULL){
        imprimirMedida(cam2->carga_util);
        cam2=cam2->prox;
    }
  
}