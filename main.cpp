// #include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
{
	
    int idx = 0;
    if (ruleKey == "color")
    {
        idx = 1;
    }
    if (ruleKey == "name")
    {
        idx = 2;
    }

    int res = 0;
    for(auto &item: items)
    {
        if (item[idx] == ruleValue)
        {
            res++
        }
    }
    
    return res;
}
int main()
{
    vector<vector<string>> items = {{"phone","blue","pixel"}, {"computer","silver","phone"}, {"phone","gold","iphone"}};
    auto res = countMatches(items, "type", "phone");
    printf("res: %d\n", res);
    return(0);
}
