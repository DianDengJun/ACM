// https://www.luogu.com.cn/problem/P1996 约瑟夫问题
// STL vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    int i = 0;
    while (!a.empty()) {
        cout << a[i = (i + m - 1) % (a.size())] << " ";
        a.erase(a.begin() + i);
    }
    return 0;
}