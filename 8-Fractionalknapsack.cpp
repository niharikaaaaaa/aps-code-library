#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
void fractional_knapsack(vector<double> &values , vector<double> &weight , int w, int n)
{
  double leftOver = w;
  double ansValue = 0;
  vector <pair <double, int>> ratio(n, make_pair(0.0, 0));
  for(int i=0;i<n;i++)
  {
    ratio[i] = make_pair(values[i]/weight[i] , i);
  }
  sort(ratio.rbegin(),ratio.rend());
  for(int i=0;i<n && leftOver > 0;i++)
  {
    if(leftOver <= 0)
      break;
    int index = ratio[i].second;
    if(weight[index] <= leftOver)
    {
      ansValue = ansValue + values[index];
      leftOver = leftOver - weight[index];
    }
    else
    {
      ansValue = ansValue + values[index] * (leftOver/weight[index]);
      leftOver = 0;
    }
  }
  cout<<ansValue<<"\n";
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,w;
  cin>>n>>w;
  vector<double>values(n);
  vector<double>weight(n);
  for(int i=0;i<n;i++)
  {
    double temp;
    cin>>temp;
    values[i] = temp;
  }
  for(int i=0;i<n;i++)
  {
    double temp;
    cin>>temp;
    weight[i] = temp;
  }
  fractional_knapsack(values,weight,w,n);
  return 0;
}