#include <string>
#include <vector>
using namespace std;

int yo[7] = { 0, 1, 2, 3, 4, 5, 6 }, month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int day, k;
vector<int> answer;
vector<int> result;

vector<int> solution(int day, int k) {
	for (int i = 0; i<12; i++) {
		result.push_back(yo[(day+((k + month[i]) % 7 - 1))%7]);
		day = result.back();
//		printf("day: %d\n", day);
		if (day == 5 || day == 6) answer.push_back(1);
		else answer.push_back(0);
	}
	return answer;
}

int main() {
	scanf("%d%d", &day, &k);

	if (k == 1) result.push_back(day);
	else {
		result.push_back(yo[(k - 1) % 7 - 1]); //첫번째 달을 미리 해둠
		day = result.back();
	}

	if(day == 5 || day == 6) answer.push_back(1);
	else answer.push_back(0);

	solution(day, k);
	for (int i = 0; i < 12; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	for (int i = 0; i < 12; i++) {
		printf("%d ", result[i]);
	}
}