#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
float change;
int changeb;
int q;
int d;
int n;
int p;
int min_coins;
    
do 

    change = get_float("Change owed: $");

while (change <= 0);
    
    changeb = (int)  (change * 100);

    do
    {
        (q = changeb / 25);  
        (changeb = changeb % 25); 
    }
    while (changeb >= 25);
    
    do
    {
        (d = changeb / 10);
        (changeb = changeb % 10);
    }
    while (changeb >= 10);
    
    do
    {
        (n = changeb / 5);
        (changeb = changeb % 5);
    }
    while (changeb >= 5);
    
    do
    { 
        (p = changeb / 1);
        (changeb = changeb % 1);
    }
    while (changeb >= 1);
    
    (min_coins = q + d + n + p);
        
    printf("The minimum nuber of coins is %i\n", min_coins);
}
