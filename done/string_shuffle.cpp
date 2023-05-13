#include <bits/stdc++.h>
using namespace std;

string restoreString(string s, vector<int>& indices) {
    int idx;
    for (int i=0; i<s.length(); ++i)
    {
        if(indices[i] == i)
        {
            continue;
        }
        idx = indices[i];
        swap(s[i], s[idx]);
        swap(indices[i], indices[idx]);
    }
    return s;
}
int main()
{
    vector<int> in = {4,5,6,7,0,2,1,3};
    auto res = restoreString("codeleet", in);
    printf("%s\n", res.c_str());
    return(0);
}
