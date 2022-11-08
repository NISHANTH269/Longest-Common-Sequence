#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char s1[100], s2[100];
char r[100][100] = { 0 };
char f[100][100] = { 0 }; ///Will f the array to track the similar CHAR.
void LCS(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                r[i][j] = r[i - 1][j - 1] + 1;
                f[i][j] = 1; //To find similar elements.

            }
            else if (r[i][j - 1] > r[i - 1][j]) { //compare elements in the right side with above.
                r[i][j] = r[i][j - 1];
                f[i][j] = -1;
            }
            else {
                r[i][j] = r[i - 1][j];
                f[i][j] = 2;
            }
        }
    }
}
void track_LCS(int n, int m) {
    char result[20];
    int k = 0; //To preserve the result.
    while (n > 0 && m > 0) {
        if (f[n][m] == 1) {
            result[k] = s1[n - 1];
            k++;
            n--;
            m--;
        }
        else if (f[n][m] == -1)
            m--;
        else if (f[n][m] == 2)
            n--;
    }
    for (n = k - 1; n >= 0; n--) {
        printf("%c", result[n]);
    }
}
int main() {
    //String 1 input
    strcpy_s(s1, "Computer Engineering");
    printf("String 1: Computer Engineering\n");
    //String 2 input
    strcpy_s(s2, "Electrical and Electronics Engineering");
    printf("String 2: Electrical and Electronics Engineering\n");
    LCS(strlen(s1), strlen(s2)); //String is fetched to LCS
    printf("LCS Length: ");
    printf("%d\n", r[strlen(s1)][strlen(s2)]);
    printf("LCS: ");
    track_LCS(strlen(s1), strlen(s2));
    return 0;
}


