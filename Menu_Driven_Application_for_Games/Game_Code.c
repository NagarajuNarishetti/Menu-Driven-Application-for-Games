#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>
int number_guess();
int r_p_s();
void cricket();
int bating();
int s_w_g();
void number_guess_about();
void r_p_s_about();
void s_w_g_about();
void selectGame();
void aboutGame();
void cricket_about();

int main() {
    int choice;
    
    do {
        printf("\n\n***Menu:***\n\n");
        printf("1. Play a game\n");
        printf("2. About the game\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                selectGame();
                break;
            case 2:
                aboutGame();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 3);
    
    return 0;
}

void selectGame() {
    int n;
    printf("ENTER :\n1.For Number Guessing Game\n2.For Rock Paper\n3.For Cricket\n4.For Snake Water Gun \n5.To go back\n");
    scanf("%d",&n);
    do{
    switch(n) {
        case 1: number_guess();
        break;

        case 2: r_p_s();
        break;

        case 3: cricket();
        break;
        
        case 4: s_w_g();
        break;

        case 5:main();
        break;

        default:printf("please enter valid input");
    } }
    while(n!=5);

}

// Structure to hold player information
struct Player {
    char name[50];
    int score;
};

int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void saveScore(struct Player *player) {
    FILE *file = fopen("scores.txt", "a");
    if (file == NULL) {
        printf("Unable to open the score file.\n");
        return;
    }

    fprintf(file, "%s %d\n", player->name, player->score);
    fclose(file);
}

void displayHighScore() {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("No high scores found.\n");
        return;
    }

    printf("High Scores:\n");
    printf("------------\n");

    struct Player player;
    while (fscanf(file, "%s %d", player.name, &player.score) != EOF) {
        printf("Player: %s\tScore: %d\n", player.name, player.score);
    }
    main();
    fclose(file);
}

int number_guess(){
    struct Player *player;
    player = (struct Player *)malloc(sizeof(struct Player));

    printf("Welcome to the Number Guessing Game!\n");
    printf("Enter your name: ");
    scanf("%s", player->name);

    printf("Hello, %s! Let's play!\n", player->name);

    int randomNumber, guess;
    int attempts = 0;
    srand(time(0));
    randomNumber = generateRandomNumber(1, 100);

    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations, %s! You guessed the number %d in %d attempts!\n", player->name, randomNumber, attempts);
            player->score = attempts;
            saveScore(player);
        }
    } while (guess != randomNumber);

    printf("Your best score is %d attempts.\n", player->score);

    int option;
    printf("Options:\n");
    printf("1. Check high score\n");
    printf("2. Quit\n");
    printf("Select an option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            displayHighScore();
            break;
        case 2:
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid option. Exiting...\n");
            break;
    }

    free(player);

    return 0;
    main();


}
// we define constants for ROCK, PAPER, SCISSORS to make our code easier to read
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int r_p_s(){
  // seed the random number generator with the current time to get different 
  // random numbers each time the program is run
  
  struct Player *player;
    player = (struct Player *)malloc(sizeof(struct Player));

    printf("Welcome to the Rock Paper Scissors Game!\n");
    printf("Enter your name: ");
    scanf("%s", player->name);
    printf("Hello, %s! Let's play!\n", player->name);
    
  int player_throw = 0;
  int ai_throw = 0;
  bool draw = false;
  
  do
  {
    // accept the player throw
    printf("Select your throw.\n");
    printf("1) Rock\n");
    printf("2) Paper\n");
    printf("3) Scissors\n");
   printf("4) EXIT\n");
    printf("Selection: ");
    scanf("%d", &player_throw);
    if(player_throw==4)
    main();
	// randomly generate the AI throw (where 1-3 represent rock/paper/scissors 
    // as defined above)
    ai_throw = (rand() % 3) + 1;
    
    // output the AI's throw to the player
    if (ai_throw == ROCK)
      printf("\nComputer throws ROCK.\n");
    else if (ai_throw == PAPER)
      printf("\nComputer throws PAPER.\n");
    else if (ai_throw == SCISSORS)
      printf("\nComputer throws SCISSORS.\n");
    
    // determine and output the winner, if any
    draw = false;
    if (player_throw == ROCK && ai_throw == SCISSORS)
      printf("\nROCK beats SCISSORS. YOU WIN.\n\n");
    else if (player_throw == ROCK && ai_throw == PAPER)
      printf("\nPAPER beats ROCK. YOU LOSE.\n\n");
    else if (player_throw == SCISSORS && ai_throw == PAPER)
      printf("\nSCISSORS beats PAPER. YOU WIN.\n\n");
    else if (player_throw == SCISSORS && ai_throw == ROCK)
      printf("\nROCK beats SCISSORS. YOU LOSE.\n\n");
    else if (player_throw == PAPER && ai_throw == ROCK)
      printf("\nPAPER beats ROCK. YOU WIN.\n\n");
    else if (player_throw == PAPER && ai_throw == SCISSORS)
      printf("\nSCISSORS beats PAPER. YOU LOSE.\n\n");
    else
    {
      // if both player and AI throw the same, it's a draw
      printf("\nDRAW! Play again.\n\n");
      draw = true;
      r_p_s();
    }
  
  // in the case of a draw, the game is played again until there is a winner
  } while (draw);
  main();
}

