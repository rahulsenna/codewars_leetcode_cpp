// https://leetcode.com/problems/product-of-array-except-self/
#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
	int count = std::count(nums.begin(), nums.end(), 0);
	if (count>1)
	{
		return vector<int>(nums.size(), 0);
	}

	if (count==1)
	{
		vector<int> r(nums.size(), 0);
		int it = find(nums.begin(), nums.end(), 0) - nums.begin();
		nums.erase(std::remove(nums.begin(), nums.end(), 0), nums.end());
		auto sum = accumulate(nums.begin(), nums.end(), 1, [](auto a, auto b) {return a*b;});
		r[it] = sum;
		return r;
	}
	
	auto sum = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());




	vector<int> res;
	for(auto &i: nums)
	{
		res.push_back(sum/i);
	}

	return res;
}

int main()
{
	vector<int> nums = {1,2,3,4};
	auto res = productExceptSelf(nums);
	return(0);
}