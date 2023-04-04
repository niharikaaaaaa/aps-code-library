#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int ansup=0,ansdown=0,ansleft=0,ansright=0,tempup=0,tempdown=0;
int kadaneSum(vector<int> temp)
{
  int n = temp.size();
  int sum = 0 , Max = temp[0];
  int start = 0;
  for(int i=0;i<n;i++)
  {
    if(sum == 0)
    {
      start = i;
    }
    sum += temp[i];
    if(Max < sum)
    {
      Max = sum;
      tempup = start;
      tempdown = i;
    }
    if(sum < 0)
      sum = 0;
  }
  return Max;
}

void printAns(vector<vector<int>>arr , int ansleft, int ansright, int ansup, int ansdown)
{
  for(int i=ansup;i<=ansdown;i++)
  {
    for(int j=ansleft;j<=ansright;j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void solve(vector<vector<int>>arr, int r, int c)
{
  int currSum = 0;
  int MAX = arr[0][0];
  for(int left = 0;left<c;left++)
  {
    vector<int>temp(r,0);
    for(int right =left;right<c;right++)
    {
      for(int row = 0; row<r;row++)
      {
        temp[row] += arr[row][right];
      }
      currSum = kadaneSum(temp);
      if(currSum > MAX)
      {
        MAX = currSum;
        ansleft = left;
        ansright = right;
        ansup = tempup;
        ansdown = tempdown;
      }
    }
  }
  printAns(arr,ansleft,ansright,ansup,ansdown);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int r,c;
  cin>>r>>c;
  vector<vector<int>>arr;
  for(int i=0;i<r;i++)
  {
    vector<int>vec;
    for(int j=0;j<c;j++)
    {
      int var;
      cin>>var;
      vec.pb(var);
    }
    arr.pb(vec);
  }
  solve(arr,r,c);
  return 0;
}