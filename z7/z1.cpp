
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