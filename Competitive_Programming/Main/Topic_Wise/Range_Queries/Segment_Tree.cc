#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n;

// The Segment tree.
vector<int> t(4*MAXN);

// v (the index of the current vertex), and the boundaries tl and tr of the current segment.
void build(vector<int> arr, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(arr, v*2, tl, tm);
        build(arr, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main(){
    vector<int> arr = {5,8,6,3,2,7,2,6};
    int n = arr.size(); 
    
    // Query
    // Query values range from  0 <= l,r <= n-1
    int l = 0, r = 2;
    
    // Build Segment Tree
    // We need to provide t1,tr as 0,n-1 always when making sum query or building the Tree & v as 1, The root vertex to start. 
    build(arr,1,0,n-1);
    
    // Sum Query
    cout << sum(1,0,n-1, l, r) << endl;
    
    // Update Query
    // Pos can range between 0 to n-1.
    int pos = 1; int new_val = 6;
    update(1,0,n-1, pos, new_val);
    
    // Sum Query
    cout << sum(1,0,n-1, l, r) << endl;
}


// Ref : https://cp-algorithms.com/data_structures/segment_tree.html