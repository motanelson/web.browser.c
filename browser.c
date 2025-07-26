#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
#define sizes 4096
#define body1 "<BODY"
#define body2 "<body"
#define script1 "<SCRIPT"
#define script2 "<script"
#define script3 "</SCRIPT"
#define script4 "</script"
#define href1 "href"
#define href2 "HREF"
#define br1 "<BR"
#define br2 "<br"
#define p1 "<P"
#define p2 "<p"
#define pe1 "</P"
#define pe2 "</p"
#define retssimbol '<'
#define retssimbol2 '>'
#define reth 'h'
#define reth2 'H'
#define retas '\"'
#define sp ' '
int main(){
    char buffer[sizes];
    char buffer2[sizes];
    char buffer3[sizes];
    int lens=0;
    int counter=0;
    int counter3=0;
    int counter4=0;
    int cursor=0;
    int n=0;
    int b= true;
    int bb=false;
    int bbb=false;
    int bts=false;
    int sbts=false;
    int closesb=false;
    int spaces=false;
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
                                 counter=0;
                                 bbb=true;
                                 spaces=true;
                                 bts=false;
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
                   if(counter<9){
                        if(counter==3){
                             buffer2[counter]=buffer[n];
                             if(strncmp(buffer2,br1,3)==0 ||strncmp(buffer2,br2,3)==0 ||strncmp(buffer2,pe1,3)==0 ||strncmp(buffer2,pe2,3)==0){
                                 printf("\n");
                                 
                             }
                         }
                         if(counter==2){
                             buffer2[counter]=buffer[n];
                             if(strncmp(buffer2,p1,2)==0 ||strncmp(buffer2,p2,2)==0 ){
                                 printf("\n");
                                 
                             }
                         }

                        if(counter==7){
                             buffer2[counter]=buffer[n];
                             if(strncmp(buffer2,script1,7)==0 ||strncmp(buffer2,script2,7)==0 ){
                                 bbb=false;
                                 
                             }
                         }
                        if(counter==8){
                             buffer2[counter]=buffer[n];
                             if(strncmp(buffer2,script3,8)==0 ||strncmp(buffer2,script4,8)==0 ){
                                 bbb=true;
                                 
                             }

                        }else{
                             buffer2[counter]=buffer[n];
                        }
                         
                    }
                   if(n>0){
                       spaces=true;
                       if(buffer[n]<33 && buffer[n-1]<33) spaces=false;
                   }else{
                       spaces=true;
                   }
                   if(buffer[n]==retssimbol){
                        
                        closesb=false;
                        bts=false;
                        counter4=0;
                    }
                    if(buffer[n]==retssimbol2){
                        
                        closesb=true;
                        bts=false;
                        counter4=0;
                    }

                    if(buffer[n]==retssimbol){
                        
                        counter=0;
                    }
                    if((buffer[n]==reth || buffer[n]==reth) && !closesb && counter4==0){
                        
                        bts=true;
                        counter3=0;
                        counter4=0;
                        sbts=false;
                    }
                    if(bts){
                        if(counter3==4){
                             buffer3[counter3]=buffer[n];
                             if(strncmp(buffer3,href1,3)==0 ||strncmp(buffer3,href2,2)==0 ){
                                 sbts=true;
                                 
                             }
                         }
                         if(buffer[n]=='\"')counter4++;
                         if(counter4==1)printf("%c",buffer[n]);
                         counter3++;
                       
                    }

                counter++;
                if(closesb && bbb && buffer[n]!=retssimbol2 && spaces) printf("%c",buffer[n]);
            }
        }
        
        if(feof(stdin))b=false;
    }
    return 0;
}
