#include <stdio.h>
#include <string.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int count_anagrams(char *word) {
    int len = strlen(word);
    int freq[256] = {0};

    for (int i = 0; i < len; i++) {
        freq[(int)word[i]]++;
    }

    int total_anagrams = factorial(len);
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            total_anagrams /= factorial(freq[i]);
        }
    }

    return total_anagrams;
}

int main() {
    char word[15];
    scanf("%s", word);
    int result = count_anagrams(word);
    printf("%d\n", result);
    return 0;
}
