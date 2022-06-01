/*
main.c
Assignment Project 1
Amos Munteanu
This file runs the entire game and used both champion.c and .h
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "champion.h"
#include "champion.c"

void printLastList(Champion* player1, Champion* player2)
{
    // prints ending of the deck
    printf ("====== GAME OVER =====\n");
    printf ("Player 1 ending champion list: ");
    printChampionList(player1); printf ("\n");
    printf ("Player 2 ending champion list: ");
    printChampionList(player2); printf ("\n");
}


// checks if game is still running
bool isGameRunning(Champion* player1, Champion* player2)
{
    int length1 = getLength(player1);
    int length2 = getLength(player2);
    if (length1 == 0 && length2 == 0) 
    {
        // this checks if both players are even and determins a tie
        printLastList(player1, player2);
        printf ("TIE -- both players ran out of champions.\n");
        return false;
    } 
    else if (length1 == 0) 
    {
        // this check for if player one won
        printLastList(player1, player2);
        printf ("Player 1 ran out of champions. Player 2 wins.\n");
        return false;
    }
    else if (length2 == 0) 
    {
        // this check for if player two won
        printLastList(player1, player2);
        printf ("Player 2 ran out of champions. Player 1 wins.\n");
        return false;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    srand (time(NULL));
    if (argc != 2) 
    {
        printf ("Error\n");
        exit (EXIT_SUCCESS);
    } else 
    {
        int n = atoi(argv[1]);
        if (n > 0) 
        {
            printf ("======= PLAYER 1 V PLAYER 2 SHOWDOWN ======\n");
            // generates the decks for player1 and player2
            Champion* player1 = buildChampionList(n);
            Champion* player2 = buildChampionList(n);
            int round = 0;
            while (true)
            {
                // prints informations for the current round
                printf ("----- Round %d -----\n", ++round);
                printf ("Player 1 (%d): ");
                printChampionList(player1); printf ("\n");
                printf ("Player 2 (%d): ");
                printChampionList(player2); printf ("\n");
                ChampionRole role1 = player1->role;
                ChampionRole role2 = player2->role;
                int level1 = player1->level;
                int level2 = player2->level;
                player1 = removeChampion(player1);
                player2 = removeChampion(player2);
                if (role1 == MAGE && role2 == MAGE) 
                {
                    printf ("Player 1 is a MAGE and Player 2 is a MAGE\n");
                    if (level1 > level2) 
                    {
                        printf ("Player 2 (MAGE) loses one champion.\n");
                        printf ("Player 1 (MAGE) wins and gains one new champion.\n");
                        Champion* champion = createChampion();
                        player1 = addChampion(player1, champion);
                        player2 = removeChampion(player2);
                    } 
                    else if (level1 < level2) 
                    {
                        printf ("Player 1 (MAGE) loses one champion.\n");
                        printf ("Player 2 (MAGE) wins and gains one new champion.\n");
                        Champion* champion = createChampion();
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2, champion);
                    } 
                    else 
                    {
                        printf ("Draw\n");
                    }
                    if (!isGameRunning(player1, player2)) 
                    {
                    destroyChampionList(player1);
                    destroyChampionList(player2);
                    // ends the entire game
                    break;
                    }
                }
            }
        }
    }
}
return 0;
































