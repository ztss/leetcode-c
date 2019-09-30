#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	vector<int> nums={-1,1,2,4};
	sort(nums.begin(),nums.end());
	int target=1;
	int res=10000000;
	int flag=0;
	for(int i=0;i<nums.size();i++)
	{
		int num=nums[i];
		int start=i+1;
		int end=nums.size()-1;
		while(end>start){
			int sum=num+nums[start]+nums[end];

			if(sum>target)
			{
				end--;
			}
			else if(sum<target){
				start++;

			}
			else{
				cout << target << endl;
				return 0;
			}
			if(res>abs(sum-target))
			{
				res=abs(sum-target);
				if(sum-target<0){
					flag=0;
				}
				else{
					flag=1;
				}
			}
		}
	}
	if(flag){
		cout << target+res << endl;
	}
	else
	{
		cout << target-res << endl;
	}
	return 0;
}


//这个题目比较简单，先排序可以减少复杂度。
