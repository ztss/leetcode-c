#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int num;
	cin >> num;
	string chr[4][10]=
	{
		{"","I","II","III","IV","V","VI","VII","VIII","IX"},
		{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
		{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
		{"","M","MM","MMM"}
	};
	string strroman=chr[3][(num/1000)%10]+chr[2][(num/100)%10]+chr[1][(num/10)%10]+chr[0][num%10];
	cout << strroman << endl;
	return 0;
}
//对于比较小范围的数，可以直接使用数组一个一个求解，对于大范围的数的话，可以使用进制，比
//如这个题，可以使用{i,iv,v,ix,x,xl,l,xc,c,cd,d,cm,m}作为进制的基础。
