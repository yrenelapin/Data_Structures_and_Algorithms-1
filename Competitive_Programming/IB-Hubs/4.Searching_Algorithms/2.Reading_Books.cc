/*
Helping a Friend Read Books

Your friend likes to read lots of books. In a library, there are N piles of books, and each pile contains pile[i] number of books. Your friend can decide K, the number of books to read in a day.

On any day, if a pile has less than K books, he reads all of them and won't read any more books that day. Similarly, if a pile has more than K books, he reads only K books of it and the rest of them are left for another day.

He wants to read all books in D days. So, write a program to find minimum K so that your friend will finish reading all books by the end of D days.

Note: Your friend can read books from only one pile on any given day. i.e., he cannot share books of two piles on the same day.

Input
First line contains a single integer N.
Second line contains N space separated integers, where the ith integer represents the number of books on the ith pile.
Third line contains a single integer D.

Output
Print a single integer representing minimum K.
*/

#include <iostream>
using namespace std ;
int main(){
    int N;
    scanf("%d",&N);
    
    int A[N];
    int sum = 0 ; 
    for (int i =0 ; i< N ; i++){
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    
    int D;
    scanf("%d",&D);

    
    int k = (sum/D);
    int req_d;
    while (true){
        if ( k*D >= sum ) {
            req_d = 0;
            for (int i = 0; i<N ; i++){
                if ( A[i] <= k) req_d++;
                else {
                     if (A[i]%k ==0)  { req_d+= (A[i]/k);}
                     else { req_d+= ((A[i]/k)+1) ; }
                }
            }
            
        }
        if (req_d == D) { printf("%d",k); return 0 ; }
        k++ ;
    }
}