#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;

bool wPreferM1OverM(vector<vector<int>> &prefer, int w, int m, int m1, int n)
{
  for(int i=0;i<n;i++)
  {
    if(prefer[w][i] == m1)
      return true;
    if(prefer[w][i] == m)
      return false;
  }
}
void stableMarriage(vector<vector<int>> &prefer, int n)
{
    vector<int>wMatch(n+1,0);
     vector<int>mFree(n+1,0);
     int freeCount = n;
     while(freeCount > 0)
     {
        int m;
        for(m=1;m<=n;m++)
        {
          if(mFree[m]==0)
            break;
        }
        for(int i=0;i<n && (mFree[m] == 0);i++)
        {
          int w = prefer[m+n-1][i];
          if(wMatch[w] == 0)
          {
            wMatch[w] = m;
            mFree[m] = 1;
            freeCount--;
          }
          else 
          {
            int m1 = wMatch[w];
            if(wPreferM1OverM(prefer,w-1,m,m1,n) == false)
            {
                wMatch[w] = m;
                mFree[m] = 1;
                mFree[m1] = 0;
            }
          }
        }
      }
    vector<int> men(n+1,0);
    for(int i=1;i<=n;i++)
    {
      men[wMatch[i]] = i;
    }
    for(int i=1;i<=n;i++)
    {
      cout<<i<<" "<<men[i]<<endl;
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
     int n,temp;
     cin>>n;
     vector<vector<int>> prefer((2*n),vector<int>(n));
    
    for(int i=0;i<(2*n);i++)
    {
        cin>>temp;
        for(int j=0;j<n;j++)
        {
             cin>>temp;
             prefer[i][j] = temp;
        }
    }
    stableMarriage(prefer,n); 
  }
  return 0;
}