#include <stdio.h>
#include <stdlib.h>
#include "definition.h"




p_def createDef(char * def, char * bas, char * flech){
    p_def def_word;
    int cmt = 0;
    int i = 4;
    int j;

    if((def[0] == 'A' && def[1] == 'd' && def[2] == 'j') || (def[0] == 'N' && def[1] == 'o' && def[2] == 'm')){
        if((def[0] == 'A' && def[1] == 'd' && def[2] == 'j')){
            def_word->adj = 1;
            def_word->adv = def_word->ver = def_word->nom = 0; 
            def_word->flechie = flech;
            def_word->base = bas;
        }
        else{
            def_word->nom = 1;
            def_word->adv = def_word->ver = def_word->adj = 0;
            def_word->flechie = flech;
            def_word->base = bas;
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
        def_word->flechie = flech;
        def_word->base = bas;
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
                def_word->flechie = flech;
                def_word->base = bas;
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
