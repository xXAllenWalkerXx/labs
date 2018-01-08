#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    float a,n;
    char b;

    if (argc <= 1) return 0;
    sscanf(argv[1], "%f", &a);
    if (argc == 3) b = argv[2][0];
    else if (argc == 2)
    {
        n = a;
    }
            if (argc ==3)
            {
              b = (char)tolower(b);
              switch (b)
               {
                case 'c':
                {
                if (a>-273.15)
                    {
                    printf("%.2fF ", (a*9)/5+32 );
                    printf("%.2fK\n", a+273 );
                    }
                else
                    printf ("The temperature is equal to absolute zero\n");
                break;
                }
                case 'f':
                {
                if(a > -459.67)
                    {
                    printf("%.2fC ", (a-32)*5/9 );
                    printf("%.2fK\n", (a-32)*5/9+273 );
                    }
                else
                    printf ("The temperature is equal to absolute zero\n");
                }
                break;
                case 'k':
                {
                if (a>=0)
                    {
                    printf("%.2fC ", a-273 );
                    printf("%.2fF\n", (a-273)*9/5+32 );
                    }
                else
                    printf ("The temperature is equal to absolute zero\n");
                }
                break;
               }
            }

            else if (argc == 2)
            {
                if (n >-273.15)
                {
                    printf("%.2fC\n", n);
                    printf(" %.2fF ", (n*9)/5+32 );
                    printf("%.2fK\n", n+273 );
                }
                else
                    printf ("C = The temperature is equal to absolute zero\n");
                if(n > -459.67)
                {
                    printf("%.2fF\n ", n);
                    printf("%.2fC ", (n-32)*5/9 );
                    printf("%.2fK\n", (n-32)*5/9+273 );
                }
                else
                    printf ("F = The temperature is equal to absolute zero\n");
                if (n>=0)
                {
                    printf("%.2fK\n ", n);
                    printf("%.2fC ", n-273 );
                    printf("%.2fF\n", (n-273)*9/5+32 );
                }
                else
                    printf ("K = The temperature is equal to absolute zero\n");
            }

return 0;
}
