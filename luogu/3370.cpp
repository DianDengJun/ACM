// https://www.luogu.com.cn/problem/P3370 字符串哈希
// STL set

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string str;
    while (n--) {
        cin >> str;
        s.insert(str);
    }
    cout << s.size();
    return 0;
}