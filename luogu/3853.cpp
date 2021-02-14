// https://www.luogu.com.cn/problem/P3853 路标设置
// 二分答案

#include <bits/stdc++.h>
using namespace std;

int a[static_cast<int>(1e7) + 5];
int L, N, K;

int main() {
    scanf("%d %d %d", &L, &N, &K);
    for (int i = 0; i < N; i++) {
        // int pos{0};
        // scanf("%d", pos);
        // a[pos] = 1;
        scanf("%d", &a[i]);
    }
    int left = 0, mid, right = L;
    int minMax{0};
    while (left <= right) {
        mid = left + (right - left) / 2;
        int count{0};
        for (int i = 1; i < N; i++) {
            if (a[i] - a[i - 1] >= mid) {
                count += (a[i] - a[i - 1]) / mid;
                if ((a[i] - a[i - 1]) % mid == 0)
                    count--;
            }
        }
        if (count > K)
            left = mid + 1;
        else {
            minMax = mid;
            right = mid - 1;
        }
    }
    printf("%d\n", minMax);
    return 0;
}