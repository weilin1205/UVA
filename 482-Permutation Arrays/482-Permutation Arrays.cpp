#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> va;
int main() {
    int T;  //先輸入case的總數
    scanf("%d", &T);
    while (T--) {
    	va.clear(); //把va清空
    	int num;
        char c;
        string str;
        //開始輸入編號，如果遇到換行符便停止輸入
        while (scanf("%d%c", &num, &c) == 2) {
            va.push_back(num);  //把輸入的數推到va裡面
            if (c == '\n')
                break;
        }
        vector<string> vb(va.size() + 1);
        //開始輸入數據並進行排列
        for (int i = 0; i < va.size(); i++) {
        	cin>>str;
            vb[va[i]] = str;
        }
        //輸出排列好的數據
        for (int i = 1; i < vb.size(); i++) {
            cout << vb[i] << "\n";
        }
        //每個case之間要有空行
        if (T != 0)
            cout << endl;
    }
    return 0;
}
