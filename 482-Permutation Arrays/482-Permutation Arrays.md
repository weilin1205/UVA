# UVa-482 Permutation Arrays #

**題目鏈結：https://onlinejudge.org/external/4/482.pdf**

---

## 題目概要與重點 ##
* 首先於第一行輸入為一個整數T，代表Case的數量。
* 接著每個Case前會有一個空白行做為開頭。
* 接下來的每個Case會包含兩行數字。
* 第一行是索引數組，從1~n。
* 第二行為數據數組，可包含浮點格式。
* 最後依照第一行的編號去輸出第二行的值。
* 兩個連續Case由空白行分隔。

## 解題思路與策略 ##
* 本題的編號都是由「1」起算，然而C語言的陣列編號是由0起算，故在輸出時要記得把編號+1。
* 本題讀取時有許多空行，輸出時也要求每個case「之間」要有空行，要注意去處理這些空行。
* 第一行的索引編號可以看作是一種置換，指定第二行數據值的輸出順序。可以把編號視為一種下標索引。
* 由於每行的數據個數是不確定的，可以使用以讀到換行符來結束編號的輸入。
* 注意數據的範圍，每行的數據個數，題目是沒有指定的，故在此使用可以自動擴容的陣列vector來解決。
* 因為讀入資料的型態可能為int、float或是double，所以可以藉由以字串的型態來存取每一筆資料，用以避免輸出格式錯誤的問題。（例如下面範例輸出的 32.0 如果用float格式輸出的話，".0"將會被捨棄，而若是使用string的話，便可解決本問題）

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

## ACCEPT程式碼 ##

### C++ ###

```c++
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
            cin >> str;
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
```

---

## 程式執行結果 ##
![image](https://user-images.githubusercontent.com/100191575/172055871-0f983284-4037-4b69-8b15-9a22803ef525.png)

