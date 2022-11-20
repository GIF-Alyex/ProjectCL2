#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  //pour srand et avoir des nombres pseudos-aléatoires
#include "tab_mots.h"
#include "tree.h"


//////////////////
// DEFINITION.C //
//////////////////




p_def createDef(char * def, char * bas, char * flech){
    p_def def_word;
    def_word = malloc(sizeof(t_def));
    int cmt = 0;
    int i = 4;
    int j;

    if((def[0] == 'A' && def[1] == 'd' && def[2] == 'j') || (def[0] == 'N' && def[1] == 'o' && def[2] == 'm')){
        if((def[0] == 'A' && def[1] == 'd' && def[2] == 'j')){
            def_word->adj = 1;
            def_word->adv = def_word->ver = def_word->nom = 0; 
            def_word->flechie = malloc((strlen(flech)+1)*sizeof(char));
            def_word->base = malloc((strlen(bas)+1)*sizeof(char));
            strcpy(def_word->flechie, flech);
            strcpy(def_word->base, bas);
        }
        else{
            def_word->nom = 1;
            def_word->adv = def_word->ver = def_word->adj = 0;
            def_word->flechie = malloc((strlen(flech)+1)*sizeof(char));
            def_word->base = malloc((strlen(bas)+1)*sizeof(char));
            strcpy(def_word->flechie, flech);
            strcpy(def_word->base, bas);
        }
        if(def[4] == 'M'){
            def_word->masc = 1;
            def_word->fem = 0;
            if(def[8] == 'S'){
                def_word->nb = 0;
            }
            else{
                def_word->nb = 1;
            }
        }
        else if (def[4] == 'F'){
            def_word->fem = 1;
            def_word->masc = 0;
            if(def[8] == 'S'){
                def_word->nb = 0;
            }
            else{
                def_word->nb = 1;
            }
        }
        else{
            def_word->masc = def_word->fem = 0;
            if(def[11] ==  'S'){
                def_word->nb = 0;
            }
            else{
                def_word->nb = 1;
            }
        }
    }


    else if (def[0] == 'A' && def[1] == 'd' && def[2] == 'v'){
        def_word->adv = 1;
        def_word->adj = def_word->nom = def_word->ver = def_word->masc = def_word->fem = def_word->nb = 0;
        def_word->flechie = malloc((strlen(flech)+1)*sizeof(char));
        def_word->base = malloc((strlen(bas)+1)*sizeof(char));
        strcpy(def_word->flechie, flech);
        strcpy(def_word->base, bas);
    }


    else if((def[0] == 'V' && def[1] == 'e' && def[2] == 'r') && ( (def[4] == 'I' && ( (def[5] == 'n' && def[6] == 'f') || (def[5] == 'I' && def[6] == 'm' && def[7] == 'p') || (def[5] == 'P' && def[6] == 'r' && def[7] == 'e') ) ) || (def[4] == 'S' && def[5] == 'P' && def[6] == 'r' && def[7] == 'e') ) ){
        
        
            while(def[i] != '\0')
            {
            if(def[i] == '3')
            {
                if(cmt == 0)
                {
                    j = i - 4;
                }
                cmt++;
            }
            i++;
            }
            if((cmt>0) || (def[4] == 'I' && def[5] == 'n' && def[6] == 'f'))
            {
                def_word->ver = 1;
                def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = 0;
                def_word->flechie = malloc((strlen(flech)+1)*sizeof(char));
                def_word->base = malloc((strlen(bas)+1)*sizeof(char));
                strcpy(def_word->flechie, flech);
                strcpy(def_word->base, bas);
                if((def[j] == 'P') || (def[4] == 'I' && def[5] == 'n' && def[6] == 'f')){
                    def_word->nb = 1;
                }
                else{
                    def_word->nb = 0;
                }
            }
            else 
            {
                def_word->ver = 0;
                def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = def_word->nb = 0;
            }
        
    }


    
    else{
        def_word->ver = def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = def_word->nb = 0;
    }

        
    return def_word;
}




////////////
// NODE.C //
////////////



p_node createNode(char val){
    p_node nouv;
    nouv = (p_node)malloc(sizeof(t_node));
    nouv->carac = val;
    nouv->isWord = 0;
    nouv->size = 0;
    for(int k = 0; k < 20; k++){
        nouv->word[k] = malloc(sizeof(t_def));
    }
    for(int i = 0; i < 26; i++){
        nouv->next_letter[i] = NULL;
    }
    return nouv;

}


