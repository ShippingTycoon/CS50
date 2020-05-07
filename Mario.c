// Problem set = https://cs50.harvard.edu/x/2020/psets/1/mario/more/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
        
       do
             
        h = get_int("Height: ");
    
    while (h <1 || h > 8);        
    
    for (int i = 0; i < h; i++)
    {
        for (int spaces = (h - 1); spaces > i; spaces--)
        {
            printf(".");
        }
        
        for (int first = 0; first <= i; first++)
        {
            printf("#");
        }
   
        printf(" ");
 
    for (int third = 0; third <= i; third++)
    {
        printf("#");
    }
    printf("\n");
    }   
    
   
    
}
