// Question :- https://www.codechef.com/START84C/problems/MAX1XOR
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
  for(int i=0;i<t;i++)
  {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int temp1 = 1;
    int temp2 = 0;
    int count1 = 0 , count2 = 0;
    for(int i=0;i<n;i++)
    {
      if(temp1 == 1)
        count1++;
      if(temp2 == 1)
        count2++;
      temp1 = temp1 ^ (s[i]-48);
      temp2 = temp2 ^ (s[i]-48);
    }
    cout<<max(count1 , count2)<<"\n";
  }
  return 0;
}