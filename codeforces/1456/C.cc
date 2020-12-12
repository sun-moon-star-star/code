/**
 * http://codeforces.com/contest/1456/problem/C
 * 
 * sample:
 * 
 * 4 0
 * 1 2 3 4
 * 
 * 4
 * 4 3
 * 4 3 2
 * 
 * 12 + 6 + 2 = 20
 * 
 * another example: 1-11 is index in array[i], array[i] < array[i + 1] (0 < i < 11):
 * 
 * 9
 * 9 6
 * 9 6 3
 * x x x x
 * x x x x 8
 * x x x x 8 5
 * x x x x 8 5 2
 * x x x x x x x x
 * x x x x x x x x 7
 * x x x x x x x x 7 4
 * x x x x x x x x 7 4 1        (1)
 * 
 * 9
 * 9 8
 * 9 8 6
 * 9 8 6 3
 * x x x x x
 * x x x x x 5
 * x x x x x 5 2
 * x x x x x x x x
 * x x x x x x x x 7
 * x x x x x x x x 7 4
 * x x x x x x x x 7 4 1        (2)
 * 
 * 9
 * 9 8
 * 9 8 7
 * 9 8 7 6
 * 9 8 7 6 3
 * x x x x x x
 * x x x x x x 5
 * x x x x x x 5 2
 * x x x x x x x x x
 * x x x x x x x x x 4
 * x x x x x x x x x 4 1        (3)
 * 
 * 9
 * 9 8
 * 9 8 7
 * 9 8 7 6
 * 9 8 7 6 5
 * 9 8 7 x 5 3
 * x x x x x x x
 * x x x x x x x 2
 * x x x x x x x x x
 * x x x x x x x x x 4
 * x x x x x x x x x 4 1        (4)
 * 
 * 9
 * 9 8
 * 9 8 7
 * 9 8 7 6
 * 9 8 7 6 5
 * 9 8 7 6 5 3
 * x x x x x x x
 * x x x x x x x 2
 * x x x x x x x x x
 * x x x x x x x x x 4
 * x x x x x x x x x 4 1        (5)
 * 
 * notice: negative perfer to use 0 0 1 1 2 2, positive perfer to use 3 4 5 ...
 */

#include <cstdio>
#include <algorithm>

const int N = 500000 + 10;

int n, k;
long long ans, sum, num;
int a[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    ++k;
    std::sort(a, a + n);
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 1ll * a[i] * (i / k);
    }
    ans = sum;
    num = 0;
    for (int i = n - 1; i >= 0; --i) {
        num += a[i];
        if (i % k != 0) {
            sum += num;
        }
        ans = std::max(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}