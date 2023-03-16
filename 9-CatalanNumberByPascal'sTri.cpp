#include<bits/stdc++.h>
#define pb push_back
#define int long long int
using namespace std;
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  if(n==0 || n==1)
  {
    cout<<"1\n";
  }
  else if(n==2)
  {
    cout<<"2\n";
  }
  else
  {
    int m = (2*n) - 2;
    m= m+1;
    vector<vector<int>>PascalTri;
    PascalTri.push_back({1});
    PascalTri.push_back({1,1});
    for(int i=2;i<m;i++)
    {
      vector<int>vec(i+1);
      vec[0] = 1;
      for(int j=1;j<i+1;j++)
      {
        vec[j] = PascalTri[i-1][j] + PascalTri[i-1][j-1];
      }
      vec[i] = 1;
      PascalTri.push_back(vec);
    }
    // TO Print Pascal Triangle
    // for(int i=0;i<m;i++)
    // {
    //   for(int j=0;j<i+1;j++)
    //   {
    //     cout<<PascalTri[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    m = m-1;
    int ans = PascalTri[m][m/2] - PascalTri[m][(m/2)-2];
    cout<<ans<<"\n";
  }
  return 0;
}