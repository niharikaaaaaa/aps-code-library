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
  vector<int>prices(n);
  for(int i=0;i<n;i++)
  {
    cin>>prices[i];
  }
  int mini = prices[0];
  int profit = 0;
  int cost = 0;
  for(int i=1;i<n;i++)
  {
      cost = prices[i] - mini;
      mini = min(mini , prices[i]);
      profit = max(profit , cost);
  }
  cout<<profit;
  return 0;
}