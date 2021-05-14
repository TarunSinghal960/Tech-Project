#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char values[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void move(char name[7])
{
	char r = ' ';
	int p;
	if(name == "player1")
	{	r = 'X';
		name = "Player 1"; }
	else
	{	r = 'O';
		name = "Player 2"; }
	while(1)
	{
		printf("%s : \n", name);
		printf("Enter position (1 - 9 in horizontal fashion) : ");
		scanf("%d", &p);
		if(values[p - 1] != ' ')
		{
			printf("Already filled ! \n");
			continue;
		}
		values[p - 1] = r;
		break;
	}
	
}

int result()
{
	int s;
	if((values[0] == 'X' && values[1] == 'X' && values[2] == 'X' ) || (values[3] == 'X' && values[4] == 'X' && values[5] == 'X') || 
	(values[6] == 'X' && values[7] == 'X' && values[8] == 'X' ) || (values[0] == 'X' && values[3] == 'X' && values[6] == 'X') || 
	(values[1] == 'X' && values[4] == 'X' && values[7] == 'X') || (values[2] == 'X' && values[5] == 'X' && values[8] == 'X') || 
	(values[0] == 'X' && values[4] == 'X' && values[8] == 'X') || (values[2] == 'X' && values[4] == 'X' && values[6] == 'X'))
		s = 1;
	else if((values[0] == 'O' && values[1] == 'O' && values[2] == 'O' )|| (values[3] == 'O' && values[4] == 'O' && values[5] == 'O') || 
	(values[6] == 'O' && values[7] == 'O' && values[8] == 'O') || (values[0] == 'O' && values[3] == 'O' && values[6] == 'O') || 
	(values[1] == 'O' && values[4] == 'O' && values[7] == 'O') || (values[2] == 'O' && values[5] == 'O' && values[8] == 'O') || 
	(values[0] == 'O' && values[4] == 'O' && values[8] == 'O') || (values[2] == 'O' && values[4] == 'O' && values[6] == 'O'))
		s =  2;
	else
		s =  0;
	return s;
}

void display()
{
	system("cls");
	printf("\n\t\t\t\t Tic-Tac-Toe Game");
	printf("\n\n\n\n");
	printf("\t\t\t\t-------------\n\t\t\t\t");
	for(int i = 0; i < 9; i++)
	{
		printf("| %c ", values[i]);
		if((i + 1) % 3 == 0)
		{
			printf("|\n");
			printf("\t\t\t\t-------------\n");
			printf("\t\t\t\t");
		}
	}
	printf("\n");
}

int main()
{
	int n, m, score;
	char ch = 'y';
	do
	{
		score = 0;
		for(int i = 0; i < 9; i++)
			values[i] = ' ';
		display();
		printf("Player 1 : X \nPlayer 2 : O \nWhich player should make the first move : ");
		scanf("%d", &n);
		if(n == 1)
			m = 2;
		else if(n == 2)
			m = 1;
		else
		{
			printf("Invalid choice !\n");
			continue;
		}
		if(n == 1)
			move("player1");
		else
			move("player2");
		display();
		
		for(int i = 1; i < 9; i++)
		{
			if((i + 1) % 2 == 0)
			{
				if(m == 1)
					move("player1");
				else
					move("player2");
			}
			else
			{
				if(n == 1)
					move("player1");
				else
					move("player2");
			}
			display();
			score = result();
			if(score == 1)
			{
				printf("Player 1 has won the match ! \n");
				break;
			}
			else if(score == 2)
			{
				printf("Player 2 has won the match ! \n");
				break;
			}
			else
				continue;
		}
		
		if(score == 0)
			printf("It's a draw ! \n");
		fflush(stdin);
		printf("Do you want to play another game (y / n) : ");
		scanf("%c", &ch);
	} while(ch == 'y' || ch == 'Y');
	
	printf("End of game ...\n");
	return 0;
}