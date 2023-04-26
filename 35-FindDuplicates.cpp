#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & nums) 
{
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) 
  {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
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
  cout<<findDuplicate(arr) << endl;
}