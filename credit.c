#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    int visa;
    int amex;
    int mastercard;
    long card_number;
    int nd;
       long a;
    long b;
    long c;
    long d;
    long e;
    long f;
    long g;
    long h;
    long i;
    long j;
    long k;
    long l;
    long m;
    long n;
    long o;
    long p;
    long thing;
    
    do
    {
    card_number = get_long("Number: ");
    nd = (floor ( log10 ( card_number)) + 1);
        }
    while (card_number <= 0 || nd < 13 || nd == 14 || nd > 16);
    
    thing = pow(10, (nd-1));
    
    if (nd == 13)
    {    
        a = card_number / thing;
            card_number = card_number - (a * thing);
            thing = thing/10;
        b = card_number / (thing);
             card_number = card_number - (b* thing);
             thing = thing/10;
        c = card_number / thing;
              card_number = card_number - (c * thing);
        thing = thing/10;
        d = card_number / thing;
             card_number = card_number - (d * thing);
        thing = thing/10;
        e = card_number / thing;
             card_number = card_number - (e * thing);
        thing = thing/10;
        f = card_number / thing;
             card_number = card_number - (f * thing);
        thing = thing/10;
        g = card_number / thing;
             card_number = card_number - (g * thing);
        thing = thing/10;
        h = card_number / thing;
             card_number = card_number - (h * thing);
        thing = thing/10;
        i = card_number / thing;
             card_number = card_number - (i * thing);
        thing = thing/10;
        j = card_number / thing;
             card_number = card_number - (j * thing);
        thing = thing/10;
        k = card_number / thing;
             card_number = card_number - (k * thing);
        thing = thing/10;
        l = card_number / thing;
             card_number = card_number - (l * thing);
        m = card_number;
        
        
        
        if (((((l*2)/10) + ((l*2)%10) + ((j*2)/10) + ((j*2)%10) + ((h*2)/10) + ((h*2)%10) + ((f*2)/10) + ((f*2)%10) + ((d*2)/10) + ((d*2)%10) + ((b*2)/10) + ((b*2)%10) + a + c + e + g + i + k + m) % 10) == 0)
        {
            if (a == 4)
            {
            printf("VISA\n");
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
  
    
     else if (nd == 15)
    {    
        a = card_number / thing;
            card_number = card_number - (a * thing);
            thing = thing/10;
        b = card_number / (thing);
             card_number = card_number - (b* thing);
             thing = thing/10;
        c = card_number / thing;
              card_number = card_number - (c * thing);
        thing = thing/10;
        d = card_number / thing;
             card_number = card_number - (d * thing);
        thing = thing/10;
        e = card_number / thing;
             card_number = card_number - (e * thing);
        thing = thing/10;
        f = card_number / thing;
             card_number = card_number - (f * thing);
        thing = thing/10;
        g = card_number / thing;
             card_number = card_number - (g * thing);
        thing = thing/10;
        h = card_number / thing;
             card_number = card_number - (h * thing);
        thing = thing/10;
        i = card_number / thing;
             card_number = card_number - (i * thing);
        thing = thing/10;
        j = card_number / thing;
             card_number = card_number - (j * thing);
        thing = thing/10;
        k = card_number / thing;
             card_number = card_number - (k * thing);
        thing = thing/10;
        l = card_number / thing;
             card_number = card_number - (l * thing);
           thing = thing/10;
        m = card_number / thing;
             card_number = card_number - (m * thing);
           thing = thing/10;
        n = card_number / thing;
             card_number = card_number - (n * thing);
           thing = thing/10;
        o = card_number / thing;
         
         if (((((n*2)/10) + ((n*2)%10) + ((l*2)/10) + ((l*2)%10) + ((j*2)/10) + ((j*2)%10) + ((h*2)/10) + ((h*2)%10) + ((f*2)/10) + ((f*2)%10) + ((d*2)/10) + ((d*2)%10) + ((b*2)/10) + ((b*2)%10) + a + c + e + g + i + k + m + o) % 10) == 0)
        {
             if ((a == 3 && b == 4) || (a ==3 && b == 7))
             {
            printf("AMEX\n");
             }
             else
             {
                 printf("INVALID");
             }
          
        }
        else 
         
        {
         
            printf("INVALID\n");
             
        }
        
    }
    
    
       else if (nd == 16)
    {    
       a = card_number / thing;
            card_number = card_number - (a * thing);
            thing = thing/10;
        b = card_number / (thing);
             card_number = card_number - (b* thing);
             thing = thing/10;
        c = card_number / thing;
              card_number = card_number - (c * thing);
        thing = thing/10;
        d = card_number / thing;
             card_number = card_number - (d * thing);
        thing = thing/10;
        e = card_number / thing;
             card_number = card_number - (e * thing);
        thing = thing/10;
        f = card_number / thing;
             card_number = card_number - (f * thing);
        thing = thing/10;
        g = card_number / thing;
             card_number = card_number - (g * thing);
        thing = thing/10;
        h = card_number / thing;
             card_number = card_number - (h * thing);
        thing = thing/10;
        i = card_number / thing;
             card_number = card_number - (i * thing);
        thing = thing/10;
        j = card_number / thing;
             card_number = card_number - (j * thing);
        thing = thing/10;
        k = card_number / thing;
             card_number = card_number - (k * thing);
        thing = thing/10;
        l = card_number / thing;
             card_number = card_number - (l * thing);
           thing = thing/10;
        m = card_number / thing;
             card_number = card_number - (m * thing);
           thing = thing/10;
        n = card_number / thing;
             card_number = card_number - (n * thing);
           thing = thing/10;
        o = card_number / thing;
             card_number = card_number - (o * thing);
        p = card_number;
           
           if (((((o*2)/10) + ((o*2)%10) + ((m*2)/10) + ((m*2)%10) + ((k*2)/10) + ((k*2)%10) + ((i*2)/10) + ((i*2)%10) + ((g*2)/10) + ((g*2)%10) + ((e*2)/10) + ((e*2)%10) + ((c*2)/10) + ((c*2)%10) + ((a*2)/10) + ((a*2)%10) + b + d + f + h + j + l + n + p) % 10) == 0)
        {
               if (a == 4)
               {
            printf("VISA\n");
               }
               else if (a == 5 && ((b == 1) || (b = 2) || (b = 3) || (b = 4) || (b = 5)))
               {
                   printf("MASTERCARD\n");
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
    
    
    
    
}
    

