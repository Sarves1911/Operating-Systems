// Optimal Page Replacement Algorithm
#include <stdio.h>
#define MAX 50

int main()
{
    int n, m, i, j, k, page_faults = 0;

    int pages[MAX], frames[MAX], temp[MAX];

    printf("Enter number of pages: ");

    scanf("%d", &n);

    printf("Enter the reference string: ");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");

    scanf("%d", &m);

    for (i = 0; i < m; i++)
        frames[i] = -1;

    for (i = 0; i < n; i++)
    {
        int flag = 0;
        for (j = 0; j < m; j++)
        {
            if (frames[j] == pages[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            int min = MAX, max = -1, pos = -1;
            for (j = 0; j < m; j++)
            {
                int temp = 0;
                for (k = i + 1; k < n; k++)
                {
                    if (frames[j] == pages[k])
                    {
                        temp = k;
                        break;
                    }
                }
                if (temp == 0)
                {
                    pos = j;
                    break;
                }
                else
                {
                    if (temp > max)
                    {
                        max = temp;
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            page_faults++;
        }
        printf("Page frames: ");

        for (j = 0; j < m; j++)
            printf("%d\t", frames[j]);
        printf("\n");
    }

    printf("Total number of page faults: %d", page_faults);

    return 0;
}
