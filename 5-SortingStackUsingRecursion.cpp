#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
void insertstack(stack<int> &s,int key)
{
  if(s.empty() || key > s.top())
  {
    s.push(key);
    return;
  }
  int temp = s.top();
  s.pop();
  insertstack(s,key);
  s.push(temp);
}
void sortstack(stack<int> &s)
{
  if(s.empty())
    return;
  int top = s.top();
  s.pop();
  sortstack(s);
  insertstack(s,top);
}
void PrintSortedStack(stack<int> &s)
{
  while(!s.empty())
  {
    cout<<s.top()<<" ";
    s.pop();
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  stack<int>s;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    s.push(temp);
  }
  sortstack(s);
  PrintSortedStack(s);
  return 0;
}