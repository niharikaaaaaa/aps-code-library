//Question :- https://www.codechef.com/START80C/problems/SUMPERM
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
	    if(n%2!=0)
	        cout<<"-1\n";
	    else
	    {
	        vector<int>vecOdd,vecEven;
	        for(int i=1;i<=n;i++)
	        {
	            if(i%2==0)
	                vecEven.pb(i);
	            else
	                vecOdd.pb(i);
	        }
	        for(int i=0;i<vecOdd.size();i++)
	        {
	            cout<<vecEven[i]<<" "<<vecOdd[i]<<" ";
	        }
	        cout<<"\n";
	    }
	}
  return 0;
}