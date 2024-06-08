#include <stdio.h>


int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to solve the linear congruence equation ax ≡ b (mod m)
void solveLinearCongruence(int a, int b, int m) {
    int inverse = modInverse(a, m);
    
    if (inverse == -1) {
        printf("Linear congruence has no solution.\n");
    } else {
        // The solution is given by the formula x ≡ b * a^(-1) (mod m)
        int x = (inverse * b) % m;
        printf("The solution to the linear congruence is x ≡ %d (mod %d)\n", x, m);
    }
}

int main() {
    int a, b, m;
    
    
    printf("Enter values for a, b, and m(linear congruence equation ax ≡ b (mod m) : ");
    scanf("%d %d %d", &a, &b, &m);
    
    
    solveLinearCongruence(a, b, m);
    
    return 0;
}
