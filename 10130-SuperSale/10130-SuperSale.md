# UVa-10130 SuperSale #

**題目鏈結：https://onlinejudge.org/external/101/10130.pdf**

---

## 題目概要 ##
1. 首先於第一行輸入為一個整數T，代表Case的數量。(1 ≦ T ≦ 1000)
2. 接著輸入N表示目前有N種商品正在進行特價。(1 ≦ N ≦ 1000)
3. 接下來需輸入N行，每行都會包含兩個數字P與W。
4. P表示價格(Price)。(1 ≦ P ≦ 100)
5. W表示重量(Weight)。(1 ≦ W ≦ 30)
6. 然後現在有一個家庭共G個人。(1 ≦ G ≦ 100)
7. 每個人都有不同的背包重量上限MW。(1 ≦ MW ≦ 30)
8. 最後需要輸出那一家人能買到的最高商品價值為何？

## 特殊要點 ##
* 本題無特殊要點。

## 解題策略 ##
* 本題可視為背包問題，dp[MW]=k表示重量上限MW的背包裝的物品最多價值k。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
2
3
72 17
44 23
31 24
1
26
6
64 26
85 22
52 4
99 18
39 13
54 9
4
23
20
20
26
```
### Sample Output ###
```
72
514
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include <cstdio>
#include <algorithm>

int T, N, G, MW;
int price[1005], weight[1005];
int dp[35];
int Knapsack();

int main()
{
    scanf("%d", &T);
    while (T--) {
        // Input
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d %d", &price[i], &weight[i]);
        scanf("%d", &G);

        std::fill(std::begin(dp), std::end(dp), 0);
        MW = 30;
        Knapsack();

        int result = 0;
        while (G--) {
            scanf("%d", &MW);
            result += Knapsack();
        }
        printf("%d\n", result);
    }
}
int Knapsack()
{
    if (dp[MW]) return dp[MW];
    int dp[35] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = MW; j-weight[i] >= 0; --j) {
            dp[j] = std::max(dp[j], dp[j-weight[i]] + price[i]);
        }
    }
    return dp[MW];
}
```
