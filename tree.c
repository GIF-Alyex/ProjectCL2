#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


t_tree creation_arbre(){
    t_tree arbre;
    arbre.root = createNode(' ');
    return arbre;

}

void arbre_des_mots(t_tree arbre, char * def, char * bas, char * mot){
    ajout_mot(arbre.root, def, bas, mot);
    return;
}
