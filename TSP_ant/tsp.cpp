#include "tsp.hpp"

int main()  {
    cin >> NumberOfNode;

    Ants = NumberOfNode * 50;

    for(int i = 1; i <= NumberOfNode; ++i)  {
        for(int j = 1; j <= NumberOfNode; ++j)  {
            cin >> Value;
            Graph[i][j].Distance = Value;
            if(!Value)
                Graph[i][j].Pheromone = -1;

            Graph[i][j].Pheromone = 1.0 / (NumberOfNode * Graph[i][j].Distance);
            Graph[i][j].Tau0 = 1.0 / (NumberOfNode * Graph[i][j].Distance);
        }
    }

    for(int Time = 1; Time <= 1000; ++Time)   {
        for(int i = 1; i <= Ants; ++i)   {
            Ant[i].Index.clear();
            Ant[i].Length = 0;
        }

        for(int i = 1; i <= Ants; ++i)   {
            Tour(i);
            if(Ant[i].Length == -1)
                continue;
            
            if(Iteration.Value > Ant[i].Length)   {
                BestPath.clear();
                for(auto j : Ant[i].Index)  {
                    BestPath.push_back(j);
                }
                
                Alpha = 1;
                Beta = 1;
                Iteration.Value = Ant[i].Length;
                Iteration.Cycle = 1;
            }
            ++Iteration.Cycle;
        }

        for (int i = 1; i <= Ants; ++i) {
			if (Ant[i].Length == -1)
				continue;

			for (int j = 0; j < Ant[i].Index.size() - 1; ++j) {
				From = Ant[i].Index[j];
                To = Ant[i].Index[j + 1];
				Graph[From][To].Pheromone += 1.0 / Ant[i].Length;
                Graph[To][From].Pheromone += 1.0 / Ant[i].Length;
			}
        }

        // if(Iteration.Cycle > 5)   {
        //     Alpha *= pow(0.5, 1);
        //     Rho *= pow(0.5, 1);
        // }

        // if(Iteration.Cycle > 50)   {
        //     Alpha *= pow(0.5, 2);
        //     Rho *= pow(0.5, 2);
        // }
        
        // if(Iteration.Cycle > 100)   {
        //     Alpha *= pow(0.5, 3);
        //     Rho *= pow(0.5, 3);
        // }

        Evaporate();

        for(auto i : BestPath)  {
            cout << i << " ";
        }
        cout << "\n";

        cout << Time << " : " << Iteration.Value << "\n";
    }

    for(auto i : BestPath)  {
        cout << i << " ";
    }

    cout << "\n" << Iteration.Value;
}

void Tour(int i) {
    memset(Visited, 0, sizeof(Visited));
    Old_From = GetRandomInt();
    From = Old_From;
    Visited[From] = true;

    for(int j = 1; j <= NumberOfNode; ++j)    {
        Ant[i].Index.push_back(From);
        To = SelectNext(From);
        if(To == -1)    {
            if(Graph[From][Old_From].Distance && Ant[i].Index.size() == NumberOfNode)    {
                Ant[i].Length += Graph[From][Old_From].Distance;
                Ant[i].Index.push_back(Old_From);
                return ;
            }

            Ant[i].Index.clear();
            Ant[i].Length = -1;
            return ;
        }
        Visited[To] = true;
        Graph[From][To].Pheromone = (1 - Phi) * Graph[From][To].Pheromone + Phi * Graph[From][To].Tau0;
        Ant[i].Length += Graph[From][To].Distance;
        From = To;
    }

    return ;
}

int SelectNext(int From)   {
    int Low, High, Middle;
    double sum = 0, Q = 0;
    vector<pair<int, double>> Probability;
    pair<int, double> MaxArg = make_pair(0, 0);

    Q = GetRandomReal();

    if(Q < Q0)  {
        for(int To = 1; To <= NumberOfNode; ++To)   {
            if(Visited[To] || !Graph[From][To].Distance)
                continue;
            
            Tau = (double)pow(Graph[From][To].Pheromone, Alpha) * (double)pow(1.0 / Graph[From][To].Distance, Beta);
            if(MaxArg.second < Tau)
                MaxArg = make_pair(To, Tau);
        }
        if(!MaxArg.first)
            return -1;
    }
    else    {
        for(int To = 1; To <= NumberOfNode; ++To)   {
            if(Visited[To] || !Graph[From][To].Distance)
                continue;

            sum += (double)pow(Graph[From][To].Pheromone, Alpha) * (double)pow(1.0 / Graph[From][To].Distance, Beta);
        }

        for(int To = 1; To <= NumberOfNode; ++To)  {
            if(Visited[To] || !Graph[From][To].Distance)
                continue;

            Probability.push_back(make_pair(To, (double)pow(Graph[From][To].Pheromone, Alpha) * (double)pow(1.0 / Graph[From][To].Distance, Beta) / sum));
        }

        if(Probability.empty()) {
            return -1;
        }

        sort(Probability.begin(), Probability.end(), [](const pair<int, double> &left, const pair<int, double> &right) {
            return left.second > right.second;
        });

        Low = 0, High = Probability.size() - 1;

        Q = GetRandomReal();

        while(Low < High)   {
            Middle = (Low + High) / 2;
            if(Probability[Middle].second <= Q)
                High = Middle;
            else
                Low = Middle + 1;
        }
        MaxArg = Probability[Low];
    }

    return MaxArg.first;
}

void Evaporate()    {
    for (int i = 0; i < BestPath.size() - 1; ++i) {
        From = BestPath[i];
        To = BestPath[i + 1];

        Graph[From][To].Pheromone = (1 - Rho) * Graph[From][To].Pheromone + 1.0 / Graph[From][To].Distance;
    }
}

double GetRandomReal()    {
    random_device rn;
    mt19937_64 rnd(rn());
 
    uniform_real_distribution<double> range(0, 1);

    return range(rnd);
}

int GetRandomInt()    {
    random_device rn;
    mt19937_64 rnd(rn());
 
    uniform_int_distribution<int> range(1, NumberOfNode);

    return range(rnd);
}