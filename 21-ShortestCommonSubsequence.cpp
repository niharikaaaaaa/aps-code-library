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
  int s1l = s1.size()+1;
  int s2l = s2.size()+1;
  vector<vector<int>>scs(s1l , vector<int>(s2l,0));
  for(int i=0;i<s1l;i++)
  {
    for(int j=0;j<s2l;j++)
    {
      if(i==0)
        scs[i][j] = j;
      else if(j==0)
        scs[i][j] = i;
      else if(s1[i-1] == s2[j-1])
        scs[i][j] = scs[i-1][j-1] + 1;
      else
        scs[i][j] = min(scs[i][j-1] , scs[i-1][j])+1;
    }
  }
  // for(int i=0;i<scs.size();i++)
  // {
  //   for(int j=0;j<scs[0].size();j++)
  //   {
  //     cout<<scs[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  cout<<scs[s1l-1][s2l-1]<<"\n";
  return 0;
}