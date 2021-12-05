#include <iostream>
using namespace std;
#include <vector>
int Change(int coins[], int n , int money){
    vector<int> ways(money+1,INT8_MAX);
    ways[0]=0;
    for(int i = 1 ; i<=money;i++){
        for(int c=0;c<n;c++){
            if(i>=coins[c]){
                int res = ways[i-coins[c]];
                if (res != INT8_MAX && res + 1 < ways[i])
                    ways[i] = res + 1;
            }
        }
    }
    return ways[money];
}
int main() {
int m;
cin>>m;
int coins[3]={1,3,4};
cout<<Change(coins,3,m)<<endl;


    return 0;
}