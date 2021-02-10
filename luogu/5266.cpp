// https://www.luogu.com.cn/problem/P5266 学籍管理
// STL map

#include <iostream>
#include <map>
using namespace std;
map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    auto n{0}, select{0};
    cin >> n;
    string name;
    long score;
    while (n--) {
        cin >> select;
        switch (select) {
            case 1: {
                cin >> name >> score;
                auto it = m.find(name);
                if (it == m.end()) { // 如果没有找到
                    m.insert({name, score});
                } else {
                    m[name] = score;
                }
                cout << "OK" << endl;
            } break;
            case 2: {
                cin >> name;
                auto it = m.find(name);
                if (it == m.end()) { // 如果没有找到
                    cout << "Not found" << endl;
                } else {
                    cout << it->second << endl;
                }
            } break;
            case 3: {
                cin >> name;
                auto it = m.find(name);
                if (it == m.end()) { // 如果没有找到
                    cout << "Not found" << endl;
                } else {
                    m.erase(name);
                    cout << "Deleted successfully" << endl;
                }
            } break;
            case 4: {
                cout << m.size() << endl;
            } break;
        }
    }
    return 0;
}