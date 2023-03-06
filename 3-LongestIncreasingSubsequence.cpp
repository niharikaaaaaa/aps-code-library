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
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    v.pb(temp);
  }
  vector<int>lis(n,1);
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<i;j++)
    {
      if(v[i]>v[j] && lis[j]+1 > lis[i])
      {
        lis[i] = lis[j]+1;
      }
    }
  }
  cout<<*max_element(lis.begin(),lis.end())<<"\n";
  return 0;
}
