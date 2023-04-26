#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;

vector < pair < int, int >> merge(vector < pair < int, int >> & arr) 
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector < pair < int, int >> ans;
  for (int i = 0; i < n; i++) 
  {
    int start = arr[i].first, end = arr[i].second;
    if (!ans.empty()) 
    {
      if (start <= ans.back().second) 
      {
          continue;
      }
    }
    for (int j = i + 1; j < n; j++) 
    {
      if (arr[j].first <= end)
        end = max(end, arr[j].second);
    }
    end = max(end, arr[i].second);
    ans.push_back({start, end});
  }
  return ans;
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  vector<pair <int , int> > arr;
  for(int i=0;i<n;i++)
  {
    int temp1;
    int temp2;
    cin>>temp1>>temp2;
    arr.pb(make_pair(temp1,temp2));
  }
  vector < pair < int, int >> ans = merge(arr);
  for (auto it: ans) 
  {
    cout << it.first << " " << it.second << "\n";
  }
}