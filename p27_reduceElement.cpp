class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int i=0;
       for(int j=0;j<nums.size();j++){
           if(nums[j]!=val){
               nums[i]=nums[j];
               i++;
           }
       }
        return i;
    }
};
//这个题要求删除数组中给定值的数，并且空间复杂度为常数，数组顺序可以改变，并且数组不是
//排好序的。也是设置两个指针i,j，都从0开始，如果j指针指向的值不等于val,则将j的值给i,然后
//i前移，j也前移，如果等于，j前移，i不移动。
