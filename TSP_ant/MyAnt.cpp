#include <stdio.h>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

const double PHEROMONE_RATE = 40; //페로몬 amout of pheromone
const double ALPHA = 1; //페로몬 중요?
const double BETA = 1; //거리 중요?
const double EVAPORATION_RATE = 0.2; //증발률
const double DETERMINISTIC_RATE = 0.7; //페로몬이 많은 길을 선택할 확률

int n;
bool visited[3000];

struct map {
	double pheromone;
	int distance;
	map() {}
	map(double pheromone, int route) : pheromone(pheromone), distance(route) {}
};
struct map Graph[3000][3000];

int GetRandomDouble() {
	random_device re;
	//mt19937_64 rnd(re());
	default_random_engine rnd{ re() };
	uniform_real_distribution<double> ran(0.0, 1.0);

	return ran(rnd);
}

double GetEveryRouteSum(int From) { //갈 수 있는 모든 경우의 합
	//x->y사이 길의 페로몬 양^a * 거리^b의 합
	double sum = 0;
	//From = now(현재위치)
	
	for (int i = 1; i <= n; i++) {
		if (visited[i] || Graph[From][i].distance != 0) { 
			continue; 
		}
		sum += (double)pow(Graph[From][i].pheromone, ALPHA) * (double)pow(Graph[From][i].distance, BETA);
	}	
	return sum;
}

int PheroRoute(int Now, int To) {
	//x->y사이 길의 페로몬 양^a * 거리^b
	//From = now(현재위치)

	int route;	
	route = (double)pow(Graph[Now][To].pheromone, ALPHA) * (double)pow(1.0 / Graph[Now][To].distance, BETA);
	
	return route;
}

int RouteSelect(int Now) { //개미가 갈 길 선택
	//개미 k가 x에서 y로 가는 확률
	memset(visited, 0, sizeof(visited));
	int Q = GetRandomDouble(), route; //Q: 0~1사이 무작위 파라미터

	if (Q < DETERMINISTIC_RATE) { //페르몬 제일 많은 길 선택 q0(고정)>=q(랜덤)
		int MaxPheromoneRoute = -1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] || Graph[Now][i].distance != 0) {
				continue;
			}

			if (MaxPheromoneRoute < PheroRoute(Now, i)) {
				MaxPheromoneRoute = PheroRoute(Now, i);
			}
		}
		return MaxPheromoneRoute;
	}
	else { //크면 랜덤 q<q0
		double EveryRouteSum = GetEveryRouteSum(Now);

		for (int i = 1; i <= n; i++) {
			if (visited[i] || Graph[Now][i].distance != 0) {
				continue;
			}
			route = PheroRoute(Now, i) / EveryRouteSum;

		}
	}
	return route;
}

int PheromoneUpdate() {
	for (int i = 1; i < n; i++) {
		(1-EVAPORATION_RATE) * Graph[
	}
}

int main() {
	scanf("%d", &n);
	int tmp = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			Graph[i][j].distance = tmp;
			
			if (tmp == 0) {
				Graph[i][j].pheromone = 0;
			}
			
			Graph[i][j].pheromone = PHEROMONE_RATE;
		}
	}

	for(int i=0;i<)
}

/*_{iu}(t)^α = 노드 i와 u를 연결하는 엣지의 페로몬
_{iu}(t)^β = 휴리스틱 함수, 일반적으로 노드 i와 u간 거리의 역수를 취함.
P^{i}_{j}(t) = 수식 (2)
,  = 페로몬과 거리 간의 중요도를 조절하는 변수. 모두 양수임.
q0 = [0, 1]사이의 난수 값.
q = 노드 선택 방법을 결정하는 변수. [0, 1]사이의 값.
*/
