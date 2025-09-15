#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    int a[100], b[100], sum[101], diff[100];

    cout << "Enter first binary number (" << n << " bits): ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Enter second binary number (" << n << " bits): ";
    for (int i = 0; i < n; i++) cin >> b[i];

    // ----- Addition -----
    int carry = 0;
    for (int i = n - 1; i >= 0; i--) {
        int s = a[i] + b[i] + carry;
        sum[i + 1] = s % 2;
        carry = s / 2;
    }
    sum[0] = carry;

    cout << "Addition result: ";
    for (int i = 0; i <= n; i++) cout << sum[i];
    cout << endl;

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

    cout << "Subtraction result: ";
    for (int i = 0; i < n; i++) {
        cout << diff[i];
    }
    cout << endl;

    return 0;
}

