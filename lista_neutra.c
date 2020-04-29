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

void inserirPosicao(TLista *lista, void *carga, int pos){
   
   if(pos>=1 && pos<=lista->qtde+1){
        int i=1;
        TELE *caminhador1=NULL;
        TELE *caminhador2=lista->inicio;

        while(i!=pos){
            caminhador1=caminhador2;
            caminhador2=caminhador2->prox;
            i++;
        }

        if(caminhador1==NULL){
            inserirInicio(lista,carga);
        }else if(caminhador2==lista->fim+1){
            inserirFim(lista,carga);
        }else{
            TELE *carga_util=criarElementoLista(carga);
            caminhador1->prox=carga_util;
            carga_util->prox=caminhador2;
        }

        lista->qtde++;

   }else{
       printf("Posicao Invalida\n");
   }
}

// *********************** FUNÇÕES DE REMOÇÂO  *********************** //

typedef void (*TDestroyMedida)(void*); // assinatura de uma função

void removerInicio(TLista *lista,TDestroyMedida destroy){ // removerInicio recebe uma lista e um função que remove uma medida genérica
    TELE *primeiro=lista->inicio;

    if(primeiro==NULL){
        printf("Nao ha elementos na lista\n");
    }else{
        if(lista->inicio==lista->fim){  // único elemento na lista;
            lista->fim=NULL; lista->inicio=NULL;
        }else{
            lista->inicio=primeiro->prox;
        }
        void *carga=primeiro->carga_util;
        free(primeiro);
        destroy(carga);
        lista->qtde--;  
    }
}
// *********************** FUNÇÕES DIVERSAS  *********************** //

int quantidadeLista(TLista *lista){
    return lista->qtde;
}

typedef void (*TImprimirElemento)(void*);

void *imprimirLista(TLista *lista,TImprimirElemento imprimir){
    TELE *caminhador=lista->inicio;

    while(caminhador!=NULL){
        imprimir(caminhador->carga_util);
        caminhador=caminhador->prox;
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
// ***************************** Main  ******************************* //
int main(){

    TLista *lista2=criarListaEncadeada();
    
    int i,num,tam;

    scanf("%d",&tam);

    for(i=0;i<tam;i++){
        scanf("%d",&num);
       TMedida *medida=criarMedida(num);

       inserirFim(lista2,medida);
    }

    TELE *cam2=lista2->inicio;
    
    printf("Inserindo no fim: ");
    imprimirLista(lista2,imprimirMedida);
}