#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{

    int randomnum, guessnum;
    int attempts=0;
    srand(time(NULL));
  printf("Welcome to the world of guessing number\n");
  randomnum =rand() % 100+1;
    do
    {
        printf("Enter number between 1 to 100 :");
        scanf("%d", &guessnum);
        attempts++;
        if (guessnum > randomnum)
        {
            printf("Too high! Please enter smaller\n");
        }
        else if(guessnum<randomnum){printf("Too low! Please enter larger\n");}
        else{
            printf("Congratulations!!! You have successfully guessed the number in %d attempts\n",attempts);
        }

    } while (guessnum != randomnum);
    printf("Game ended.Thanks for playing...\n");
    printf("Developed by: Md.Alvi Zaman");

    return 0;
}
