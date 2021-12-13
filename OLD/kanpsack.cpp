#include <iostream>
#include <vector>
using namespace std;

using std::vector;
int getMaxValuePerUnit(vector<int>weights , vector<int>values){
    int maxVal=0;
    double max=0;
    for (int i =0 ; i<weights.size();i++){
        if(weights[i]!=0 and (double) values[i]/weights[i]>max ){
            max=(double) values[i]/weights[i];
            maxVal=i;
        }
    }
    // write your code here

    return maxVal;

}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    // write your code here
    for(int i =0 ; i<weights.size();i++){
        if(capacity==0)
            return value;
        int maxVAl=getMaxValuePerUnit(weights,values);
        int choice = min(capacity,weights[maxVAl]);
        value+=choice* (double )values[maxVAl]/weights[maxVAl];
        weights[maxVAl]-=choice;
        capacity-=choice;
    }


    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}