#include "node.h"
#include "definition.c"
#include <stdio.h>
#include <stdlib.h>


p_node createNode(char val){
    p_node nouv;
    nouv = (p_node)malloc(sizeof(t_node));
    nouv->carac = val;
    nouv->isWord = 0;
    for(int k = 0; k < 20; k++){
        nouv->word[k] = NULL;
    }
    for(int i = 0; i < 26; i++){
        nouv->next_letter[i] = NULL;
    }
    return nouv;

}



void ajout_mot(p_node p, char * def, char * bas, char * mot){
    int k = 0;
    if(bas[0] == '\0'){
        p->isWord = 1;
        while(p->word[k] != NULL){
            k++;
        }
        p->word[k] = createDef(def, bas, mot);
        return;
    }
    for(int i = 0; i<26 ; i++){
        if(p->next_letter[i]->carac == bas[0]){
            ajout_mot(p->next_letter[i], def, bas+1, mot);
        }
        else if(p->next_letter[i]== NULL){
            p_node nouv_lettre = createNode(bas[0]);
            p->next_letter[i] = nouv_lettre;
            ajout_mot(p->next_letter[i], def, bas+1, mot);
        }
    }

}