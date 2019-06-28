#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	vector<vector<int>> vnums;
	//vector<int> temp;
	vector<int> nums={-1,0,1,2,-1,-4};
	int size=nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<size;i++)
	{
		while(i>0&&i<size&&nums[i]==nums[i-1])
		{
			i++;
		}
		int j=i+1;
		int k=size-1;
		while(j<k)
		{
			int sum=nums[i]+nums[j]+nums[k];
			if(sum==0)
			{
				vector<int> temp(3);
				temp[0]=nums[i];
				temp[1]=nums[j];
				temp[2]=nums[k];
				vnums.push_back(temp);
				k--;
				j++;
				while(j<k&&nums[j]==nums[j-1])
				{
					j++;
				}
				while(k>j&&nums[k]==nums[k+1])
				{
					k--;
				}
			}
			else if(sum<0)
			{
				j++;
				while(j<k&&nums[j]==nums[j-1])
				{
					j++;
				}
			}
			else
			{
				k--;
				while(k>j&&nums[k]==nums[k+1])
				{
					k--;
				}
			}
		}
	}
	cout << vnums.size() << endl;
	return 0;
}
//算法需要先进行排序，这样是为了跳过重复的元素以及能够升序排序结果。然后就是两重循环，
//第一层循环遍历i，然后在这重循环第一步跳过重复的位置，然后定义两个指针指向i的前一个位置
//以及数组的最后一个位置，检查三个数相加是否等于1，直到两个指针相遇，记得j,k指针每改变
//一次位置就要检查是否与前一个位置的数重复，重复就直接跳过。
