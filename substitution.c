https://cs50.harvard.edu/x/2020/psets/2/substitution/


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    //check for command line argument
    if (argv[1] == 0)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    //iterate through chars in argv if alpha
    for (int a = 0; key[a] != '\0'; a ++)
    {
        if ((key[a] >= 'a' && key[a] <= 'z') || (key[a] >= 'A' && key[a] <= 'Z'))
        {
            //check no letters are repeated in 26 character key
            if (a > 0)
            {
                for (int b = -1; key[b + (strlen(key) - a + 2)] != '\0'; b ++)
                {
                    if (key[a] == toupper(key[b]) || key[a] == tolower(key[b]))
                    {
                        printf("Invalid command line argument\n");
                        return 1;
                    }
                }
            }

        }
        else
        {
            printf("Invalid command line argument\n");
            return 1;
        }
    }
    if (strlen(key) != 26)
    {
        printf("Invalid command line argument\n");
        return 1;
    }
    //get user input
    string p = get_string("plaintext: ");
    //start printing ciphertext
    printf("ciphertext: ");
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            for (int c = 0; c != 27; c++)
            {
                if (p[i] == alpha[c])
                {
                    printf("%c", tolower(key[c]));
                }
            }
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            for (int c = 0; c != 27; c++)
            {
                if (p[i] == toupper(alpha[c]))
                {
                    printf("%c", toupper(key[c]));
                }
            }
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}
