#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define sizes 4096
#define body1 "<BODY"
#define body2 "<body"
#define retssimbol '<'
#define retssimbol2 '>'
int main(){
    char buffer[sizes];
    char buffer2[sizes];
    int lens=0;
    int counter=0;
    int cursor=0;
    int n=0;
    int b= true;
    int bb=false;
    int closesb=false;
    int rect=false;
    printf("\033c\033[43;30m\n\n");
    while(b){
        fgets(buffer,sizes-1,stdin);
        lens=strlen(buffer);
        for (n=0;n<lens-1;n++){
            if(!bb){
                
               
                    if(counter<6){
                        if(counter==5){
                             buffer2[counter]=buffer[n];
                             if(strncmp(buffer2,body1,5)==0 ||strncmp(buffer2,body2,5)==0 ){
                                 bb=true;
                                 closesb=false;
                             }
                        }else{
                             buffer2[counter]=buffer[n];
                        }
                    }
                
                    if(buffer[n]==retssimbol){
                        
                        counter=0;
                    }
                counter++;
            }else{
                   if(buffer[n]==retssimbol){
                        
                        closesb=false;
                    }
                    if(buffer[n]==retssimbol2){
                        
                        closesb=true;
                    }

                

                if(closesb) printf("%c",buffer[n]);
            }
        }
        
        if(feof(stdin))b=false;
    }
    return 0;
}
