#include <iostream>
#include "vector"
using namespace std;

/**
 *
 * Problem Money Change Greedy (Algorithmic Toolbox)
 * Change input value into coins with denominations of 1, 5 and 10.
 * ex: m = 28  out = 6 (28 = 10 + 10 + 5 +1 +1 +1)
 *
 * 1 <= m <= 1000
 * */

int main() {
    int m;
    cin>>m;

    int change[3] = {0,0,0};

    while(m!=0){
        if(m >= 10){
            change[2]++;
            m-=10;
        }else if(m<10 && m>=5){
            change[1]++;
            m-=5;
        }else{
            change[0]++;
            m--;
        }
    }

    cout<<change[0]+change[1]+change[2];


    return 0;
}
