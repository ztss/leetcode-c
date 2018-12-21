class Solution {
public:
    int myAtoi(string str) {
        int index=0;
        int length=str.size();
        bool zeroflag=false;
        while(str[index]==' '||str[index]=='0')
	    {
            if(str[index]=='0')
		    {
			    zeroflag=true;
		    }
            if(zeroflag&&str[index]==' ')
            {
                return 0;
            }
		    index++;
	    }
        if((str[index]>'9'||str[index]<'0'||index==length)&&str[index]!='-'&&str[index]!='+')
	    {
		    //cout<<"this not a legal string"<<endl;
		    //cout<<0<<endl;
		    return 0;
	    }
        bool flag=true;
        if(str[index]=='-')
	    {
            if(zeroflag)
		    {
			    //cout<<"0"<<endl;
			    return 0;
		    }
		    flag=false;
		    index++;
	    }
        if(str[index]=='+'&&flag==true)
        {
            if(zeroflag)
		    {
			    //cout<<"0"<<endl;
			    return 0;
		    }
            index++;
        }
        int res=0;
        for(int i=index;i<length&&str[i]<='9'&&str[i]>='0';i++)
	    {
		    int pop=str[i]-'0';
            if(flag==false)
            {
                pop='0'-str[i];
            }
		    if(res>(INT_MAX/10)||(res==(INT_MAX/10)&&pop>7))
		    {
			    //cout<<"the number is over the upperlimit"<<endl;
			    //cout<<INT_MAX<<endl;
			    return INT_MAX;
		    }
		    if(res<(INT_MIN/10)||(res==(INT_MIN/10)&&pop<-8))
		    {
			    //cout<<"the number if over the lowerlimit"<<endl;
			    //cout<<INT_MIN<<endl;
			    return INT_MIN;
		    }
		    res=res*10+pop;
	    }
        return res;
    }
};

//这个题目要注意各种边界条件，然后就是注意int的范围。具体可以参考reverse_integer.cpp
