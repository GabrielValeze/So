#include <stdio.h>
#include <stdlib.h>

struct Fila {

	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;

};

void criarFila( struct Fila *f, int c ) {

	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;

}

void processoInclusao(struct Fila *f, int v) {

	for (size_t i = 0; i < 10; i++) {

		if(f->ultimo == f->capacidade-1)
			f->ultimo = -1;

		f->ultimo++;
		f->dados[f->ultimo] = v; // incrementa ultimo e insere
		f->nItens++; // mais um item inserido

	}
}

int processoRemocao( struct Fila *f ) { // pega o item do comeÃ§o da fila

	for (size_t i = 0; i < 10; i++) {

		int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro

		if(f->primeiro == f->capacidade)
			f->primeiro = 0;

		f->nItens--;  // um item retirado
		return temp;

	}
}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%.2f\t",f->dados[i++]);

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}


int randomica( struct Fila *f){
	int count1=0;
	int count0=0;
	int x,y;

	int capa;
	capa = 1000;
	struct Fila umaFila;
	criarFila(&umaFila, capa);


	for (size_t i = 0; i < 199; i++) {


		y=rand()%2;

		if(y==1){
			for (size_t i = 0; i < 5; i++) {
				printf("processo de remocao: %i\n", i);
				processoRemocao(&umaFila);
			}
			for (size_t i = 0; i < 5; i++) {
				count1+=1;
				int valor=1;
				printf("processo de inclusao: %i\n", i);
				processoInclusao(&umaFila,valor);
		}
	}else {

			for (size_t i = 0; i < 5; i++) {
				count1+=1;
				int valor=1;
				printf("processo de inclusao: %i\n", i);
				processoInclusao(&umaFila,valor);
		}
			for (size_t i = 0; i < 5; i++) {
					printf("processo de remocao: %i\n", i);

				processoRemocao(&umaFila);
			}

		}
		}
	return 1;
		}



void main () {

	int opcao, capa;
	float valor;
	struct Fila umaFila;

	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Processo Inclusao\n2 - Processo Remocao\n3 - Mostrar processos\n4-  Gerar randômicamente 200 processos\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\n Qual é o id de identificação do processo a ser inserido?(O ID é dado por um valor numérico inteiro) ");
					scanf("%f", &valor);
					processoInclusao(&umaFila,valor);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					valor = processoRemocao(&umaFila);
					printf("\n%1f removido com sucesso\n\n", valor) ;

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila => ");
						mostrarFila(&umaFila);

					}
					break;

					case 4: // Fazer a parada randômica.
						randomica(&umaFila);
						break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}
