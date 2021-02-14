// https://www.luogu.com.cn/problem/P2440 木材加工
// 二分答案

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n, k;
int a[MAXN];
int maxLength{0};

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxLength = max(maxLength, a[i]);
    }
    int left = 1, mid, right = maxLength;
    int minDivided{0};
    while (left <= right) {
        mid = left + (right - left) / 2;
        long long count = 0;
        for (int i = 1; i <= n;i++) {
            count += a[i] / mid;
        }
        if (count < k)
            right = mid - 1;
        else if (count >= k){
            minDivided = mid;
            left = mid + 1;
        }
    }
    printf("%d\n", minDivided);
    return 0;
}