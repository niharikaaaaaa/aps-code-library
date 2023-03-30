#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
bool RightToLeft = false;
bool LeftToRight = true;

int fact(int n)
{
  int res = 1;
  for(int i=1;i<=n;i++)
  {
    res = res * i;
  }
  return res;
}

int getMobile(vector<int> &a , vector<bool> &dir , int n)
{
  int mobile = 0;
  int mobilePrev = 0;

  for(int i=0;i<n;i++)
  {
    if(dir[i] == RightToLeft && i != 0)
    {
      if(a[i] > a[i-1] && a[i] > mobilePrev)
      {
        mobile = a[i];
        mobilePrev = mobile;
      }
    }
    if(dir[i] == LeftToRight && i != n-1)
    {
      if(a[i] > a[i+1] && a[i] > mobilePrev)
      {
        mobile = a[i];
        mobilePrev = mobile;
      }
    }
  }
  if(mobile == 0 && mobilePrev == 0)
    return 0;
  else
    return mobile;
}

int searchArr(vector<int> &a , int n , int mobile)
{
  for(int i=0;i<n;i++)
  {
    if(a[i] == mobile)
      return i;
  }
}

void printNextPerm(vector<int> &a , vector<bool> &dir , int n)
{
  int mobile = getMobile(a,dir,n);
  int pos = searchArr(a,n,mobile);

  if(dir[pos] == RightToLeft)
  {
    swap(a[pos] , a[pos-1]);
    swap(dir[pos] , dir[pos-1]);
  }
  else if(dir[pos] == LeftToRight)
  {
    swap(a[pos] , a[pos+1]);
    swap(dir[pos] , dir[pos+1]);
  }

  for(int i=0;i<n;i++)
  {
    if(a[i] > mobile)
    {
      if(dir[i] == LeftToRight)
        dir[i] = RightToLeft;
      else if(dir[i] == RightToLeft)
        dir[i] = LeftToRight;
    }
  }

  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<"\n";
}

void printPerm(int n)
{
  vector<int>a(n);
  vector<bool>dir(n);

  for(int i=0;i<n;i++)
  {
    a[i] = i+1;
    cout<<a[i]<<" ";
    dir[i] = RightToLeft;
  }
  cout<<"\n";

  for(int i=1;i<fact(n);i++)
  {
    printNextPerm(a,dir,n);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  printPerm(n);
  return 0;
}