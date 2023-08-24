/* Fila e Pilha Estática
   Chen - ago/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM 100

int fila[TAM];
int pilha[TAM];
int tam;
int pti, ptf, ptopo;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void escreve(void)
{
	int i;

	gotoxy(0, 10);
	printf("Fila\n");
	if (pti == ptf)
		printf("<empty>\n\n");
	else
	{
		printf("\033[1;33m");
		for (i = pti + 1; i <= ptf; i++)
			printf("%d, ", fila[i]);
		printf("                 \033[0m\n\n");
	}
	printf("Pilha\n");
	if (ptopo < 0)
		printf("<empty>\n\n");
	else
	{
		printf("\033[1;33m");
		for (i = 0; i <= ptopo; i++)
			printf("%d, ", pilha[i]);
		printf("                 \033[0m\n\n");
	}
}

void insere(int num)
{
	if (ptf < tam - 1)
	{
		printf("\033[1;33mInsere: %d         \033[0m\n", num);
		ptf++;
		fila[ptf] = num;
	}
	else
		printf("\033[1;33mInsere: Queue Overflow \033[0m\n");
}
void remove(void)
{
	int num;

	if (pti == ptf)
	{
		printf("Queue: <empty>\n\n");
		pti = -1;
		ptf = -1;
	}
	else
	{
		pti++;
		num = fila[pti];
		printf("\033[1;33mRemove: %d               \033[0m\n", num);
	}
}
void empilha(int num)
{
	if (ptopo < tam - 1)
	{
		printf("\033[1;33mEmpilha: %d              \033[0m\n", num);
		ptopo++;
		pilha[ptopo] = num;
	}
	else
		printf("\033[1;33mEmpilha: Stack Overflow  \033[0m\n");
}
void desempilha(void)
{
	int num;

	if (ptopo < 0)
		printf("Stack: <empty>\n\n");
	else
	{
		num = pilha[ptopo];
		ptopo--;
		printf("\033[1;33mDesempilha: %d           \033[0m\n", num);
	}
}

int main(void)
{
	int fg, op, num;

	srand(time(NULL));
	system("cls");

	printf("Estrutura de Dados - filas e pilhas estaticas\n\n");
	printf("Tamanho das estruturas (max 100): ");
	scanf("%d", &tam);
	gotoxy(0, 5);
	printf("1-Insere, 2-Remove, 3-Empilha, 4-Desempilha, 5-Fim ==> ");
	pti = -1;
	ptf = -1;
	ptopo = -1;
	while (1 == 1)
	{
		escreve();
		fg = 0;
		while (fg == 0)
		{
			gotoxy(0, 5);
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

		if (op == 1)
		{
			num = rand() % 100;
			insere(num);
		}
		else if (op == 2)
			remove();
		else if (op == 3)
		{
			num = rand() % 100;
			num *= (rand() % 2 == 0 ? 1 : -1);
			empilha(num);
		}
		else
			desempilha();
	}

	return 0;
}