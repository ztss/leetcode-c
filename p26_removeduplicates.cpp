class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

//本题的要求是原地删除数组中相同的元素，假设数据元素是排序后的，并且返回删除后数组的长度
//使用双指针法，一个指针j从数组第二个位置开始，然后遍历完整个数组，一个i指针从数组第一个元
//素开始，当两个指针指向的值相同时，移动指针j,同时指针i不动，到两个指针指向的值不同时，
//向前移动指针i，然后将j处的值赋值给i处的值，然后继续移动指针j，直到j遍历完整个数组。
