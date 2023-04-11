#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
int findSecond(vector<int> &nums , int idx , int firstNum , int len)
{
  int second = idx;
  for(int i=idx+1;i<len;i++)
  {
    if(nums[i] > firstNum && nums[i] < nums[second] )
      second = i;
  }
  return second;
}
void nextPermutation(vector<int> &nums , int n)
{
  int flag = 0;
  int i;
  while(flag == 0)
  {
    for(i=n-2;i>=0;i--)
    {
      if(nums[i] < nums[i+1])
      {
        break;
      }
    }
    if(i == -1)
    {
      sort(nums.begin(),nums.end());
      for(int j=0;j<n;j++)
      {
        cout<<nums[j]<<" ";
      }
      break;
    }
    else
    {
      int second = findSecond(nums,i+1,nums[i],n);
      swap(nums[i],nums[second]);
      sort(nums.begin()+i+1,nums.end());
      for(int j=0;j<n;j++)
      {
        cout<<nums[j]<<" ";
      }
      flag = -1;
      break;
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  nextPermutation(nums,n);
  return 0;
}