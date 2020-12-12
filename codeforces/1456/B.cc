/**
 * http://codeforces.com/contest/1456/problem/B
 */

#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;
int n;
int a[N];
int pre[N];
int ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        pre[i + 1] = pre[i] ^ a[i];
    }
    for (ans = 1; ans <= n - 2; ++ans) {
        for (int i = 0, j = ans + 1; j < n; ++i, ++j) {
            for (int k = i + 1; k <= j ; ++k) {
                if ((pre[k] ^ pre[i]) > (pre[k] ^ pre[j + 1])) {
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}