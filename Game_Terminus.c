#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define FLUSH fflush(stdin)

void menu(void);
void Play(void);
void Credit(void);
void minesweeper(void);
void numberg(void);
void wordg(void);

int main(int argc, char** argv)
{

	menu();
	return 0;
}



void menu(void)
{
	int choice;

	do
	{
        system("cls");
        printf("\n\n\t\t\t\t********GAME TERMINUS********\n\n\n");
		printf("\t\t\t\t   <<<<<MAIN MENU>>>>\n\n");
		printf("\t\t1. Play\n");
		printf("\t\t2. Credit\n");
		printf("\t\t3. Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: Play();
				break;
			case 2: Credit();
				break;
			case 3: printf("Terminating  Game Terminus!\n Thank you for playing! \n Hope you have a great day! \n");
				exit(0);
				break;
			default: printf("Invalid choice!\n");
				break;
		}

	} while (choice != 3);

}

void Play(void)
{
	int gamec;
	int ch;
    int select;
    system("cls");
	printf("Please Choose from the following game you want to play:\n\n");
	printf("Enter number 1: MINESWEEPER\n");

	printf("Enter number 2: Number Guessing\n");

	printf("Enter number 3: Word Guessing\n");
    scanf("%d",&select);

    if(select == 1)
    {
        minesweeper();
    }

    else if(select == 2)
    {
        numberg();
    }
    else if(select ==3)
    {
        wordg();
    }

	scanf("%d",&gamec);


	while ( (ch = getchar()) != '\n' && ch != EOF) ;

	printf("\n\nPress ENTER to continue.");
	while ( (ch = getchar()) != '\n' && ch != EOF);




	return;
}



void Credit(void)
{
	int ch;
    system("cls");
	printf("||Pavan Sastry       ||    Krishna Bindu         ||   Baladithya        ||\n");
	printf("||Team lead,Developer|| Documentation,Testing(QC)||Developer,Testing(QC)|| \n");


	while ((ch = getchar()) != '\n' && ch != EOF) ;

	printf("\n\nPress ENTER to continue.");
	while ((ch = getchar()) != '\n' && ch != EOF)
		;

	return;
}

//**************************************************************************


void gamehelp( void );
void level( void );
void beginner( void );
void intermediate( void );
void advanced( void );
void custom( void );
void mfgenerator( void );
void printmf( void );
void guess( void );
void lose( void );
void printfinalmf( void );
void win( void );
void play_again( void );

int x, y, z;
int M, N;
char pname[20];
float diff;
int total_mines = 0;
int mines = 0;
int minefield[30][30];                                      //This 2-D array contains all of the mines, numbers and blank spaces
int blank_minefield[30][30];                                //This contains the minefield full of '|-|' characters
int final_minefield[30][30];

void minesweeper()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Enter your name:");
    scanf("%s",pname);
    printf("\t\tWelcome to Minesweeper, %s!\n",pname);
    printf("\n\t\tPress 1 to start the game,Press 2 to read game help :\n");
    scanf("%d",&z);
    switch(z)
    {
        case 1:
        level();
        break;


        case 2:
        gamehelp();
        break;


    }


    return;
}

