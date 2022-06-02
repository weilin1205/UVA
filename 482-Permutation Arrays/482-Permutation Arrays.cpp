#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vi;

int main() {
    int test_case;
    scanf("%d", &test_case);
    while (test_case--) {
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
        if (test_case != 0)
            cout << endl;
    }
    return 0;
}
