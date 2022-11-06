#ifndef PROJET_C_GAP_NODE_H

#define PROJET_C_GAP_NODE_H



#include "definition.h"



struct s_node

{

    char carac;

    struct s_node *next_letter[26];  // 26 fils pour 26 lettres

    int isWord;                      // {0,1} , 0 si le caractère N'EST PAS le caractère final d'un mot, 1 sinon

    p_def word;                      // toutes les informations sur le mot

};



typedef struct s_node t_node, *p_node;


p_node createNode(char);

void ajout_mot(p_node, char *);


#endif //UNTITLED_NODE_H




