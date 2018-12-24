class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int m=x;
        long res=0;
        while(m)
	    {
		    int pop=m%10;
		    res=res*10+pop;
		    m=m/10;
	    }
	    if(res==x)
	    {
		    return true;
	    }
	    else
	    {
		    return false;
	    }
    }
};

//这个题目很简单，但是也有优化的空间，就是while循环可以只做一半，然后比较x和res的值的
//大小就可以了
