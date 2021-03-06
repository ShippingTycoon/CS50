Problem set https://cs50.harvard.edu/x/2020/psets/6/readability/


#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //get text input from user to grade
    string text = get_string("Text: ");

    float letters = 0;
    float words = 0;
    float scentences = 0;
    int n = 0;
    int i = 0;

    for (i = 0, n = strlen(text); i < n; i++) //counting the number of letters and words and scentences
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        //checking its an alphabetical character
        {
            letters ++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        //checking for end of scentence
        {
            scentences ++;
            words ++;
        }
        else if ((text[i] == ' ' && ((text[i - 1] >= 'a' && text[i - 1] <= 'z') || (text[i - 1] >= 'A' && text[i - 1] <= 'Z')))
        || ((text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ':' || text[i] == ';' || text[i] == '*' || text[i] == '/'
        || text[i] == ')')))
        //checking for end of word
        {
            words ++;
        }
    }

    float L = (letters * (100 / words));//average number of letters per 100 words

    float S = (scentences * (100 / words));//average number of scentences per 100 words

    int grade = (0.0588 * L - 0.296 * S - 15.8) + 0.5;//Coleman-Liau index formula
    //L is the average number of letters per 100 words in the text, S is the average number of scentences per 100 words

    if (grade >= 1 && grade < 16)//checking grade is above 1 and below 16
    {
        printf("Grade %i\n", grade);//output grade
    }
    else if (grade < 1)
    {
        printf("Before grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}
