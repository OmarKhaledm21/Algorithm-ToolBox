#include <iostream>
#include "vector"
#include "map"

using namespace std;

/**
 *
 * Problem 3 Greedy (Algorithmic Toolbox)
 * Celebration Party.
 * Find minimum number of segments to cover all the points on a line segment.
 * */

int main() {
    //A Child of 3.5 years is a point with coordinate 3.5 in a line.
    int n;
    cin>>n;

    int* x = new int [n];
    for(int i=0; i<n; i++){
        cin>>x[i];
    }

    //sort points (we assume sorted here).

    int segments_size=2;
    int count =1;

    map<int,vector<int>> segments;
    segments[count].push_back(x[0]);

    int leftmost_segment = x[0];
    for(int i=1; i<n; i++){
        if(x[i]-leftmost_segment <= segments_size){
            segments[count].push_back(x[i]);
        }else{
            count++;
            segments[count].push_back(x[i]);
            leftmost_segment = x[i];
        }
    }

    for(int i=1; i<=count; i++){
        cout<<"We have points ";
        for(int j=0; j<segments[i].size(); j++){
            cout<<segments[i][j]<<" ";
        }
        cout<<"at segment "<<i<<"\n";
    }


    return 0;
}
