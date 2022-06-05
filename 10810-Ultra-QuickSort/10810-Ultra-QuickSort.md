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
* 本題的可以使用Bubble sort來做，但是很容易會出現TLE的問題。(時間複雜度為 *O(n^2)*)
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
int A[500005];
int tmp[500005];
int n;

long long mergesort(int l,int r)
{
	if(l>=r){
        return 0;
	}
	int m=l+(r-l)/2;
	long long cnt=0;
	cnt+=mergesort(l,m);
	cnt+=mergesort(m+1,r);
	int f=l, p=m+1;
	for(int i=0;i<r-l+1;i++){
		if(p>r || (f<=m && A[f]<=A[p])) tmp[i]=A[f++];
		else tmp[i]=A[p++], cnt+=m-f+1;
	}
	f=0;
	for(int i=l;i<=r;i++) A[i]=tmp[f++];
	return cnt;
}
int main()
{
	while(scanf("%d",&n)==1 && n){
		for(int i=0;i<n;i++) scanf("%d",&A[i]);
		printf("%lld\n",mergesort(0,n-1));
	}
}
```
