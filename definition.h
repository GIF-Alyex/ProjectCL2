//

// Created by maxka on 03/11/2022.

//



#ifndef PROJET_C_GAP_DEFINITION_H

#define PROJET_C_GAP_DEFINITION_H



// structure stockant toutes les informations du mot



struct s_definition{
    int nom;
    int adj;
    int adv;
    int ver;
    int nb; // 0 pour singulier et !=0 sinon
    int masc;
    int fem;

};

typedef struct s_definition t_def, *p_def;

// char * def_type(char *);
p_def createDef(char *);


#endif //PROJET_C_GAP_DEFINITION_H


