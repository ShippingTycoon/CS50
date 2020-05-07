# Problem set = https://cs50.harvard.edu/x/2020/psets/1/credit/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    long card_number;
    int number_digits = 0;

    // Count number of digits
    card_number = get_long("Number: ");
    long number = card_number;
    while (number != 0)
    {
        number = number / 10;
        number_digits ++;
    }

    if (number_digits == 13 || (number_digits > 14 && number_digits < 17))
    {
        // Initialise number array
        int num_array[number_digits];

        int new_number;

        // Populate number array
        for (int i = 1; i <= number_digits; i ++)
        {
            new_number = card_number / pow(10, (number_digits - i));
            num_array[i - 1] = new_number;
            card_number -= new_number * pow(10, (number_digits - i));
        }

        // Luhn algorithm function

        // Populate array with every other number multiplied by 2, separated out into individual digits
        int step1[number_digits];
        for (int i = 0; i < number_digits; i++)
        {
            step1[i] = 0;
        }
        int number_digits2;
        int j = 0;
        for (int i = number_digits - 2; i >= 0; i -= 2)
        {
            int tmp = (num_array[i] * 2);

            // Separate new number into individual numbers
            if (tmp >= 10)
            {
                step1[j] = 1;
                step1[j + 1] = tmp - 10;
                j += 2;
            }
            else if (tmp < 10)
            {
                step1[j] = tmp;
                j ++;
            }
        }

        int step2 = 0;
        // Add numbers in step1 array together
        for (int i = 0; i < number_digits; i ++)
        {
            step2 += step1[i];
        }

        // Add the digits from the input number that werent multiplied by two
        int step3 = 0;

        for (int i = number_digits - 1; i >= 0; i -= 2)
        {
            step3 += num_array[i];
        }

        // Add step2 to step3
        int step4 = step2 + step3;

        // Check if number ends in 0
        int step5 = step4 % 10;

        // Check for card type
        if (step5 == 0)
        {
            if (num_array[0] == 3 && (num_array[1] == 4 || num_array[1] == 7) && number_digits == 15)
            {
                printf("AMEX\n");
                return 0;
            }
            else if (num_array[0] == 5 && (num_array[1] == 1 || num_array[1] == 2 || num_array[1] == 3 || num_array[1] == 4
                                           || num_array[1] == 5) && number_digits == 16)
            {
                printf("MASTERCARD\n");
                return 0;
            }
            else if (num_array[0] == 4 && (number_digits == 13 || number_digits == 16))
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
