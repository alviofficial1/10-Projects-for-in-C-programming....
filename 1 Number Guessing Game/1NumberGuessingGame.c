#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number,randomNum,
    attempt=0;
    char exit;
    srand(time(0));
    randomNum =rand()%100+1;
   
    printf("    Enter to The World of Guessing Number!!!!!\n");
    printf("----------------------------------------------------\n");
 while (number!=randomNum)
 {

    printf("Enter a number between 1-100: ");
    scanf("%d",&number);
    attempt++;
    if (number>randomNum)
    {
         printf("Too High!!Enter a Smaller Number....\n");
    }
    else if (number<randomNum)
    {
        printf("Too Low!!Enter a Higher Number....\n");
    }
    else if (number==randomNum)
    {
         printf("Congratulations!!!You Have Guessed The Number(%d) in %d Attempts\n",randomNum,attempt);
         
    }
  
    
    
 }
   printf("Thanks For Playing......\n");
   printf("Developed By MD.ALVI ZAMAN....\n");
    
    return 0;
}
