#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b)
{
	return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b)
{
	return strcmp(a, b) * -1;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
	char check[26] = { 0 };
	int count_a = 0;
	for (int i = 0; i < strlen(a); ++i)
	{
		if (check[a[i] - 'a'] == 0)
		{
			check[a[i] - 'a'] = 1;
			++count_a;
		}
	}

	int count_b = 0;
	memset(check, 0, 26);
	for (int i = 0; i < strlen(b); ++i)
	{
		if (check[b[i] - 'a'] == 0)
		{
			check[b[i] - 'a'] = 1;
			++count_b;
		}
	}

	if (count_a != count_b)
		return count_a - count_b;
	else
		return strcmp(a, b);
}

int sort_by_length(const char* a, const char* b)
{
	if (strlen(a) != strlen(b))
		return strlen(a) - strlen(b);
	else
		return strcmp(a, b);
}

void string_sort(char** arr, const int len, int(*cmp_func)(const char* a, const char* b))
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (cmp_func(arr[i], arr[j]) > 0)
			{
				char* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int n;
	scanf_s("%d\n", &n);

	char** arr;
	arr = (char**)malloc(n * sizeof(char*));

	for (int i = 0; i < n; ++i)
	{
		arr[i] = (char*)malloc(1024 * sizeof(char));
		gets(arr[i]);
		arr[i] = (char*)realloc(arr[i], strlen(arr[i]) + 1);
	}

	string_sort(arr, n, lexicographic_sort);
	for (int i = 0; i < n; ++i)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, lexicographic_sort_reverse);
	for (int i = 0; i < n; ++i)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_length);
	for (int i = 0; i < n; ++i)
		printf("%s\n", arr[i]);
	printf("\n");

	string_sort(arr, n, sort_by_number_of_distinct_characters);
	for (int i = 0; i < n; ++i)
		printf("%s\n", arr[i]);
	printf("\n");

	return 0;
}