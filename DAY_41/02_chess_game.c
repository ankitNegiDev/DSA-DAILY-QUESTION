// Q 4 => four players are playing a tournament of chess with round robin method (each player will play with every other player). Each win has 2 points , draw has 1 point and loose has 0 points . Declare a score_board two dimensional array to store the scores of the players agains each player.
/*
Matches:

P0 vs P1

P0 vs P2

P0 vs P3

P1 vs P2

P1 vs P3

P2 vs P3
*/
/*
Scoring
Win = 2 points

Draw = 1 point each

Loss = 0 points
 */

//  we have to create 4*4 size of 2d array.

// Q 1 -> for question 4 , define a function to update score board after each match result.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Min
{
    int min;
    int index;
};



struct Max
{
    int max;
    int index;
};





void initializeScoreBoard(int **board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = 0;
        }
    }
}






void displayScoreBoard(int **board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}










// Q 1 -> update score board..
void updateScoreBoard(int **score, int player1, int player2, int result)
{
    if (result == 0)
    {
        /*
        printf("the value of result is %d \n",result);
        printf("\n\nMatch is DRAW\n\n");
        */
        printf("\nMatch is a DRAW\n");
        // draw...both player got 1 points
        score[player1][player2] = 1;
        score[player2][player1] = 1;
    }
    else if (result == 1)
    {
        // player 1 wins ...
        /*
        printf("the value of result is %d\n",result);
        printf("\n\nPlayer1 win against player2\n\n");
        */
        printf("\nPlayer %d wins against Player %d\n", player1, player2);
        score[player1][player2] = 2;
        score[player2][player1] = 0;
    }
    else if (result == 2)
    {
        /*
        printf("the value of result is %d\n",result);
        printf("\n\nplayer2 wins agains player1\n\n");
        */
        printf("\nPlayer %d wins against Player %d\n", player2, player1);
        // player 2 wind...
        score[player2][player1] = 2;
        score[player1][player2] = 0;
    }
}







// Q 2 => for question 4 , define a function to display scoreboard.
// so we already define a function displayboard for 2d arry or board..
/*
void displayScoreBoard(int **board){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}
*/








// Q 3 => for question 4, define a function which return the score of a specific player.

// so we need to first calcualte the total score and then return it.

int getPlayerScore(int **score, int player)
{
    int totalScore = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != player)
        {
            // if i=0 and player is 0 then 0,0 why to calculate it..means in round robin format a player does not play with itself.
            totalScore = totalScore + score[player][i];
        }
    }
    return totalScore;
}







// Q 4 => for question 4 , define a function to find the windder of the tournament..
// winner will be whose score is maximum among all.
int winnerOfTournament(int **score)
{
    /*
    int maxScore=-1;
    int player=-1;
    int scoreArr[4];
    for(int i=0; i<4; i++){
        int playerTotalScore=getPlayerScore(score,i);
        scoreArr[i]=playerTotalScore;
    }
    for(int i=0; i<4; i++){
        if(maxScore<scoreArr[i]){
            maxScore=scoreArr[i];
            player=i;
        }
    }
    printf("the %d player has max score of %d\n",player,maxScore);
    return player;
    */
    // there is no need to create array.
    int maxScore = -1;
    int winnerPlayer = -1;
    for (int i = 0; i < 4; i++)
    {
        int playerTotalScore = getPlayerScore(score, i);
        if (maxScore < playerTotalScore)
        {
            maxScore = playerTotalScore;
            winnerPlayer = i;
        }
    }
    printf("the %d player has max score of %d\n", winnerPlayer, maxScore);
    return winnerPlayer;
}







