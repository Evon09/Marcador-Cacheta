#include <windows.h>
#include <stdio.h>
#include "desenha.h"







void gotoxy(int x, int y){
    COORD c;
    c.X = x -1;
    c.Y = y -1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

reniciaStatus(){
for(int i;i<10;i++){

    nome.stats[i]=0;

}





}






int verificavitoria(int qj){

        int perdedor=0;
                for(int cont=0;cont<qj;cont++){
                     perdedor=0;
                        for(int i=0;i<qj;i++){
                            if(nome.pontos[i]==0&&cont!=i){
                                perdedor++;
                            }
                            if(perdedor==qj-1)
                                return(cont);

                            }


                }
                return(11);

}
int tipo(){

    int pos=0, lin=5, col=7;
    int tecla;
    system("mode con:cols=33 lines=12");
    do {
        moldura(1,33,2,11);
        gotoxy(col,lin-2); printf("Escolha O Tipo de Jogo:");
        gotoxy(col,lin); printf("Simples");
        gotoxy(col,lin+2); printf("Ilimitado");
        gotoxy(col,lin+4); printf("Exit");
        gotoxy(col-4,lin+pos);printf("%c",3);
        tecla=getch();

        if(tecla!=13){

            switch(tecla) {
                case 80:
                    gotoxy(col-4,lin+pos); printf("   ");
                    if(pos<4) pos+=2;
                    break;
                case 72:
                    gotoxy(col-4,lin+pos); printf("   ");
                    if(pos>0) pos-=2;
                    break;

            }
        }
        else{
            switch (pos){
                case 0:system("cls");nome.modo=1;return(1);
                case 2:system("cls");nome.modo=2;return(2);
                case 4:system("cls");nome.modo=4;return(0);
            }



        }
    } while(1);




}

int jogador(){

    int pos=0, lin=5, col=7;
    int tecla;
    system("mode con:cols=33 lines=15");
    do {
        moldura(1,33,2,14);
        gotoxy(col-2,lin-2); printf("Escolha quantos Jogadores:");
        gotoxy(col+3,lin); printf("2 jogadores");
        gotoxy(col+3,lin+2); printf("3 jogadores");
        gotoxy(col+3,lin+4); printf("4 jogadores");
        gotoxy(col+3,lin+6); printf("5 jogadores");

        gotoxy(col-1,lin+pos); printf("%c",6);
        tecla=getch();

        if(tecla!=13){

            switch(tecla) {
                case 80:
                    gotoxy(col-1,lin+pos); printf("     ");
                    if(pos<6) pos+=2;
                    break;
                case 72:
                    gotoxy(col-1,lin+pos); printf("     ");
                    if(pos>0) pos-=2;
                    break;

            }
        }
        else{
            switch(pos){
                case 0:pos=2;break;
                case 2:pos=3;break;
                case 4:pos=4;break;
                case 6:pos=5;break;
            }
            system("cls");
            return(pos);
            break;
        }
    } while(1);


}

int jogador2(int qj){

    system("mode con:cols=25 lines=5");
    do{
        system("cls");
        moldura(1,25,2,4);

        fflush(stdin);
        gotoxy(3,3);
        printf("Quantos Jogadores: ");
        scanf("%d",&qj);
        if(qj>1 && qj<11){
            system("cls");
            return(qj);
        }
        else{
            system("cls");
            moldura(1,25,2,4);
            gotoxy(3,3);
            printf("Quantidade Invalida!!");
            Sleep(1000);
        }
    }while(1);

}

int pontos(){

    system("mode con:cols=28 lines=10");
    int pos=0, lin=5, col=7;
    int tecla;
    do {
        moldura(1,28,2,9);
        gotoxy(col-3,lin-2); printf("Escolha quantos Pontos:");
        gotoxy(col,lin); printf("7 Pontos");
        gotoxy(col,lin+2); printf("10 Pontos");
        gotoxy(col-2,lin+pos);printf("%c",5);
        tecla=getch();

        if(tecla!=13){

            switch(tecla) {
                case 80:
                    gotoxy(col-2,lin+pos); printf("   ");
                    if(pos<2) pos+=2;
                    break;
                case 72:
                    gotoxy(col-2,lin+pos); printf("   ");
                    if(pos>0) pos-=2;
                    break;

            }
        }
        else{
            switch(pos){
                case 0:pos=7;break;
                case 2:pos=10;break;
            }
            system("cls");
            return(pos);
            break;
        }
    } while(1);


}

int seleciona(int qj,int qp,int rodada,int pos,int modo){
int lin=5, col=5,lim,soma=0,jg;
int tecla,perdedor=0;
    lim=(4*qj)-4;





    do{
        gotoxy(col-2,lin+pos);printf("%c",4);
        partida(qj,rodada);
        fflush(stdin);
        tecla=getch();



        if(tecla!=13){

            switch(tecla) {
                case 80:
                    gotoxy(col-2,lin+pos); printf(" ");
                    if(pos<lim) pos+=4;

                    break;
                case 72:
                    gotoxy(col-2,lin+pos); printf(" ");
                    if(pos>0) pos-=4;
                    break;

            }
        }
        else{
            if(tecla==13){

                jg=pos/4;
                if(nome.stats[jg]==0&&nome.pontos[jg]>0){
                    gotoxy(col-2,lin+pos); printf(" ");

                    return(jg);
                }
            }
        }
        //printf("                                                %d--%d---%d",modo,tecla,jg);
       // system("pause");

        if(tecla == VK_ESCAPE && modo == 11){
            gotoxy(col-2,lin+pos); printf(" ");
            break;
        }



    } while(1);

}

int corre (int qj,int qp,int rodada,int pos,int modo){
int lin=5, col=5,lim,cont=1;
int correr,jg=0;
    lim=(4*qj)-4;



    do{

        gotoxy(col-1,lin+pos);printf(">");

        fflush(stdin);
        correr=getch();



        if(correr!=13){

            switch(correr) {
                case 80:
                    gotoxy(col-1,lin+pos); printf(" ");
                    if(pos<lim) pos+=4;

                    break;
                case 72:
                    gotoxy(col-1,lin+pos); printf(" ");
                    if(pos>0) pos-=4;
                    break;

            }
        }
        else{

            jg=pos/4;
            if(nome.stats[jg]==0){


                gotoxy(col-3,lin+pos); printf("#");
                nome.stats[jg]++;
            }
            else{
                gotoxy(col-3,lin+pos); printf(" ");

                nome.stats[jg]--;

            }



        }
        gotoxy(col-1,lin+pos); printf(" ");
//printf("%d",modo);
       // system("pause");


    } while(correr!=VK_ESCAPE&& nome.modo==2);
}




int modo2(int qj,int qp,int modo){
    int    rodada=0,jg,pos=0,ganh,op;
    for(int i=0;i<qj;i++){
            nome.pontos[i]=qp;
        }

        partida(qj,1);rodada++;
    do{


        jg=gerenciarodada(qj,qp,modo,rodada);


        marcapontos(jg,qj,modo);
        rodada++;partida(qj,rodada);






     ganh=verificavitoria(qj);
        if(ganh!=11)
            break;


    }while(1);
    return(ganh);





}

int modo1(int qj,int qp,int modo){
int    rodada=0,jg,pos=0,ganh;
    for(int i=0;i<qj;i++){
            nome.pontos[i]=qp;
        }

    do{
        rodada++;partida(qj,rodada);
        jg=seleciona(qj,qp,rodada,pos,modo);

        marcapontos(jg,qj,modo);
        ganh=verificavitoria(qj);
        if(ganh!=11)
            break;


    }while(1);
    return(ganh);

}
