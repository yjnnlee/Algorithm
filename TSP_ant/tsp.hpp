#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <random>
#include <set>

#define NODE 1000
#define INF 10000000

using namespace std;

struct Edge {
    int Distance = 0;
    double Pheromone = 0;
    double Tau0 = 0;
	Edge() {}
	Edge(int Distance, double Pheromone) : Distance(Distance), Pheromone(Pheromone) {}
};

struct AntStruct {
    vector<int> Index;
    int Length = 0;
};

struct IterationStruct  {
    int Value;
    int Cycle;
};

struct Edge Graph[NODE + 1][NODE + 1];
vector<int> BestPath;
vector<int> TSP;
AntStruct Ant[10001];
bool Visited[NODE + 1] = {0, };
IterationStruct Iteration = {INT32_MAX, 0};

int Ants;
int NumberOfNode;
int From, To, Old_From, Value;

int TSPLength = 0;

double Alpha = 0.5;
double Beta = 5;
double Rho = 0.05;
double Q0 = 0.9;
double Tau = 0;
double Phi = 0.02;

int GetRandomInt();
double GetRandomReal();
int SelectNext(int i);
void Tour(int i);
void Evaporate();