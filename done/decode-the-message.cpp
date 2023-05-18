#include <bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message)
{
	unordered_map<char, char> map;

	int i = 97;
	for (auto &e: key)
	{
		if (!map[e] && e != ' ')
			map[e] = (char)i++;
	}
    map[' '] = ' ';

	for (auto &e: message)
	{
		e = map[e];
	}
    
    return message;
};

int main()
{
	auto res = decodeMessage("the quick brown fox jumps over the lazy dog", "vkbs bs t suepuv");
	printf("res: %s\n", res.c_str());
	return(0);
}


// Verbose and Slow
#if 0
	
	string decodeMessage(string key, string message)
	{
		unordered_map<char, int> d;
	    auto p_end = remove_if(key.begin(), key.end(),
	                           [&d](auto e) { 
	                           	if (isspace(e)||d[e]>0)
	                           		return (true);
	                            else
	                            {
	                            	d[e]++;
	                                return (false);
	                            }
	                           });
	    // key = {key.begin(), p_end};
	
	    int i = 97;
	    auto p_begin =key.begin();
	    while(p_begin != p_end)
	    {
	        d[*p_begin++] = i++;
	    }
	    d[' '] = ' ';
	    for (auto &e: message)
	    {
	    	e = (char)d[e];
	    }
	    return message;
	}
#endif