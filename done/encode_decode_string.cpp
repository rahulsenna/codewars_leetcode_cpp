#include <bits/stdc++.h>
using namespace std;


string encode(vector<string> &strs)
{

    ostringstream os;
    for (auto &s : strs)
    {
        os << s << " ";
    }
    return os.str();
}


vector<string> decode(string &str)
{

    istringstream  iss(str);
    vector<string> res;

    while (iss)
    {
        string s;
        iss >> s;
        res.push_back(s);
    }
    res.pop_back();
    return res;
}

int main()
{


    int deb = 3;
    return (0);
}