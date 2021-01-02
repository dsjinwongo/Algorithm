#include <iostream>

using namespace std;
int main()
{
	int k, a, ak, b, bk;

	cin >> k;
	a = 1;
	b = 0;
	while (k--)
	{
		bk = a + b;
		ak = b;
		b = bk;
		a = ak;
	}
	cout << ak << " " << bk;
}