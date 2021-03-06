Problem from https://cs50.harvard.edu/x/2020/psets/2/caesar/


#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argv[1] == 0)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    int k;
    string key = (argv[1]);
    //check the command line argument is an integer
    for (int a = 0; argv[1][a] != '\0'; a++)
    {
        if (argv[1][a] >= '0' && argv[1][a] <= '9')
        {
            k = atoi(key);
        }
        else
        {
            printf("Command-line argument must be integer\n");
            return 1;
        }
    }
    if (argv[2] > 0)
    {
        printf("Command-line argument must be integer\n");
        return 1;
    }
    if (argc == 2)//checks if the user has specified the cypher key in the command prompt
    {//need to check if the user isn't cooperating



    string p = get_string("plaintext: ");// asks user for plaintext
    printf("ciphertext: ");// begins output

    //run through chars in p until end of string
    for (int i = 0; p[i] != '\0'; i ++)
    {
        int c;
        char ct;
        int r = 1;
        //check if p[i] is alpha and lower case
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            c = (p[i] + k);
            //check if cyphertext is now outside of alpha lower values
            if (c > 'z')
            {
                //get the remainder after you've added the cypher to p[i]
                //take the value of 'z' away from p[i] then mod 26 to get remainder
                r = (c - 122) % 26;
                //new vairable for cyphertext as c is type int
                ct = 'a' + (r - 1);
            }
            else
            {
                ct = (p[i] + k);
            }

        }
        if (p[i] >= 'A' && p[i] <= 'Z')
        {
            c = (p[i] + k);
            //check if cyphertext is now outside of alpha lower values
            if (c > 'Z')
            {
                //get the remainder after you've added the cypher to p[i]
                //take the value of 'Z' away from p[i] then mod 26 to get remainder
                r = (c - 90) % 26;
                //new vairable for cyphertext as c is type int
                ct = 'A' + (r - 1);
            }
            else
            {
                ct = (p[i] + k);
            }
        }
        if (p[i] < 'A' || (p[i] > 'Z' && p[i] < 'a') || p[i] > 'z')
        {
            ct = p[i];
        }
        printf("%c", ct);
        k = atoi(key);
    }
    }
    printf("\n");
    return 0;
}
