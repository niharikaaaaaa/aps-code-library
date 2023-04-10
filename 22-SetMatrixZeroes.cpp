#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
  int r = matrix.size();
  int c = matrix[0].size();
  int ref = 1;
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      if(matrix[i][j] == 0)
      {
        matrix[i][0] = 0;
        if(j!=0)
          matrix[0][j] = 0;
        else
          ref = 0;
      }
    }
  }
  for(int i=1;i<r;i++)
  {
    for(int j=1;j<c;j++)
    {
      if(matrix[i][j] != 0)
      {
        if(matrix[i][0] == 0 || matrix[0][j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
  if(matrix[0][0] == 0)
  {
      for(int j=0;j<c;j++)
      {
          matrix[0][j] = 0;
      }
  }
  if(ref == 0)
  {
      for(int i=0;i<r;i++)
      {
          matrix[i][0] = 0;
      }
  }
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<"\n";
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r, vector<int>(c,0));
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        cin>>matrix[i][j];
      }
    }
    setZeros(matrix);
  }
  return 0;
}