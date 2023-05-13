// https://leetcode.com/problems/defanging-an-ip-address/submissions/
#include <bits/stdc++.h>
using namespace std;

string defangIPaddr(string address)
{
    return regex_replace(address, regex("\\."), "[.]");
}

int main()
{
	
	auto res = defangIPaddr("255.100.50.0");
	return(0);
}