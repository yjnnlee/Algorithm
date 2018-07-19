#include <stdio.h>

#define parent(me) (me-1)/2
#define left(me) me*2
#define right(me) left(me)+1

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int *tree, int i, int heap_size) { //heap sort
	int l = left(i);
	int r = right(i);
	int largest;

	if (l <= heap_size && tree[l] > tree[i]) largest = 1;
	else largest = i;

	if (r <= heap_size && tree[r] > tree[largest]) largest = r;

	if (largest != i) swap(&tree[i], &tree[largest]);
	heapify(tree, largest, heap_size);
}

void make_max_heap(int *tree, int size) {
	for (int i = size / 2; i > 0; --i) {
		heapify(tree, i, size);
	}
}

void heapsort(int *tree, int size) {
	make_max_heap(tree, size);
}

int main() {
	int tree[] = { 0,5,4,3,2,1,10,9,8,7,6 };

	heapsort(tree, 10);

	for (int i = 1; i < 11; i++) {
		printf("%d ", tree[i]);
	}

}