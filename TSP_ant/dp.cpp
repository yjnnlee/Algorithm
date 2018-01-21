#include <cstdio> 
#include <cmath>
#include <Windows.h>
#include <algorithm> 
#define MAX_VALUE 987654321
using namespace std; 
int n; //경로를 저장할 dp 
int cache[3000][65536], dist[3000][3000]; 

//LARGE_INTEGER Frequency;
//LARGE_INTEGER BeginTime;
//LARGE_INTEGER Endtime;

int TSP(int cur, int visited) { 
	//점이 10개라면, 100000000000-1 =011111111111; 
	if (visited == (1 << n)-1) return dist[cur][0]; 
	
	int& ret = cache[cur][visited]; 
	if (ret != 0) return ret; 
	ret = MAX_VALUE; 
	for (int next = 0; next <= n; next++) { 
		if (visited&(1 << next))continue; 
		if (dist[cur][next]==0) continue; 
		ret = min(ret,TSP(next, visited | (1 << next)) + dist[cur][next]); 
	} 
	return ret; 
} 

int main(){ 
	//FILE *f;
	//f = fopen("10.out", "w");
	//QueryPerformanceFrequency(&Frequency);

	scanf("%d", &n); 
	for(int i=0;i<n;i++){ 
		for(int j=0;j<n;j++){ 
			scanf("%d",&dist[i][j]); 
		} 
	} 

	//QueryPerformanceCounter(&BeginTime);
	printf("%d",TSP(0,1)); 

	//QueryPerformanceCounter(&Endtime);
	//int elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	//double duringtime = (double)elapsed / (double)Frequency.QuadPart;
	//printf("\n%f\n\n", duringtime);
	//fprintf(f, "%f\n\n", duringtime);
	//fclose(f);
} 
