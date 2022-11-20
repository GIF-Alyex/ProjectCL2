#include "tab_mots.h"
#include <stdio.h>
#include <stdlib.h>


p_tab_mots createTabMots(){
    p_tab_mots nouv;
    nouv->size = 0;
    return nouv;
}


void add_mot_tab(p_tab_mots tab, char *bas){
    int i = 0;
    while(i < tab->size){
        if(tab->forme_bases[i] == bas){
            return;
        }
        i++;
    }
    tab->forme_bases[tab->size] = bas;
    tab->size = tab->size + 1;
    return;
}