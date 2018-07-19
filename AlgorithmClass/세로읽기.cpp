#include <stdio.h>
#include <string.h>
char a[5][16];
int len, tmp;

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%s", &a[i]);
		tmp = strlen(a[i]);
		if (tmp > len) {
			len = tmp;
		}
	}	

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[j][i] >= 'A' || a[j][i] <= 'Z' || a[j][i] >= 'a' || a[j][i] <= 'z' || a[j][i] >= 0 || a[j][i] <= 9){
				if (a[j][i] != NULL) {
					printf("%c", a[j][i]);
				}
			}
		}
	}
}

//#include <stdio.h>
//#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
//#define LCHILD(me)   (2*me +1)
//#define RCHILD(me)  (LCHILD(me)+1)
//#define PARENT(me)  ((me-1)/2)
//
//void ViewArr(int *arr, int n);
//void HeapSort(int *base, size_t n);
//int main(void)
//{
//	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
//	ViewArr(arr, 10);
//	HeapSort(arr, 10);
//	ViewArr(arr, 10);
//	return 0;
//}
//void HeapSort(int *base, size_t n)
//{
//	for (size_t i = 1; i<n; i++)
//	{
//		int j = i;
//		while (j>0)//루트가 아니면 반복
//		{
//			int pa = PARENT(j);//부모 인덱스를 구하기                 
//			if (base[j]< base[pa]) //부모보다 크면
//			{
//				SWAP(base[j], base[pa]);//부모와 교환                
//				ViewArr(base, n);
//				j = pa;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	SWAP(base[0], base[n - 1]);//루트와 마지막 자손 교환    
//	ViewArr(base, n);
//	n--;
//	size_t me;
//	size_t lc;
//	size_t rc;
//	while (n>1)//반복: n이 1보다 크면 
//	{
//		me = 0;
//		while (1)
//		{
//			lc = LCHILD(me);
//			rc = RCHILD(me);
//			if (lc >= n)//자식이 없음
//			{
//				break;
//			}
//			if (rc == n)//왼쪽 자식만 있음
//			{
//				if (base[me]< base[lc])
//				{
//					SWAP(base[me], base[lc]);
//					ViewArr(base, n);
//				}
//				break;
//			}
//			int bc = lc;
//			if (base[lc]< base[rc])
//			{
//				bc = rc;
//			}
//			if (base[bc]> base[me])
//			{
//				SWAP(base[bc], base[me]);
//				ViewArr(base, n);
//				me = bc;
//			}
//			else
//			{
//				break;
//			}
//		}
//		SWAP(base[0], base[n - 1]);//루트와 마지막 자손 교환        
//		ViewArr(base, n);
//		n--;
//	}
//}
//void ViewArr(int *arr, int n)
//{
//	int i = 0;
//	for (i = 0; i<n; i++)
//	{
//		printf("%2d ", arr[i]);
//	}
//	printf("\n");
//}
