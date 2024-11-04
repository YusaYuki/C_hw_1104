#include <stdio.h>
#include <stdlib.h>

long factor(long num);

int main(void)
{
	int i;
	for (i = 0;i <= 10;i++)
	{
		printf("%2d! = %1d\n", i, factor(i));
	}
	system("pause");
	return 0;
}

long factor(long num)
{
	if (num <= 1)
	{
		return 1;
	}
	else
	{
		return(num * factor(num - 1));
	}
}