// https://www.luogu.com.cn/problem/P2249 【深基13.例1】查找
// 二分查找

#include <iostream>
#include <stdio.h>
using namespace std;

int a[static_cast<int>(1e6) + 5];

int binarySearch(int number, int length) {
    int left = 1, right = length;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= number)
            right = mid;
        else if (a[mid] < number)
            left = mid + 1;
    }
    if (a[left] == number)
        return left;
    else
        return -1;
}

int main() {
    auto n{0}, m{0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int number;
    for (int i = 0; i < m; i++) {
        scanf("%d", &number);
        printf("%d ", binarySearch(number, n));
    }
    return 0;
}