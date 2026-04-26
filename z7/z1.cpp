#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <iostream>

#include "../libraries/libInput.h"

using namespace std;

void LCG(int Xmax, int n, int x0) {
    if (n < 0) return;
}

vector<int> primeFactorization(int m, vector<int> result) {
    if (m == 1) return result;

    int i = 2;
    while (m % i != 0) {
        i++;
    }

    m /= i;

    result.push_back(i);

    return primeFactorization(m, result);
}

int findA(int m, vector<int> factorizedM) {
    int largestLambda = 0;
    vector<pair<int,int>> list;
    for (int a = 2; a < m; a++) {
        int lambda = 1;
        while (static_cast<int>(pow(a,lambda)) % m != 1) {
            lambda++;
        }

        list.push_back({a, lambda});

        if (lambda > largestLambda) {
            largestLambda = lambda;
        }
    }

    for (int i = 0; i < list.size(); i++) {
        if (list[i].second == largestLambda && list[i].first != 2) {
            int a = list[i].first - 1;
            bool second = true;
            for (int j = i + 1; j < factorizedM.size(); j++) {
                if (factorizedM[j] % a != 0) {
                    second = false;
                    break;
                }

                /// tu koniec
            }

        }
    }
}

int main() {
    int* tab = new int[1];

    int x0 = tab[0] % 10;
    int xMax,n;
    xMax = inputPositiveInteger();
    n = inputPositiveInteger();

    int m = xMax + 1;
    int c = xMax;

    vector<int> v;
    vector<int> factorizedM = primeFactorization(m, v);

    delete [] tab;
    return 0;
}