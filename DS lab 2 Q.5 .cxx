#include <stdio.h>


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}

// Function to implement Chinese Remainder Theorem
int findMinX(int num[], int rem[], int k) {
    
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    
    int result = 0;

    // Apply the formula mentioned in the theorem
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}


int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1}; 
    int k = sizeof(num)/sizeof(num[0]);
    printf("The minimum number is %d", findMinX(num, rem, k));
    return 0;
}
