// https://www.luogu.com.cn/problem/P5638 【CSGRound2】光骓者的荣耀

#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = (int) 1e6 + 5;

//long long a[maxN] = {0}, s[maxN] = {0};
long long a = 0, s[maxN] = {0}; // a用不到数组，直接变为变量

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
//        cin >> a[i];
//        s[i] = s[i - 1] + a[i]; // 前缀和
        cin >> a;
        s[i] = s[i - 1] + a; // 前缀和
    }
    if (!k)
        cout << s[n - 1] << endl;
    else if (k >= n) cout << 0 << endl;
    else {
        long long ans = 0;
        // 枚举出每一个城市作为跳跃出发点
        for (int i = k; i <= n - 1; i++) {
            ans = max(ans, s[i] - s[i - k]);
        }
//        for (int i = 1; i <= n - 1; i++) {
//            ans = max(ans, s[i + k - 1] - s[i - 1]);
//        }
        cout << s[n - 1] - ans << endl;
    }
    return 0;
}