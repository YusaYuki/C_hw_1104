#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum status {Continue,Won,Lost};

int rollDice(void);

int main(void)
{
	int sum, point;

	enum status gamestatus;

	srand(time(NULL));
	sum = rollDice();

	switch (sum)
	{
		case 7:
		case 11:
			gamestatus = Won;
			break;
		case 2:
		case 3:
		case 12:
			gamestatus = Lost;
			break;
		default:
			gamestatus = Continue;
			point = sum;
			printf("point is %d\n", point);
			break;
	}

	while (gamestatus == Continue)
	{
		sum = rollDice();
		if (sum == point)
		{
			gamestatus = Won;
		}
		else
		{
			if (sum == 7)
			{
				gamestatus = Lost;
			}
		}
	}
	if (gamestatus == Won)
	{
		printf("Player wins\n");
	}

	if (gamestatus == Lost)
	{
		printf("Player loses\n");
	}
	system("pause");
	return 0;
}

int rollDice(void)
{
	int d1, d2, sum;

	d1 = 1 + (rand() % 6);
	d2 = 1 + (rand() % 6);
	sum = d1 + d2;
	
	printf("Player rolled %d + %d = %d\n", d1, d2, sum);
	return sum;
}