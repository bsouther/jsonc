/* 
 * Ben Souther
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RED   "\x1B[31m"
#define CYAN  "\x1B[36m"
#define RESET "\x1b[0m" 

void colorize(FILE *fp){

    int  c;
    int  nextChar = EOF;
    int  last     = EOF;
    bool instr    = false;
    bool inesc    = false;

    for(c = EOF; (c = getc(fp)) != EOF; ){

        if(instr){
            if(inesc){
                inesc = false;
                printf("%c", c);
            }else if(c == '\\'){
                inesc = true;
                printf("%c", c);
            }else if(c == '"' && last != '\\'){
                instr = false;
                printf("%c", c);
                printf("%s", RESET);
                last = c;
                continue;
            }
            printf("%c", c);

        }else{
            if(c == '"'){
                printf("%s", RED);
                instr = true;
                printf("%c", c);
            }else{

                /* control characters */
                if(c == '{' || c == '[' || c == ']' || c == '}' || c == ',' || c == ':'){
                    printf("%s%c%s",CYAN, c, RESET);


                    /* Should be the end of the JSON doc, flush stdout */
		    if(c == '}' && last == '\n'){
                        fflush(stdout);
                    }

                /* booleans or numerics */
                }else if( c == 't' || c == 'r' || c == 'u' || c == 'e' ||
                          c == 'f' || c == 'a' || c == 'l' || c == 's' || 
                          c == '0' || c == '1' || c == '2' || c == '3' ||
                          c == '4' || c == '5' || c == '6' || c == '7' ||
                          c == '8' || c == '9' || c == '-' || c == '.' ||
                          c == 'n' || c == 'l'){

                    printf("%s%c%s",RED, c, RESET);
                }else{
                    printf("%c", c);
                }
            }
        }

        last = c;
    }// for
}// colorize



/* Entry point ... */
int main(int argc, char *argv[]){
    FILE *fp = stdin;

    if(argc == 2){      /* work off a file */
        fp = fopen(argv[1], "r");
        if(!fp){
            fprintf(stderr, "Unable to open file: %s\n", argv[1]);
            return 1;
        }
    }
    
    if(fp!=stdin){
        fclose(fp);
    }
    colorize(fp);
    return 0;
}







