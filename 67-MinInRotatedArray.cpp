#include<bits/stdc++.h>

using namespace std;
int main() 
{
  int n;
  cin>>n;
  int nums[n];
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  int i;
  int left = 0, right = 4, minVal = INT_MAX;

  while (left <= right) {
    if (nums[left] < nums[right]) {
      minVal = min(minVal, nums[left]);
      break;
    }
    int mid = left + (right - left) / 2;

    if (nums[left] <= nums[mid]) {
      minVal = min(minVal, nums[left]);
      left = mid + 1;
    } else {
      minVal = min(minVal, nums[mid]);
      right = mid - 1;
    }
  }
  cout << minVal;
  return 0;
}