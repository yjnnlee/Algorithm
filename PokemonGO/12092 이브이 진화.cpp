#include <iostream>
#include <string>
using namespace std;
int n;
int main(){
	string str[3]={"Vaporeon", "Jolteon", "Flareon"};
    cin>>n;
    cout<<str[++n%3]; //++n은 시간끌기용 n+1도 가능
}
