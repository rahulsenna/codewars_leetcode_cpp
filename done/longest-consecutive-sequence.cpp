#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int res         = 1;
    int consecutive = 1;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i]==nums[i + 1]) continue;
        if (nums[i] == nums[i + 1] - 1)
        {
            consecutive++;
            if (res < consecutive)
            {
                res = consecutive;
            }
        } else
        {
            consecutive = 1;
        }
    }
    return res;
}
int main()
{

    vector<int> in  = {1,2,0,1};
    auto        res = longestConsecutive(in);

    return (0);
}