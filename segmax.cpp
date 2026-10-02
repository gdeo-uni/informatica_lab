#include <iostream>
#include <vector>

using namespace std;


int somma1(vector<int>  a, int i, int j){
    int somma=0; //dimensione di a

    for(int k=i; k<=j; k++){
        somma += a[k];
    }
    return somma;
}

int segmax(vector<int> a){
    int n = a.size(), somma=0, i_min=0, j_max = 0;

    for(int i = 0; i<n; i++){
        for(int j=i; j<n; j++){
            if(somma1(a,i,j) > somma){
                somma = somma1(a, i, j);
                i_min = i;
                j_max = j;
            }               
        }
    }

    cout << '['<< i_min << ';' << j_max<< ']' <<endl;
    return 1;
}

int main(){
    int risultato = 0;
    vector<int> input = {4, -6, 3, 5, -2, 1, -4, 6, 2, -3};

    cout << "segmento massimo individuato nella sequenza " << segmax(input);
}


