#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>
#include "tadFilaPrioridade.h"

struct hash
{
	int simbolo, frequencia;
	struct hash *esq, *dir;
};typedef struct hash Hash;

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

Tree * criaNo(int info)
{
	Tree *nova = (Tree*)malloc(sizeof(Tree));
	nova->info = info;
	nova->esq = nova->dir = NULL;
	return nova;
}

int main()
{
	
}
