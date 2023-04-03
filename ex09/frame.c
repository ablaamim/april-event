#include <stdio.h>
int longest_line(char **av)
{
    int i = 0;
    int n = 0;
    int j = 0;
    while(av[1][i] != '\0')
    {
        while(av[1][i] != ' ' && av[1][i] != '\0')
        {
            i++;
            n++;
        }
        while(av[1][i] == ' ' && av[1][i] != '\0')
            i++;
        if(n > j)
            j = n;
        n = 0;
    }
    return j;
}
int main(int ac, char **av)
{
    int i = 0;
    int n = 0;
    int j = 0;
    int x = 0;
    if(ac == 2)
    {
        i = longest_line(av);
        while(j  < i + 4)
        {
            printf("*");
            j++;
        }
        printf("\n");
        j = 0;
        while(av[1][j] != '\0')
        {
            x = 0;
            n = 0;
            printf("* ");
            while(av[1][j] != ' ' && av[1][j] != '\0')
            {
                printf("%c", av[1][j]);
                j++;
                x++;
            }
            if(av[1][j] == ' ' && av[1][j] != '\0')
            {
                while(n < i - x + 1)
                {
                    printf(" ");
                    n++;
                }
                // printf("%d %d", n, x);
                printf("*\n");
                j++;
            }
        }
        while(n < i - x + 1)
        {
            printf(" ");
            n++;
        }
        printf("*\n");
        j = 0;
        while(j < i + 4)
        {
            printf("*");
            j++;
        }
        printf("\n");
    }
}