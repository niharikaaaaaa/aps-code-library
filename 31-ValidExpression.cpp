// Question :- https://www.codechef.com/START78C/problems/EVALMAS
#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,x;
	    cin>>n>>x;
	    if(n>=x && x>0)
	    {
	        for(int i=0;i<x-1;i++)
	        {
	            cout<<"+";
	        }
	        int m = n-(x-1);
	        for(int i=0;i<m;i++)
	        {
	            cout<<"*";
	        }
	        cout<<"\n";
	    }
	    else if(n == (x-1))
	    {
	        for(int i=0;i<n;i++)
	        {
	            cout<<"+";
	        }
	        cout<<"\n";
	    }
	    else if(n > (-1*x) && x<=0)
	    {
	        x = x*(-1);
	        int m = n-(x+1);
	        for(int i=0;i<m;i++)
	        {
	            cout<<"*";
	        }
	        for(int i=0;i<x+1;i++)
	        {
	            cout<<"-";
	        }
	        cout<<"\n";
	    }
	    else
	    {
	        cout<<"-1\n";
	    }
	}
	return 0;
}