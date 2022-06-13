# UVa-10810 Ultra-QuickSort #

**題目鏈結：https://onlinejudge.org/external/108/10810.pdf**

---

## 題目概要與重點 ##
* 首先於第一行輸入為一個整數n，代表目前的Case中一共有n個數字。(n<500,000)
* 各別的每個數字，其範圍是0 ≤ a[i] ≤ 999,999,999
* 每個數字可以和其左右兩個數字做位置交換。
* 題目的目標是要把這些數字由小而大地排好。
* 最終要輸出最少的交換次數為多少。
* 當輸入n=0的時候，程式終止。

## 解題思路與策略 ##
* 本題也可以使用Bubble sort來做，但是很容易會出現TLE的問題。(時間複雜度為 *O(n^2)*)
* 故在此更換作法為使用Merge sort來實作。(時間複雜度為 *O(nlogn)*)
* 次數的部分使用 long long ，以避免overflow。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
5
9
1
0
5
4
3
1
2
3
0
```
### Sample Output ###
```
6
0
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include <iostream>
#include <stdio.h>
using namespace std;
int temp[500005];

long long int mergesort(int a[], int x, int y, long long int k) {
    if (y == x)
        return k;
    k = mergesort(a, x, (x+y)/2, k);
    k = mergesort(a, (x+y)/2+1, y, k);
    for (int i = x, i1 = (x+y)/2+1, j = (x+y)/2, j1 = y, l = 0;;) {
        if (i>j && i1>j1)
            break;
        else {
            if (i>j) {
                while (i1 <= j1) temp[l] = a[i1], i1++, l++;
            }
            else if (i1>j1) {
                while (i<=j) temp[l] = a[i], i++, l++;
            }
            else if (a[i] > a[i1]) {
                temp[l] = a[i1], k+= (j-i+1), l++, i1++;
            }
            else if (a[i] < a[i1]) {
                temp[l] = a[i], l++, i++;
            }
        }
    }
    for(int i = x, j = 0; i<=y; i++, j++)
        a[i] = temp[j];
    return k;
}
int main() {
    int n, a[500005];
    long long int k;
    while( scanf("%d",&n) && n) {
        k = 0;
        for(int i = 0; i<n; i++)
            scanf("%d", &a[i]);
        k = mergesort(a, 0, n-1, k);
        printf("%lld\n", k);
    }
    return 0;
}
```
---

## 程式執行結果 ##
![image](https://user-images.githubusercontent.com/100191575/172055983-2d0df1f2-6d83-42e3-ab43-ed56a349d477.png)


