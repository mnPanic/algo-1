#include <iostream>
#include "vector"
#include <string>

#include "ps.h"
#include "utilidades.h"

using namespace std;

void countingSort(vector<int> &s, int k) {
    vector<int> cantAp(k, 0);

    for(int i = 0; i < s.size(); i++) {
        cantAp[s[i]]++;
    }

    int l = 0;
    for(int i = 0; i < cantAp.size(); i++) {
        for(int j = 1; j <= cantAp[i]; j++) {
            s[l] = i;
            l++;
        }
    }
}

int main() {
    //mainP7();
    mainP8();
    return 0;
}


