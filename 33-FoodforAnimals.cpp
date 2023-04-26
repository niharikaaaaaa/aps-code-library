//Question :- https://codeforces.com/contest/1675/problem/A
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
        ll a,b,c,x,y,ref,temp1,temp2;
        cin>>a>>b>>c>>x>>y;
        if(x<a && y<b)
        {
            cout<<"YES\n";
        }
        else if (x<a && y>b)
        {
            ref = y-b;
            if(ref<=c)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else if (x>a && y<b)
        {
            ref = x-a;
            if(ref<=c)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
        else
        {
            temp1 = x-a;
            temp2 = y-b;
            ref = temp1+temp2;
            if(ref<=c)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}