void gamehelp( void )
{
     void level( void );
     int chx;
                   system("cls");
     printf("\n\n ************************* GAME INSTRUCTIONS *************************");
     printf("\n -------------------------------------------------------------------------");
     printf("\n >> There are 4 types of difficulty Begginer , Intermediate , Advanced and Custom");
     printf("\n >> After  choosing the difficulty , The user has to enter the x and y value of the grid the  wants to uncover. ");
     printf("\n    The number on the block shows the number of mines adjacent to it.");
     printf("\n    If it shows the letter 'B' it means the adjacent sides are all without any bombs");
     printf("\n >> You win the game by Successfully clearing the grid without getting any mines. ");
     printf("\n >> If you hit a mine,You lose.");
     printf("\n >> Finally , Have fun!");

    printf("\n\n ************************* BEST OF LUCK *************************\n\n");


    printf("\nContinue playing ? Press 1 to start the game \n :  ");
    scanf("%d",&chx);

    if(chx==1)
    {
        level();
    }
    else
    {
        printf("Please Enter 1 to go back.");
        gamehelp();
    }
}
void level( void )                                     //Function for choosing the difficulty level
{
    system("cls");
    diff = 0;
    while( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
    {
        printf("\t\tChoose a difficulty level(1-3) or 4 for a custom game:");
        scanf("%f", &diff);
        FLUSH;
        if( (diff != 1) && (diff != 2) && (diff != 3) && (diff != 4))
        {
            printf("\t\tPlease enter either 1, 2, 3 or 4\n");
        }
    }

    if( diff == 1 )                                         //If, else if and else statements that each go to the respective difficulty
    {
        beginner();
    }
    else if( diff == 2 )
    {
        intermediate();
    }
     else if( diff == 3 )
    {
        advanced();
    }
    else if( diff == 4)
    {
        custom();
    }
}

void beginner( void )                                       //Gives the minefield the 'beginner' grid and mines
{
    M = 9;
    N = 9;
    total_mines = 10;
    mfgenerator();
    guess();
}

void intermediate( void )                                   //Gives the minefield the 'intermediate' grid and mines
{
    M = 16;
    N = 16;
    total_mines = 40;
    mfgenerator();
    guess();
}
void advanced( void )                                         //Gives the minefield the 'advanced' grid size and mines
{
    M = 16;
    N = 30;
    total_mines = 99;
    mfgenerator();
    guess();
}

void custom( void )
{
    M = 0;
    N = 0;
    total_mines = 0;
    printf("\t\tPlease enter the size of the dimensions you want\n");
    printf("\t\tFirst value:\n");
    scanf("%d", &M);
    printf("\t\tSecond value:\n");
    scanf("%d", &N);
    printf("\t\tNumber of mines you want to assign to the board:\n");
    scanf("%d", &total_mines);
    mfgenerator();
    guess();
}

void mfgenerator( void )                            //Function that generates the minefield
{
    int i = 0, j = 0;
    srand( time( NULL ) );                                  //Starts the random no. generator

    while( j < N )                                          //Nested loop for making the blank minefield and final minefield
    {
        while( i < M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )                            //Randomly generates the mines into the minefield
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')                         //If statement that checks if there is a mine already there and doesn't place a mine if there is
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;
    while( j < N )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < M)
        {
            if( minefield[i][j] != '*')
            {
                minefield[i][j] = 0;
            }
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}

void printmf(void)                                  // This function prints the minefield
{
    int i = 0, j = 0, z = 0;
    while( z < M )                                          // This while loop prints out the line of co-ordinates along the x axis of the minefield
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          // Loop that prints out each character in the minefield
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )                 // This changes any spaces with values of zero to the character 'B'
            {
                blank_minefield[i][j] = 'B';
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void guess( void )
{
    int q = 0, i=0, j=0, match=0;
    printmf();
    while( j < N )                                          // While loop for testing whether or not the user has cleared the minefield
    {
        while( i < M )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines))                 // If the user has cleared the minefield, the win() function is run
    {
        win();
    }

    printf("\nEnter the x value, then a space, then the y value:");
    scanf("%d %d", &x, &y);                                 // Reading in the co-ordinates for the guess
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nPlease enter a value inside the grid\n");
        guess();
    }
    if( minefield[x][y] == '*' )                            // Runs the lose() function if the user selects a mine
    {
        lose();
    }
    if( blank_minefield[x][y] != '-' )
    {
        printf("\nPlease enter a value that has not already been entered\n");
        guess();
    }

    else                                                // Checks if the adjacent spaces are blank, then changes the values in the blank_minefield array. Because they are changed, they will now print out in the printmf function
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess();
    }
}

void lose( void )                                       // Runs the printfinalmf function, then the play_again function
{
    printfinalmf();
    printf("\n\t\tYou hit a mine at %d,%d\n\t\tYOU LOSE!!!!", x, y);
    play_again();
}

