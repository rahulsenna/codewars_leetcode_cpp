// https://leetcode.com/problems/top-k-frequent-elements/submissions/948327664/
#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (auto &n : nums)
    {
        map[n]++;
    }
    vector<pair<int, int>> vmap(map.begin(), map.end());

    sort(vmap.begin(), vmap.end(),
         [](auto &a, auto &b) { return a.second > b.second; });

    vector<int> res;
    for (auto &e : vector<pair<int, int>>(vmap.begin(), vmap.begin() + k))
    {
        res.push_back(e.first);
    }
    return res;
}

int main()
{
	
	return(0);
}