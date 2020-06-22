#include <stdio.h>
#include <limits.h>

int main(void)
{
    int  n, m, t, a;
    int i, j;
    scanf("%d%d", &t, &n);
    long long s[n][n];

    for (a = 0; a < t; a++) {
        scanf("%d", &m);
        

        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                scanf("%lld", &s[i][j]);
            }
        }
        long long max = LLONG_MIN, min = LLONG_MAX, maxik;
        int k = 0, l = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                if (s[i][j] < min) {
                    min = s[i][j];
                    k = i;
                }

                if (s[j][i] > max) {
                    max = s[j][i];
                    l = i;
                }

            }
        
        }
        long long q = 0;
        for (i = 0; i < m; i++) {
            
            q += s[k][i] * s[i][l];
        }
        printf("%lld\n", q);
        q = 0;
    }

    return 0;
}