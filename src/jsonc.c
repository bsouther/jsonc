/*  First Draft.
 *  It's ugly (for now) but works with stdin.'
 *  Ben Souther
 */



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define RED   "\x1B[31m"
#define CYAN  "\x1B[36m"
#define RESET "\x1b[0m" 

int nextChar = EOF;
bool instr = false;
bool inesc = false;


int get(){
  return getc(stdin);
}

void colorize(){
    int last;
    int c;
    last = EOF;
    for(c = EOF; (c = get()) != EOF; ){

        if(instr){
            if(inesc){
                inesc = false;
                printf("%c", c);
                last = c;
                continue;
            }
            if(c == '\\'){
                inesc = true;
                printf("%c", c);
                last = c;
                continue;
            }
            if(c == '"' && last != '\\'){
                instr = false;
                printf("%c", c);
                printf("%s", RESET);
                last = c;
                continue;
            }
        }else{
            if(c == '"'){
                printf("%s", RED);
                instr = true;
            }else{

                // control characters
                if(c == '{' || c == '[' || c == ']' || c == '}' || c == ',' || c == ':'){
                    printf("%s%c%s",CYAN, c, RESET);
                    last = c;
                    continue;

                // booleans or numerics
                }else if( c == 't' || c == 'r' || c == 'u' || c == 'e' ||
                          c == 'f' || c == 'a' || c == 'l' || c == 's' || 
                          c == '0' || c == '1' || c == '2' || c == '3' ||
                          c == '4' || c == '5' || c == '6' || c == '7' ||
                          c == '8' || c == '9' || c == '-' || c == '.'){

                    printf("%s%c%s",RED, c, RESET);
                    last = c;
                    continue;
                }
            }
        }

        printf("%c", c);
        last = c;
    }// for
}// colorize

int main(int argc, char* argv){
    colorize();
    return 0;
}







