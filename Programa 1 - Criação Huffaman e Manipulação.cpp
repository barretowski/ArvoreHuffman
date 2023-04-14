//Arvore binária
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio2.h>
#include "tadFilaPrioridade.h"

/*
struct fila
{
	Tree* info;
	struct fila *prox;
};typedef struct fila Fila;
*/
//fila com prioridade na inserção baseado na frequencia e remoção

struct registro
{
	int simbolo;
	char palavra[20];
	int frequencia;
	char codHuffman[20];
};typedef struct registro Registro;

struct lista
{
	Registro reg;
	struct lista *prox;
};typedef struct lista Lista;


Lista * criaNo(Registro reg)
{
	Lista *nova = (Lista*)malloc(sizeof(Lista));
	nova->reg = reg;
	nova->prox = NULL;
	
	return nova;
}

void insereNaLista(char frase[200],Lista **lista)
{
	Lista *auxLista = *lista;
	Registro reg;
	strcpy(reg.codHuffman,"0000");
	reg.frequencia = 1;
	reg.simbolo = 1;
	strcpy(reg.palavra,frase);
	
	Lista *nova = criaNo(reg);
	
	if(*lista == NULL)
		*lista = nova;
	else
	{
		while(auxLista->prox != NULL)
			auxLista = auxLista->prox;
			
		auxLista->prox = nova;
	}
		
}

void buscaLista(Lista *lista, char nova[200], Lista **aux)
{
	printf("%s",lista->reg.palavra);
	while(lista != NULL && aux==NULL)
	{
		if(strcmp(lista->reg.palavra,nova)==0)
			*aux = lista;
			
		lista = lista->prox;
	}
}

void manipulaFrase(char frase[200], Lista **lista)
{
	Lista *aux;
	int x,j;
	char nova[200];
	for(x=0; x<strlen(frase);x++)
	{
		if(frase[x] == ' ')
		{
			strcpy(nova," ");
		}
		else
		{
			nova[0] = '\0';
			j=0;
			while(frase[x] != ' ' && x<strlen(frase))
				nova[j++] = frase[x++];
			nova[j] = '\0';
		}
		//verifica se a frase ja existe na lista
		buscaLista(*lista, nova, &aux);
		
		if(aux != NULL)
			aux->reg.frequencia++;
		else
			insereNaLista(nova,&*lista);
	}
}
void exibeFrase(Lista *lista)
{
	int i=0;
	while(lista != NULL)
	{
		printf("\n[%d] - [%s] - [%d] - [%s]",lista->reg.simbolo, lista->reg.palavra, 
		lista->reg.frequencia, lista->reg.codHuffman);
		lista = lista->prox;
	}
}
int main()
{
	Lista *lista = NULL;
	char string[200];
	strcpy(string, "hoje eh hoje e nao eh amanha, pois tem que ser hoje e nao amanha");
	manipulaFrase(string, &lista);
	//exibeFrase(lista);
}
