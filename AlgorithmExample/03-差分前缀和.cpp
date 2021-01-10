// https://www.bilibili.com/video/BV1b4411D7yr
// 差分前缀和

#include <iostream>
#include <string>
using namespace std;

int map[10005];// 原始数组
int dp[10005]; // 差分前缀和

void Print(int a[], int size, int d[]) {
    cout << "当前数组:" << endl;
    for (int i = 1; i <= size; i++) {
        a[i] = d[1];
        for (int j = 2; j <= i; j++) {
            a[i] += d[j];
        }
        cout << a[i] << ((i % 5 && i != size) ? ' ' : '\n');
    }
}

int main() {
    int n;
    cout << "输入数组的大小:";
    cin >> n;
    cout << "请输入这" << n << "个数:" << endl;
    // todo: 1.预处理
    for (int i = 1; i <= n; i++) {
        cin >> map[i];
        dp[i] = map[i] - map[i - 1];
    }
    int times;
    cout << "请输入操作的次数:";
    cin >> times;
    int l, r;
    int number;
    for (int i = 0; i < times; i++) {
        cout << endl
             << "第" << i + 1 << "次操作:" << endl
             << "请输入左右区间[l,r]:";
        cin >> l >> r;
        cout << "请输入要加上的数量:(可以是负数)";
        cin >> number;
        dp[l] += number;
        dp[r + 1] -= number;
        Print(map, n, dp);
    }
    return 0;
}