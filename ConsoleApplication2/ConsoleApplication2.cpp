#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>


#define NomeTitulo 50
#define NumTarefas 101
#define MaxDescricao 100

typedef struct Tarefas {

	char nome[NomeTitulo];
	char descricao[MaxDescricao];
	int id;
	int TarefasConcluidas = 0;
	char status[10];

};

Tarefas tarefas[NumTarefas];
int contador = 0;

void AdicionarTarefas(void);
void LimparBuffer(void);
void MostrarLista(void);
void ConcluirTarefa(void);
void ExcluirTarefa(void);


int main() {
	int opcao;
	setlocale(LC_ALL, "Portuguese_Brazil.1252");

	printf("Crie seu bloco de atrefas: \n");

	do {


		printf("digte: \n 1_ adicionar tarefas \n 2_ consultar lista de tarefas \n 3_ marcar como concluida  \n 4_ para excluir uma tarefa \n 5_ Encerrar o programa \n");
		scanf_s("%i", &opcao);
		LimparBuffer();

		switch (opcao) {

		case 1:
			AdicionarTarefas();
			system("cls");
			break;

		case 2:
			MostrarLista();
			break;

		case 3:
			ConcluirTarefa();
			break;

		case 4:
			ExcluirTarefa();
			system("cls");
			break;

		}



	} while (opcao != 5);


	printf("obrigado por utilizar o programa :D");

}



void AdicionarTarefas(void) {
	Tarefas nova;


	if (contador >= NumTarefas) {
		printf("Limite de tarefas alcançado");
		return;
	}

	nova.id = contador + 1;
	printf("adicione os dados da sua nova tarefa: \n");
	printf("nome: ");
	gets_s(nova.nome, NomeTitulo);
	printf("descricao de %s: \n", nova.nome);
	gets_s(nova.descricao, MaxDescricao);
	tarefas[contador++] = nova;
	system("pause");
}

void MostrarLista(void) {

	if (contador == 0) {
		printf("Nenhuma tarefa cadastrada: ");
		return;
	}




	printf("\nsua lista atualmente: \n");
	for (int i = 0;i < contador;i++) {

		if (tarefas[i].TarefasConcluidas == 0) {

			printf("Id: %i \n Nome: %s \n descriçao: %s \n status: pendente. \n\n", tarefas[i].id, tarefas[i].nome, tarefas[i].descricao);
		}

		else if (tarefas[i].TarefasConcluidas == 1) {
			printf("Id: %i \n Nome: %s \n descriçao: %s \n status:  concluida.\n\n", tarefas[i].id, tarefas[i].nome, tarefas[i].descricao);
		}

	}



	printf("tarefa não encontrada");
}


void ConcluirTarefa(void) {


	int id;
	printf("digite o Id da tarefa que deseja concluir: ");
	scanf_s("%d", &id);
	for (int i = 0;i < contador;i++) {

		if (tarefas[i].id == id) {
			tarefas[i].TarefasConcluidas = 1;
			printf("\n Tarefa concluida com sucesso!\n");
			return;
		}


	}

}

void ExcluirTarefa(void) {
	int id, i, indice = -1;


	printf("digite o Id que deseja excluir: ");
	scanf_s("%i", &id);

	for (i = 0;i < contador;i++) {
		if (tarefas[i].id == id) {
			indice = i;
			break;
		}

	}

	if (indice == -1) {
		printf("tarefa não encontrada");

	}

	for (int i = indice; i < contador - 1;i++) {
		tarefas[i] = tarefas[i + 1];
	}

	contador--;

	printf("tarefas com ID: %i excluida com sucesso!", id);

}




void LimparBuffer(void) {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

