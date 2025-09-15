#include <stdio.h>

// Function to add two binary numbers represented as integers
long binaryAddition(long bin1, long bin2) {
    int i = 0, remainder = 0, sum[20]; 
    long result = 0;

    while (bin1 != 0 || bin2 != 0) {
        sum[i++] = (bin1 % 10 + bin2 % 10 + remainder) % 2;
        remainder = (bin1 % 10 + bin2 % 10 + remainder) / 2;
        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }

    if (remainder != 0) {
        sum[i++] = remainder;
    }

    --i; 

    while (i >= 0) {
        result = result * 10 + sum[i--];
    }
    return result;
}

// Function to subtract two binary numbers 
long binarySubtraction(long bin1, long bin2) {
    int i = 0, borrow = 0, diff[20];
    long result = 0;

    while (bin1 != 0 || bin2 != 0) {
        int bit1 = bin1 % 10;
        int bit2 = bin2 % 10;

        int sub = bit1 - bit2 - borrow;

        if (sub < 0) {
            sub = sub + 2;  // borrow from next higher bit
            borrow = 1;
        } else {
            borrow = 0;
        }

        diff[i++] = sub;

        bin1 = bin1 / 10;
        bin2 = bin2 / 10;
    }

    --i;

    while (i >= 0) {
        result = result * 10 + diff[i--];
    }
    return result;
}

// Main function
int main() {
    long bin1, bin2, sum, diff;

    printf("Enter the first binary number: ");
    scanf("%ld", &bin1);

    printf("Enter the second binary number: ");
    scanf("%ld", &bin2);

    sum = binaryAddition(bin1, bin2);
    printf("Sum of two binary numbers: %ld\n", sum);

    diff = binarySubtraction(bin1, bin2);
    printf("Difference of two binary numbers (bin1 - bin2): %ld\n", diff);

    return 0;
}
