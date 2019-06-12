#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char,int> mr;
	mr.insert(pair<char,int>('I',1));
	mr.insert(pair<char,int>('V',5));
	mr.insert(pair<char,int>('X',10));
	mr.insert(pair<char,int>('L',50));
	mr.insert(pair<char,int>('C',100));
	mr.insert(pair<char,int>('D',500));
	mr.insert(pair<char,int>('M',1000));
	int sum=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(mr[s[i-1]]>=mr[s[i]])
		{
			sum+=mr[s[i]];
		}
		else
		{
			sum+=(mr[s[i]]-mr[s[i-1]]);
			i--;
		}
	}
	cout << sum << endl;
	return 0;
}
//这个题目可以从右往左遍历罗马字符串，如果左边的比右边的对应的数字小，那么就用右边的减去
//左边的数字然后加入总和中，否则一个一个依次加入总和，最后的结果即是正确答案。
