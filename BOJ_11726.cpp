/*
Problem: 11726
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int recursive(int n);

int dp[10001]={0};

int main()
{
	int n;
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	
	cin>>n;
	
	cout<<recursive(n);
    
    return 0;
}

int recursive(int n) {
	
	if(dp[n]==0)
		dp[n] = (recursive(n-1)+recursive(n-2))%10007;
	
	return dp[n];
}