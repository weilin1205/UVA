#include <cstdio>
#include <algorithm>
using namespace std;

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

        fill(begin(dp),end(dp), 0);
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
            dp[j] = max(dp[j], dp[j-weight[i]] + price[i]);
        }
    }
    return dp[MW];
}
