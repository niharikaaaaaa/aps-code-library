#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1,s2;
  cin>>s1>>s2;
  int len1 = s1.size();
  int len2 = s2.size();
  vector<vector<int>>lcs;
  for(int i=0;i<=len1;i++)
  {
    vector<int>vec;
    for(int j=0;j<=len2;j++)
    {
      if(i==0 || j==0)
        vec.pb(0);
      else 
        vec.pb(-1);
    }
    lcs.pb(vec);
  }
  for(int i=1;i<=len1;i++)
  {
    for(int j=1;j<=len2;j++)
    {
      if(s1[i-1]==s2[j-1])
        lcs[i][j] = lcs[i-1][j-1]+1;
      else
        lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
    }
  }
  cout<<lcs[len1][len2];
  return 0;
}
