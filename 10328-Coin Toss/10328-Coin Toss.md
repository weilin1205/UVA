# UVa-10328 Coin Toss #

**題目鏈結：https://onlinejudge.org/external/103/10328.pdf**

---

## 題目概要與重點 ##
*  有一枚公正硬幣，連續拋擲n次，試問出現連續至少k次正面的次數為何。(1 ≦ k ≦ n ≦ 100)
*  題目例子：若投擲3次，則它會有8種結果( HHH , HHT , HTH , HTT , THH , THT , TTH , TTT )。
*  而就上述例子來說：連續至少3次H的次數為1次，連續至少2次H的次數為3次，連續至少1次H的次數為7次。
*  當輸入發生EOF時，便結束輸入。

## 解題思路與策略 ##
* 原本的題目問"`連續至少k次正面`"，比較不好下手，故使用逆向思維，我們可以將其轉化為"`(連續至多n次正面)-(連續至多k-1次正面)`"。
*  `(連續至多n次正面)`：即為 `2的n次方`，而考慮到n比較大，故使用高精度大整數來做計算。
*  `(連續至多k-1次正面)`：先根據k-1是否為0定義f[1][1]的初始值，f[1][2]肯定為1(陣列的第二維中1代表正,2代表反的總情況數)，由於對反面牌沒有要求,所以:第i次為反情況數=第i-1次為正情況數+第i-1次為反情況數。
   * 如果i<=k-1,隨便放,那麼第i次為正情況數=第i-1次為正情況數+第i-1次為反情況數。
   * 如果i=(k-1)+1,那麼第i次為正情況數=第i-1次為正情況數+第i-1次為反情況數-1，那個-1是減去前面全是正面的情況。
   * 如果i>(k-1)+1,那麼第i次為正情況數=第i-1次為正情況數+第i-1次為反情況數-第i-(k-1)-1次為反情況數，那個-第i-(k-1)-1次為反情況數 是排除第i-(k-1)-1次為反而且中間全是正的情況的情況。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
4 1
4 2
4 3
4 4
6 2
```
### Sample Output ###
```
15
8
3
1
43
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include <iostream>
#include <cstring>

#define mod 1000000005
using namespace std;

typedef long long LL;

const int N = 1010;

LL dp[N];

LL n, k;

LL fun(LL n,LL k) {
	//dp[i]表示拋第i個硬幣時連續的H不超過k個的情況總數
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;//
	for (int i = 1; i <= n; i++) {
		LL sum = (2 * dp[i - 1]) % mod;
		if (i <= k)dp[i] = sum;
		else if (i == k + 1)dp[i] = (sum - 1) % mod;
		else dp[i] = (sum - dp[i - k - 2]) % mod;
	}
	return dp[n];
}
int main() {
	while (scanf("%lld %lld", &n, &k) != EOF) {
		printf("%lld\n", (fun(n,n) - fun(n,k-1) + mod) % mod);
	}
	return 0;
}

```

---

## 程式執行結果 ##
![image](https://user-images.githubusercontent.com/100191575/172637065-5a13f278-3602-4cc6-80a2-fd410e5e70cc.png)