void free_tab_def(p_node pn){
    int i = 0;
    int j = 20;
    while(pn->word[i] != NULL || i<20){
        i++;
    }
    while(pn->word[0] != NULL){
        pn->word[i-1] == NULL;
        i = i - 1;
    }
    while(j > 0){
        free(pn->word[j-1]);
        j = j - 1;
    }
}


void free_node(p_node pn){
    int k;
    int compt = 0;
    for(int i = 0; i < 26; i++){
        if(pn->next_letter[i] != NULL){
            compt++;
        }
    }
    if(compt == 0){
        free_tab_def(pn);
        pn = NULL;
        free(pn);
        return;
    }
    while(pn->next_letter[0] != NULL){
        k = 0;
        while(pn->next_letter[k+1] != NULL || k < 25){
            k++;
        }
        free_node(pn->next_letter[k]);
    }
}


void ajout_mot(p_node p, char * def, char * bas, char * clabase, char * mot){
    if(bas[0] == '\0'){
        p->isWord = 1;
        p->word[p->size] = createDef(def, clabase, mot);
        p->size = p->size + 1;
        return;
    }
    for(int i = 0; i<26 ; i++){
        if(p->next_letter[i]== NULL){
            p_node nouv_lettre = createNode(bas[0]);
            p->next_letter[i] = nouv_lettre;
            ajout_mot(p->next_letter[i], def, bas+1, clabase, mot);
            return;
        }
        else if(p->next_letter[i]->carac == bas[0]){
            ajout_mot(p->next_letter[i], def, bas+1, clabase, mot);
            return;
        }
    }
    //return;

}


p_node findNode(p_node pn, char c){
    if(pn == NULL){
        return NULL;
    }
    if(pn->carac == c){
        return pn;
    }
    p_node found;
    for(int i = 0; i < 26; i++){
        found = findNode(pn->next_letter[i], c);
        if( (found != NULL) ){
            return found;
        }
    }
}

p_node extractNode(p_node pn, char * rbas){
    int i = 0;
    p_node tmp = pn;
    while(rbas[i] != '\0'){
        tmp = findNode(tmp, rbas[i]);
        i = i + 1;
    }
    return tmp;
}

////////////
// TREE.C //
////////////



t_tree creation_arbre(){
    t_tree arbre;
    arbre.root = createNode(' ');
    return arbre;

}


void arbre_des_mots(t_tree arbre, char * def, char * bas, char * clabase, char * mot){
    ajout_mot(arbre.root, def, bas, clabase, mot);
    return;
}


void free_tree(t_tree arbre){
    free_node(arbre.root);
    free(arbre.root);
}


p_node extractNodeFromTree(t_tree t, char * rbas){
    extractNode(t.root, rbas);
}

////////////////
// TAB_MOTS.C //
////////////////

p_tab_mots createTabMots(){
    p_tab_mots nouv = malloc(sizeof(t_tab_mots));
    for(int k = 0; k < 10000; k++){
        nouv->forme_bases[k] = malloc(30*sizeof(char));
    }
    nouv->size = 0;
    return nouv;
}


void add_mot_tab(p_tab_mots tab, char *bas){
    int i = 0;
    while(i < tab->size){
        if(strcmp(tab->forme_bases[i],bas) == 0){
            return;
        }
        i++;
    }
    strcpy(tab->forme_bases[tab->size],bas);
    tab->size = tab->size + 1;
    return;
}


void free_tab_mots(p_tab_mots tab){
    for(int k = 0; k < 20; k ++){
        free(tab->forme_bases[k]);
    }
    free(tab);
}

//strcpy(tab->forme_bases[tab->size],bas);



///////////////////     ///////////////////     ///////////////////
// Jeux de Tests //     // Jeux de Tests //     // Jeux de Tests //
///////////////////     ///////////////////     ///////////////////   



////////////////////////////////////
// CREATION DE DEFINITIONS (TEST) //
////////////////////////////////////

/*

        printf("flechie : %s\n",flech);
        printf("base : %s\n",bas);
        printf("def : %s\n",def);
        printf("%d\n",definition->adj);
        printf("%d\n",definition->ver);
        printf("%d\n",definition->nom);
        printf("%d\n",definition->adv);
        printf("%d\n",definition->masc);
        printf("%d\n",definition->fem);
        printf("%d\n",definition->nb);
        
*/


