#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


t_tree creation_arbre(){
    t_tree arbre;
    arbre.root = createNode(' ');
    return arbre;

}

t_tree arbre_des_mots(t_tree arbre, char * mot){
    ajout_mot(arbre.root, mot);
    return arbre;
}
