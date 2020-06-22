#include <stdio.h>

int main(void)
{
    int n, m, t, a, b;
    int i, j;
    scanf("%d%d", &t, &n);
    long long s[n][n];

    for (b = 0; b < t; b++) {
        scanf("%d\n", &m);
        

        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                scanf("%lld", &s[i][j]);
            }
        }

        int k = 1;
        int q = 1;
        if (m != 0) {
            printf("%lld ", s[m - 1][0]);
        }
        i = m - 1;
        j = 0;
        while (k < m) {

            if (k % 2 == 1) {
                printf("%lld ", s[i][j + 1]);
                j++;
                q = -1;

            } else {
                printf("%lld ", s[i - 1][j]);
                i--;
                q = 1;

            }

            for (a = 0; a < k; a++) {
                printf("%lld ", s[i + q][j + q]);
                i += q;
                j += q;
            }
            k++;
        }
        k--;
        while (k > 0) {

            if (k % 2 == 1) {
                printf("%lld ", s[i][j + 1]);
                j++;
                q = 1;

            } else {
                printf("%lld ", s[i - 1][j]);
                i--;
                q = -1;

            }
            for (a = 0; a < k - 1; a++) {
                printf("%lld ", s[i + q][j + q]);
                i += q;
                j += q;
            }
            k--;
        }
        printf("\n");

    }
    return 0;
}