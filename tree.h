#ifndef PROJET_C_GAP_TREE_H

#define PROJET_C_GAP_TREE_H



#include "node.h"



typedef struct s_tree
{
    p_node root;

} t_tree, *p_tree;


t_tree creation_arbre();

t_tree arbre_des_mots(t_tree, char *);


#endif