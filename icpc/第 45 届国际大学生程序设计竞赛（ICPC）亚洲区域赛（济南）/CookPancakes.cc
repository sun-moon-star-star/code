#include <cstdio>
#include <algorithm>

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        printf("%d\n", std::max(2, (n * 2 + k - 1) / k));
    }
    return 0;
}