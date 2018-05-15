/*≈≈–ÚÀ„∑®*/
#include <iostream>
using namespace std;

void sort(int a[], int n)
{
	int i = 0, j = 0;
	int temp = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int l = 0;
	cin>>l;
	
	int s[l], i = 0;
	for (i = 0; i < l; i++)
	{
		cin>>s[i];
	}
	sort(s,l);
	return 0;
}
