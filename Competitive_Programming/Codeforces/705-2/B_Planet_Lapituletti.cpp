#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

map<int,int> mirror = {  {0,0}, {1,1}, {2,5}, {5,2}, {8,8}, {3,-1}, {4,-1}, {6,-1}, {7,-1}, {9,-1} };

pair<int,int> get_reflection(string s){

        // Tokenizing a String based on ":"
        stringstream ss(s);
        string first, second;
        getline(ss, s, ':');
        first = s;
        getline(ss, s, ':');
        second = s;

        string curr_h = first;
        string curr_m = second;

        int curr_h_int = stoi(curr_h);
        int curr_m_int = stoi(curr_m);

        string d = to_string( mirror[ curr_h[0] - '0'   ] );
        string c = to_string( mirror[ curr_h[1] - '0'   ] );
        string b = to_string( mirror[ curr_m[0] - '0'   ] );
        string a = to_string( mirror[ curr_m[1] - '0'   ] );
        
        if (a == "-1" or b == "-1" or c == "-1" or d == "-1"){
            return make_pair(-1,-1);
        }

        string ref_h = a + b;
        int ref_h_int = stoi(ref_h);

        string ref_m = c + d;
        int ref_m_int = stoi(ref_m);

        return make_pair(ref_h_int, ref_m_int);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t ;
    cin >> t;
    while(t--){
        
        int h, m;
        string s;
        cin >> h >> m >> s;
        
        int curr_h_int = stoi(s.substr(0, 2));
        int curr_m_int = stoi(s.substr(3, 2));
        int count_h = 0 ;
        int flag = 0;
        for (int H = curr_h_int ; count_h < h ; ( H = (H + 1)% h ),  count_h++ ){
                
                int M;
                if (H == curr_h_int){
                        M = curr_m_int;
                }
                else{
                    M = 0;
                }
                
                for ( ; M < m  ; M++ ){

                            string M_str ;
                            if (M < 10){
                                M_str =  "0" + to_string(M);}
                            else{ 
                                M_str  = to_string(M);}

                            string H_str ;
                            if (H < 10){
                                H_str =  "0" + to_string(H);}
                            else{ 
                                H_str  = to_string(H);}

                        string colon = ":";                        
                        string str = H_str + colon + M_str;    
                        auto result = get_reflection(str);

                        int hours_fin = result.first;
                        int minutes_fin = result.second;
                        
                        bool valid_h = (hours_fin >= 0 && hours_fin < h);
                        bool valid_m = (minutes_fin >= 0 && minutes_fin < m);

                    if (hours_fin != -1 and minutes_fin != -1 and valid_h and valid_m){
                            flag = 1;
                            
                            string M_str ;
                            if (M < 10){
                                M_str =  "0" + to_string(M);}
                            else{ 
                                M_str  = to_string(M);}

                            string H_str ;
                            if (H < 10){
                                H_str =  "0" + to_string(H);}
                            else{ 
                                H_str  = to_string(H);}

                            cout << H_str << ":" << M_str << endl;
                            break; }

                }

                if (flag == 1){
                    break;
                }
        }
        
        if (flag == 0){
            for (int m_rem = 0 ; m_rem < curr_m_int ; m_rem++){
                
                        string M_str ;
                        if (m_rem < 10){
                            M_str =  "0" + to_string(m_rem);}
                        else{ 
                            M_str  = to_string(m_rem);}

                        string H_str ;
                        if (curr_h_int < 10){
                            H_str =  "0" + to_string(curr_h_int);}
                        else{ 
                            H_str  = to_string(curr_h_int);}

                        string colon = ":";                        
                        string str = H_str + colon + M_str;   

                
                auto result = get_reflection(str);
        
                int hours_fin = result.first;
                int minutes_fin = result.second;
                
                bool valid_h = (hours_fin >= 0 && hours_fin < h);
                bool valid_m = (minutes_fin >= 0 && minutes_fin < m);

                if (hours_fin != -1 and minutes_fin != -1 and valid_h and valid_m){
                    flag = 1;

                      string M_str ;
                        if (m_rem < 10){
                            M_str =  "0" + to_string(m_rem);}
                        else{ 
                            M_str  = to_string(m_rem);}

                        string H_str ;
                        if (curr_h_int < 10){
                            H_str =  "0" + to_string(curr_h_int);}
                        else{ 
                            H_str  = to_string(curr_h_int);}

                    cout << H_str << ":" << M_str << endl;
                    break; }

                }
        }
    }
    return 0;
}