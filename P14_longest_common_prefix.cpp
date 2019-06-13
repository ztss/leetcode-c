class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        else if(strs.size()==1)
        {
            return strs[0];
        }
        int minsize=100;
        for(auto &s:strs)
	    {
		    if(s.size()<minsize)
		    {
			    minsize=s.size();
		    }
	    }
        int sz=strs.size();
	    string res="";
	    for(int i=0;i<minsize;i++)
	    {
		    bool flag=true;
		    for(int j=0;j<sz-1;j++)
		    {
			    if(strs[j+1][i]!=strs[j][i])
			    {
				    flag=false;
				    break;
			    }
		    }
		    if(flag==true)
		    {
			    res+=strs[0][i];
		    }
		    else
		    {
			    break;
		    }
	    }
        return res;
    }
};
