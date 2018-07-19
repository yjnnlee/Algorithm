//#include <stdio.h>
//char arr[20], arr2[20];
//char from, to, chr;
//int length = 0;
//
//int strlen(char *str) {
//	int i = 0;
//	for (int i = 0; i < 20; i++) {
//		if (arr[i] == NULL) {
//			return length;
//		}
//		else length++;
//	}
//}
//
//void strcpy(char *from, char *to) {
//	for (int i = 0; i < length; i++) {
//		if (arr[i] == *from) {
//			for (int j = arr[i]; j == *to; j++) {
//				printf("%c" ,arr[j]);
//			}
//		}
//	}
//}
//
//void strcmp(char *str1, char *str2) {
//	int chk = 0;
//	for (int i = 0; i < length; i++) {
//		if (arr[i] != arr2[i]) {
//			printf("문자열이 다름");
//			break;
//		}
//		else chk++;
//	}
//	if (chk == length) {
//		printf("문자열이 같음");
//	}
//}
//
//void strchr(char *str, char chr) {
//	for (int i = 0; i < length; i++) {
//		if (str[i] == chr) {
//			printf("%d번째에서 등장", i);
//			break;
//		}
//	}
//}
//
//int main() {
//	scanf("%s", arr);
//	printf("문자열의 길이 구하기: %d\n", strlen(arr));
//
//	printf("from에서 to로 문자열 전체 복사: ");
//	scanf("%c%c", from, to);
//	strcpy(*from, to);
//
//	printf("str1과 str2가 완벽히 같은 문자열인지 검사");
//	scanf("%s", arr2);
//	strcmp(arr, arr2);
//
//	printf("str안에 chr이 몇번째에서 등장하는지 위치 반환");
//	scanf("s", chr);
//	strchr(arr, chr);
//}