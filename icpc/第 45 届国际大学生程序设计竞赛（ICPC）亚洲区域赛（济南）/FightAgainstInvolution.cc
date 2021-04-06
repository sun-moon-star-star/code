#include <cstdio>
#include <algorithm>

struct A
{
    int l, r;
    bool inline const operator<(const A &other) const
    {
        if (r != other.r)
        {
            return r < other.r;
        }
        return l > other.l;
    }
} a[100000 + 10];

int main()
{
    int n, last, last2;
    long long ans;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &a[i].l, &a[i].r);
        }
        std::sort(a, a + n);
        ans = last = a[0].l;
        for (int i = 1; i < n; ++i)
        {
            last = std::max(last, a[i].l);
            ans += last;
        }
        printf("%lld\n", ans);
    }
    return 0;
}