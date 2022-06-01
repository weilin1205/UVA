# UVa-482 Permutation Arrays #

**題目連結：https://onlinejudge.org/external/4/482.pdf**

---

## 題目概要 ##
* 第一行輸入為一個整數T，代表Case的數量。
* 每個Case前會有一個空白行做為開頭。
* 每個Case會包含兩行數字。
* 第一行是編號索引數組，從1~n。
* 第二行為數據數組，可包含浮點格式。
* 最後依照第一行的編號去輸出第二行的值。

## 特殊要點 ##
* 本題的編號都是由「1」起算，然而C語言的陣列編號都是由0起算，故需要。
* 本題讀取時有許多空行，輸出時也要求每個case「之間」要有空行，需要小心處理這些空行。
* 並且將排序好的數據數組x輸出，每個數據一行(如範例輸出)。
* 兩個連續Case由空白行分隔。

## 解題策略 ##
* 第一行輸入為一個整數T，代表Case的數量。
* 每個Case前有皆有一個空白行做為開頭。
* 每個Case會包含兩行數字。
* 第一行是索引數組p，從1~n。此行中的數字將以某種方式排列。
* 第二行為數據數組x，可能包含浮點格式。

---

## Sample Input ##

```
1

3 1 2
32.0 54.7 -2
```

## Sample Output ##

```
54.7
-2
32.0
```
---
## Code ##

### C++ ###

```c++
#include <stdio.h>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    int t;
    string line;
    scanf("%d", &t);
    getchar();
    while(t--) {
        getchar();
        int idx[5000], n = 1, i = 1;
        string x[5000];
        getline(cin, line);
        stringstream sin;
        sin << line;
        while(sin >> idx[n])
            n++;
        getline(cin, line);
        sin.clear();
        sin << line;
        while(sin >> x[idx[i]])
            i++;
        for(i = 1; i < n; i++)
            cout << x[i] << endl;
        if(t)
            puts("");
    }
    return 0;
}
```
