#include <iostream>
#include <vector>
using namespace std;

int number_of_possibilities = 0;


/*
This algorithm is called Recursive BackTracking and It is similar to DFS.
*/
void Dice_Helper(int number_of_dice, vector<int> &chosen){

    if (number_of_dice==0) {
        number_of_possibilities++;
        for (int j : chosen) {
            cout << j << " "; 
        }
        cout << endl;
    }

    else{
        for (int k = 1; k <= 6; k++){
            chosen.push_back(k);
            Dice_Helper(number_of_dice-1, chosen);
            chosen.pop_back();
        }
    }

};


void possible_combinations(int number_of_dice, vector<int> &chosen){
        Dice_Helper(number_of_dice, chosen);
}

int main(){
    int number_of_dice = 3;
    vector<int> chosen;
    possible_combinations(number_of_dice, chosen);
    cout << "Total number of possibilities :- " << number_of_possibilities ;
}