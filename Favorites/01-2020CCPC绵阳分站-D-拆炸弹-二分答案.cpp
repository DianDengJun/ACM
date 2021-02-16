/**
 * https://www.cnblogs.com/jianjinxiani/p/13916699.html
 * 
 * 给 n 个炸弹，每个炸弹有一个倒计时 Ai ，
 * 倒计时小于 0 炸弹就会爆炸，现在顺序做如下操作：
 *   把一个炸弹的时间加 1 。
 *   所有炸弹时间减 1 。
 *   如果没有炸弹爆炸，重复上述操作。
 * 问最多能做多少次第一个操作
 * 1 <= n <= 10^5
 * 
 * 示例输入
 * 2
 * 2
 * 1 1
 * 3
 * 1 2 3
 * 示例输出
 * Case #1: 3
 * Case #2: 4
 */

#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 10;
long long arr[MAXN];
int n;

bool check(long long x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < x - 1)
            sum += 0 - (arr[i] - x + 1);
        if (sum > x - 1)
            return false;
    }
    return true;
}

int main() {
    int t, T = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", arr + i);
        printf("Case #%d: ", T++);
        long long l = 0, r = 1e18, res = 1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(mid))
                res = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%lld\n", res);
    }
    return 0;
}