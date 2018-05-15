/*头文件iomanip的用法，fixed 补充0，setpercision设置小数点后的位置*/
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
