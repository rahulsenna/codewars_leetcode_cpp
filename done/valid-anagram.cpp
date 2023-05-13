// https://leetcode.com/problems/valid-anagram/submissions/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	return(0);
}

bool isAnagram(string s, string t)
{
    // slow Runtime 16 ms
    /*
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
    */

    if (s.size() != t.size())
        return false;


    /*
    // Runtime 11 ms
    unordered_map<char,int> smap;
    unordered_map<char,int> tmap;

    for (int i=0; i<s.size(); ++i)
    {
        smap[s[i]]++;
        tmap[t[i]]++;
    }

    return smap == tmap;
    */

    // Runtime 10 ms
    int map[26] = {0};
    for (int i=0; i<s.size(); ++i)
    {
        map[s[i] - 'a']++;
        map[t[i] - 'a']--;
    }

    for (auto &c: map)
    {
        if (c != 0)
            return false;
    }
    return true;
}
