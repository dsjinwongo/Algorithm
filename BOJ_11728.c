#include<stdio.h>
#include<stdlib.h>

int compare(int *a, int *b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else return 0;
}

int main()
{
	int* A,* B, *C;
	int n, m, i;
	scanf("%d %d", &n, &m);
	C = (int*)calloc(m + n, sizeof(int));
	for (i = 0; i < n + m; i++)
		scanf(" %d", &C[i]);

	qsort(C, n + m, sizeof(int), compare);

	for (i = 0; i < m + n; i++)
		printf("%d ", C[i]);
}