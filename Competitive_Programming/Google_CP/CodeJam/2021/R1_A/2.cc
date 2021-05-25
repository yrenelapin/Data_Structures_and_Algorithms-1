#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "  ,  " << #y << "=" << y << endl
typedef unsigned long long ll;
const ll mod = 1e9 + 7;



ll score = 0;

void combinationUtil(  vector<ll> arr, ll data[],
					ll start, ll end,
					ll index, ll r)
{
	// Current combination is ready
	// to be prlled, prll it
	if (index == r)
	{   
        vector<ll> copy = arr;

        ll sum_data = 0;
        ll product_data = 1;
		for (ll j = 0; j < r; j++)
			{   // cout << data[j] << " ";

               sum_data += data[j];
               product_data *= data[j];
                
                auto itr = find (copy.begin(), copy.end(), data[j]);
                copy.erase(itr);
            }
        

        // deb(copy.size());
        ll sum_copy = 0;
        ll product_copy = 1;
        for (ll i = 0; i < copy.size();  i++){
                sum_copy += copy[i];
                product_copy *= copy[i];
        }

        // deb2(sum_copy, product_copy);

        if (sum_copy == product_data) {
            score = max(score, sum_copy);
        }

        if (product_copy == sum_data){
            score = max(product_copy, score);
        }

		return;
	}


	for (ll i = start; i <= end &&
		end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, r);
	}
}




void solve() {

  ll m; cin >> m;
  vector<ll> num;
  for (ll i = 0; i <m ; i++){
      ll a, b; 
      cin >> a >> b;
      while(b--){
          num.push_back(a);
      }
  }

    ll n =  num.size();
    
    for (ll R = 1;  R <= n/2 ; R++ ){

    
        const ll r = R ;
        
        ll data[r];

        vector<ll> num_copy = num;

        // deb(r); 
        combinationUtil(num_copy, data, 0, n-1, 0, r);
       

    }

    cout << score << endl;
    score = 0;
 


}

int main() {
    fastIO;
    ll t = 1;
    cin >> t; // Comment if only 1 testcase.
    
    for(ll a = 1; a <= t; a++ ){

    cout << "Case #" << a << ": ";
      
    solve();


    }

    return 0;
}