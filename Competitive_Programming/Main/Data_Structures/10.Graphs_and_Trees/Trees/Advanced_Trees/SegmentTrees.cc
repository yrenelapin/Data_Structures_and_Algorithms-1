#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> SegmentTree(4*MAXN);

// v (the index of the current vertex), and the boundaries start and end of the current segment.
// O(n)
void build(vector<int> arr, int v, int start, int end) {

    if (start == end) {
        SegmentTree[v] = arr[start];
    } 
    else {
        int mid = (start + end) / 2;

        // Recursively build the left child
        build(arr, v*2, start, mid);

        // Recursively build the right child
        build(arr, v*2+1, mid+1, end);

        // Sum of both the child
        SegmentTree[v] = SegmentTree[v*2] + SegmentTree[v*2+1];
    }

}

// O(logn)
int sum(int v, int start, int end, int l, int r) {

    // Completely outside the range
    if (l > r) 
        return 0;

    // Completely inside the range
    if (l == start && r == end) {
        return SegmentTree[v];
    }

    // Partially present in the range
    int mid = (start + end) / 2;
    int left_part = sum(v*2, start, mid, l, min(r, mid));
    int right_part = sum(v*2+1, mid+1, end, max(l, mid+1), r);

    return  left_part + right_part ;
}

// O(logn)
void update(int v, int start, int end, int pos, int new_val) {

    if (start == end) {
        SegmentTree[v] = new_val;
    } 
    else {
        int mid = (start + end) / 2;
        
        // Position to be updated is in left subtree.
        if (pos <= mid)
            update(v*2, start, mid, pos, new_val);

        else
            update(v*2+1, mid+1, end, pos, new_val);

        // Recomputing the values similar to `build`
        SegmentTree[v] = SegmentTree[v*2] + SegmentTree[v*2+1];
    }
}


int main(){
    vector<int> arr = {5,8,6,3,2,7,2,6};
    int n = arr.size(); 
    
    // Query
    // Query values range from  0 <= l,r <= n-1
    int l = 0, r = 2;
    
    // Build Segment Tree
    // We need to provide start,end as 0,n-1 always when making sum query or building the Tree & v as 1, The root vertex to start. 
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