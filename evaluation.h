#ifndef EVALUATION_H_INCLUDED
#define EVALUATION_H_INCLUDED

#include "backgammon.h"
#include "backgammon_private.h"

#include "possibles.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct played_board
{
        sZone  board[28];
        struct played_board* next;
}played_board;

typedef struct
{
        signed char triangle[28];
        unsigned int win;
        unsigned int loose;
}b_ligne;

typedef struct decatree
{
        struct decatree *next[13];
        unsigned int win;
        unsigned int loose;
}decatree;

decatree *create_decatree(FILE* ressource);
decatree *add_ligne(decatree *arbre, b_ligne *ligne, int prof);

possible_movements *eval(FILE* ressource, const possible_movements *liste);

int existe2(decatree *arbre, const sZone board[28], float *note, int *sens);
int existe(FILE *ressource, const sZone board[28], float *note, int *sens);

void add_plateau(FILE* ressource,  const sZone board[28], const ePlayer winner);
played_board *memorise(played_board *liste, const sZone board[28]);

void free_memorise(played_board *liste);

#endif
