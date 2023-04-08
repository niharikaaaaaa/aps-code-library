#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
const int N = 1e5+2;
int rootN;
struct Q
{
  int index , l ,r;
};
Q q[N];

bool compare(Q q1 , Q q2)
{
  if(q1.l/rootN == q2.l/rootN)
    return q1.r > q2.r;
  return q1.l/rootN < q2.l/rootN;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  rootN = sqrtl(n);
  for(int i=0;i<m;i++)
  {
    int l,r;
    cin>>l>>r;
    q[i].l = l;
    q[i].r = r;
    q[i].index = i;
  }
  sort(q , q+m , compare); 
  for(int i=0;i<m;i++)
  {
    cout<<q[i].l<<" "<<q[i].r<<"\n";
  }
  vector<int>ans(m);
  int mo_left = 0 , mo_right = -1 , l ,r;
  int cur_MIN = 1e5+2;
  for(int i=0;i<m;i++)
  {
    l = q[i].l;
    r = q[i].r;

    while(mo_right < r)
    {
      cur_MIN = min(cur_MIN , arr[mo_right]);
      mo_right++;
    }

    while(mo_right > r)
    {
      mo_right--;
    }

    while(mo_left < l)
    {
      mo_left++;
    }

    while(mo_left > l)
    {
      cur_MIN = min(cur_MIN , arr[mo_left]);
      mo_left--;
    }
    cout<<cur_MIN<<"\n";
  }
  return 0;
}