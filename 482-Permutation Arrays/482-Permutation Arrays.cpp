#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vi;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        vi.clear();
        int n;
        char c;
        string s;
        while (scanf("%d%c", &n, &c) == 2) {
            vi.push_back(n);
            if (c == '\n')
                break;
        }
        vector<string> vs(vi.size() + 1);
        for (int i = 0; i < vi.size(); i++) {
            cin >> s;
            vs[vi[i]] = s;
        }
        for (int i = 1; i < vs.size(); i++) {
            cout << vs[i] << endl;
        }
        if (T != 0)
            cout << endl;
    }
    return 0;
}
