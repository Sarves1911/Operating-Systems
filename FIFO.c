// Page replacement Algorithm
#include <stdio.h>

#define MAX_PAGES 100

int main()
{
    int pages[MAX_PAGES], frame_size, num_pages, num_faults = 0, next_frame = 0;

    printf("Enter the number of pages: ");

    scanf("%d", &num_pages);

    printf("Enter the page references:\n");

    for (int i = 0; i < num_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");

    scanf("%d", &frame_size);

    int frames[frame_size];

    for (int i = 0; i < frame_size; i++)
    {
        frames[i] = -1; // initialize all frames to -1 to indicate they are empty
    }
    for (int i = 0; i < num_pages; i++)
    {
        int page = pages[i];
        int hit = 0;
        for (int j = 0; j < frame_size; j++)
        {
            if (frames[j] == page)
            {
                hit = 1;
                break;
            }
        }
        if (hit == 0)
        {
            frames[next_frame] = page;
            next_frame = (next_frame + 1) % frame_size; // wrap around to the beginning of the frames array
            num_faults++;
        }
        printf("Page %d: ", page);

        for (int j = 0; j < frame_size; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }
    printf("Number of page faults: %d\n", num_faults);

    return 0;
}