void printfinalmf( void )                      // Prints the minefield, showing where all of the mines are placed
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void win( void )                                        // Runs the play_again function
{
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    play_again();
}

void play_again( void )                                 // Gives the user the option to play again
{
    char option[2];

    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y'))        // Restarts the program from after the welcome message
    {
        level();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        printf("\tGame Over\n");
        system("cls");
        menu();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again();
    }
}


//**************************************************************************


void guess1(int N)
{

	int number, guess, numberofguess = 0;
    char playern[20];

	                                                                        // Generate a random number
	number = rand() % N;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Enter your name:");
    scanf("%s",playern);
    system("cls");
    printf("Welcome to Number Guessing Game %s!\n Guess the randomly generated number between 1 to %d.\n Good luck!\n",playern,N);
	printf("Enter Your Guess : \n",N);
        
    {
                                                             // Using a do-while loop that will work until user guesses the correct number

	    do {

		    if (numberofguess > 9)
            {
			    printf("\nYou Loose!\n");
			    break;
		    }

		                                                        // Input by user
		    scanf("%d", &guess);

	                                                        	// When user guesses lower than the actual number

		    if ( guess > number)

		    {
			    printf("Lower number ""please!\n");
			    numberofguess++;
		    }

		                                                            // When user guesses higher than actual number

		    else if ( number > guess)

		    {
			    printf("Higher number"" please!\n");
			    numberofguess++;
		    }

		                                                              // Printing number of times user has taken to guess the number

		    else
			    printf("You guessed the"" number in %d ""attempts!\n",numberofguess);


	    } while (guess != number);
    }

}

void play_again1( void )                                 // Gives the user the option to play again
{
    char choice1[2];

    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &choice1[0]);
    FLUSH;
    if((choice1[0] == 'Y') || (choice1[0] == 'y'))        // Restarts the program
    {
        numberg();
    }
    else if( (choice1[0] == 'N') || (choice1[0] == 'n'))
    {
        printf("\tGame Over\n");
        system("cls");
        menu();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again1();
    }
}

                                                    // main function for number guessing
void numberg()
{
	int N = 100;

	                                                // Calling the Function
	guess1(N);
    play_again1();
	return;
}


//**************************************************************************


void wordg()
{

    void start(void);
    void instructions(void);

    char playername[20];

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Enter your name:");
    scanf("%s",playername);
    system("cls");
    
     printf("\n\t\t\t                     HELLO %s!",playername);
     printf("\n\t\t\t                      WELCOME\n ");
     printf("\n\t\t\t                        to\n ");
     printf("\n\t\t\t                 THE QUIZ ON CAPITALS !");
     printf("\n\t\t");
     printf("\n\t\t            ****************************************");
     printf("\n\t\t            ****************************************");

     int chc=0;

    printf("\n Press 1 to start the game\nPress 2 to see Game Help\n:   ");
    scanf("%d",&chc);

    switch(chc)
    {
        case 1:
        start();
        break;


        case 2:
        instructions();
        break;


    }


}

void instructions()                                                                               // instructions 
{
    void start();
     int ch;
                   system("cls");
     printf("\n\n ************************* GAME INSTRUCTIONS *************************");
     printf("\n -------------------------------------------------------------------------");
     printf("\n >> There will be a total of  100 questions");
     printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the");
     printf("\n    right option");
     printf("\n >> Each question will carry 10 points");
     printf("\n >> You will be asked questions continuously.");
     printf("\n >> There is no negative marking for wrong answer");

    printf("\n\n ************************* BEST OF LUCK *************************\n\n");


    printf("\nContinue playing ? Press 1 to start the game \n :  ");
    scanf("%d",&ch);

    if(ch==1)
    {
        start();
    }
    else                                                                                    //function calling for instructions and start                                
    {
        printf("Please Enter 1 to go back.");
        instructions();
    }

}

