#include <stdio.h>

int main()
{
	int result[10] = { 0 }, i;
	char num[1001];

	gets(num);

	for (i = 0; num[i] != 0; ++i)
	{
		if (num[i] - '0' >= 0 && num[i] - '0' <= 9)
			++result[num[i] - '0'];
	}

	for (i = 0; i < 10; ++i)
		printf("%d ", result[i]);
	return 0;
}