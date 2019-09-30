#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
using namespace std;



int main(){
	vector<string> a={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	vector<string> res;
	string digits="23";
	if(digits.size()==0){
		cout << "empty size" << endl;
	}
	res.push_back("");//这里需要注意，应该先往res里push一个空字符串。
	cout << res.size() << endl;
	for(int i=0;i<digits.size();i++){
		int index=digits[i]-'2';
		int length=res.size();
		for(int i=0;i<length;i++){
			for(auto m:a[index]){
				res.push_back(res[i]+m);
			}
		}
		res.erase(res.begin(),res.begin()+length);//删除前面的结果
	}
	cout << res.size() << endl;
	return 0;
}

//
