#include <stdio.h>

#define ZV_LETTERS (1u << ('b' - 'a') | 1u << ('v' - 'a') | 1u << ('g' - 'a') | 1u << ('d' - 'a') | 1u << ('z' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') | 1u << ('n' - 'a') | 1u << ('r' - 'a'))
#define VOWELS (1u << ('a' - 'a') | 1u << ('i' - 'a') | 1u << ('e' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

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
    return (c == ' ' || c == ',' || c == '\n' || c == EOF || c == '\t') ? 1 : 0;
}

int main(void)
{
    int c;
    unsigned int letters_set = 0;

    do {
        c = getchar();
        if (is_spase(c)) {
            if (((letters_set & ~VOWELS) & ~ZV_LETTERS) == 0 && (letters_set & ~VOWELS) != 0) {
                printf("Yes\n");
                return 0;
            }
            letters_set = 0;
        } else {
            letters_set = letters_set | char_to_set(c);
        }
    } while (c != EOF);
    printf("No\n");
    return 0;
}