void cricket(){
	
	int toss,bating_selection,toss_number_player,number,tsum,result,pscore,cscore,ctoss=0;
 	struct Player *player;
    player = (struct Player *)malloc(sizeof(struct Player));
    printf("Welcome to the Number Guessing Game!\n");
    printf("Enter your name: ");
    scanf("%s", player->name);
    printf("Hello, %s! Let's play!\n", player->name);
	printf("select  odd-1  or even-2 for toss :  ");
 	scanf("%d",&toss);
 	printf("\nnow enter number of your choice below 100 :  ");
 	scanf("%d",&toss_number_player);
    srand(time(0));
    number = rand()%100;
    printf("\n%d is computers number\n",number);
    tsum=toss_number_player+number;
    printf("\nsum of your choices is %d\n",tsum);
    result=tsum%2;
    if(result==0&&toss==2)
    printf("\nsum is even ** you won the toss**\n");
    else if(result!=0&&toss==1)
    printf("sum is odd  ** you won the toss **\n");
    else{
    printf("**computer won the toss**\n");
    ctoss=1;} 
    if(ctoss==0){
    printf("\nselect whether to bat 1st or 2nd : ");
    scanf("%d",&bating_selection);
}
else{srand(time(0));
	  bating_selection =  rand()%2+1;
	  printf("computer selected %d\n",bating_selection);
}
    if(bating_selection==1&&ctoss==0){
    pscore=bating();
    printf("\n\n***Your score is %d ***\n\n",pscore);
    printf("It is time for computer bating");
    cscore=bating();
    printf("\n\n***The score of the Computer  is %d***\n\n",cscore);
    if(pscore>cscore)
    printf("**YOU WON with %d runs**\n",pscore-cscore);
    else if(pscore==cscore)
    printf("**game is a tie with %d runs each **\n",pscore);
    else
    printf("**Computer WON with %d runs**\n",cscore-pscore);
   
	}
	else{
		cscore=bating();
    printf("\n\n***The score of the Computer  is %d***\n\n",cscore);
    printf("It is time for your bating\n");
    pscore=bating();
    printf("\n\n***your score is %d ***\n\n",pscore);
    if(pscore>cscore)
    printf("**YOU WON with %d runs**\n",pscore-cscore);
    else if(pscore==cscore)
    printf("**game is a tie with %d runs each **\n",pscore);
    else
    printf("**Computer WON with %d runs**\n",cscore-pscore);
	}
	main();
}

int bating(){
 	   int pchoice, cchoice,score=0;
 		printf("\nwelcome to the game All the best\n\n");
		 do{
    	printf("enter a number below 7 :  ");
    	scanf("%d",&pchoice);
    	srand(time(0));
	  cchoice =  rand()%6+1;
	  printf("computer choice is %d\n",cchoice);
	  score+=pchoice+cchoice;
	  printf("\nscore increased to %d \n\n",score);
}while(pchoice!=cchoice);
return score;
 }

