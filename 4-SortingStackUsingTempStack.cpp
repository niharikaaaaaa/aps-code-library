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
  stack<int>s;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    s.push(temp);
  }
  stack<int>tempStack;
  while(!s.empty())
  {
    
    int var = s.top();
    s.pop();
    while(!tempStack.empty() && tempStack.top() > var)
    {
      s.push(tempStack.top());
      tempStack.pop();
    }
    tempStack.push(var);
  }
  for(int i=0;i<n;i++)
  {
    cout<<tempStack.top()<<" ";
    tempStack.pop();
  }
  return 0;
}