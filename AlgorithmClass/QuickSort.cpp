#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100], n, pivot, right, left;

void quicksort(int a[], int left, int right) {
	int l = left;
	int r = right;

	pivot = a[(left + right) / 2];
	/*랜덤 피벗 Deterministic selection이라고 함
	원래 최악은 O(n^2)이고 평균은 O(n)인데 Deterministic은 최악이 O(n)임
	대충 뭔내용이냐면 일단 배열을 5개씩 쪼갬(가장 빠르게 정렬되는 수임. 증명되었음)
	잘린 p1, p2, p3, p4, p5에서 또 중간값을 정함. 3번째 값이 됨->중간값의 중간값
	그래서 중간값의 중간값으로 비교하면 무조건 25%~75% 확률로 맞아떨어짐
	응.. 잘 모르겠으면 찾아보기
	*/
	if (left < right) {

	}

	while (left <= right) {
		while (a[left] < pivot) left++;
		while (a[right] > pivot) right--;
		//2, 9, 4, 18, 5, 1, 7, 8, 15, 12
		if (left <= right) {
			if (left != right) {
				swap(a[left], a[right]);
			}
			left++, right--;
		}
	}
	if (left < r) quicksort(a, left, r);
	if (l < right) quicksort(a, l, right);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quicksort(a, a[0], a[n - 1]);

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}