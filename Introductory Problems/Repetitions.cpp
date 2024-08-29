// Problem link:- https://cses.fi/problemset/task/1069
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int count = 1, ct=1;
    string str;
    cin >> str;
    for(int i=0; i<str.length()-1; i++) {
        if(str[i] == str[i+1])
            ct++;
        else {
            count = max(ct, count);
            ct = 1;
        }
    }
    count = max(count, ct);
    cout << count << endl;
}