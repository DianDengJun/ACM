// https://www.cnblogs.com/-Ackerman/p/11162651.html
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "��������Ĵ�С:";
    cin >> n;
    int a[n + 1] = {0};
    int b[n + 1] = {0};//ǰ׺��
    cout << "��������" << n << "����" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    int q;
    cout << "�������ѯ�Ĵ���:";
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++) {
        cout << endl
             << "��" << i + 1 << "�β���:" << endl
             << "������������l:";
        cin >> l;
        cout << "������������r:";
        cin >> r;
        cout << "����[" << l << "," << r << "]��Ϊ:" << b[r] - b[l - 1] << endl;
    }
}