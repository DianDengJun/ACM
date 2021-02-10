// https://www.luogu.com.cn/problem/P5250 木材仓库
// STL map

#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<int, int> m; // map模板参数1：int，记录长度，模板参数2：int，记录对应数量
    int n;
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x == 1) {
            if (m.count(y)) printf("Already Exist\n");
            else
                m[y] = 1;
        } else {
            if (m.empty()) printf("Empty\n");
            else if (m.count(y)) {
                m.erase(y);
                printf("%d\n", y);
            } else {
                m[y] = 1; // 假定存一个进去，然后找最近的
                auto it = m.find(y); // 找y对应的迭代器
                auto xit = it; // 复制保留迭代器值
                it++; // 自增找下一个
                // 几种特判
                if(xit == m.begin()) { // 没有比它更短的
                    printf("%d\n", it->first);
                    m.erase(it);
                } else if (it == m.end()) { // 没有比它更长的
                    printf("%d\n", (--xit)->first);
                    m.erase(xit);
                }
                // 长度比较
                else if (y-(--xit)->first > it->first-y) {
                    printf("%d\n", it->first);
                    m.erase(it);
                } else {
                    printf("%d\n", xit->first);
                    m.erase(xit);
                }
                m.erase(y); // 将假定的y删除
            }
        }
    }
}