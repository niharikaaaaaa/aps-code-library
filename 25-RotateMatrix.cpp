#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r,c;
  cin>>r>>c;
  vector<vector<int>> matrix(r , vector<int>(c,0));
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cin>>matrix[i][j];
    }
  }
  for(int i=0;i<r;i++)
  {
    for(int j=i+1;j<c;j++)
    {
      swap(matrix[i][j] , matrix[j][i]);
    }
  }
  for(int i=0;i<r;i++)
  {
    reverse(matrix[i].begin(),matrix[i].end());
    for(int j=0;j<c;j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}