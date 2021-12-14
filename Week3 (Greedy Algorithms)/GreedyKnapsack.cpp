#include <iostream>
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

/**
 *
 * Problem 4 Greedy (Algorithmic Toolbox) (Fractional Knapsack).
 * Maximum Value of loot Example
 * A thief finds much more loot than his bag can fit. Help him to find the most valuable combination
 * of items assuming that any fraction of a loot item can be put into his bag.
 * */

int main() {
    cout<<"Enter number of items and capacity of bag: "<<endl;
    int n,w;
    cin>>n>>w;

    /*** pair<value, weight> */
    vector<pair<int,int>> items(n);
    vector<double> itemValPerUnit(n);
    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second;
        itemValPerUnit[i]= ( ((double)items[i].first) / items[i].second );
    }

    double sum=0.0;
    int currentWeight=0;
    double max=0.0;
    while (currentWeight < w){
        int index=0;
        for(int i=0; i<n; i++){
            if(max<itemValPerUnit[i]){
                max = itemValPerUnit[i];
                index=i;
            }
        }

        int stolenItemWeight = min(items[index].second, w - currentWeight);
        currentWeight+=stolenItemWeight;
        sum+= stolenItemWeight * itemValPerUnit[index];
    }

    cout<<sum<<endl;
    return 0;
}
