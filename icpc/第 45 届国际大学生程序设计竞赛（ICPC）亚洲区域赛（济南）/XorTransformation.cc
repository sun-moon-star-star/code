#include <cstdio>
#include <algorithm>

int main()
{
    long long x, y;
    long long a, b;
    long long tmp;
    while (~scanf("%lld%lld", &x, &y))
    {
        if (x == y)
        {
            printf("1\n0\n");
            continue;
        }
        if ((x ^ y) < x)
        {
            printf("1\n%lld\n", x ^ y);
            continue;
        }

        tmp = 1;
        while (tmp <= x)
        {
            tmp <<= 1;
        }
        tmp >>= 1;

        printf("2\n");
        b = tmp;
        a = (x - tmp) ^ y;
        printf("%lld %lld\n", a, b);
    }
    return 0;
}