// Q 5 => for question no 4, define a function to display rank of the players.
struct Min minNumber(int *ptr, int startingIndex)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = startingIndex; i < 4; i++)
    {
        if (ptr[i] < min)
        {
            min = ptr[i];
            index = i;
        }
    }
    struct Min m;
    m.min = min;
    m.index = index;
    return m;
}
struct Max maxNumber(int *ptr, int startingIndex)
{
    int max = INT_MIN;
    int index = -1;
    for (int i = startingIndex; i < 4; i++)
    {
        if (ptr[i] > max)
        {
            max = ptr[i];
            index = i;
        }
    }
    struct Max m;
    m.max = max;
    m.index = index;
    return m;
}
int *rankOfPlayers(int **score)
{
    int maxScore = -1;
    int player = -1;
    int scoreArr[4];
    int playerRank[4];
    for (int i = 0; i < 4; i++)
    {
        int playerTotalScore = getPlayerScore(score, i);
        scoreArr[i] = playerTotalScore;
        playerRank[i] = i;
    }
    for (int i = 0; i < 4; i++)
    {
        if (maxScore < scoreArr[i])
        {
            maxScore = scoreArr[i];
            player = i;
        }
    }

    // -------- player ranks in ascending order ---------
    // now we have player score.. and player at index..
    // now doing sorting using the bruteforce..
    for (int i = 0; i < 2; i++)
    {
        struct Min m = minNumber(scoreArr, i);
        // now we have min score and its index which is player.
        int temp = scoreArr[i];
        scoreArr[i] = m.min;
        scoreArr[m.index] = temp;
        // we have to do swapping
        temp = playerRank[i];
        playerRank[i] = m.index;
        playerRank[m.index] = temp;
    }
    printf("the player score in ascending order are \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", scoreArr[i]);
    }
    printf("the player rank in ascending order are \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", playerRank[i]);
    }

    // ------player ranks in desceding order----------
    // in descending order
    for (int i = 0; i < 2; i++)
    {
        struct Max m = maxNumber(scoreArr, i);
        // now we have min score and its index which is player.
        int temp = scoreArr[i];
        scoreArr[i] = m.max;
        scoreArr[m.index] = temp;
        // we have to do swapping
        temp = playerRank[i];
        playerRank[i] = m.index;
        playerRank[m.index] = temp;
    }
    printf("the player score in descending order are \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", scoreArr[i]);
    }
    printf("the player rank in descending order are \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", playerRank[i]);
    }
    return playerRank;
}






// Q 6 => for question 4, define a function to run a tournament , in which user has to enter result of each game and update score board using score_board function.
// Function to run the tournament
void runTournament(int **scoreBoard)
{
    int result;

    // Loop over all matches and ask the user to input the results
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            printf("\nMatch between Player %d and Player %d\n", i, j);
            printf("Enter result (0 for Draw, 1 for Player %d win, 2 for Player %d win): ", i, j);
            scanf("%d", &result);

            do
            {
                scanf("%d", &result);
                if (result < 0 || result > 2)
                {
                    printf("Invalid input! Please enter a valid result (0, 1, or 2): ");
                }
            } while (result < 0 || result > 2);

            // Update the score board based on the result
            updateScoreBoard(scoreBoard, i, j, result);

            // Display the updated score board after each match
            printf("\nUpdated Scoreboard:\n");
            displayScoreBoard(scoreBoard);
        }
    }
}






int main()
{
    int **scoreBoard;
    scoreBoard = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        scoreBoard[i] = (int *)malloc(4 * sizeof(int));
    }
    initializeScoreBoard(scoreBoard);
    displayScoreBoard(scoreBoard);

    int player1, player2, result;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            printf("\n\n");
            printf("- - - - - - - - - - - - - - - - - - -\n\n");
            player1 = i;
            player2 = j;
            printf("\n- - - - - - - - - - - - - - - - - - -\n");
            printf("Match: Player %d vs Player %d\n", player1, player2);
            printf("Enter the result of the match (0 = Draw, 1 = Player 1 wins, 2 = Player 2 wins): ");
            /*
            printf("the player1 is %d : \n",player1);
            printf("the player2 is %d : \n",player2);
            printf("enter the result of match\n");
            scanf("%d", &result);
            while(1){
                if(result>=0 && result<=2){
                    break;
                }else{
                    printf("enter the correct match result\n");
                    scanf("%d",&result);
                }
            }
            */
            do
            {
                scanf("%d", &result);
                if (result < 0 || result > 2)
                {
                    printf("Invalid input! Please enter a valid result (0, 1, or 2): ");
                }
            } while (result < 0 || result > 2);
            updateScoreBoard(scoreBoard, player1, player2, result);
            displayScoreBoard(scoreBoard);
            printf("\n- - - - - - - - - - \n");
        }
    }

    // total score of each player.
    for (int i = 0; i < 4; i++)
    {
        int score = getPlayerScore(scoreBoard, i);
        printf("\nTotal score of Player %d is: %d\n", i + 1, score);
    }

    // player ranks
    int *playerRanks = rankOfPlayers(scoreBoard);
    printf("the player ranks are \n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", playerRanks[i]);
    }

    // Free allocated memory
    for (int i = 0; i < 4; i++)
    {
        free(scoreBoard[i]);
    }
    free(scoreBoard);
    return 0;
}