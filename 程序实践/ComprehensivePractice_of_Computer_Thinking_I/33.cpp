#include <stdio.h>

void itob(int n, char s[], int b) {
    const char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i = 0, sign = n;

    if (b < 2 || b > 36) {
        s[0] = '\0';
        return;
    }

    if (n < 0) {
        n = -n;
    }

    do {
        s[i++] = digits[n % b];
        n /= b;
    } while (n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    // 反转字符串
    for (int j = 0; j < i / 2; j++) {
        char temp = s[j];
        s[j] = s[i - j -1];
        s[i - j -1] = temp;
    }
    s[i] = '\0';
}

int main() {
    int n, b;
    char s[100];

    scanf("%d %d", &n, &b);

    itob(n, s, b);

    printf("%s\n", s);

    return 0;
}