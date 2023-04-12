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
  int low = 0;
  int mid = 0;
  int high = n-1;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  while(mid <= high)
  {
    if(nums[mid] == 0)
    {
      swap(nums[mid] , nums[low]);
      low++;
      mid++;
    }
    else if(nums[mid] == 1)
    {
      mid++;
    }
    else if(nums[mid] == 2)
    {
      swap(nums[mid] , nums[high]);
      high--;
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<nums[i]<<" ";
  }
  return 0;
}