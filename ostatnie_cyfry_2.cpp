#include <bits/stdc++.h>
using namespace std;
const int stala = 262144;
int tab[2*stala][10];
int bonus[2*stala];
int temp[10];

void sumowanie_bonus(int i){
        tab[i][0]=tab[2*i][0]+tab[2*i+1][0];
        tab[i][1]=tab[2*i][1]+tab[2*i+1][1];
        tab[i][2]=tab[2*i][2]+tab[2*i+1][2];
        tab[i][3]=tab[2*i][3]+tab[2*i+1][3];
        tab[i][4]=tab[2*i][4]+tab[2*i+1][4];
        tab[i][5]=tab[2*i][5]+tab[2*i+1][5];
        tab[i][6]=tab[2*i][6]+tab[2*i+1][6];
        tab[i][7]=tab[2*i][7]+tab[2*i+1][7];
        tab[i][8]=tab[2*i][8]+tab[2*i+1][8];
        tab[i][9]=tab[2*i][9]+tab[2*i+1][9];
        for(int j=0;j < 10;j++){
                temp[j]=tab[i][(j+bonus[i])%10];
            }
        for(int j=0;j < 10;j++){
                tab[i][j]=temp[j];
            }
    }



void dodawanie(int a, int b,int poczatek,int koniec,int numer,int dodawana){
        if (poczatek == a && koniec == b){
            for(int i=0;i < 10;i++){
                temp[i]=tab[numer][(i+dodawana)%10];
            }
            for(int i=0;i < 10;i++){
                tab[numer][i]=temp[i];
            }
            bonus[numer]=(bonus[numer]+dodawana)%10;
            int x = numer;
            while (x > 0){
                x = x/2;
                sumowanie_bonus(x);
            }
        }
        if (a >= (poczatek+koniec+1)/2){
            dodawanie(a,b,(poczatek+koniec+1)/2,koniec,2*numer+1,dodawana);
        }else {
            if (b <= (poczatek+koniec-1)/2){
                dodawanie(a,b,poczatek,(poczatek+koniec-1)/2,2*numer,dodawana);
            }else{
                dodawanie(a,(poczatek+koniec-1)/2,poczatek,(poczatek+koniec-1)/2,2*numer,dodawana);
                dodawanie((poczatek+koniec+1)/2,b,(poczatek+koniec+1)/2,koniec,2*numer+1,dodawana);
            }
    }
    }


int wynik(int a,int b,int poczatek,int koniec,int numer,int bonusik){
        if (poczatek == a && koniec == b){
            for(int i=0;i < 10;i++){
                temp[i]=tab[numer][(i+bonusik)%10];
            }
            for(int i=0;i < 10;i++){
                tab[numer][i]=temp[i];
            }
            bonus[numer]=(bonus[numer]+bonusik)%10;
            int x = numer;
            while (x > 0){
                x = x/2;
                sumowanie_bonus(x);
            }
            int suma = 0;
            for (int i=1; i < 10;i++){
                suma = suma + i*tab[numer][i];
            }
            return suma;
        }
        if (a >= (poczatek+koniec+1)/2){
                return wynik(a,b,(poczatek+koniec+1)/2,koniec,2*numer+1,(bonusik+bonus[numer])%10);
        }else {
            if (b <= (poczatek+koniec-1)/2){
                return wynik(a,b,poczatek,(poczatek+koniec-1)/2,2*numer,(bonusik+bonus[numer])%10);
            }else{
                return (wynik(a,(poczatek+koniec-1)/2,poczatek,(poczatek+koniec-1)/2,2*numer,(bonusik+bonus[numer])%10)+wynik((poczatek+koniec+1)/2,b,(poczatek+koniec+1)/2,koniec,2*numer+1,(bonusik+bonus[numer])%10));
            }
        }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int dciagu,loperacji;
    char char1;
    long temp,temp2,temp1,dodawana;
    cin >> dciagu >> loperacji;
    for (int i=stala;i<2*stala;i++){
        tab[i][0]=0;
        tab[i][1]=0;
        tab[i][2]=0;
        tab[i][3]=0;
        tab[i][4]=0;
        tab[i][5]=0;
        tab[i][6]=0;
        tab[i][7]=0;
        tab[i][8]=0;
        tab[i][9]=0;
    }
    for (int i=1; i <2*stala;i++){
            bonus[i]=0;
            }
    for (int i=stala; i < dciagu+stala;i++){//tutaj ustawiamy podane liczby modulo 10
        cin >> temp2;
        temp2 = temp2 % 10;
        tab[i][temp2]=1;
    }
    for (int i=stala-1;i>0;i--){
        sumowanie_bonus(i);
    }
    char c;
    int temp5,temp6,temp7;
    for (int i=0; i < loperacji;i++){
        cin >> c;
        if (c == '+'){
            cin >> temp5 >> temp6 >> temp7;
            dodawanie(temp,temp6,1,stala,1,(temp7 % 10));
        }
        if (c == '?'){
            cin >> temp5 >> temp6;
            cout << wynik(temp5,temp6,1,stala,1,0) << endl;
        }
    }







}
