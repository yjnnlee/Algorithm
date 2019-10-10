#include <iostream>
#include <stack>
#include <string>
using namespace std;

string a;
stack<char> s;
bool chk = false;

void print(stack<char> &s){
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

int main(){
	getline(cin, a);
	for(int i=0;i<a.size();i++){
		if(a[i]=='<'){
			print(s);
			chk = true;
			cout<<a[i];
		}
		else if(a[i]=='>'){
			chk=false;
			cout<<a[i];
		}
		else if(chk){
			cout<<a[i];
		}
		else {
			if(a[i] == ' ') {
				print(s);
				cout<<a[i];
			}
			else{
				s.push(a[i]);
			}
		}
	}
	print(s);
}
