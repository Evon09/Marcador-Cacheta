#include <windows.h>
#include <stdio.h>

struct cadastro{
        char nomes[10][13];
        int pontos[10];
        int stats[10];
        int modo;


    };

struct cadastro nome;



void moldura(int ci, int cf, int li, int lf){
    int l,c;
    for (c = ci + 1; c < cf; c++){
        gotoxy(c,li);printf("%c",205);
        gotoxy(c,lf);printf("%c",205);
    }

    for (l = li + 1; l < lf ; l++){
        gotoxy(ci,l);printf("%c",186);
        gotoxy(cf,l);printf("%c",186);

    }

    gotoxy(ci,li);printf("%c",201);
    gotoxy(ci,lf);printf("%c",200);
    gotoxy(cf,li);printf("%c",187);
    gotoxy(cf,lf);printf("%c",188);
}





gerenciarodada2(int qj,int qp,int rodada){

    int pos=0,lin=3, col=18 ;

    col=col+(6*rodada);
    int tecla;


        gotoxy(col,lin);   printf("+--------------+");
        gotoxy(col,lin+1); printf("|    Rodada:   |");
        gotoxy(col,lin+2); printf("|              |");gotoxy(col+7,lin+2); printf("%d",rodada);
        gotoxy(col,lin+3); printf("|              |");
        gotoxy(col,lin+4); printf("|     ESC:     |");
        gotoxy(col,lin+5); printf("|              |");
        gotoxy(col,lin+6); printf("|   Para Sair  |");
        gotoxy(col,lin+7); printf("|              |");
        gotoxy(col,lin+8); printf("+--------------+");
        corre(qj,qp,rodada,pos);




    }

    gerenciarodada0(int qj,int qp,int rodada){

    int pos=0,lin=3, col=18, jg=11 ;

    col=col+(6*rodada);
    int tecla;


        gotoxy(col,lin);   printf("+--------------+");
        gotoxy(col,lin+1); printf("|    Rodada:   |");
        gotoxy(col,lin+2); printf("|              |");gotoxy(col+7,lin+2); printf("%d",rodada);
        gotoxy(col,lin+3); printf("|              |");
        gotoxy(col,lin+4); printf("|     ESC:     |");
        gotoxy(col,lin+5); printf("|              |");
        gotoxy(col,lin+6); printf("|   Para Sair  |");
        gotoxy(col,lin+7); printf("|              |");
        gotoxy(col,lin+8); printf("+--------------+");
        jg=seleciona(qj,qp,rodada,pos);
        if(jg!=11)
            return(jg);



    }




int gerenciarodada(int qj,int qp,int modo,int rodada){

    int pos=0,lin=3,jg=23, col=18;

    col=col+(6*rodada);
    int tecla;

    do {

        gotoxy(col,lin);   printf("+--------------+");
        gotoxy(col,lin+1); printf("|    Rodada:   |");
        gotoxy(col,lin+2); printf("|              |");gotoxy(col+7,lin+2); printf("%d",rodada);
        gotoxy(col,lin+3); printf("|              |");
        gotoxy(col,lin+4); printf("|    Iniciar   |");
        gotoxy(col,lin+5); printf("|              |");
        gotoxy(col,lin+6); printf("|    Correr    |");
        gotoxy(col,lin+7); printf("|              |");
        gotoxy(col,lin+8); printf("+--------------+");
        gotoxy(col+3,lin+pos+4);printf("%c",6);
        tecla=getch();

        if(tecla!=13){

            switch(tecla) {
                case 80:
                    gotoxy(col+3,lin+pos); printf(" ");
                    if(pos<2) pos+=2;
                    break;
                case 72:
                    gotoxy(col+3,lin+pos); printf(" ");
                    if(pos>0) pos-=2;
                    break;

            }
        }
        else{
            switch (pos){
                case 0:jg=gerenciarodada0(qj,qp,rodada);break;
                case 2:gerenciarodada2(qj,qp,rodada);break;
            }
            if(jg>=0&&jg<=10)
                return(jg);
        }

    }while(1);




}


partida(int qj, int rodada){
    int pos=0,lin=2, col=12 ;

    col=col+(6*rodada);


     gotoxy(col,lin);printf("|     |");gotoxy(col+3,lin);printf("R%d",rodada);
     for(int i=0;i<qj;lin=lin+4,i++){


            gotoxy(col,lin+1);printf("+-----+");
            gotoxy(col,lin+2);printf("|     |");
            gotoxy(col,lin+3);printf("|     |");
            gotoxy(col,lin+4);printf("|     |");gotoxy(col+3,lin+3);printf("%d", nome.pontos[i]);


        }
        gotoxy(col,lin+1);printf("+-----+");

        //printf("-------------\n");







}
