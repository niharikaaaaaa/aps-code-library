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
  vector<int>v;
  int target;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    v.pb(temp);
  }
  cin>>target;
  vector<vector<int>>ss;
  for(int i=0;i<=n;i++)
  {
    vector<int>vec;
    for(int j=0;j<=target;j++)
    {
      if(i==0 && j>=1)
        vec.pb(0);
      else if(i>=0 && j==0)
        vec.pb(1);
      else
        vec.pb(-1);
    }
    ss.pb(vec);
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=target;j++)
    {
      if(ss[i-1][j]==1)
        ss[i][j] = 1;
      else if(v[i-1]>j)
        ss[i][j] = 0;
      else
        ss[i][j] = ss[i-1][j-v[i-1]];
    }
  }
  if(ss[n][target])
    cout<<"Subset equal to target exists\n";
  else
    cout<<"Subset equal to target does not exists\n";
  return 0;
}