//////////////////////////////////////////////////////////////////////////////
// CREATION ARBRES + TABLEAUX DE FORMES DE BASE + TEST CONTENU DES TABLEAUX //
//////////////////////////////////////////////////////////////////////////////

/*
char flech[30];
    char bas[30];
    char def[150];

    
    t_tree arbre_adj = creation_arbre();
    t_tree arbre_adv = creation_arbre();
    t_tree arbre_nom = creation_arbre();
    t_tree arbre_ver = creation_arbre();

    p_tab_mots tab_nom = createTabMots();
    p_tab_mots tab_adj = createTabMots();
    p_tab_mots tab_adv = createTabMots();
    p_tab_mots tab_ver = createTabMots();

    while (!feof(fic)){
        p_def definition;
        fscanf(fic,"%s %s %s", flech, bas, def);
        char *clabase = bas;
        definition = createDef(def,bas,flech);
        if (definition->adj == 1){
            arbre_des_mots(arbre_adj, def, bas, clabase, flech);
            add_mot_tab(tab_adj,bas);
        }
        else if(definition->ver == 1){
            arbre_des_mots(arbre_ver, def, bas, clabase, flech);
            add_mot_tab(tab_ver,bas);
        }
        else if(definition->adv == 1){
            arbre_des_mots(arbre_adv, def, bas, clabase, flech);
            add_mot_tab(tab_adv,bas);
        }
        else if(definition->nom == 1){
            arbre_des_mots(arbre_nom, def, bas, clabase, flech);
            add_mot_tab(tab_nom,bas);
        }
        else{

        }
    }
    printf("%d\n",tab_nom->size);
    for(int i = 0; i < tab_nom->size; i++){
        printf("%s\n", tab_nom->forme_bases[i]);
    }
    printf("\n");
    printf("%d\n",tab_adj->size);
    for(int i = 0; i < tab_adj->size; i++){
        printf("%s\n", tab_adj->forme_bases[i]);
    }
    printf("\n");
    printf("%d\n",tab_ver->size);
    for(int i = 0; i < tab_ver->size; i++){
        printf("%s\n", tab_ver->forme_bases[i]);
    }
    printf("\n");
    printf("%d\n",tab_adv->size);
    for(int i = 0; i < tab_adv->size; i++){
        printf("%s\n", tab_adv->forme_bases[i]);
    }
    printf("\n");
*/



////////////////////////////////////////////////////////////////////////
// CREATION DE "PHRASES" AVEC DES FORMES DE BASE DE MANIÈRE ALÉATOIRE //
////////////////////////////////////////////////////////////////////////


/*
    srand((unsigned) time(NULL));

    int ri_nom_a = rand() % (tab_nom->size);
    int ri_nom_b = rand() % (tab_nom->size);
    int ri_ver_a = rand() % (tab_ver->size);
    int ri_ver_b = rand() % (tab_ver->size);
    int ri_adj = rand() % (tab_adj->size); // random_value_from_min_to_max = min + rand() % (max + 1 - min)
    int ri_adv = rand() % (tab_adv->size);

    char * r_nom_a = tab_nom->forme_bases[ri_nom_a];
    char * r_nom_b = tab_nom->forme_bases[ri_nom_b];
    char * r_ver_a = tab_ver->forme_bases[ri_ver_a];
    char * r_ver_b = tab_ver->forme_bases[ri_ver_b];
    char * r_adj = tab_adj->forme_bases[ri_adj];
    char * r_adv = tab_adj->forme_bases[ri_adv];

    printf("%s %s %s %s\n", r_nom_a, r_adj, r_ver, r_nom_b);
*/



///////////////////////////////////////////////////////////////////////////////////////////////////////////
// EXTRACTION DES FORMES FLÉCHIES : ATTENTION !!! PROBLÈME DÈS LES MOTS COMMENÇANT PAR LA LETTRE 'R' ??? //
///////////////////////////////////////////////////////////////////////////////////////////////////////////



