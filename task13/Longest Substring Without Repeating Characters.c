#include <string.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s){
int n = strlen(s);
    int ans = 0;
    int index[128] = {0};
    for (int j = 0, i = 0; j < n; j++) {
        i = fmax(index[s[j]], i);
        ans = fmax(ans, j - i + 1);
        index[s[j]] = j + 1;
    }
    return ans;
}

int main(){
    int test = lengthOfLongestSubstring("pwwkew");
    printf("%d\n", test);
    return 0;
}