# UVa-11321 Sort! Sort!! And Sort!!! #

**題目鏈結：https://onlinejudge.org/external/113/11321.pdf**

---

## 題目概要與重點 ##
* 輸入測資檔包含 20 筆的輸入測資。每組測資一開始包含兩個整數 N, M。(0 ≦ N,M ≦ 10000)
* 接下來的N行裡每一行只包含一個整數。這些整數保證都可以被存在32-bit有號整處理。輸入N=0,M=0時表示結束，同時也一起輸出0 0。
* 先利用每個數字除以M的餘數由小到大排，並遵守以下規則：
  * 若排序中比較的兩數為一奇一偶且兩數除以M 的餘數相等，則奇數要排在偶數前面。
  * 若兩奇數除以M餘數大小相等，則原本數值較大的奇數排在前面。
  * 若兩偶數除以M餘數大小相等，則較小的偶數排在前面。
* 負數的餘數計算和C語言裡的定義相同，即負數的餘數絕對不會大於零。例如：-100 MOD 3 = -1, -100 MOD 4 = 0 依此類推。

## 解題思路與策略 ##
* 本題依照題目給的規則直觀打出即可。
* 可以善用algorithm函式庫的sort函式的第三參數去做判斷。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
15 3
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0 0
```
### Sample Output ###
```
15 3
15
9
3
6
12
13
7
1
4
10
11
5
2
8
14
0 0
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
bool cmp(int i, int j) {
    if (i % m != j % m) {
        return i % m < j % m;
    }
    if ((i & 1) && (j & 1))
        return i > j;
    else if (!(i & 1) && !(j & 1))
        return i < j;
    else
        return i & 1;
}

int main() {
    while (cin >> n >> m, n) {
        cout << n << " " << m << endl;
        vector<int> nums(n);
        for (auto& i : nums) {
            cin >> i;
        }
        sort(nums.begin(), nums.end(), cmp);
        for (auto& i : nums)
            cout << i << endl;
    }
    cout << 0 << " " << 0 << endl;
}
```

---

## 程式執行結果 ##

![image](https://user-images.githubusercontent.com/100191575/173395126-acab86e8-ecf5-4f05-986f-8d032710588d.png)
