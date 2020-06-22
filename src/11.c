#include <stdio.h>

typedef enum {NUMBER, SIGN, SPACE, OTHER, ifC} State;



int is_digit(char n)
{
    return (n >= '0' && n <= '9');
}

int is_sign(char n)
{
    return (n == '+' || n == '-');
}

int is_space(char n)
{
    return (n == ' ' || n == '\n' || n == ';');
}


int C(char n)
{
    return (n == 'C');
}

long long roundF(long long a)
{
    return (((a * 9) % 5) <= 2 ? a * 9 / 5 : a * 9 / 5 + 1);
}

int main(void)
{
    char c;
    long long l = 0;
    long long k = 0;
    int j = 1;
    State St = SPACE;
    do {
        c = getchar();
        switch (St) {
            case SIGN:
                if (is_space(c)) {
                    if (c == '\n') {
                        printf("\n");
                    }
                    St = SPACE;
                    j = 1;
                } else if (is_digit(c)) {
                    l = c - '0';
                    St = NUMBER;
                } else {
                    St = OTHER;
                    j = 1;
                }
                break;
            case SPACE:
                if (is_digit(c)) {
                    l = c - '0';
                    St = NUMBER;
                } else if (is_sign(c)) {
                    if (c == '-') {
                        j = -1;
                    }
                    if (c == '+') {
                        j = 1;
                    }
                    St = SIGN;
                } else {
                    St = OTHER;
                }
                break;
            case NUMBER:
                if (is_digit(c)) {
                    l = l * 10 + (c - '0');
                }
                if (is_space(c)) {
                    if (c == '\n') {
                        printf("\n");
                    }
                    St = SPACE;
                    l = 0;
                    j = 1;
                }
                if (C(c)) {
                    St = ifC;
                    k = l;
                } else if (!is_digit(c) && !is_space(c)) {
                    St = OTHER;
                    l = 0;
                    j = 1;
                }
                break;
            case ifC:
                if (is_space(c)) {
                    k = roundF(k) * j + 32;
                    if (c == '\n') {
                        printf("%lldF\n", k);
                    } else {
                        printf("%lldF ", k);
                    }
                    j = 1;
                    St = SPACE;
                } else {
                    St = OTHER;
                    k = 0;
                    j = 1;
                }
                break;
            case OTHER:
                if (is_space(c)) {
                    if (c == '\n') {
                        printf("\n");
                    }
                    St = SPACE;
                }
                break;
        }
    } while (c != EOF);
    printf("\n");
    return 0;
}