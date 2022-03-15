/*
* Problem: 1629
* Solver: Jinwon
* Reference: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kks227&logNo=220583413569
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long dividePow(long long base, long long n);

long long a, b, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> a >> b >> c;

	cout << dividePow(a, b);

	return 0;
}

long long dividePow(long long base, long long n)
{
	long long answer = 1;

	while (n)
	{
		if (n % 2 != 0)
			answer = (answer * base) % c;
		base = (base * base) % c;
		n /= 2;
	}

	return answer;
}