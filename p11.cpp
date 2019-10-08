#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& vi)
{
	size_t start=0;
	size_t end=vi.size()-1;
	int max=0;
	while(start!=end)
	{
		int area=min(vi[start],vi[end])*(end-start);
		if(vi[start]<=vi[end])
		{
			start++;
		}
		else
		{
			end--;
		}
		if(max<area)
		{
			max=area;
		}
	}
	return max;
}

int main()
{
	vector<int> vi={1,8,6,2,5,4,8,3,7};
	cout << maxArea(vi) << endl;
	return 0;
}
