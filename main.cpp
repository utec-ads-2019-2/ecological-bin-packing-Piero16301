#include <bits/stdc++.h> 

using namespace std;

map <string, int> binPacking(vector <int> bottles) {

    map <string, int> result;
    vector <string> combinacionLetras;
    vector <int> combinacionNumeros;
    int minimoMovimientos;

    for (int i = 0; i < 6; i++) {
        int movimientos = 0;
        switch (i) {
            case 0: {
                movimientos = bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4];
                combinacionLetras.push_back("BCG");
                combinacionNumeros.push_back(movimientos);
                break;
            }
            case 1: {
                movimientos = bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5];
                combinacionLetras.push_back("BGC");
                combinacionNumeros.push_back(movimientos);
                break;
            }
            case 2: {
                movimientos = bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4];
                combinacionLetras.push_back("CBG");
                combinacionNumeros.push_back(movimientos);
                break;
            }
            case 3: {
                movimientos = bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3];
                combinacionLetras.push_back("CGB");
                combinacionNumeros.push_back(movimientos);
                break;
            }
            case 4: {
                movimientos = bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5];
                combinacionLetras.push_back("GBC");
                combinacionNumeros.push_back(movimientos);
                break;
            }
            case 5: {
                movimientos = bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3];
                combinacionLetras.push_back("GCB");
                combinacionNumeros.push_back(movimientos);
                break;
            }
        }
    }

    minimoMovimientos = *min_element(combinacionNumeros.begin(), combinacionNumeros.end());

    for (int j = 0; j < 6; j++) {
        if (combinacionNumeros[j] == minimoMovimientos) {
            result[combinacionLetras[j]] = minimoMovimientos;
            break;
        }
    }

    return result;

}

vector <int> concatenarInput(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) {
    vector <int> resultado;
    resultado.push_back(n1);
    resultado.push_back(n2);
    resultado.push_back(n3);
    resultado.push_back(n4);
    resultado.push_back(n5);
    resultado.push_back(n6);
    resultado.push_back(n7);
    resultado.push_back(n8);
    resultado.push_back(n9);
    return resultado;
}

int main() {

    int n1, n2, n3, n4, n5, n6, n7, n8, n9;

    while (scanf("%d %d %d %d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9) == 9) {

        vector <int> bottles = concatenarInput(n1, n2, n3, n4, n5, n6, n7, n8, n9);
        
        map <string, int> resultado = binPacking(bottles);
        
        map <string, int> :: iterator itr;

        for (itr = resultado.begin(); itr != resultado.end(); itr++) {
            cout << itr->first << ' ' << itr->second << '\n';
        }
    }
    
    return 0;

}
