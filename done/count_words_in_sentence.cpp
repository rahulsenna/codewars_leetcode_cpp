#include <bits/stdc++.h>
using namespace std;
int mostWordsFound(vector<string> &sentences)
{
    int res = 0;
    for (auto &sentence : sentences)
    {
        istringstream iss(sentence);

        int sz = (int) distance(istream_iterator<string>(iss), istream_iterator<string>());
        if (res < sz)
        {
            res = sz;
        }
    }
    return res;
}
int main (int argc, char *argv[])
{
    vector<string> in = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};
    auto res = mostWordsFound(in);
    printf("res: %d\n", res);
    return 0;
}
