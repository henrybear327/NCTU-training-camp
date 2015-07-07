#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    char input1[100010], input2[100010], input3[100010];
    fgets(input1, 100010, stdin);
    fgets(input2, 100010, stdin);
    fgets(input3, 100010, stdin);
    if (input1[strlen(input1) - 1] == '\n')
        input1[strlen(input1) - 1] = '\0';
    if (input2[strlen(input2) - 1] == '\n')
        input2[strlen(input2) - 1] = '\0';
    if (input3[strlen(input3) - 1] == '\n')
        input3[strlen(input3) - 1] = '\0';

    int count1[26] = {0};
    int count2[26] = {0};
    int count3[26] = {0};
    for (int i = 0; i < (int)strlen(input1); i++) {
        count1[input1[i] - 'a']++;
    }
    for (int i = 0; i < (int)strlen(input2); i++) {
        count2[input2[i] - 'a']++;
    }
    for (int i = 0; i < (int)strlen(input3); i++) {
        count3[input3[i] - 'a']++;
    }

    int max_i = 0, max_j = 0, total = 0, flag = 1;
    for (int i = 0;; i++) {
        int temp_max_j = 1000000;
        for (int j = 0; j < 26; j++) {
            if (i * count2[j] > count1[j]) {
                flag = 0;
                break;
            }

            if (count3[j]) {
                temp_max_j = MIN(temp_max_j, (count1[j] - i * count2[j]) / count3[j]);
            }
        }

        if (flag == 0)
            break;
        /* wrong!
        int temp = 0;
        for (int j = 0; j < 26; j++) {
            temp += (i * count2[j] + temp_max_j * count3[j]);
        }
        */
        if (i + temp_max_j > total) {
            total = i + temp_max_j;
            max_i = i;
            max_j = temp_max_j;
        }
    }

    for (int i = 0; i < max_i; i++)
        printf("%s", input2);
    for (int i = 0; i < max_j; i++)
        printf("%s", input3);
    for (int i = 0; i < 26; i++) {
        count1[i] -= (count2[i] * max_i + count3[i] * max_j);
        for (int j = 0; j < count1[i]; j++)
            printf("%c", i + 'a');
    }
    printf("\n");

    return 0;
}