#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>

void init(int data[], int size)
{
    for (int i = 1; i <= size; i++) {
        data[i] = -1;
    }
}

void uniona(int a, int b, int data[], int size)
{
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int i = 1; i <= size; i++) {
        if (data[i] == b)
            data[i] = a;
    }
}

int main()
{
    int test_case;
    scanf("%d", &test_case);
    while (test_case--) {
        int criminals, messages;
        scanf("%d %d", &criminals, &messages);
        char input[10];
        fgets(input, 10, stdin);

        int data[criminals + 1];
        init(data, criminals);

        int group = 2;
        while (messages--) {
            char input[100] = {'\0'};
            fgets(input, 100, stdin);
            int a, b;
            char operation;

            operation = input[0];
            sscanf(input + 1, "%d %d", &a, &b);
            // printf("%c %d %d\n", operation, a, b);

            if (operation == 'D') {
                if (data[a] == -1 && data[b] == -1) {
                    data[a] = group++;
                    data[b] = group++;
                } else if (data[a] == -1 || data[b] == -1) {
                    if (data[a] != -1) {
                        if (data[a] % 2 == 0) {
                            data[b] = data[a] + 1;
                        } else {
                            data[b] = data[a] - 1;
                        }
                    } else {
                        if (data[b] % 2 == 0) {
                            data[a] = data[b] + 1;
                        } else {
                            data[a] = data[b] - 1;
                        }
                    }
                } else {
                    if (data[a] % 2 == 0 && data[b] % 2 == 0) {
                        uniona(data[a], data[b] + 1, data, criminals);
                        uniona(data[b], data[a] + 1, data, criminals);
                    } else if (data[a] % 2 == 0 && data[b] % 2 == 1) {
                        uniona(data[a], data[b] - 1, data, criminals);
                        uniona(data[a] + 1, data[b], data, criminals);
                    } else if (data[a] % 2 == 1 && data[b] % 2 == 0) {
                        uniona(data[b] + 1, data[a], data, criminals);
                        uniona(data[a] - 1, data[b], data, criminals);
                    } else {
                        uniona(data[b] - 1, data[a], data, criminals);
                        uniona(data[a] - 1, data[b], data, criminals);
                    }
                }
            } else {
                if (data[a] != -1 && data[b] != -1) {
                    if ((data[a] % 2 == 0 && data[b] == data[a] + 1) ||
                        (data[a] % 2 == 1 && data[b] == data[a] - 1))
                        printf("In different gangs.\n");
                    else if (data[a] == data[b])
                        printf("In the same gang.\n");
                    else
                        printf("Not sure yet.\n");
                } else {
                    printf("Not sure yet.\n");
                }
            }
        }
    }

    return 0;
}
