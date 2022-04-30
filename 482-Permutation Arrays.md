# UVa-482 Permutation Arrays (排列數組) #
---
## Problem ##

### 原文 ###
*In many computer problems, it is necessary to permute data arrays. That is, the data in an array must
be re-arranged in some specified order. One way to permute arbitrary data arrays is to specify the
permutations with an index array to point out the position of the elements in the new array. Let x
be an array that is to be permuted and let x be the permuted array. Then, we have the relationship
between x and x that x pi = xi.*

### 大意 ###
* 在許多電腦問題中，必須置換數據陣列。 
* 也就是說，必須以某些指定順序重新排列數組中的數據。
* 置換任意數據數組的一種方法是使用索引數組指定置換，以指出元素在新數組中的位置。
---
## Input ##

### 原文 ###
The input begins with a single positive integer on a line by itself indicating the number of the cases
following, each of them as described below. This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
Each input set will contain two lines of numbers. The first line will be an index array p containing
the integers 1 . . . n, where n is the number of integers in the list. The numbers in the first line will have
been permuted in some fashion. The second line will contain a list numbers in floating point format.
### 大意 ###
* 第一行為一個整數T，代表Case數量。
* 每個Case前有皆有一個空白行做為開頭。
* 每個Case將包含兩行數字。
* 第一行是索引數組p，從1~n。此行中的數字將以某種方式排列。
* 第二行為數據數組x，可能包含浮點格式。
---
## Output ##

### 原文 ###
For each test case, the output must follow the description below. The outputs of two consecutive cases
will be separated by a blank line.
The output for this program will be the list of floating point numbers from the input set, ordered
according to the permutation array from the input file. The output numbers must be printed one per
line in the same format in which they each appeared in the input file.
### 大意 ###
* 對於每個Case。
* 請將數據數組x根據索引數組p進行排序。
* 並且將排序好的數據數組x輸出，每個數據一行(如範例輸出)。
* 兩個連續Case由空白行分隔。
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
