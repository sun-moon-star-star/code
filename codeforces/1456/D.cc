/**
 * http://codeforces.com/contest/1456/problem/C
 * 
 * @ref: https://www.cnblogs.com/gmh77/p/14063410.html
 * 
做法很多，但是想出一个阳间做法很难

我的想法：设f[i,j],g[i,j]表示第i个蛋糕落下来时，人接分身在j/分身接人在j，问题是有人放下分身后马上赶路的情况，这样可能在分身接住蛋糕时人不在下落点上

题解做法设f[i]表示接住了前i个蛋糕，且第i个蛋糕是用分身接（已接住或者已经放好了等着蛋糕下来）的最小时间，这样就解决了上面的问题

再设g[i,j]表示接住了前i个蛋糕分身在蛋糕j处是否可行，且第i个蛋糕是用本体接的

转移考虑分本体和分身接讨论，先考虑f[i]：

①i+1用本体接：则可以找一个地方j放分身，然后从j跑到i+1更新g[i+1,j]，注意放分身时接i的分身必须已接完

②i+1用分身接：直接往i+1跑更新f[i+1]，也要注意要先接到i

接着考虑g[i,j]，当i+1!=j时显然只能用本体接i+1，当i+1=j时用分身接i+1，然后考虑i+2怎么接：

①i+2用本体接：找一个地方k放分身，然后i->k->i+2更新g[i+2,k]，注意在k处放分身时i+1要已接到

②i+2用分身接：直接i->i+2更新f[i+2]，同样i+1要接到

时间复杂度O(n^2)
 */

#include <cstdio>
#include <cstring>

#define abs(x) ((x) > 0 ? (x) : -(x))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define ll long long

using namespace std;

int n, i, j, k, l;
int t[5001], x[5001];
ll f[5001];
bool g[5001][5001];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &t[i], &x[i]);

    memset(f, 1, sizeof(f));
    f[0] = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        if (f[i] <= t[i])
        {
            for (int j = i + 2; j <= n; ++j)
                if (max(f[i] + abs(x[i] - x[j]), t[i]) + abs(x[j] - x[i + 1]) <= t[i + 1])
                    g[i + 1][j] = 1;
            f[i + 1] = min(f[i + 1], max(f[i] + abs(x[i] - x[i + 1]), t[i]));
        }
        for (int j = i + 2; j <= n; ++j)
            if (g[i][j] && t[i] + abs(x[i] - x[i + 1]) <= t[i + 1])
                g[i + 1][j] = 1;
        if (g[i][i + 1])
        {
            if (i < n - 1)
            {
                for (int k = i + 3; k <= n; ++k)
                    if (max(t[i] + abs(x[i] - x[k]), t[i + 1]) + abs(x[k] - x[i + 2]) <= t[i + 2])
                        g[i + 2][k] = 1;
                f[i + 2] = min(f[i + 2], max(t[i] + abs(x[i] - x[i + 2]), t[i + 1]));
            }
            else
                f[n] = 0;
        }
    }
    printf((f[n] <= t[n]) ? "YES\n" : "NO\n");

    return 0;
}