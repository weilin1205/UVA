# UVa-482 Permutation Arrays #

**題目鏈結：https://onlinejudge.org/external/4/482.pdf**

---

## 題目概要 ##
1. 首先於第一行輸入為一個整數T，代表Case的數量。
2. 接著每個Case前會有一個空白行做為開頭。
3. 接下來的每個Case會包含兩行數字。
4. 第一行是索引數組，從1~n。
5. 第二行為數據數組，可包含浮點格式。
6. 最後依照第一行的編號去輸出第二行的值。
7. 兩個連續Case由空白行分隔。

## 特殊要點 ##

* 本題的編號都是由「1」起算，然而C語言的陣列編號是由0起算，故需要當心。
* 本題讀取時有許多空行，輸出時也要求每個case「之間」要有空行，需要小心處理這些空行。
* 注意數據的範圍，每行的數據個數，題目是沒有指定的。

## 解題策略 ##
* 第一行的索引編號可以看作是一種置換，指定第二行數據值的輸出順序。可以把編號視為一種下標索引。
* 由於每行的數據個數是不確定的，可以使用以讀到換行符來結束編號的輸入。
* 由於題目沒有給定數據的範圍，故在此使用vector來解決。
* 因為讀入資料的型態可能為int、float或是double，所以可以藉由以字串的型態來存取每一筆資料，用以避免輸出格式錯誤的問題。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
1

3 1 2
32.0 54.7 -2
```
### Sample Output ###
```
54.7
-2
32.0
```
---

## 程式碼 ##

### C++ ###

```c++
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

        /// _ symbol means space, input : 3 1 2 -> (3_)(1_)(2\n)
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

        for (int i = 1; i < vs.size(); i++)
            cout << vs[i] << endl;

        if (test_case != 0)
            cout << endl;
    }
    return 0;
}

```
