# UVa-12372-Packing for Holiday #

**題目鏈結：https://onlinejudge.org/external/123/12372.pdf**

---

## 題目概要與重點 ##
* 豆豆先生手提箱的大小是20x20x20。
* 首先於第一行輸入為一個整數T，代表Case的數量。(T ≦ 100)
* 接下來的T列每一列會有三個整數L,W,H，分別表示禮物盒的長寬高。(1 ≦ L, W,H ≦ 50)
* 禮物盒的每一個面都要與手提箱內側的每一個面平行。
* 如果禮物盒可以放進手提箱就輸出“Case #: good”，否則輸出“Case #: bad”，(#為測資Case的編號)。

## 解題思路與策略 ##
* 由於題目有說禮物盒的每一個面都要與手提箱內側的每一個面平行，所以也不用考慮禮物盒斜放的問題。
* 只要單純去判斷禮物盒的三個邊長個別是否有超過20x20x20即可。
* 若都沒有超過就輸出“Case #: good”；若有一邊超過就輸出“Case #: bad”。

---

## 範例輸入與輸出 ##
### Sample Input ###
```
2
20 20 20
1 2 21
```
### Sample Output ###
```
Case 1: good
Case 2: bad
```
---

## ACCEPT程式碼 ##

### C++ ###

```c++
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;++i) {
	int a,b,c;
	cin>>a>>b>>c;
	if(a<=20 && b<=20 && c<=20) {
		//三邊都不超過20就輸出Case i: good。
		cout<<"Case "<<i<<": good\n"; }
	else {
		//任意一邊超過20就輸出Case i: bad。
		cout<<"Case "<<i<<": bad\n"; }
	}
	return 0;
}
```
