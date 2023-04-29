#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
int n = a.size();
vector<vector<int>> ans;
for(int i = 0;i<n;i++)
{
if(ni[1]<a[i][0]) //if interval to be merged is less than interval in array
{
ans.push_back(ni);
for(;i<n;i++)
{
ans.push_back(a[i]);
}
return ans;
}
else if(a[i][1] < ni[0]) //If current interval is before newInterval
ans.push_back(a[i]);
else
{
ni[0] = min(ni[0],a[i][0]);
ni[1] = max(ni[1],a[i][1]);
}
}
ans.push_back(ni);
return ans;
}

int main(){
vector<vector<int>>intervals;
intervals.push_back({1,3});
intervals.push_back({6,9});
vector<int>newInterval;
newInterval.push_back(2);
newInterval.push_back(5);
intervals = insert(intervals,newInterval);
for(int i=0;i<intervals.size();i++){
cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<" ";
}
return 0;
}