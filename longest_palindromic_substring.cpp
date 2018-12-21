class Solution {
public:
    string longestPalindrome(string s) {
        int length=s.size();
        int maxLen=0;
        int istart=0;
	    for(int start=0;start<length;start++)
	    {
		    for(int end=start;end<length;end++)
		    {
                string str=s.substr(start,end-start+1);
			    if(is_palindromic(str))
			    {
				    if(maxLen<(end-start+1))
				    {
					    maxLen=end-start+1;
					    istart=start;
				    }
			    }
		    }
	    }
        string resstr=s.substr(istart,maxLen);
	    return resstr;
        }
    bool is_palindromic(string &s)
{
	int length=s.size();
	int bound=length/2;
	for(int i=0;i<bound;i++)
	{
		if(s[i]!=s[length-i-1])
		{
			return false;
		}
	}
	return true;
}

};
//这个题目没什么好说的，就是注意string 类的substring函数
//str.substring(pos,len)可以得到一个str的子string对象，从pos开始长度为length的字串
//可以使用expand around center方法。即从一个string中找一个字符串分别从左从右扩展，就
//可以找到回文串。注意有2n-1个中点，因为有可能是两个连续的字符串为中点
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

int is_palindromic(string &str,int left,int right);

int main()
{
	string s;
	cin>>s;
	int length=s.size();
	int maxLen=0;
	int istart=0;
	for(int i=0;i<length;i++)
	{
		int len1=is_palindromic(s,i,i);
		int len2=is_palindromic(s,i,i+1);
		int len=max(len1,len2);
		if(maxLen<len)
		{
			maxLen=len;
			istart=i-(maxLen-1)/2;
		}
	}
	string str=s.substr(istart,maxLen);
	for(auto i:str)
	{
		cout<<i;
	}
	cout<<endl;
	return 0;
}

int is_palindromic(string &str,int left,int right)
{
	int length=str.size();
	while(left>=0&&right<length&&str[left]==str[right])
	{
		left--;
		right++;
	}
	return right-left-1;
}
