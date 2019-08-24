#include <stdio.h>
int n;

int main() {
	scanf("%d", &n);
	for(int i=n;i>=1;i--){
		if(i==1) printf("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n\n");
		else if(i-1 != 1) printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n\n", i, i, i-1);
		else printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottle of beer on the wall.\n\n", i, i, i-1);

	}
	if(n!=1) printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottles of beer on the wall.", n);
	else printf("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, %d bottle of beer on the wall.", n);

}
