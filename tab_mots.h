//

// Created by maxka on 08/11/2022.

//



#ifndef PROJET_C_GAP_TAB_MOTS_H

#define PROJET_C_GAP_TAB_MOTS_H



// structure stockant toutes les informations du mot



struct s_tab_mots{
    char * forme_bases[10000];
    int size;

};

typedef struct s_tab_mots t_tab_mots, *p_tab_mots;

/*
p_tab_mots createTabMots();

void add_mot_tab(p_tab_mots tab, char *);
*/

#endif //PROJET_C_GAP_TAB_MOTS_H
