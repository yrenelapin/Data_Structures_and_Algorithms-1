/*Given an array A of integers of N length, elements (A[i], A[j]) becomes a special pair if i < j and A[i] > 2*A[j].
Write an efficient program to find the number of special pairs present in A. If there are no special pairs, return -1.*/

#include <iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;


// We get Sorted Arrays.
ll merge_them(ll* a,ll* temp,int l,int mid,int h)

{


  ll i=l;        // Initial index of first subarray
  ll j=mid+1;    // Initial index of second subarray
  ll k=l;       // Initial index of merged subarray

 ll count=0;

  while(i<=mid && j<=h)

  {

  if(a[i]<=2*a[j])

    i++;

  else

    {j++;

    count+=mid-i+1;}

  }

  i=l,j=mid+1;

  while(i<=mid && j<=h)

  {

  if(a[i]<=a[j])

    temp[k++]=a[i++];

  else

  {temp[k++]=a[j++];}

  }

  while(i<=mid)

  temp[k++]=a[i++];

   

  while(j<=h)

  temp[k++]=a[j++];

   

  for(int i=l;i<=h;i++)

  a[i]=temp[i];

  return count;

   

}

ll mergesort(ll* a,ll * temp,int l,int h)

{

  int mid,count=0;

  if(h>l){

    mid=(l+h)/2;

    count+=mergesort(a,temp,l,mid);

    count+=mergesort(a,temp,mid+1,h);

    count+=merge_them(a,temp,l,mid,h);

  }

  return count;

}




int main() {

    int n;

    cin>>n;

    ll arr[n];

   for(int i=0;i<n;i++)

    cin>>arr[i];

   ll temp[n];

   ll count = mergesort(arr,temp,0,n-1);

  if (count) cout<<count;

  else {
      cout << -1;
  }

}