#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 2, m, primo = 0, i = 2;

	scanf("%d", &m);

	for (n; n <= m; n++)
	{
		while (i < n)
		{
			if (n % i == 0)
			{
				primo++;
			}
			i++;
		}

		i = 2;

		if (primo == 0)
			printf("%d ", n);

		primo = 0;
	}
	return 0;
}
