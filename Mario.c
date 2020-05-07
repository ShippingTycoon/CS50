// Problem set = https://cs50.harvard.edu/x/2020/psets/1/mario/more/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;

    // Get height from user
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Print out pyramid
    for (int i = 0; i < h; i++)
    {
        // Number of spaces needed to come before hash
        for (int spaces = (h - 1); spaces > i; spaces--)
        {
            printf(" ");
        }

        // Number of hashes to print
        for (int first = 0; first <= i; first++)
        {
            printf("#");
        }

        // Space in the middle
        printf("  ");

        // Hashes on other side
        for (int third = 0; third <= i; third++)
        {
            printf("#");
        }
        printf("\n");
    }

}
