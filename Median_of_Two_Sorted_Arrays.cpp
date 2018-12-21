class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  	decltype(nums1.size()) index1=nums1.size();
	  decltype(nums1.size()) index2=nums2.size();
	int m=index1;
	int n=index2;
    double res;
	if(index1>index2)
	{
		vector<int> temp=nums2;
		nums2=nums1;
		nums1=temp;
		int tmp=m;
		m=n;
		n=tmp;
	}
	//cout<<m<<" "<<n<<endl;
	int imin=0;
	int imax=m;
	int halflen=(m+n+1)/2;
	//cout<<"......"<<endl;
	while(imin<=imax)
	{
		int imedian=(imin+imax)/2;
		int j=halflen-imedian;
		//cout<<imedian<<" "<<j<<endl;
		if(imedian>imin&&nums1[imedian-1]>nums2[j])
		{
			imax=imedian-1;
			//cout<<"decrease i"<<endl;
		}
		else if(imedian<imax&&nums2[j-1]>nums1[imedian])
		{
			imin=imedian+1;
			//cout<<"increase i"<<" "<<imedian<<endl;
		}
		else
		{
			int maxleft=0;
			if(imedian==0)
			{
				maxleft=nums2[j-1];
			}
			else if(j==0)
			{
				maxleft=nums1[imedian-1];
			}
			else
			{
				maxleft=max(nums1[imedian-1],nums2[j-1]);
			}
			if((m+n)%2==1)
			{
			    res=maxleft;
			    return res;
			}
			int minright=0;
			if(imedian==m)
			{
				minright=nums2[j];
			}
			else if(j==n)
			{
				minright=nums1[imedian];
			}
			else
			{
				minright=min(nums1[imedian],nums2[j]);
			}
			res=(maxleft+minright)/2.0;
			return res;
		}
	}
    }
};
