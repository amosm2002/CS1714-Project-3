/*
champion.c
Assignment Project 3
Amos Munteanu
This file stores all of the function's and their logic to make main.c file work
*/ 


#include <stdio.h>
#include <stdlib.h>
#include "champion.h"


/*
Function: createChampion
dynamically allocates new Champions
generates 4 differnt roles of Champions
gives each champion type a role
Return: the created champion
*/ 


Champion* createChampion()
{
    Champion* Champion = (Champion*) malloc(sizeof(Champion));
    if (Champion == NULL)   exit (EXIT_FAILURE);
    int number = (1 + rand() % 100);
    if (number <= 25) 
    {
        Champion->role = MAGE;
        Champion->level = 5 + rand() % 4;
    } else if (number < 25 && number <= 50) 
    {
        Champion->role = FIGHTER;
        Champion->level = 1 + rand() % 4;
    } else if (number < 50 && number <= 75) 
    {
        Champion->role = SUPPORT;
        Champion->level = 3 + rand() % 4;
    } else 
    {
        Champion->role = TANK;
        Champion->level = 1 + rand() % 8;
    }
    Champion->next = NULL;
    return Champion;
}

/*
Function: removeChampion
removes a champion from the list 
Returns: newHead
*/ 

Champion* removeChampion( Champion *head )
{
    if (head == NULL)   return head;
    Champion* newHead = head->next;
    free (head);
    return newHead;
}

/*
Function: addChampion
this function add's a champion to the deck 
Returns: new head
*/ 
Champion* addChampion( Champion *head, Champion *c )
{
    if (head == NULL)   return Champion;
    if (Champion == NULL)   return head;
    if (Champion->level > head->level) 
    {
        Champion->next = head;
          return champion;
    }
     Champion* prevChampion = NULL;
    Champion* tempChampion = head;
    while (tempChampion != NULL && tempChampion->level >= Champion->level) 
    {
        prevChampion = tempChampion;
        tempChampion = tempChampion->next;
    }
    Champion->next = tempChampion;
    prevChampion->next = Champion;
    return head;
}

/*
Function: printChampion
this function prints the champion letter 
Returns: letter and level of the champion
*/ 

void printChampion(Champion* Champion) 
{
    if (Champion != NULL) 
    {
        char role = 'M';
        if (Champion->role == FIGHTER)   role = 'F';
        else if (Champion->role == SUPPORT) role = 'S';
        else if (Champion->role == TANK) role = 'T';
        printf ("%c%d ", role, Champion->level);
    }
}

/*
Function: printChampionList
this function prints the current champion list
Returns: Champion's printed list
*/ 

void printChampionList( Champion *head ) 
{
    Champion* tempChampion = head;
    while (tempChampion != NULL) 
    {
        printChampion(tempChampion);
        tempChampion = tempChampion->next;
    }
}

/*
Function: destroyChampionList
this function destroyes the entire champion list by delteing all nodes in the linked list
Returns: null
*/ 

Champion* destroyChampionList( Champion *head ) 
{
    do 
    {
        head = removeChampion(head);
    }
    while (head != NULL);
    return NULL;
}
/*
Function: buildChampionList
this function biulds the list for the deck 
Returns: champion list
*/ 

Champion* buildChampionList( int n )
{
    Champion* head = NULL;
    for (int i = 0; i < n; ++i) 
    {
        Champion* Champion = createChampion();
        head = addChampion(head, Champion);
    }
    return head;
}

/*
Function: getLength
this function gets the length of the champion to help determin with the game is over
Returns: length of the deck
*/ 

int getLength(Champion* head) 
{ 
    int length = 0;
    while (head != NULL) 
    {
        length++;
        head = head->next;
    }
    return length;
}






















    