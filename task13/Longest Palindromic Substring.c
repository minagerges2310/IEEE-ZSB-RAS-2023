#include <stdio.h>
#include <string.h>

char * longestPalindrome(char * s){
    int n = strlen(s);
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int start = 0;
    int maxLen = 1;
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }
    
        for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0'; 
    return result;
}

int main() {
    char s[] = "aaaccdds";
    char* result = longestPalindrome(s);
    printf("%s\n", result); 
    free(result); 
    return 0;
}