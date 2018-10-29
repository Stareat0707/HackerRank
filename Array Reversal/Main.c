#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, i;
	int* arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	for (i = n - 1; i >= 0; --i)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	return 0;
}