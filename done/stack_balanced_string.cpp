// #include <bits/stdc++.h>
#include <string>
#include <stack>
#include <cstdint>
#include <algorithm>
using namespace std;

int balancedStringSplit(string s)
{
	int res = 0;
    stack<char> st;
	for(auto &c: s)
	{
        if (st.empty() || st.top() == c)
        {
            st.push(c);
        } 
		else
		{
			st.pop();
			if (st.empty())
			{
                res++;
            }
		}
	}
	return(res);
}

int main()
{
	auto res = balancedStringSplit("RLRRRLLRLL");
	printf("res: %d", res);
	return(0);
}