void start()                                                                            // game start function
{
        void play_again2();
        system("cls");
          int ans;
          int score=0;



        printf("******************* Welcome  to C Quiz Game *************************** \n\n");

        system("cls");
        printf("\n *********** Welcome  to capital guessing *****************");
        printf("\n\n Here are some tips you might wanna know before playing:");
        printf("\n ********************************************************************************");
        printf("\n    total of 10 questions. Each right answer will be awarded with 10 points!");
        printf("\n    you can score upto 100 points ");
        printf("\n >> You will be given 4 options to guess the right option");
        printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!\n\n\n");


        printf("Q(1).WHAT IS THE CAPITAL OF LARGEST STATE IN INDIA? \n 1.jaipur \t\t2.kota\n 3.jodhpur\t\t4.None of the above\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
        system("cls");

        if(ans==1)
        {
            printf("Correct! +10 points\n\n");
            score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 1.jaipur\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(2) WHAT IS CAPITAL OF LARGEST POPULATION STATE? \n 1.kanpur \t\t2.lucknow\n 3.mirzapur\t\t4.varanasi\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
        system("cls");

        if(ans==2)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;

        }
        else
        {
            printf("Wrong answer! Correct answer is 2.lucknow\n\n");
        }
        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(3) what is the capital of daman and diu? \n 1.port blair \t\t2.daman\n 3.noida\t\t4.silvassa\n\n");

        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==2)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 2.daman\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(4).WHICH CAPITAL IS CALLED SILICON VALLEY OF INDIA? \n1.mumbai\t2.hyderabad\n3.bengaluru\t4.delhi\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==3)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 3.bengaluru\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(5).WHAT IS THE CAPITAL OF ANDHRA PRADESH? \n1.amaravati\t2.kurnool\n3.vizag\t\t4.All of the above\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==4)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 4.All of the above\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(6).WHICH CAPTIAL IS KNOW AS CAPITAL FOR TWO STATES? \n1.amritsar\t2.chandighar\n3.delhi\t\t4.none of the above\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==2)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 2.chandighar\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(7). WHAT IS THE CAPTIAL OF STATE WHICH IS KNOW AS GODS OWN COUNTRY? \n1.kozhikode\t2.gangtok\n3.shimla\t4.thirunanthapuram\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==4)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 4.thiruvananthapur\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(8).WHAT IS THE CAPITAL OF INDIA BEFORE IT CHANGED TO DELHI? \n1.bombay\t2.madras\n3.calcutta\t4.benaras\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==3)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 3.calcutta\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(9).WHAT IS THE CAPITAL OF ODISHA? \n1.bhubaneshwar\t2.puri\n3.cuttak\t4.nagpur\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==1)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 1.bhubaneshwar\n\n");
        }

        printf("\n------------------------------------------------------------------------------\n");
        printf("Q(10).WHAT IS THE CAPITAL OF NAGALAND? \n1.kohima\t2.dispur\n3.agartala\t4.imphal\n\n");
        printf("Your answer: ");
        scanf("%d",&ans);
         system("cls");

        if(ans==1)
        {
            printf("Correct! +10 points\n\n");

                score=score+10;
        }
        else
        {
            printf("Wrong answer! Correct answer is 1.kohima\n\n");
        }
        printf("\n------------------------------------------------------------------------------\n");
        printf("your total score = %d\n", score);
        printf("\n------------------------------------------------------------------------------\n");

        printf("thanks for playing\n");
        printf("hope you enjoyed");
        play_again2();
  }

void play_again2( void )                                         // Gives the user the option to play again
{
    char choice2[2];

    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &choice2[0]);
    FLUSH;
    if((choice2[0] == 'Y') || (choice2[0] == 'y'))              // Restarts the program
    {
        wordg();
    }
    else if( (choice2[0] == 'N') || (choice2[0] == 'n'))
    {
        printf("\tGame Over\n");
        system("cls");
        menu();
    }
    else
    {
        printf("Please enter either Y or N");
        play_again2();
    }
}
