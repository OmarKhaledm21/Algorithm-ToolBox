#include <iostream>
#include "vector"
using namespace std;

/**
 *
 * Problem 2 Greedy (Algorithmic Toolbox)
 * Car refueling problem.
 * */
int minRefills(vector<int>x, int destination_index, int tank){
    int numRefills=0,currentStation=0;
    while (currentStation <= destination_index){
        int lastRefillStation = currentStation;
        while ((currentStation <= destination_index) && (x[currentStation + 1] - x[lastRefillStation] <= tank))
        {
            currentStation++;
        }
        if(currentStation == lastRefillStation){
            cout << "Unreachable\n";
            return -1;
        }
        if(currentStation <= destination_index){
            numRefills++;
        }
    }
    return numRefills;
}

int main() {
    int distance, tank, stations_number;
    cin>>distance>>tank>>stations_number;

    vector<int>stations(stations_number+2);

    stations[0]=0;
    for(int i=1; i<stations_number+1; i++){
        cin>>stations[i];
    }
    stations[stations_number+1]=distance;

    cout<<minRefills(stations,stations_number,tank);
    return 0;
}
