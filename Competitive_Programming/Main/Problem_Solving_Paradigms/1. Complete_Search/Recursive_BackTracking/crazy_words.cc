#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
STATUS : Trying to optimise the earlier submission
*/

bool is_vowel(char ch){
    return (0x208222 >> (ch & 0x1f)) & 1;
}

bool is_cons(char ch){
    return ( not(is_vowel(ch)) ) ;
}

bool is_crazy(string &s){

    if (count(s.begin(), s.end(), '_') >= 1 ) return false;
    bool seq_check = false, vow_check = false;
    bool z_check = (count(s.begin(), s.end(), 'z') >= 1); 
    
    int flag_vow = 1;
    for (int i = 0; i<= s.size()-3; i++){
        bool temp = true;
        for (int j = i; j < i+3; j++){
            if (  is_vowel(s[j]) ){
                temp &= true;
            }
            else {temp &= false;}
        }
        
        // There are 3 sequential vowels.
        if (temp == true){
            flag_vow = 0;
            break;
        }
    }
    if (flag_vow==1){vow_check = true;}
    
    int flag_cons = 1;
    for (int i = 0; i <= s.size()-3; i++){
        bool temp = true;
        for (int j = i; j < i+3; j++){
            if ( is_cons(s[j]) ){
                temp &= true;
            }
            else {temp &= false;}
        }
        
        // There are 3 sequential vowels.
        if (temp == true){
            flag_cons = 0;
            break;
        }
    }
    if (flag_cons==1) {seq_check = true;}
    
    return (seq_check and vow_check and z_check);

}
// set<string> result;
int counter = 0;

// int counter = 0;
void build_crazy_words(string &s , vector<char> &v, int place_where_modified){

    if (is_crazy(s)){

        cout << s << " ";
        cout << s[place_where_modified-1] << endl;
        if ( s[place_where_modified-1] == 'z' ) {counter++;}
        else if ( s[place_where_modified-1]=='a') { counter += 5; }
        else {counter += 21 ;}
        // result.insert(s);

    }

    
    else{
        
        {if ( s[place_where_modified-1] == 'z' ) {counter++;}
        else if ( s[place_where_modified-1]=='a') { counter += 5; }
        else {counter += 21 ;}
        }
        for (int i = place_where_modified ; i < s.size(); i++){

            if (s[i] == '_'){
            
                for ( int  j = 0 ; j < 3 ; j++ ){
                    
                    if ( ( is_cons(s[i-1]) && is_cons(s[i+1]) && is_cons(v[j]) ) or 
                      ( is_vowel(s[i-1]) && is_vowel(s[i+1]) && is_vowel(v[j]) ) ){
                          continue;
                      }
                      
                    else { 
                        s[i] = v[j] ;
                        build_crazy_words(s, v, i+1);
                        s[i] = '_';}
                        
                }
            }
        }
        
        
        
    }
}

int main(){
    string s; cin >> s;
    vector<char> v;
    v.push_back('a');    // Vowel        --> 5
    v.push_back('z');    // Compulsory   --> 1
    v.push_back('b');    // Consonanat   --> 21
    build_crazy_words(s, v, 0);
    cout << counter;
}