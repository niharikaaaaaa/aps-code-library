#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    v[i]=temp;
  }
  int sum = 0 , MAX = v[0];
  for(int i=0;i<n;i++)
  {
    sum += v[i];
    MAX = max(sum,MAX);
    if(sum < 0)
      sum = 0;
  }
  cout<<MAX<<"\n";
  return 0;
}