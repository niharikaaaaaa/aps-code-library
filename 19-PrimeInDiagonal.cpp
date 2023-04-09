#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vector<int>>nums(n , vector<int>(m,0));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin>>nums[i][j];
    }
  }
  vector<int>vec;
  for(int i=0;i<nums.size();i++)
  {
      for(int j=0;j<nums[0].size();j++)
      {
          if(i==j)
              vec.push_back(nums[i][j]);
      }
      vec.push_back(nums[i][nums.size()-i-1]);
  }
  int ans = 0,MAX = 0;
  for(int i=0;i<vec.size();i++)
  {
    //cout<<vec[i]<<" ";
    bool prime=true;
    if(vec[i] == 1)
    {
      MAX = 0;
    }
    else if(vec[i] != 1)
    {
      for(int j=2;j*j<=vec[i];j++)
      {
        if(vec[i]%j==0)
        {
          prime=false;
          break;
        }
      }
      if(prime)
      {
        ans = vec[i];
        MAX = max(ans,MAX);
      }  
    }
  }
  cout<<MAX<<"\n";
  return 0;
}