#include <iostream>
#include "string"
#include "vector"
using namespace std;

/**
 *
 * Problem 1 Greedy (Algorithmic Toolbox)
 * What is the largest number that consists of the given n digits?
 * */

void printResult(vector<int>numbers){
    for(int i=0; i<numbers.size(); i++){
        cout<<numbers[i];
    }
}

//1- Find max
//2- Append it to new number
//3- Remove it of the old list
//4- Repeat until list is empty
void greedyStrategy(vector<int>numbers){
    for(int k=0; k<numbers.size(); k++) {
        for (int i = k+1; i < numbers.size(); i++) {
            int temp = numbers[k];
            if (numbers[i] > temp) {
                numbers[k] = numbers[i];
                numbers[i] = temp;
            }
            printResult(numbers);
            cout<<"\n";
        }
    }

    printResult(numbers);
}

int main() {
    int size;
    cin>>size;
    vector<int> numbers(size);
    for(int i=0; i<numbers.size(); i++){
        cin>>numbers[i];
    }

    greedyStrategy(numbers);

    return 0;
}
