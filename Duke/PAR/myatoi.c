#include <stdio.h>
#include <stdlib.h>

int myatoi(const char * str);
int myatoiHex(const char * str);
int mystrtol(const char * str, const char ** endstr, int base);

int main(void) {
    char * str = NULL;
    const char  ** endstr = &(str);
    printf("This is CS%i\n", myatoi("      50AB"));
    printf("This is CS%i\n", myatoiHex("      32gg"));
    printf("This is %i\n", mystrtol("   11abcFkka", endstr, 16));
    printf("%s\n", *endstr);
    return EXIT_SUCCESS;
}

int myatoi(const char * str) {
    int result = 0;
    while (*str == 32) {
        str++;
    }
    while(*str >= '0' && *str <='9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result;
}

int myatoiHex(const char * str) {
    int result = 0;
    while (*str == 32) {
        str++;
    }
    while(1) {
        if (*str >= '0' && *str <='9') {
            result = result * 16 + (*str - '0');
            str++;
        } else if (*str >= 'A' && *str <='F') {
            result = result * 16 + (*str - 'A') + 10;
            str++;
        } else if (*str >= 'a' && *str <='f') {
            result = result * 16 + (*str - 'a') + 10;
            str++;
        } else {
            return result;
        }
    }
    return result;
}

int mystrtol(const char * str, const char ** endstr, int base) {
    int result = 0;
    while (*str == 32) {
        str++;
    }

    if (base == 16 || base == 0 ) {
        if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X')) {
            str++;
            str++;
            base = 16;
        }

        if (*str == '0' && *(str + 1) >= '0' && *(str + 1) <= '9') {
            str++;
            base = 8;
        }
    }

    if (base == 0 && *str != 0) {
        base = 10;
    }

    while(1) {
        if (*str >= '0' && *str <='9') {
            result = result * base + (*str - '0');
            str++;
        } else if (*str >= 'A' && *str <=('A' + base - 11)) {
            result = result * base + (*str - 'A') + 10;
            str++;
        } else if (*str >= 'a' && *str <=('a' + base -11)) {
            result = result * base + (*str - 'a') + 10;
            str++;
        } else {
            return result;
        }
    }

    *endstr = str;
    return result;
}
