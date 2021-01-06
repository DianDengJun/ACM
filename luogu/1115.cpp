// https://www.luogu.com.cn/problem/P1115 P1115 最大子段和
// 以前缀和为模板的动态规划

#include <algorithm>
#include <cstdio>

using namespace std;

//const int maxN = 2e5 + 10;
const int INF = 2e9 + 1;
int a;
// int s[maxN] = {0};//前缀和
int s[2] = {0};//前缀和

int main() {
    int n;
    scanf("%d", &n);
    int ans = -INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        // if(i<2) s[i] = a;
        if (i < 2) s[1] = a;
        else
            // 比较当前输入的数a和<上一次字段和加上a><s[i+1]+a>哪个大
            // 如果a本身就比s[i+1]+a大,就没有将s[i+1]+a作为新的字段和s[i]的必要

            // s[i] = max(a, s[i-1]+a));
            s[i & 1] = max(a, s[!(i & 1)] + a);//滚动数组
            // 实际上只要保留两个关键的值:新字段和和上一次字段和

        // ans用于记录最大字段和
        // 由于存在<a本身就比s[i+1]+a大>的情况,会有不同的字段和
        // ans = max(ans, s[i]);
        ans = max(ans, s[i & 1]);
    }
    printf("%d\n", ans);
    return 0;
}