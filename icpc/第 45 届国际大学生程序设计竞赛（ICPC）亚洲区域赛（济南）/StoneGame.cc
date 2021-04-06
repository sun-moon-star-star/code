#include <cstdio>
#include <algorithm>

int main()
{
    long long a1, a2, a3, ans;
    while (~scanf("%lld%lld%lld", &a1, &a2, &a3))
    {
        ans = 0;
        if (a1 && a2)
        {
            if (a1 > a2)
            {
                ans += a2 * 2;
                a1 -= a2;
                a2 = 0;
            }
            else
            {
                ans += a1 * 2;
                a2 -= a1;
                a1 = 0;
            }
        }
        if (a1 > 1)
        {
            ans += a1 / 3 * 3;
            if (a1 % 3 == 2)
            {
                ans += 1;
            }
        }
        if (a2 > 1)
        {
            ans += a2 / 3 * 6;
            if (a2 % 3 == 2)
            {
                ans += 4;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}