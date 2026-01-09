#include <stdio.h>

int main() {
    int n, i, count;
    int A[10], Q[10], M[10];
    int Q_1 = 0;
    int carry, sum;
    int temp[10];

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter Multiplicand (M): ");
    for (i = 0; i < n; i++)
        scanf("%d", &M[i]);

    printf("Enter Multiplier (Q): ");
    for (i = 0; i < n; i++)
        scanf("%d", &Q[i]);

    // Initialize A = 0
    for (i = 0; i < n; i++)
        A[i] = 0;

    printf("\nA      Q      Q-1\n");
    printf("------------------\n");

    count = n;

    while (count > 0) {

        // Display current values
        for (i = 0; i < n; i++) printf("%d", A[i]);
        printf(" ");
        for (i = 0; i < n; i++) printf("%d", Q[i]);
        printf(" %d\n", Q_1);

        /* Check Q0 and Q-1 */
        if (Q[n - 1] == 1 && Q_1 == 0) {
            // A = A - M (2's complement)
            for (i = 0; i < n; i++)
                temp[i] = M[i] ^ 1;

            carry = 1;
            for (i = n - 1; i >= 0; i--) {
                sum = A[i] + temp[i] + carry;
                A[i] = sum % 2;
                carry = sum / 2;
            }
        }
        else if (Q[n - 1] == 0 && Q_1 == 1) {
            // A = A + M
            carry = 0;
            for (i = n - 1; i >= 0; i--) {
                sum = A[i] + M[i] + carry;
                A[i] = sum % 2;
                carry = sum / 2;
            }
        }

        /* Arithmetic Right Shift */
        Q_1 = Q[n - 1];

        for (i = n - 1; i > 0; i--)
            Q[i] = Q[i - 1];

        Q[0] = A[n - 1];

        for (i = n - 1; i > 0; i--)
            A[i] = A[i - 1];

        count--;
    }

    // Final Output
    for (i = 0; i < n; i++) printf("%d", A[i]);
    printf(" ");
    for (i = 0; i < n; i++) printf("%d", Q[i]);
    printf(" %d\n", Q_1);

    printf("\nFinal Result (A Q): ");
    for (i = 0; i < n; i++) printf("%d", A[i]);
    for (i = 0; i < n; i++) printf("%d", Q[i]);

    return 0;
}
