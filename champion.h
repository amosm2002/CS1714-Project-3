/*
champion.h
Assignment Project 3
Amos Munteanu
This file stores the enum and function names
*/ 
#ifndef CHAMPION_H
#define CHAMPION_H

typedef enum ChampionRole{MAGE, FIGHTER, SUPPORT, TANK} ChampionRole;
typedef struct Champion{
    ChampionRole role;
    int level;
    struct Champion* next;
}Champion;

/*
Function: createChampion
dynamically allocates new Champions
generates 4 differnt roles of Champions
gives each champion type a role
Return: the created champion
*/ 

Champion* createChampion(); 

/*
Function: removeChampion
removes a champion from the list 
Returns: newHead
*/ 


Champion* removeChampion(Champion* head);

/*
Function: addChampion
this function add's a champion to the deck 
Returns: new head
*/ 

Champion* addChampion(Champion* head, Champion* Champion);

/*
Function: printChampion
this function prints the champion letter 
Returns: letter and level of the champion
*/ 

void printChampion(Champion* Champion);

/*
Function: printChampionList
this function prints the current champion list
Returns: Champion's printed list
*/ 

void printChampionList(Champion* head);

/*
Function: buildChampionList
this function biulds the list for the deck 
Returns: champion list
*/ 

Champion* buildChampion(int n);

/*
Function: destroyChampionList
this function destroyes the entire champion list by delteing all nodes in the linked list
Returns: null
*/ 

Champion* destroyChampion(Champion* Champion);

/*
Function: getLength
this function gets the length of the champion to help determin with the game is over
Returns: length of the deck
*/ 

int getLength(Champion* head);

/*
Function: printLastList
this function prist the last lsit for the game
Returns: prints last cards
*/ 

void printLastList(Champion* player1, Champion* player2);

#endif