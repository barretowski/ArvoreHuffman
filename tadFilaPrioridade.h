//Fila com prioridade

struct hash
{
	int simbolo, frequencia;
	struct hash *esq, *dir;
};typedef struct hash Hash;

struct fila
{
	struct fila *prox;
	struct hash *hash;
};typedef struct fila Fila;

void init(Fila **F)
{
	*F = NULL;
}

char isEmpty(Fila *F)
{
	return F == NULL;
}


void enqueue(Fila **fila, Hash hash) {

}

int vazia(Lista *l) {
    return (l->topo == NULL);
}
