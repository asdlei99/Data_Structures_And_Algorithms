/*ͷ�ļ�iomanip���÷���fixed ����0��setpercision����С������λ��*/
#include <iostream>
#include <iomanip>
#define PI 3.14159265358979323
using namespace std;

int main()
{
	int r;
	cin>>r;
	cout<<fixed<<setprecision(7)<<PI * r * r<<endl;
	return 0;
}
