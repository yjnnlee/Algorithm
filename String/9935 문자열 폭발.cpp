#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

char a[1000005];
//vector<char> newa;
char newa[1000005], n[40];
int idx = 0;

int main(){
	scanf("%s%s", a, n);
	int len = strlen(a);
	int len2 = strlen(n);

	for (int i = 0; i < len; i++){
		//newa.push_back(a[i]);
		
		newa[idx] = a[i];
		idx++;
		if (a[i] == n[len2 - 1] && i >= len2 - 1){ //폭발이랑 같은 끝자리가 등장하면
			/*printf("i: %d, idx: %d\n", i,idx);
			for (int i = 0; i < idx; i++){
				printf("%c", newa[i]);
			}
			printf("\n");*/
			//printf(">%d\n", newa.size());
			//int idx = newa.size() - 1;
			bool f = true;
			int k = idx - 1;
			for (int j = len2 - 1; j >= 0; j--){ //전으로 돌아가면서 확인
				//printf("->%c %c, %d\n", newa[idx], n[j], j);
				if (newa[k] != n[j]){
					f = false;
					break;
				}
				k--;
			}

			if (f){
				/*if (!newa.empty()){
					for (int q = 0; q <= len2; q++){
						printf("back : %c\n", newa.back());					
						newa.pop_back();
					}
				}*/
				idx -= len2;
			}
			/*else{
				newa.push_back(a[i]);
			}*/

			/*for (int i = 0; i < newa.size(); i++){
				printf("%c", newa[i]);
				}
				printf("\n");
				*/
		}

	}

	/*if (newa.empty()){
		printf("FRULA");
	}
	else {
		for (int i = 0; i < newa.size(); i++){
			printf("%c", newa[i]);
		}
	}*/
	if (idx == 0){
		printf("FRULA");
	}
	else {
		for (int i = 0; i < idx; i++){
			printf("%c", newa[i]);
		}
	}


	/*while (scanf("%[^\n]s", a) > 0){
	printf("%s", a);
	}*/
	/*
	C4C4C4C
	C4C
	*/
}

//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//char a[1000005];
//vector<char> newa;
//char n[40];
//int idx = 0;
//
//int main(){
//	scanf("%s%s", a, n);
//	int len = strlen(a);
//	int len2 = strlen(n);
//
//	for (int i = 0; i < len; i++){
//		newa.push_back(a[i]);
//		//newa[idx++] = a[i];
//		if (a[i] == n[len2 - 1] && i >= len2 - 1){ //폭발이랑 같은 끝자리가 등장하면
//			//printf(">%d\n", newa.size());
//			int idx = newa.size() - 1;
//			bool f = true;
//
//			for (int j = len2 - 1; j >= 0; j--){ //전으로 돌아가면서 확인
//				//printf("->%c %c\n", newa[idx], n[j]);
//				if (newa[idx] != n[j]){
//					f = false;
//					break;
//				}
//				if (idx < 0) continue;
//				else idx--;
//			}
//
//			if (f){
//				if (!newa.empty()){
//					for (int q = 0; q <= len2; q++){
//						printf("back : %c\n", newa.back());
//						newa.pop_back();
//					}
//				}
//				//idx -= len2;
//			}
//
//			/*for (int i = 0; i < newa.size(); i++){
//			printf("%c", newa[i]);
//			}
//			printf("\n");
//			*/
//		}
//
//	}
//
//	if (newa.empty()){
//		printf("FRULA");
//	}
//	else {
//		for (int i = 0; i < newa.size(); i++){
//			printf("%c", newa[i]);
//		}
//	}
//}

//#include <stdio.h>
//char a[1001];
//
//int main(){
//	scanf("%s", a);
//	for (int i = 0; a[i]; i++){
//		printf("%d %c\n", i, a[i]);
//	}
//}
