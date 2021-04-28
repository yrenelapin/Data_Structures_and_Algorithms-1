#include <iostream>
#include <vector>
using namespace std;

int number_of_possibilities = 0;


/*
This algorithm is called Recursive BackTracking and It is similar to DFS.
*/
void Dice_Helper(int number_of_dice, int required_sum, int current_sum, vector<int> &chosen){

    if (number_of_dice==0) {
        if (required_sum == current_sum){
                number_of_possibilities++;
                for (int j : chosen) {
                    cout << j << " "; 
                }
                cout << endl;
        }
    }

    else{
        if ( (current_sum + 1*number_of_dice  <= required_sum) && (current_sum + 6*number_of_dice  >= required_sum)){

            for (int k = 1; k <= 6; k++){
                chosen.push_back(k);
                Dice_Helper(number_of_dice-1, required_sum, current_sum + k, chosen);
                chosen.pop_back();
            }

        }
    }

};


void possible_combinations(int number_of_dice, int required_sum, vector<int> &chosen ){
        // 0 is the current sum. 
        Dice_Helper(number_of_dice, required_sum, 0, chosen);
}

int main(){
    int number_of_dice = 3;
    int required_sum = 7;
    vector<int> chosen;
    possible_combinations(number_of_dice, required_sum, chosen);
    cout << "Total number of possibilities :- " << number_of_possibilities ;
}