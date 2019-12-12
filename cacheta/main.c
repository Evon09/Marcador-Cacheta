#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "selecionar.h"

void pedenome(int qj){
    system("mode con:cols=28 lines=7");
    for(int i=0;i<qj;i++){
        system("cls");
        moldura(1,28,2,6);
        gotoxy(2,3);
        printf("Informe nome do jogador %d",i+1);
        gotoxy(4,5);
        fflush(stdin);
        fgets(nome.nomes[i], 11, stdin);


    }



}

void escrevenome(int qj){
    system("cls");
    int pos=0, lin=3, col=5;
    do{
        for(int i=0;i<qj;i++,lin=lin+4){

            gotoxy(col,lin);printf("-------------");


            gotoxy(col,lin+2);printf("  %s",nome.nomes[i]);



        }
         gotoxy(col,lin);printf("-------------");




         //system("pause");

        break;
    }while(1);
}





void marcapontos(int jg,int qj,int modo){

    if(nome.pontos[jg]>0){
                for(int i=0;i<qj;i++){
                    if(i!=jg&&nome.pontos[i]>0){
                        if(modo==1)
                            nome.pontos[i]-=1;
                        else{
                            if(nome.pontos[i]>0){
                                if(nome.pontos[i]==1||nome.stats[i]==1)
                                    nome.pontos[i]-=1;
                                else
                                    nome.pontos[i]-=2;
                            }

                        }
                    }

                }

            }


    }





main()
{
    SetConsoleTitle("UOF7 - UTFPR 2019");
    SetConsoleCP(32);
    int qj,qp,ganhador,modo,lim;


    do{
    for(int i=0;i<10;i++){
        nome.stats[i]==0;

    }




    modo=tipo();
    if(modo==1||modo==2){




    if(modo==1){


    qj=jogador();

    qp=pontos();
    pedenome(qj);
    //lim=(qj*5)+5;

    system("mode con:cols=101 lines=55");
    escrevenome(qj);
    ganhador=modo1(qj,qp,modo );
    system("mode con:cols=35 lines=5");
    system("cls");
    moldura(1,35,2,4);
    gotoxy(3,3);
    printf("O Jogador : %s ",nome.nomes[ganhador]);
    gotoxy(25,3);
    printf("Ganhou!!!");
    printf(" ");
    getch();


    }
    else{
        qj=jogador2(qj);
        qp=pontos();
        reniciaStatus();

        pedenome(qj);
        system("mode con:cols=101 lines=55");
        escrevenome(qj);

        ganhador=modo2(qj,qp,modo);
        system("mode con:cols=35 lines=5");
        system("cls");
        moldura(1,35,2,4);
        gotoxy(3,3);
        printf("O Jogador : %s ",nome.nomes[ganhador]);
        gotoxy(25,3);
        printf("Ganhou!!!");
        printf(" ");
        getch();


    }
    }
    }while(nome.modo!=4);


}




