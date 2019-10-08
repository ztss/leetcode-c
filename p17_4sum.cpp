//使用四个指针，abcd,a<b<c<d.先固定ab指针，然后c=b+1,d=length-1.然后cd指针。直到cd指
//针相遇。然后向右移动b，做完b里面的循环，向右移动a。需要注意的是为了不得到重复解，每次
//移动指针的时候，必须使得移动之后的值与之前的值不一样
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> nums={1,0,-1,0,-2,2};
	int target=0;
	sort(nums.begin(),nums.end());
	vector<vector<int>> res;
	for(int a=0;a<nums.size();a++){
		if(a>0&&nums[a-1]==nums[a]){
			continue;
		}
		for(int b=a+1;b<nums.size();b++){
			if(b>a+1&&nums[b]==nums[b-1]){
				continue;
			}
			int c=b+1;
			int d=nums.size()-1;
			while(c<d){
				int temp=nums[a]+nums[b]+nums[c]+nums[d];
				if(temp<target){
          //这里移动指针之所以不要检查，是因为如果移动后的数与之前的数相同，那么也不会
          //是正确结果，所以就无需做检查了。而检查是放在下面的
					c++;
				}
				else if(temp>target){
					d--;
				}
				else{
					vector<int> e={nums[a],nums[b],nums[c],nums[d]};
					res.push_back(e);
					while(c<d&&nums[c+1]==nums[c]){
						c++;
					}
					while(c<d&&nums[d-1]==nums[d]){
						d--;
					}
					c++;
					d--;
				}
			}
		}
	}
	cout << res.size() << endl;
	return 0;
}