/*
    p_node flech_r_nom_a = malloc(sizeof(p_node));

    flech_r_nom_a = extractNodeFromTree(arbre_nom, r_nom_a);
    if(flech_r_nom_a != NULL){
        printf("%c\n", flech_r_nom_a->carac);
    }
    else{
        printf("PROBLEME !!!\n");
    }


    //p_def def_r_nom_a = malloc(sizeof(p_def));
    //def_r_nom_a = flech_r_nom_a->word[0];
    //printf("%s\n", def_r_nom_a->flechie);
    
    free(flech_r_nom_a);
    //free(def_r_nom_a);
*/



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(){

    FILE *fic = fopen("minidico.txt", "r");

    char flech[30];
    char bas[30];
    char def[150];

    
    t_tree arbre_adj = creation_arbre();
    t_tree arbre_adv = creation_arbre();
    t_tree arbre_nom = creation_arbre();
    t_tree arbre_ver = creation_arbre();

    p_tab_mots tab_nom = createTabMots();
    p_tab_mots tab_adj = createTabMots();
    p_tab_mots tab_adv = createTabMots();
    p_tab_mots tab_ver = createTabMots();

    while (!feof(fic)){
        p_def definition;
        fscanf(fic,"%s %s %s", flech, bas, def);
        char *clabase = bas;
        definition = createDef(def,bas,flech);
        if (definition->adj == 1){
            arbre_des_mots(arbre_adj, def, bas, clabase, flech);
            add_mot_tab(tab_adj,bas);
        }
        else if(definition->ver == 1){
            arbre_des_mots(arbre_ver, def, bas, clabase, flech);
            add_mot_tab(tab_ver,bas);
        }
        else if(definition->adv == 1){
            arbre_des_mots(arbre_adv, def, bas, clabase, flech);
            add_mot_tab(tab_adv,bas);
        }
        else if(definition->nom == 1){
            arbre_des_mots(arbre_nom, def, bas, clabase, flech);
            add_mot_tab(tab_nom,bas);
        }
    }


    int choice=0;
    while(choice==0){
        printf("Bienvenue dans le générateur de phrase:\nQue voulez-vous faire ?\n1) Générer des phrases aléatoirement selon un modèle\n2) Quitter\n");
        scanf("%d",&choice);
        if (choice==1){
            printf("\n");
            printf("\n");
            int lowchoice=0;
            while(lowchoice==0){

                    srand((unsigned) time(NULL));

                    int ri_nom_a = rand() % (tab_nom->size);
                    int ri_nom_b = rand() % (tab_nom->size);
                    int ri_ver_a = rand() % (tab_ver->size);
                    int ri_ver_b = rand() % (tab_ver->size);
                    int ri_adj = rand() % (tab_adj->size); // random_value_from_min_to_max = min + rand() % (max + 1 - min)
                    int ri_adv = rand() % (tab_adv->size);

                    char * r_nom_a = tab_nom->forme_bases[ri_nom_a];
                    char * r_nom_b = tab_nom->forme_bases[ri_nom_b];
                    char * r_ver_a = tab_ver->forme_bases[ri_ver_a];
                    char * r_ver_b = tab_ver->forme_bases[ri_ver_b];
                    char * r_adj = tab_adj->forme_bases[ri_adj];
                    char * r_adv = tab_adj->forme_bases[ri_adv];


                printf("Quel modèle voulez-vous utiliser ?\n1) Nom - adjectif - verbe - nom\n2) Nom - 'qui' - verbe - verbe - nom - adjectif\n3) Nom - verbe - adverbe\n4) Retour\n");
                scanf("%d",&lowchoice);
                printf("\n");
                printf("\n");
                printf("\n");
                if (lowchoice==1){
                    printf("%s %s %s %s\n", r_nom_a, r_adj, r_ver_a, r_nom_b);
                    lowchoice = 0;
                }
                if (lowchoice==2){
                    printf("%s qui %s %s %s %s\n", r_nom_a, r_ver_a, r_ver_b, r_nom_b, r_adj);
                    lowchoice = 0;
                }
                if (lowchoice==3){
                    printf("%s %s %s\n", r_nom_a, r_ver_a, r_adv);
                    lowchoice = 0;
                }
                printf("\n");
                printf("\n");
                printf("\n");
                if(lowchoice == 4){
                    choice = 0;
                }
                if (0 > lowchoice || lowchoice > 4){
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("Le choix n'est pas valide\n");
                    lowchoice=0;
                    printf("\n");
                    printf("\n");
                    printf("\n");
                }
            }
        }
        if (choice == 2){
            printf("Vous sortez du programme !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
        if (0>choice || choice>2){
            printf("\n");
            printf("\n");
            printf("\n");
            printf("Le choix n'est pas valide\n");
            choice=0;
            printf("\n");
            printf("\n");
            printf("\n");
        }
    }




    fclose(fic);


    return 0;
}
