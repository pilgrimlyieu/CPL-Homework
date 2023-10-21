#include <stdio.h>

int main(void) {
    int sodoku[81], error = 0, middles[9] = { 10, 13, 16, 37, 40, 43, 64, 67, 70 };
    for (int i = 0; i < 81; i++) {
        scanf("%d", &sodoku[i]);
    }
    for (int i = 0; i < 9; i++) {
        int nums[9] = { 0 };
        for (int j = i; j < 81; j += 9) {
            nums[sodoku[j] - 1]++;
        }
        for (int j = 0; j < 9; j++) {
            if (nums[j] != 1) {
                error = 1;
                break;
            }
        }
    }
    for (int i = 0; i < 81; i += 9) {
        int nums[9] = { 0 };
        for (int j = i; j < i + 9; j++) {
            nums[sodoku[j] - 1]++;
        }
        for (int j = 0; j < 9; j++) {
            if (nums[j] != 1) {
                error = 1;
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        int sum = sodoku[middles[i] - 10] + sodoku[middles[i] - 9] + sodoku[middles[i] - 8] + sodoku[middles[i] - 1] + sodoku[middles[i]] + sodoku[middles[i] + 1] + sodoku[middles[i] + 8] + sodoku[middles[i] + 9] + sodoku[middles[i] + 10];
        int product = sodoku[middles[i] - 10] * sodoku[middles[i] - 9] * sodoku[middles[i] - 8] * sodoku[middles[i] - 1] * sodoku[middles[i]] * sodoku[middles[i] + 1] * sodoku[middles[i] + 8] * sodoku[middles[i] + 9] * sodoku[middles[i] + 10];
        if (sum != 45 || product != 362880) {
            error = 1;
            break;
        }
    }
    printf("%s", error ? "NO" : "YES");
    return 0;
}