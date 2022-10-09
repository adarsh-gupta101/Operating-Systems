#include <stdio.h>

void main()
{
    int number, page[100], frames, i, k = 0, FR[10], flag, count=0;

    printf("Enter the number of pages: ");
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        printf("Enter the page number: ");
        scanf("%d", &page[i]);
    }
    printf("ENTER THE NUMBER OF FRAMES : ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
    {
        FR[i] = -1;
    }

    // print frames
    printf("\n\tREFERENCE STRING\t PAGE NUMBER\t\t  STATUS\n");

    // for (i = 0; i < frames; i++)
    // {
    //     printf("%d\t", FR[i]);
    // }

    for (i = 0; i < number; i++)
    {
        flag = 0;
        printf("\t\t%d\t\t", page[i]);

        for (int j = 0; j < frames; j++)
        {
            if (FR[j] == page[i])
            {
                flag = 1;
                // printf("HIT\n");
            }
        }
        if (flag == 0)
        {
            FR[k] = page[i];
            k = (k + 1) % frames;
            // count++;
        }

        for(int j=0;j<frames;j++)
		{
			if(FR[j] != -1)
			{
				printf("%d   ",FR[j]);
			}
		}
        if (flag == 1)
        {
            printf("\t\tHIT\n");
        }
        else
        {
            printf("\t\tMISS\n");
                        count++;

        }
    }

    // for (int j = 0; j < frames; j++)
    // {
    //     /* code */
    //     if (FR[j] == -1)
    //     {
    //         printf("-\t");
    //     }
    //     else
    //         printf("%d\t", FR[j]);
    // }

    printf("Page faults %d", count);
}