#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool comtochar(char a,char b){
	if(a=='('&&b==')'){
		return true;
	}
	else if(a=='{'&&b=='}'){
		return true;
	}
	else if(a=='['&&b==']'){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string s="{[";
	stack<char> store;
	bool flag=false;
	if(s.empty()){
		flag=true;
		cout << "right!" << endl;
	}
	else{
		for(int i=0;i<s.size();i++){
			if(store.empty()||!comtochar(store.top(),s[i])){
				store.push(s[i]);
			}
			else{
				store.pop();
			}
		}
	}
	if(store.empty()){
		flag=true;
		cout << "right!" << endl;
	}
	else{
		cout << "false!" << endl;
	}
	return 0;
}


//这个题目很简单。
