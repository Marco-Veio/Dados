#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

int main()
{
    system("color F0");
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    char sair;
    do{
        int n,cont,dado,i=0,d1=0,d2=0,d3=0,d4=0,d5=0,d6=0;
        float soma=0;
        char num[101];
        printf("Quantos dados você deseja jogar?\n");
        do{
            num[i]=getch();
            if((num[i]>='1' && num[i]<='9')||(num[i]=='0' && i>0)){
                printf("%c",num[i]);
                i++;
            }
            if(num[i]==8 && i>0){
                system("cls");
                num[i]=0;
                i--;
                num[i]=0;
                printf("Quantos dados você deseja jogar?\n");
                if(num[0]!=0)
                    printf("%s",num);
            }
            if(num[i]==27){
                i++;
                num[i]=13;
                sair=27;
            }
        }while(num[i]!=13 || num[0]==13);
        num[i]=0;
        if(sair!=27){
            n=atoi(num);
            for (cont=1;cont<=n;cont++){
                dado=1+rand()%6;
                switch(dado){
                    case 1:d1++;break;
                    case 2:d2++;break;
                    case 3:d3++;break;
                    case 4:d4++;break;
                    case 5:d5++;break;
                    case 6:d6++;break;
                }
                soma+=dado;
            }
            system("cls");
            printf("Você jogou %d dados\n",n);
            printf("A soma dos valores dos dados é %.0f\n",soma);
            printf("A média dos valores dos dados é %.0f\n",soma/n);
            if (d1>=d2&&d1>=d3&&d1>=d4&&d1>=d5&&d1>=d6)
                printf("O valor que mais apareceu é 1\n");
            if (d2>=d1&&d2>=d3&&d2>=d4&&d2>=d5&&d2>=d6)
                printf("O valor que mais apareceu é 2\n");
            if (d3>=d2&&d3>=d1&&d3>=d4&&d3>=d5&&d3>=d6)
                printf("O valor que mais apareceu é 3\n");
            if (d4>=d2&&d4>=d3&&d4>=d1&&d4>=d5&&d4>=d6)
                printf("O valor que mais apareceu é 4\n");
            if (d5>=d2&&d5>=d3&&d5>=d4&&d5>=d1&&d5>=d6)
                printf("O valor que mais apareceu é 5\n");
            if (d6>=d2&&d6>=d3&&d6>=d4&&d6>=d5&&d6>=d1)
                printf("O valor que mais apareceu é 6\n");
            printf("Aperte enter para reiniciar ou esc para sair!");
            do{
                sair=getch();
            }while(sair!=13 && sair!=27);
            system("cls");
        }
    }while(sair==13);
    return 0;
}
