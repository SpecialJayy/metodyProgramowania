#include "libRandom.h"

#include <chrono>
#include <numeric>
#include <vector>

int modularPow(int base, int exp, int mod) {
    long long res = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp /= 2;
    }
    return static_cast<int>(res);
}

std::vector<int> primeFactorization(int m) {
    std::vector<int> factors;
    for (int i = 2; i * i <= m; ++i) {
        while (m % i == 0) {
            factors.push_back(i);
            m /= i;
        }
    }
    if (m > 1) factors.push_back(m);
    return factors;
}

int findA(int m) {
    std::vector<int> primeFactors = primeFactorization(m);
    int largestLambda = 0;
    std::vector<std::pair<int, int>> candidates;

    for (int a = 2; a < m; ++a) {
        if (std::gcd(a, m) != 1) continue;

        int lambda = 1;
        while (modularPow(a, lambda, m) != 1) {
            lambda++;
        }

        candidates.push_back({a, lambda});
        if (lambda > largestLambda) largestLambda = lambda;
    }

    std::vector<int> maxLambdaValues;
    for (const auto& pair : candidates) {
        if (pair.second == largestLambda) maxLambdaValues.push_back(pair.first);
    }

    for (int a : maxLambdaValues) {
        int b = a - 1;
        bool satisfiesAll = true;

        for (int p : primeFactors) {
            if (b % p != 0) {
                satisfiesAll = false;
                break;
            }
        }

        if (satisfiesAll && (m % 4 == 0) && (b % 4 != 0)) {
            satisfiesAll = false;
        }

        if (satisfiesAll) return a;
    }

    int bestA = -1;
    for (int a : maxLambdaValues) {
        if (a > bestA) bestA = a;
    }

    return bestA == -1 ? 1 : bestA;
}

int findC(int m) {
    for (int c = 1; c < m; ++c) {
        if (std::gcd(c, m) == 1) return c;
    }
    return 1;
}

//liczba losowa inną metodą niż random, zczytywanie clock z procesora
long long chronoRandom() {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
}

std::vector<int> runGenerator(int xMax, int n, int choice) {
    int m = xMax + 1;
    int a = findA(m);
    int c = (choice == 2) ? findC(m) : 0;

    int nanos = chronoRandom();

    int x0 = nanos % m;
    if (x0 < 0) x0 = -x0;

    std::vector<int> res;
    res.reserve(n);
    res.push_back(x0);

    for (int i = 1; i < n; ++i) {
        long long nextVal = (static_cast<long long>(a) * res.back() + c) % m;
        res.push_back(static_cast<int>(nextVal));
    }

    return res;
}