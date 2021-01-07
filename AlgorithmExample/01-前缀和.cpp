// https://www.cnblogs.com/-Ackerman/p/11162651.html
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "输入数组的大小:";
    cin >> n;
    int a[n + 1] = {0};
    int b[n + 1] = {0};//前缀和
    cout << "请输入这" << n << "个数" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    int q;
    cout << "请输入查询的次数:";
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++) {
        cout << endl
             << "第" << i + 1 << "次操作:" << endl
             << "请输入左区间l:";
        cin >> l;
        cout << "请输入右区间r:";
        cin >> r;
        cout << "区间[" << l << "," << r << "]和为:" << b[r] - b[l - 1] << endl;
    }
}