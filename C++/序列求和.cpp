/*	1、等差数列求和公式 s = n * a1 + d*(n * (n-1))/2 
 *	2、当此题数据为很大时，int无法保存，所以用long long int 
 */
#include <iostream>
using namespace std;

int main()
{
	long long int n = 0, i = 0, sum = 0;
	cin>>n;
	sum = n + (n * (n-1))/2;
	cout<<sum<<endl;
	return 0;
} 
