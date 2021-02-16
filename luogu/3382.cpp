// https://www.luogu.com.cn/problem/P3382 【模板】三分法
// 三分

#include <bits/stdc++.h>
using namespace std;

#define eps 1e-7

int n;
double l, r;
double a[20];

// 求函数值
double f(double x) {
    double u = 1, ans = 0;
    for (int i = n; i >= 0; i--) {
        ans += u * a[i];
        u *= x;
    }
    return ans;
}

// 三分
double threeDivide(double left, double right) {
    while (left + eps < right) {
        double lMid = left + (right - left) / 3;
        double rMid = right - (right - left) / 3;
        if (f(lMid) <= f(rMid))
            left = lMid;
        else
            right = rMid;
    }
    return right;
}

int main() {
    scanf("%d %lf %lf", &n, &l, &r);
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("%.5lf", threeDivide(l, r));
    return 0;
}