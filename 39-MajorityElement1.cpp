#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;

int majorityElement(vector<int> v) 
{
    int n = v.size();
    int cnt = 0; 
    int el; 

    for (int i = 0; i < n; i++) 
    {
        if (cnt == 0) 
        {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) 
            cnt++;
        else 
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++) 
    {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) 
        return el;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans = majorityElement(arr);
    cout << ans << endl;
    return 0;
}