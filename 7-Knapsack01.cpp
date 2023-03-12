#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N,W;
  cin>>N>>W;
  vector<int>weight,values;
  for(int i=0;i<N;i++)
  {
    int temp;
    cin>>temp;
    values.pb(temp);
  }
  for(int i=0;i<N;i++)
  {
    int temp;
    cin>>temp;
    weight.pb(temp);
  }
  // map<int,int>mp;
  // for(int i=0;i<N;i++)
  // {
  //   mp.insert(make_pair{weight[i],values[i]});
  // }
  vector<vector<int>> k(N+1 , vector<int>(W+1));
  for(int i=0;i<N+1;i++)
  {
    for(int j=0;j<W+1;j++)
    {
      if(i==0 || j==0)
      {
        k[i][j] = 0;
      }
      else if(weight[i-1] > j)
      {
        k[i][j] = k[i-1][j];
      }
      else
      {
        k[i][j] = max(k[i-1][j] , values[i-1]+k[i-1][j-weight[i-1]]);
      }
    }
  }
  cout<<k[N][W]<<"\n";
  return 0;
}