#include <iostream>

using namespace std;

bool osszekottetes(int pont1, int pont2, int matrix[10][10])
{
    if(matrix[pont1-1][pont2-1] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int osszekottetes_szama(int csomopont, int matrix[10][10]){
    int szamlalo = 0;
    for(int i=0; i<8; i++){
        if(matrix[csomopont-1][i] == 1){
            szamlalo ++;
        }
    }
    return szamlalo;
}

int main()
{
    int a[10][10] = {0};
    a[0][1] = 1;
    a[0][5] = 1;
    a[1][0] = 1;
    a[1][2] = 1;
    a[1][3] = 1;
    a[2][1] = 1;
    a[2][3] = 1;
    a[3][1] = 1;
    a[3][2] = 1;
    a[3][7] = 1;
    a[4][5] = 1;
    a[4][6] = 1;
    a[4][7] = 1;
    a[5][0] = 1;
    a[5][4] = 1;
    a[6][4] = 1;
    a[7][3] = 1;
    a[7][4] = 1;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int pont1, pont2;
    cout << "elso pont: ";
    cin >> pont1;
    cout << "masodik pont: ";
    cin >> pont2;
    if(osszekottetes(pont1, pont2, a) == 1){
        cout << "van osszekottetes" << endl;
    }
    else{
        cout << "nincs osszekottetes" << endl;
    }
    int csomopont;
    cout << "csomopont: ";
    cin >> csomopont;
    cout << "osszekottetesek szama = " << osszekottetes_szama(csomopont, a) << endl;
    int tomb1[10], tomb2[10];
    for(int i=0 ; i<8; i++){
        tomb1[i] = osszekottetes_szama(i+1, a);
        tomb2[i] = i+1;
    }
    for(int i=0; i<7; i++){
        for(int j=i+1; j<8; j++){
            if(tomb1[i]>tomb1[j]){
                swap(tomb1[i], tomb1[j]);
                swap(tomb2[i], tomb2[j]);
            }
        }
    }
    cout << "a pontok az osszekottetesek szamanak novekvo sorrendjeben: ";
    for(int i=0; i<8; i++){
        cout << tomb2[i] << " ";
    }
    return 0;
}
