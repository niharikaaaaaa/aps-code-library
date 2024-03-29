#include<iostream>

using namespace std;

int peakEleOptimal(int arr[], int n) {
  int start = 0, end = n - 1;

  while (start < end) {
    int mid = (start + end) / 2;

    if (mid == 0)
      return arr[0] >= arr[1] ? arr[0] : arr[1];

    if (mid == n - 1)
      return arr[n - 1] >= arr[n - 2] ? arr[n - 1] : arr[n - 2];

    //Cheking whether peak ele is in mid position
    if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
      return arr[mid];

    //If left ele is greater then ignore 2nd half of the elements
    if (arr[mid] < arr[mid - 1])
      end = mid - 1;

    //Else ignore first half of the elements
    else
      start = mid + 1;
  }

  return arr[start];
}

int main() 
{

  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  cout << "Peak Element is " << peakEleOptimal(arr, n);

  return 0;
}