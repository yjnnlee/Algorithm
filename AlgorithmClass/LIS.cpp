#include <stdio.h>
int arr[100000];
int temp[100000];
int t_last = 0;
int first = 0, last;
int N;

int upgraded_b_search(int target, int range_f, int range_l) {
	if (range_f == range_l) return range_l;
	else if (range_f + 1 == range_l) {
		return range_l;
	}
	int middle = (first + last + 1) / 2;
	if (temp[middle] == target) return middle;
	else if (temp[middle]>target) {
		range_l = middle;
		last = middle - 1;
	}
	else {
		range_f = middle;
		first = middle + 1;
	}
	return upgraded_b_search(target, range_f, range_l);
}

void find_Lis_length() {
	for (int i = 1; i<N; ++i) {
		first = 0;
		last = t_last;
		if (arr[i]>temp[t_last]) {
			temp[++t_last] = arr[i];
			//printf("okay\n");
		}
		else {
			//printf("b_search : ");
			int d = upgraded_b_search(arr[i], 0, t_last);
			//printf("upgraded_b_search(arr[i], 0, t_last) : %d\n",d);
			temp[d] = arr[i];
		}
		//for(int i=0; i<t_last; ++i){
		// printf("%d ", temp[i]);
		//}
		//printf("\n");
	}
	return;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i<N; ++i) {
		scanf("%d", &arr[i]);
	}
	temp[0] = arr[0];
	find_Lis_length();
	printf("\n");
	for (int i = 0; i<t_last + 1; ++i) {
		printf("%d ", temp[i]);
	}
	printf("\n");
	printf("length : %d", t_last + 1);//index starts from zero. so +1.

}

