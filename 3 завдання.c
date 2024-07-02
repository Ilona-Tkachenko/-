#include <stdio.h>

int countNumbers(int p) {
    if (p == 1) return 2; 

    int dp[p + 1][4];
    

    dp[1][0] = 1; 
    dp[1][1] = 0; 
    dp[1][2] = 1; 
    dp[1][3] = 0; 

    for (int i = 2; i <= p; i++) {
        dp[i][0] = dp[i - 1][2] + dp[i - 1][3];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][3] = dp[i - 1][2];
    }

    return dp[p][0] + dp[p][1] + dp[p][2] + dp[p][3];
}

int main() {
    int p;
    printf("Введіть кількість розрядів p (p ≤ 30): ");
    scanf("%d", &p);

    if (p > 30) {
        printf("Значення p повинно бути не більше 30.\n");
        return 1;
    }

    int result = countNumbers(p);
    printf("Кількість чисел з %d розрядів: %d\n", p, result);

    return 0;
}
