#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


LinkedList* ll_newLinkedList(void){

	LinkedList* lista;

	lista = (LinkedList*)  malloc(sizeof(LinkedList));

	lista->pFirstNode = NULL;
	lista->size = 0;

 return lista;
}

int ll_len(LinkedList* this){
	int tamanio;
	tamanio = this->size;

	return tamanio;
}
int ll_add(LinkedList* this, void* pElement){
	Node* iterador;
	int todoOk =0;

	if (this != NULL && pElement != NULL){

	if (this->pFirstNode == NULL && this->size == 0){
		Node* nodo;
		nodo = (Node*) malloc(sizeof(Node));
		nodo->pElement = pElement;
		nodo->pNextNode = NULL;

	} else{
		iterador = this->pFirstNode;
		while(iterador->pNextNode != NULL){
			iterador = iterador->pNextNode;

		}
				Node* nodo;
				nodo = (Node*) malloc(sizeof(Node));
				nodo->pElement = pElement;
				nodo->pNextNode = NULL;
			iterador->pNextNode = nodo;

	}
	this->size++;
	todoOk =1;
	}

return todoOk;
}
int ll_deleteLinkedList(LinkedList* this){
	int todoOk = 0;

	if(this != NULL){

		free(this);
		todoOk = 1;
	}
	return todoOk;
}
int ll_remove(LinkedList* this,int index){
	int todoOk=0;
	Node* iterador;
	int contador= 0;

	if(this != NULL && index >=0){
		if (index == 0){
			Node* primerNodo;
			Node* segundoNodo;
			primerNodo = this->pFirstNode;
			segundoNodo = primerNodo->pNextNode;
			free(primerNodo);
			this->pFirstNode = segundoNodo;
			this->size--;
		} else if (index == this->size-1){
			Node* anteUltimoNodo;
			Node* ultimoNodo;
			iterador = this->pFirstNode;
			while(iterador->pNextNode->pNextNode != NULL){
						iterador = iterador->pNextNode;
					}
			anteUltimoNodo = iterador;
			ultimoNodo = iterador->pNextNode;
			anteUltimoNodo->pNextNode = NULL;
			free(ultimoNodo);
			this->size--;

		} else if(index>0 && index <this->size-1){
			Node* nodoABorrar;
			Node* anteriorABorrar;
			Node* siguienteABorrar;

			iterador = this->pFirstNode;
			while(contador < index-1){
				iterador = iterador->pNextNode;
				contador++;
			}
			anteriorABorrar = iterador;
			nodoABorrar = iterador->pNextNode;
			siguienteABorrar = nodoABorrar->pNextNode;

			anteriorABorrar->pNextNode = siguienteABorrar;
			free(nodoABorrar);
			this->size--;
		}



		todoOk=1;
	}
	return todoOk;
}
void* ll_get(LinkedList* this, int index){
Node* iterador;
iterador = this->pFirstNode;
while(iterador->pNextNode != NULL){
	iterador = iterador->pNextNode;
}

return iterador->pElement;
}
