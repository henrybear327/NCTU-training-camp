#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char input1[100010], input2[100010], input3[100010];
    while (fgets(input1, 100010, stdin) != NULL &&
           fgets(input2, 100010, stdin) != NULL &&
           fgets(input3, 100010, stdin) != NULL) {
        input1[strlen(input1) - 1] = '\0';
        input2[strlen(input2) - 1] = '\0';
        input3[strlen(input3) - 1] = '\0';
        int count1[26] = {0};
        int count2[26] = {0};
        int count3[26] = {0};
        for (int i = 0; i < strlen(input1); i++) {
            count1[input[i] - 'a']++;
        }
        for (int i = 0; i < strlen(input2); i++) {
            count2[input[i] - 'a']++;
        }
        for (int i = 0; i < strlen(input3); i++) {
            count3[input[i] - 'a']++;
        }

        
    }

    return 0;
}