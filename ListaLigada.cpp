/* Lista Ligada
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

node *heap, *pointx;

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
	printf("Lista Ligada Ordenada\n");
	if (heap == NULL)
		printf("<empty>\n\n");
	else
	{
		printf("\033[1;33m");
		px = heap;
		while (px != NULL)
		{
			printf("%d, ", px->info);
			px = px->lig;
		}
		printf("                 \033[0m\n\n");
	}
}

int insere(node *px)
{
	node *ptx, *pty;

	gotoxy(0, 4);
	printf("\033[1;33mInsere: %d         \033[0m\n", px->info);
	if (heap == NULL)
	{
		heap = px;
	}
	else
	{
		ptx = heap;
		while (ptx != NULL)
		{
			if (ptx->info > px->info)
			{
				px->lig = ptx;
				if (heap == ptx)
					heap = px;
				else
					pty->lig = px;
				return 0;
			}
			else
			{
				pty = ptx;
				ptx = ptx->lig;
			}
		}
		if (ptx == NULL)
		{
			pty->lig = px;
		}
	}
	return 0;
}

int pesq(int num)
{
	node *ptx, *pty;

	if (heap == NULL)
	{
		return -1;
	}

	pointx = NULL;
	ptx = heap;
	pty = NULL;

	while (ptx != NULL)
	{
		if (ptx->info < num)
		{
			pty = ptx;
			ptx = ptx->lig;
		}
		else
			break;
	}

	if (ptx == NULL)
		return -1;

	if (ptx->info == num)
	{
		pointx = pty;
		return 0;
	}

	return -1;
}

void remove(void)
{
	node *px;
	int rc, num;

	gotoxy(0, 4);
	if (heap == NULL)
	{
		printf("Lista: <empty>\n\n");
	}
	else
	{
		gotoxy(0, 4);
		printf("\033[1;33mRemove:                                      \033[0m");
		gotoxy(7, 4);
		scanf("%d", &num);
		rc = pesq(num);
		if (rc == 0)
		{
			if (pointx == NULL)
			{
				px = heap;
				heap = heap->lig;
			}
			else
			{
				px = pointx->lig;
				pointx->lig = px->lig;
			}
			free(px);
		}
		else
			printf("No exist element # %d\n", num);
	}
}

void procura(void)
{
	node *px;
	int rc, num;

	gotoxy(0, 4);
	if (heap == NULL)
	{
		printf("Lista: <empty>\n\n");
	}
	else
	{
		gotoxy(0, 4);
		printf("\033[1;33mProcura:                                      \033[0m");
		gotoxy(9, 4);
		scanf("%d", &num);
		rc = pesq(num);
		if (rc == 0)
		{
			printf("Element # %d found.\n", num);
		}
		else
			printf("No exist element # %d\n", num);
	}
}

void inverte(void)
{
	node *ptx, *pty, *ptz;

	gotoxy(0, 4);
	if (heap == NULL)
		printf("Lista: <empty>\n\n");
	else
	{
		ptx = heap;
		pty = NULL;
		while (ptx != NULL)
		{
			ptz = ptx->lig;
			ptx->lig = pty;
			pty = ptx;
			ptx = ptz;
		}
		heap = pty;
	}
}

int main(void)
{
	node *px;
	int fg, op, num;

	srand(time(NULL));
	system("cls");

	printf("Estrutura de Dados - Lista ligada ordenada\n\n");
	gotoxy(0, 3);
	printf("1-Insere, 2-Remove, 3-Procurar, 4-Inverter ordenacao, 5-Fim ==> ");
	heap = NULL;

	while (1 == 1)
	{
		escreve();
		fg = 0;
		while (fg == 0)
		{
			gotoxy(0, 3);
			printf("1-Insere, 2-Remove, 3-Procurar, 4-Inverter ordenacao, 5-Fim ==> ");
			scanf("%d", &op);
			if ((op > 0) && (op < 6))
				break;
		}
		gotoxy(0, 5);
		printf("                              ");
		if (op == 5)
		{
			printf("\nFinish...\n");
			return 0;
		}
		if (op == 1)
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
			insere(px);
		}
		else if (op == 2)
			remove();
		else if (op == 3)
			procura();
		else
			inverte();
	}

	return 0;
}