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
    
    printf("\ninserir no fim:");
    while(cam2!=NULL){
        imprimirMedida(cam2->carga_util);
        cam2=cam2->prox;
    }
}