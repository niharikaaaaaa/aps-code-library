#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string src,dest;
  cin>>src>>dest;
  int sl = src.size()+1;
  int dl = dest.size()+1;
  vector<vector<int>>ed(dl , vector<int>(sl,0));
  for(int i=0;i<dl;i++)
  {
    for(int j=0;j<sl;j++)
    {
      if(i==0)
        ed[i][j] = j;
      else if(j==0)
        ed[i][j] = i;
      else
      {
        if(src[j-1] == dest[i-1])
        {
          ed[i][j] = ed[i-1][j-1];
        }
        else
        {
          ed[i][j] = min({ed[i-1][j] , ed[i][j-1] , ed[i-1][j-1]})+1;
        }
      }
    }
  }
  cout<<ed[dl-1][sl-1]<<"\n";
  // for(int i=0;i<ed.size();i++)
  // {
  //   for(int j=0;j<ed[0].size();j++)
  //   {
  //     cout<<ed[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  return 0;
}