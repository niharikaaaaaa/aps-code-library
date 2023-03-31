#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
void update(int fenwick[], int n, int i, int add)
{
  i++;
  while(i < n)
  {
    fenwick[i] += add;
    i += (i & (-i));
  }
}
int sum(int i , int fenTree[])
{
  int s = 0;
  while(i > 0)
  {
    s += fenTree[i];
    i -= (i & (-i));
  }
  return s;
}
int rangeSum(int l , int r, int fenTree[])
{
  return sum(r+1,fenTree) - sum(l,fenTree);
}
int *constructFen(vector<int>& v, int n)
{
  int *fenwick = new int[n+1];
  for(int i=0;i<=n;i++)
  {
    fenwick[i] = 0;
  }
  for(int i=0;i<n;i++)
  {
    update(fenwick, n , i , v[i]);
  }
  return fenwick;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    v[i] = temp;
  }
  int *fenTree = constructFen(v,n);
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int l,r;
    cin>>l>>r;
    int ans = rangeSum(l,r,fenTree);
    cout<<ans<<"\n";
  }
  return 0;
}