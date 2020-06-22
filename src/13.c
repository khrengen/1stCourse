#include <stdio.h>

#define ZV_LETTERS (1u << ('b' - 'a') | 1u << ('v' - 'a') | 1u << ('g' - 'a') | 1u << ('d' - 'a') | 1u << ('z' - 'a'))
#define VOWELS (1u << ('a' - 'a') | 1u << ('i' - 'a') | 1u << ('e' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

int tolower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

unsigned int char_to_set(char c)
{
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

int is_spase(int c)
{
    return (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == ',');
}

int main(void)
{
    int c;
    unsigned int letters_set = 0;

    while ((c = getchar()) != EOF) {
        if (is_spase(c)) {
            if (((letters_set & ~VOWELS) & ~ZV_LETTERS) == 0 && letters_set != 0) {
                printf("Yes\n");
                return 0;
            }

            letters_set = 0;
        } else {
            letters_set = letters_set | char_to_set(c);
        }
    }
    printf("No\n");
    return 0;
}
