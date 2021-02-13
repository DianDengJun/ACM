// https://www.luogu.com.cn/problem/P2678 跳石头
// 二分答案

#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 50010;
int a[MAXN];
int L, N, M;

bool judge(int x) {
    int total = 0;      // 计数器，记录以当前答案需要移走的实际石头数
    int i = 0;          // 下一块石头的编号
    int now = 0;        // 当前位置
    while (i < N + 1) { // 终点是 N + 1位置
        i++;
        if (a[i] - a[now] < x) // 判断距离差
            total++;
        else
            now = i; // 距离比x大，不用拿走，跳过去
    }
    if (total > M)
        return false;
    else
        return true;
}

int main() {
    scanf("%d %d %d", &L, &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    a[N + 1] = L; // 非终点，指示右边界

    int ans;
    int left = 1, mid, right = L;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (judge(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}