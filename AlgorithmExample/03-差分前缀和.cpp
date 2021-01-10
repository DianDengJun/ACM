// https://www.bilibili.com/video/BV1b4411D7yr
// ���ǰ׺��

#include <iostream>
#include <string>
using namespace std;

int map[10005];// ԭʼ����
int dp[10005]; // ���ǰ׺��

void Print(int a[], int size, int d[]) {
    cout << "��ǰ����:" << endl;
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
    cout << "��������Ĵ�С:";
    cin >> n;
    cout << "��������" << n << "����:" << endl;
    // todo: 1.Ԥ����
    for (int i = 1; i <= n; i++) {
        cin >> map[i];
        dp[i] = map[i] - map[i - 1];
    }
    int times;
    cout << "����������Ĵ���:";
    cin >> times;
    int l, r;
    int number;
    for (int i = 0; i < times; i++) {
        cout << endl
             << "��" << i + 1 << "�β���:" << endl
             << "��������������[l,r]:";
        cin >> l >> r;
        cout << "������Ҫ���ϵ�����:(�����Ǹ���)";
        cin >> number;
        dp[l] += number;
        dp[r + 1] -= number;
        Print(map, n, dp);
    }
    return 0;
}