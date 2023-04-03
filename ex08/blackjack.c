#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int blackjack(int sum, int argc, char **argv)
{
    int i = 0;
    while(argv[1][i] != '\0')
    {
        if(argv[1][i] >= 50 && argv[1][i] <= 57)
            sum = sum + (argv[1][i] - 48);
        else if(argv[1][i] == 74 ||argv[1][i] == 84 ||argv[1][i] == 75 || argv[1][i] == 81)
            sum = sum + 10;
        else if(argv[1][i] == 65)
        {
            if(sum + 11 <= 21)
                sum = sum + 11;
            else
                sum = sum + 1;
        }
        else
        {
            printf("invalid cards\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }
    return (sum);
}

int main(int argc, char **argv)
{
    int win = blackjack(win, argc, argv);
    if(win == 21)
        printf("Blackjack!\n");
    else
        printf("%d\n", win);
    return (EXIT_SUCCESS);
}