#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main() {
/*	int n=4, m=4;
	vector<int> xarr{1};
	vector<int> yarr{3};*/
 
	int n=7, m=8;
	vector<int> xarr{1,3};
	vector<int> yarr{3,5};
 
	int maxx = xarr[0];
	int maxy = yarr[0];
 
	for(int i=1;i<xarr.size()-1;i++){
		if(maxx<xarr[i+1]-xarr[i]) maxx = xarr[i+1]-xarr[i];
	}
	if(maxx<m-xarr[xarr.size()-1]) maxx = m-xarr[xarr.size()-1];
	for(int i=1;i<yarr.size()-1;i++){
		if(maxy<yarr[i+1]-yarr[i]) maxx = yarr[i+1]-yarr[i];
	}
	if(maxy<m-yarr[yarr.size()-1]) maxy = m-yarr[yarr.size()-1];
 
	cout<<maxx<<" "<<maxy<<" "<<maxx*maxy;
}
