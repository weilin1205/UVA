# UVa-10015 Joseph’s Cousin #

**題目鏈結：https://onlinejudge.org/external/100/10015.pdf**

---

## 題目概要與重點 ##
* 本題為約瑟夫環問題(Josephus Problem)的變形。
  > *原始約瑟夫環問題簡述：有一群編號為1~n的n個人圍成一個圓圈，每數到第m個人時他就會被殺掉(在此m是固定的一個數)，第一輪由1開始數，殺完人後就從那個人再繼續往下數，直到最後只剩下一個人。問題的目標是要求出這個唯一的倖存者在初始位置的編號是多少。舉例：如果n=6,m=5，則被殺掉的人的編號依序是5,4,6,2,3，最後只有編號1活了下來。*
* 此變形題的問題為：有一群編號為1~n的n個人圍成一個圓圈，每數到第m個人時他就會被殺掉，而這個m是一個會隨著每輪做變動的數，變動規則為按質數的順序(2,3,5,7…)來變化，即處決第i輪時使用第i個質數作為該輪要數的數字，第一輪由1開始數，殺完人後就從那個人再繼續往下數，直到最後只剩下一個人。問題的目標是要求出這個唯一的倖存者在初始位置的編號是多少。舉例：如果n=6，則被殺掉的人的編號依序是2,5,6,1,3，最後只有編號4活了下來。
* 本題有多個測資，每個測資一行，每一行有一個數字n。 (1 ≦ n ≦ 3501)
* 當輸入n=0時，程式終止。
* 針對輸入的每個測資輸出一行，表示最後活下來的人的編號。

## 解題思路與策略 ##
* 本題在了解題目規則時，可以先舉個例子並加以印證(如上方的舉例)，以方便了解題意並確定自己的想法是否正確。
* 第i輪使用第i個質數作為淘汰的步長。
* 我們可以先打表計算前3501個質數。
* 同時可透過使用已推導出來的Josephus Problem的DP式`for(int i=1;i<=n;++i)  ans=(ans+m)%i;`，並把其中的m修改成prime[n-i]來實作本題。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
6
0
```
### Sample Output ###
```
4
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int prime[4000];
int visit[35000] = {0};

int main()
{
        //先建立一個質數表
	int prime_size = 0;
	for(int i=2;i<35000;++i) {
		if(!visit[i]) {
			prime[prime_size ++]=i;
			for(int j=i*i;j<35000;j+=i) {
				visit[j]=1;
			}
		}
	}
	int n;
	while(~scanf("%d",&n)&&n) {
		int ans=0;
		for(int i=2;i<=n;++i) {
			ans=(ans+prime[n-i])%i;
		}
		printf("%d\n",ans+1);
	}
	
	return 0;
}
```

---

## 程式執行結果 ##
![image](https://user-images.githubusercontent.com/100191575/172105630-e1030dc3-a1c6-4507-94d6-cb8a9e83d18f.png)


