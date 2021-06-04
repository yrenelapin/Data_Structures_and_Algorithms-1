#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define oo 1000000010
const int N = 300010;

int n , m;

int a[N] , b[N] , c[N] , ans[N];

vector< int > g[N];

void solve(){

	scanf("%d%d",&n,&m);

    // Clear to reuse for each test case.
	for(int i = 1 ;i <= n;i++) g[i].clear();

	for(int i = 0 ;i < n;i++)
		scanf("%d",&a[i]);

	for(int i = 0 ;i < n;i++){
		scanf("%d",&b[i]);

        // If colors are needed, we push the color & corresponding indices into g.
		if(b[i] != a[i])
			g[b[i]].push_back(i);
	}


	for(int i = 0; i < m;i++){
		scanf("%d",&c[i]);
	}


	int last = -1;  // Store the index of the last plank such that bx = cm

    // If ax != bx & bx = cm, we prefer that.
	if((int)g[c[m - 1]].size() > 0){

        // Take the last plank
		last = g[c[m - 1]].back();
		g[c[m - 1]].pop_back();
	}
	else{
        // We just check if bx = cm exists atleast.
		for(int i = 0 ;i < n;i++){
			if(b[i] == c[m - 1]){
				last = i;
				break;
			}
		}
	}

    // There is no requirement of c[m-1] or there is no x such that bx = cm
    // which means its impossible to color in the required way.
	if(last == -1){
		puts("NO");
		return;
	}

    // Saving the lastly painted plank's index. 
	ans[m - 1] = last;

    // Greedily painting the planks.  -> O(m). Earlier my code was O(mn). So TLE. Its better to use `maps` in this kind of scenarios.
	for(int i = 0 ;i < m - 1; i++){

        // If the color is not needed, we just paint the plank `last`.
        // Notice that we are not actually painting everytime, 
        // We are just removng the required paintings from the map `g`.

		if((int)g[c[i]].size() == 0){
		 	ans[i] = last;
		}
		else{

            // If color is required, Paint the last indexed plank from all the indices where this color is req.
			ans[i] = g[c[i]].back();

			g[c[i]].pop_back();
		}
	}


	for(int i = 1;i <= n;i++){
        // If any one required index is not yet painted, It means its not possible to paint.
		if((int)g[i].size() > 0){
			puts("NO");
			return;
		}
	}
    
    // Printing the indices.
	puts("YES");
	for(int i = 0 ;i < m;i++){
		if(i) putchar(' ');
		printf("%d",ans[i] + 1);
	}
	puts("");
}



int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}