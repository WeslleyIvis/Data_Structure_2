/* Fila e Pilha Dinâmica
   Chen - ago/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct tynode node;

struct tynode
{
	int info;
	node *lig;
};

node *pti, *ptf, *ptopo;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void escreve(void)
{
	node *px;

	gotoxy(0, 10);
	printf("Fila\n");
	if (pti == NULL)
		printf("<empty>\n\n");
	else
	{
		printf("\033[1;33m");
		px = pti;
		while (px != NULL)
		{
			printf("%d, ", px->info);
			px = px->lig;
		}
		printf("                 \033[0m\n\n");
	}
	printf("Pilha\n");
	if (ptopo == NULL)
		printf("<empty>\n\n");
	else
	{
		px = ptopo;
		printf("\033[1;33m");
		while (px != NULL)
		{
			printf("%d, ", px->info);
			px = px->lig;
		}
		printf("                 \033[0m\n\n");
	}
}

void insere(node *px)
{
	printf("\033[1;33mInsere: %d         \033[0m\n", px->info);
	if (ptf == NULL)
	{
		ptf = px;
		pti = px;
	}
	else
	{
		ptf->lig = px;
		ptf = px;
	}
}

void remove(void)
{
	node *px;

	if (pti == NULL)
	{
		printf("Queue: <empty>\n\n");
	}
	else
	{
		printf("\033[1;33mRemove: %d               \033[0m\n", pti->info);
		px = pti->lig;
		free(pti);
		pti = px;
	}
}

void empilha(node *px)
{
	printf("\033[1;33mEmpilha: %d              \033[0m\n", px->info);
	px->lig = ptopo;
	ptopo = px;
}

void desempilha(void)
{
	node *px;

	if (ptopo == NULL)
		printf("Stack: <empty>\n\n");
	else
	{
		printf("\033[1;33mDesempilha: %d           \033[0m\n", ptopo->info);
		px = ptopo->lig;
		free(ptopo);
		ptopo = px;
	}
}

int main(void)
{
	node *px;
	int fg, op, num;

	srand(time(NULL));
	system("cls");

	printf("Estrutura de Dados - filas e pilhas dinamica\n\n");
	gotoxy(0, 3);
	printf("1-Insere, 2-Remove, 3-Empilha, 4-Desempilha, 5-Fim ==> ");
	pti = NULL;
	ptf = NULL;
	ptopo = NULL;

	while (1 == 1)
	{
		escreve();
		fg = 0;
		while (fg == 0)
		{
			gotoxy(0, 3);
			printf("1-Insere, 2-Remove, 3-Empilha, 4-Desempilha, 5-Fim ==> ");
			scanf("%d", &op);
			if ((op > 0) && (op < 6))
				break;
		}
		if (op == 5)
		{
			printf("\nFinish...\n");
			return 0;
		}
		if ((op == 1) || (op == 3))
		{
			px = (node *)malloc(sizeof(node));
			if (px == NULL)
			{
				printf("\nFailed to allocate memory for queue\n");
				exit(-1);
			}
			num = rand() % 100;
			num *= (rand() % 2 == 0 ? 1 : -1);
			px->info = num;
			px->lig = NULL;
		}

		if (op == 1)
			insere(px);
		else if (op == 2)
			remove();
		else if (op == 3)
			empilha(px);
		else
			desempilha();
	}

	return 0;
}