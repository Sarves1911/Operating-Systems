// Least Recently used Page Replacement Algorithm
#include <stdio.h>
#define MAX 100

int main()
{
    int numberofpages, numberofframes, page_faults = 0;

    int pages[MAX], frame[MAX], counter[MAX];

    printf("Enter the number of pages: ");

    scanf("%d", &numberofpages);

    printf("Enter the page sequence: ");

    for (int i = 0; i < numberofpages; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");

    scanf("%d", &numberofframes);

    for (int i = 0; i < numberofframes; i++)
    {
        frame[i] = -1;
        counter[i] = 0;
    }

    int j = 0;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < numberofpages; i++)
    {
        printf("%d\t", pages[i]);
        int flag = 0;
        for (int k = 0; k < numberofframes; k++)
        {
            if (frame[k] == pages[i])
            {
                flag = 1;
                counter[k] = 0;
                break;
            }
        }
        if (flag == 0)
        {
            int pos = 0, max = counter[0];
            for (int k = 1; k < numberofframes; k++)
            {
                if (counter[k] > max)
                {
                    max = counter[k];
                    pos = k;
                }
            }
            frame[pos] = pages[i];
            counter[pos] = 0;
            page_faults++;
        }
        for (int k = 0; k < numberofframes; k++)
        {
            if (frame[k] != -1)
            {
                printf("%d\t", frame[k]);
                counter[k]++;
            }
        }
        printf("\n");
    }

    printf("\nTotal page faults: %d", page_faults);
    return 0;
}
