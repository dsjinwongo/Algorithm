#include <stdio.h>

int main()
{
	int n, t = 0, d[2] = { 0 }, e[2] = { 0 }, newnum;
	scanf("%d", &n);
	if (n / 10 == 0)
		d[1] = n;
	else
	{
		d[0] = n / 10;
		d[1] = n % 10;
	}
	if (d[0] != e[0] || d[1] != e[1])
	{

		e[1] = (d[0] + d[1]) % 10;
		e[0] = d[1];
		t++;
	}
	else
	{
		printf("%d", t + 1);
		return 0;
	}
	while (d[0] != e[0] || d[1] != e[1])
	{
		newnum = (e[0] + e[1]) % 10;
		e[0] = e[1];
		e[1] = newnum;
		t++;
	}
	printf("%d", t);
	return 0;
}