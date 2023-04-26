//Question :- https://codeforces.com/contest/1820/problem/A
#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int j=0;j<t;j++)
  {
    string s;
    cin>>s;
    int count = 0;
    int n = s.size();
    if(s[0] == '^' && n == 1)
    {
      count++;
    }
    if(s[0] == '_')
    {
      //cout<<"^"<<s[0];
      count++;
    }
    // else
    // {
    //   cout<<s[0];
    // }
    for(int i=0;i<n;i++)
    {
      if(s[i] == '_' && s[i+1] == '_')
      {
        //cout<<s[i]<<"^";
        count++;
      }
      // else
      // {
      //   cout<<s[i];
      // }
    }
    if(s[n-1] == '_')
    {
      //cout<<s[n-1]<<"^";
      count++;
    }
    // else
    // {
    //   cout<<s[n-1];
    // }
    cout<<" "<<count<<"\n";
  }
  return 0;
}