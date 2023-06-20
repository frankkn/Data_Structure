#include <stdio.h>
#define ll long long
ll a[(int)1e5+3];

int binarySearch(int L, int R, ll x) {
    while (L < R) {
        int M = L + (R - L) / 2;
        if (a[M] <= x)
            R = M;
        else
            L = M + 1;
    }
    return R;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);

    for (int i = 0; i < m; ++i) {
        ll q;
        scanf("%lld", &q);
        int idx = binarySearch(0, n, q);
        if (a[idx] != q)
            printf("N");
        else
            printf("Y");

        if (i != m - 1)
            printf(" ");
        else
            printf("\n");
    }

    return 0;
}
