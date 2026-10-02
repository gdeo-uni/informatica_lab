#include <iostream>
#include <vector>

using namespace std;


int somma(vector<int>  a, int i, int j){
    int somma=0; //dimensione di a

    for(int k=i; k<=j; k++){
        somma += a[k];
    }
    return somma;
}

int somma1(vector<int> a){
    int n = a.size(), ris=0, i_min=0, j_max = 0;

    for(int i = 0; i<n; i++){
        for(int j=i; j<n; j++){
            if(somma(a,i,j) > ris){
                ris = somma(a, i, j);
                i_min = i;
                j_max = j;
            }               
        }
    }
    cout << '['<< i_min << ';' << j_max<< "] con somma " << ris << endl;
    return 0;
}

int somma2(vector<int> a){
    auto massimale = 0;
    auto massimo=0;

    for(auto i=0; i < a.size(); i++){
        if(massimo>0){
            massimo += a[i];
        }else{
            massimo = a[i];
        }

        if(massimo>massimale){
            massimale = massimo;
        }
    }

    return massimale;
}

int random(int a, int b){
    return a+rand()%(b-a+1);
}

vector<int> generaArrayCasuale(int n, int min_val = -100, int max_val=+100){
    vector<int> A(n);

    for (auto i=0; i<n; i++){
        A[i] = random(min_val, max_val);
    }

    return A;
}

void printArray(vector<int> A){
    for (auto x : A){
        cout << x << " ";
    }
}

int main(){
    int risultato = 0;
    vector<int> input = generaArrayCasuale(11);
    risultato = somma2(input);
    cout << "Array generato ";
    printArray(input);
    cout << endl;
    cout << "segmento somma massima " << risultato << endl;
}


