#ifndef PROJET_C_GAP_NODE_H

#define PROJET_C_GAP_NODE_H



#include "definition.h"



struct s_node

{
    char carac;
    struct s_node *next_letter[26];  // 26 fils pour 26 lettres

    int isWord;                      // {0,1} , 0 si le caractère N'EST PAS le caractère final d'un mot, 1 sinon

    p_def word[20];                      // toutes les informations sur les mots fléchis ayant cette forme de base
    int size;

};



typedef struct s_node t_node, *p_node;

/*
p_node createNode(char);

void free_node(p_node)

void ajout_mot(p_node, char *, char *, char *);
*/

#endif //PROJET_C_GAP_NODE_H




