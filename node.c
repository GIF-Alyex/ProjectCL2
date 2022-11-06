#include "node.h"
#include <stdio.h>
#include <stdlib.h>


p_node createNode(char val){
    p_node nouv;
    // nouv = (p_node)malloc(sizeof(t_node));
    nouv->carac = val;
    nouv->isWord = 0;
    nouv->word = NULL;
    for(int i = 0; i < 26; i++){
        nouv->next_letter[i] = NULL;
    }
    return nouv;

}



void ajout_mot(p_node p, char * mot){
    if(mot == '\0'){
        p->isWord = 1;
        return;
    }
    for(int i = 0; i<26 ; i++){
        if(p->next_letter[i]->carac == mot){
            ajout_mot(p->next_letter[i], mot+1);
        }
        else if(p->next_letter[i]== NULL){
            p_node nouv_lettre = createNode(mot);
            p->next_letter[i] = nouv_lettre;
            ajout_mot(p->next_letter[i], mot+1);
        }
    }

}