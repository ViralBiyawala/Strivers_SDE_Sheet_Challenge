#include <iostream>

int modularExponentiation(int x, int n, int m) {
    if (n == 0)
        return 1;

    long long result = 1;
    x = x % m;
    //doing x^n by "exponentiation by squaring"
    while (n > 0) {
        if (n % 2 == 1)
            result = (result * x) % m;

        x = (x * x) % m;
        n = n / 2;
    }

    return result;
}