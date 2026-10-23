// compila con: g++ -std=c++17 sortalg.cpp -o sortalg
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// per creare numeri casuali
#include <random>
using namespace std;

/* UTILITY */

int random(int a, int b){ // restituisce un numero random in [a..b]
static random_device rd; // per inizializzare il generatore
static mt19937 gen(rd()); // static evita di creare ogni volta il generatore a ogni chiamata
uniform_int_distribution<int> dist(a, b);

return dist(gen);

}

vector<int> generaArrayCasuale(int n, int minVal = -100, int maxVal = 100){ // accetta solo n > 0 oppure tutti gli argomenti
    vector<int> A(n); // vettore di n interi da riempire
    for (auto i = 0; i < n; i++){
        A[i] = random(minVal,maxVal);
    }
    return A; // non fa la copia!
}

void printArray(const vector<int>& B){
    for (auto x : B){
        cout << x << " ";
    }
    cout << endl;
    cout << endl;
}

/* DA COMPLETARE E FARE DEBUG */

int Distribuzione(vector<int>& A, int sx, int px, int dx) {
    if (px != dx) swap(A[px], A[dx]);
    int p = A[dx];

    int i = sx;
    int j = dx - 1;
    while (i <= j) {
        while (i <= j && A[i] < p) i++;
        while (i <= j && A[j] > p) j--;
        if (i < j) {
            swap(A[i], A[j]);
            i++;
            j--;
        } else {
            break;
        }
    }

    swap(A[i], A[dx]);
    return i;
}


void QuickSort(vector<int>& A, int sx, int dx) {
    if (sx < dx) {
        int pivot = dx; // può essere qualunque valore in [sx .. dx]

        //stampe per osservare l'albero della ricorsione
        cout << "sx --> " << sx << "  " << "dx --> " << dx << endl;
        printArray(A);

        int rango = Distribuzione(A, sx, pivot, dx);
        QuickSort(A, sx, rango - 1);
        QuickSort(A, rango + 1, dx);
    }
}


int main(){
    //constexpr auto N = 12;
    //vector<int> A = generaArrayCasuale(N);
    vector<int> A = {15, 7, 8, 3, 18, 10, 5, 16};
    auto N = A.size();
    //printArray(A);
    //Distribuzione(A, 0, N-1, N-1);
    //printArray(A);

    QuickSort(A, 0, N-1);

    return 0;
}