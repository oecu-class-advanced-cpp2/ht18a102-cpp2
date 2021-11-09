#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000
#define PrimeNumMAX 168

int primeNum[PrimeNumMAX] = {2,3,5,7,11,13,17,19,23,29,31,983,991,997};
int checkPrime(int num) {
    if (num <= 1)return 0;
    for (int counter = 0; counter < PrimeNumMAX; counter++) {
        if (num == primeNum[counter])return 1;
        if (num % primeNum[counter] == 0)return 0;
        if (num < (primeNum[counter + 1] * primeNum[counter + 1]))return 1;
    }
}
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
    int currentPrime = 0;
    for (int currentNum = 0; a + d * (currentNum + 1) <= CPP2_PRIME_UPPER_LIMIT;currentNum++) {
        if (checkPrime(a+d*currentNum)==1) {
            currentPrime += 1;
            if (currentPrime == n)return a+d*currentNum;
        }
    }
    cout << "error:Upper limit of prime number is 1000000. " << endl;
    return -1;
}