// we define constants for WATER, SNAKE, GUN to make our code easier to read
#define WATER 1
#define SNAKE 2
#define GUN 3

int s_w_g() {
struct Player *player;
    player = (struct Player *)malloc(sizeof(struct Player));
    printf("Welcome to the Snake Water Gun Game!\n");
    printf("Enter your name: ");
    scanf("%s", player->name);
    printf("Hello, %s! Let's play!\n", player->name);
  // seed the random number generator with the current time to get different 
  // random numbers each time the program is run
  srand( time(NULL) );
  
  int player_throw = 0;
  int ai_throw = 0;
  bool draw = false;
  do
  {
    // accept the player throw
    printf("Select your throw.\n");
    printf("1) WATER\n");
    printf("2) SNAKE\n");
    printf("3) GUN\n");
    printf("4)EXIT\n");
    printf("Selection: ");
    scanf("%d", &player_throw);
    if(player_throw==4)
    main();
    // randomly generate the AI throw (where 1-3 represent WATER/SNAKE/GUN 
    // as defined above)
    ai_throw = (rand() % 3) + 1;
    // output the AI's throw to the player
    if (ai_throw == WATER)
      printf("\nAI throws WATER.\n");
    else if (ai_throw == SNAKE)
      printf("\nAI throws SNAKE.\n");
    else if (ai_throw == GUN)
      printf("\nAI throws GUN.\n");
    // determine and output the winner, if any
    draw = false;
    if (player_throw == WATER && ai_throw == GUN)
      printf("\nWATER beats GUN. YOU WIN.\n\n");
    else if (player_throw == WATER && ai_throw == SNAKE)
      printf("\nSNAKE beats WATER. YOU LOSE.\n\n");
    else if (player_throw == GUN && ai_throw == SNAKE)
      printf("\nGUN beats SNAKE. YOU WIN.\n\n");
    else if (player_throw == GUN && ai_throw == WATER)
      printf("\nWATER beats GUN. YOU LOSE.\n\n");
    else if (player_throw == SNAKE && ai_throw == WATER)
      printf("\nSNAKE beats WATER. YOU WIN.\n\n");
    else if (player_throw == SNAKE && ai_throw == GUN)
      printf("\nGUN beats SNAKE. YOU LOSE.\n\n");
    else
    {
      // if both player and AI throw the same, it's a draw
      printf("\nDRAW! Play again.\n\n");
      draw = true;
    }
  
  // in the case of a draw, the game is played again until there is a winner
  } while (draw);

 main();
}

void aboutGame() {
	int n;
    printf("ENTER :\n1.For Number guessing Game\n2.For Rock Paper\n3.for Cricket\n4.For Snake Water Gun\n5.To go back");
    scanf("%d",&n);
    do{
    switch(n) {
        case 1: number_guess_about();
        break;

        case 2: r_p_s_about();
        break;
        
        case 3: cricket_about();
        break;

        case 4: s_w_g_about();
        break;

        case 5: main();
        break;

        default:printf("please enter valid input");
    } }
    while(n!=5);

}

void number_guess_about(){
    FILE *file;
    char filename[100]="number.txt";
    char ch;
    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        main();
    }
 // Read and print the contents of the file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
 // Close the file
    fclose(file);
    main();
}
void r_p_s_about(){
	FILE *file;
    char filename[100]="rock.txt";
    char ch;
    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
    }
 // Read and print the contents of the file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
 // Close the file
    fclose(file);
main();

}
void s_w_g_about(){
FILE *file;
    char filename[100]="snake.txt";
    char ch;
    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
    }
 // Read and print the contents of the file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
 // Close the file
    fclose(file);
    main();
}
void cricket_about(){
	FILE *file;
    char filename[100]="cricket.txt";
    char ch;
    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
    }
 // Read and print the contents of the file
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
 // Close the file
    fclose(file);
    main();
}



