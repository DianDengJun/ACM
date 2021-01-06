// https://www.luogu.com.cn/problem/P5638 【CSGRound2】光骓者的荣耀
// 前缀和、模拟

#include <algorithm>
#include <cstdio>

using namespace std;

const int maxN = (int) 1e6 + 5;

//long long a[maxN] = {0}, s[maxN] = {0};
long long a = 0, s[maxN] = {0};// a用不到数组，直接变为变量

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n - 1; i++) {
        scanf("%lld", &a);
        s[i] = s[i - 1] + a;// 前缀和
    }
    if (!k)
        printf("%lld\n", s[n - 1]);
    else if (k >= n)
        printf("0\n");
    else {
        long long skip = 0;
        // 枚举出每一个城市作为跳跃出发点，skip是计算跳过的路径
        for (int i = k; i <= n - 1; i++) {
            skip = max(skip, s[i] - s[i - k]);
        }
        // for (int i = 1; i <= n - k; i++) {
        //     skip = max(skip, s[i + k - 1] - s[i - 1]);
        // }
        printf("%lld\n", s[n - 1] - skip);
    }
    return 0;
}