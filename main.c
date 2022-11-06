#include <stdio.h>
#include <stdlib.h>
#include "definition.h"
#include "definition.c"

/*

p_def def_ver(char * def){
    p_def def_word;
    int cmt = 0;
    int i = 4;
    int j;
    if ((def[0] == 'V' && def[1] == 'e' && def[2] == 'r') && ( (def[4] == 'I' && ( (def[5] == 'n' && def[6] == 'f') || (def[5] == 'I' && def[6] == 'm' && def[7] == 'p') || (def[5] == 'P' && def[6] == 'r' && def[7] == 'e') ) ) || (def[4] == 'S' && def[5] == 'P' && def[6] == 'r' && def[7] == 'e') ) ){
        if (def[4] == 'I' && def[5] == 'n' && def[6] == 'f'){
            def_word->ver == 1;
            def_word->nb = 1;
            def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = 0;
        }
        else{
            while(def[i] != '\0'){
            if(def[i] == '3'){
                if(cmt == 0){
                    j = i - 4;
                }
                cmt++;
            }
            i++;
            }
            if(cmt>0){
                def_word->ver = 1;
                def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = 0;
                if(def[j] == 'S'){
                    def_word->nb = 0;
                }
                else{
                    def_word->nb = 1;
                }
            }
            else{
                def_word->ver = def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = def_word->nb = 0;
            }
        }
    }
    else{
        def_word->ver = def_word->adj = def_word->nom = def_word->adv = def_word->masc = def_word->fem = def_word->nb = 0;
    }
    return def_word;

}

*/


int main(){

    FILE *fic = fopen("dictionnaire_non_accentue.txt", "r");

    char flechie[30];
    char base[30];
    char def[100];
    p_def definition;


    while (!feof(fic)){
        fscanf(fic,"%s %s %s", flechie, base, def);
        printf("flechie : %s\n",flechie);
        printf("base : %s\n",base);
        printf("def : %s\n",def);
        definition = createDef(def);
        printf("%d\n",definition->adj);
        printf("%d\n",definition->ver);
        printf("%d\n",definition->nom);
        printf("%d\n",definition->adv);
        printf("%d\n",definition->masc);
        printf("%d\n",definition->fem);
        printf("%d\n",definition->nb);
    }
    
    fclose(fic);


    return 0;
}