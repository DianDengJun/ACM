// https://www.luogu.com.cn/problem/P1115 P1115 最大子段和

#include <iostream>
#include <algorithm>

using namespace std;

//const int maxN = 2e5 + 10;
const int INF = 2e9 + 1;
int a;
int s[2] = {0};  //前缀和

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (i < 2) s[1] = a;
        else s[i&1] = max(a, s[!(i&1)] + a);    //滚动数组
        ans = max(ans, s[i&1]);
    }
    cout << ans;
    return 0;
}