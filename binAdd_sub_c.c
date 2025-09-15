#include <stdio.h>

int main() {
    int n;
    printf("Enter number of bits: ");
    scanf("%d", &n);

    int a[100], b[100], sum[101], diff[100];

    printf("Enter first binary number (%d bits): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter second binary number (%d bits): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    // ----- Addition -----
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int s = a[i] + b[i] + carry;
        sum[i + 1] = s % 2;
        carry = s / 2;
    }
    sum[0] = carry;

    printf("Addition result: ");
    for (int i = 0; i <= n; i++)
        printf("%d", sum[i]);
    printf("\n");

    // ----- Subtraction (a - b) -----
    int borrow = 0;
    for (int i = n - 1; i >= 0; i--) {
        int d = a[i] - borrow - b[i];
        if (d < 0) {
            d += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        diff[i] = d;
    }

    printf("Subtraction result: ");
    for (int i = 0; i < n; i++)
        printf("%d", diff[i]);
    printf("\n");

    return 0;
}
