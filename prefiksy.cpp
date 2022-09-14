pr#include <bits/stdc++.h>
using namespace std;


int main(){
    int d1,d2;
    cin >> d1 >> d2;
    string s1,s2;
    cin >> s1 >> s2;
    s1.append("X");
    s1.append(s2);
    //cout << s1;
    int T[400003];
    T[0]=0;
    int licznik = 0;
    for (int i=1; i <= d1+d2;i++){
        while (s1[licznik] != s1[i] && licznik > 0){
            licznik = T[licznik-1];
        }
        if(s1[licznik]==s1[i])licznik++;
        T[i]=licznik;
        //cout << T[i] << " ";//to dzia³a prawdopodobmnie
    }
    int W[200001];
    for (int i=1; i <= d1;i++){
        W[i]=0;
    }
    for (int i=d2+1;i <=d1+d2;i++){
        if(T[i]!=0)W[T[i]]++;
    }
    for (int i=d1-1;i >= 0;i--){
        W[T[i]]=W[T[i]]+W[i];
    }
    for (int i=0; i < d1;i++){
        cout << W[i] << " ";
    }



    }
