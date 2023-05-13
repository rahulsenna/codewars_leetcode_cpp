#include <bits/stdc++.h>
using namespace std;

string interpret(string command) {

    command = regex_replace(command, regex("\\(al\\)"), "al");
    command = regex_replace(command, regex("\\(\\)"), "o");
    return command;
}
int main()
{
    auto res = interpret("(al)G(al)()()G");
    printf("%s\n", res.c_str());
    return(0);
}
