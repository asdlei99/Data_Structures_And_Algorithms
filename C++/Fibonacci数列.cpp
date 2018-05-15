#include <iostream>
using namespace std;

int main()
{
	int f[1000000];
	int i = 0, n = 0;
	cin>>n;
	f[1] = f[2] = 1;
	for (i = 3; i <= n; i++)
	{
		f[i] = (f[i-1] + f[i-2])%10007;
	}
	cout<<f[n];
	return 0;
}
