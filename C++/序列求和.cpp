/*	1���Ȳ�������͹�ʽ s = n * a1 + d*(n * (n-1))/2 
 *	2������������Ϊ�ܴ�ʱ��int�޷����棬������long long int 
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
