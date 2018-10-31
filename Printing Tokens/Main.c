#include <stdio.h>
#include <string.h>

int main()
{
	char s[1001];
	gets(s);

	for (int i = 0; s[i] != 0; ++i)
	{
		if (s[i] == ' ')
			printf("\n");
		else
			printf("%c", s[i]);
	}

	return 0;
}