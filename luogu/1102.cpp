// https://www.luogu.com.cn/problem/P1102 A-B 数对
// 二分查找，使用STL upper_bound

/**
 * cnt 计数
 * 由于 上限-下限 较大，每次cnt再自增，更大，会超出int范围
 * 因此，cnt应选用 long
 * 但GCC编译器在Windows平台中生成的64位应用程序 long 和 int 一样占 4 字节
 * 导致无法在windows中试验效果。
 * 因此，选用long long
 * OJ平台一般使用 Linux GCC ，其生成的64位应用程序 long 占 8 字节，long long 也占 8 字节。
 * 
 * 综上，直接long long
 */

#include <bits/stdc++.h>
using namespace std;

int a[static_cast<int>(2e5) + 5];


int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    long long cnt{0};
    for (int i = 1; i <= n; i++) {
        cnt += (upper_bound(a + 1, a + n + 1, a[i] - c) - a) - (lower_bound(a + 1, a + n + 1, a[i] - c) - a);
    }
    printf("%ld\n", cnt);
    return 0;
}