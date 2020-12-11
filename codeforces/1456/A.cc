/**
 * http://codeforces.com/contest/1456/problem/A
 */

#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int T;
int n, p, k;
int x, y;
char str[N];
int dp[N];
int ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &p, &k);
        scanf("%s", str + 1);
        scanf("%d %d", &x, &y);
        ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; ++i) {
            if (i < p) {
                dp[i] = i * y;
            } else {
                dp[i] = x * (str[i] == '0') + (i - p) * y;
                if (i >= p + k) {
                    dp[i] = std::min(dp[i], dp[i - k] + x * (str[i] == '0'));
                }
                if (i + k > n) {
                    ans = std::min(ans, dp[i]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}