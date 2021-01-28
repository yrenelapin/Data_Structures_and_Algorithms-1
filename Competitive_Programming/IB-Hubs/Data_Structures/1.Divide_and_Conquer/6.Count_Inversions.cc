/*
Given an array A of integers, write a program to find the number of inversions in A. 
Two elements A[i] and A[j] form a inversion if A[i] > A[j] and i < j.
*/

#include<iostream>
using namespace std;

typedef long long int ll;

ll merge(ll *arr,ll *temp,ll l,ll mid,ll r)

{

  ll i=l;        // Initial index of first subarray
  ll j=mid+1;    // Initial index of second subarray
  ll k=l;       // Initial index of merged subarray
  long long int count=0;
  
  while( i<=mid && j<=r)

  {

    if(arr[i]<=arr[j]){

      temp[k++]=arr[i++];

    }

    else{

      temp[k++]=arr[j++];

      count+=mid-i+1;

    }

  }

  while(i<=mid){

    temp[k++]=arr[i++];

  }

  while(j<=r){

    temp[k++]=arr[j++];

  }

  for(ll x=l;x<=r;x++)

  arr[x]=temp[x];

  return count;

}





ll sort(ll *arr,ll *temp,ll l,ll r)

{

  long long int count=0;

  if(l<r)

  {

    ll mid=(l+r)/2;

    count+=sort(arr,temp,l,mid);

    count+=sort(arr,temp,mid+1,r);

    count+=merge(arr,temp,l,mid,r);

  }

  return count;

}



void fun(ll *arr,ll n)
{
  ll temp[n];
  cout<<sort(arr,temp,0,n-1);

}

int main()

{
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++)
  cin>>arr[i];
  fun(arr,n);
}