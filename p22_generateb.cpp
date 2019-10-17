class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        bracket(res,"",0,0,n);
        return res;
    }

    void bracket(vector<string>& res,string temp,int open ,int close,int max){
	if(temp.size()==2*max){
		cout << temp << endl;
		res.push_back(temp);
		return;
	}
	if(open<max){
		bracket(res,temp+'(',open+1,close,max);
	}
	if(open>close){
		bracket(res,temp+')',open,close+1,max);
	}
}
};

//这道题需要生成所有带有n对括号的序列。并且要求括号是合法的。首先我们要知道，在括号的生
//成过程中，左括号的数量一定得大于右括号得数量。如果在加括号得过程中右括号多于左括号那么
//这个序列一定是不合法的，并且左括号如果还要再想加入左括号，那么数量一定得小于n。而如果
//想加入右括号，那么左括号一定得多与右括号。但生成得序列长度等于2n的时候，由于之前已经
//验证过了合法性，那么直接加入最后的结果中去即可。
