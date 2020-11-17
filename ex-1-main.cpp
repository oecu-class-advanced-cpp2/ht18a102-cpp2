#include <iostream>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000
#define PrimeNumMAX 168
int primeNum[PrimeNumMAX] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101, 103, 107,109,113,127,131,137,139,149,151,  //ëfêîï\
157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,
349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,
563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,
769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887, 907,911,919,929,937,941,947,953,967,971,977,983,991,997
};

//int numÇ™ëfêîÇ©Ç«Ç§Ç©ämîFÇ∑ÇÈ
int checkPrime(int num) {
    if (num <= 1)return 0;                                                                              //nÇ™1ÇÃéûÇÕëfêîÇ≈ÇÕÇ»Ç¢
    for (int counter = 0; counter < PrimeNumMAX; counter++) {
        if (num == primeNum[counter])return 1;                                              //nÇ™ëfêîÉäÉXÉgÇÃêîéöÇ∆ìØÇ∂Ç»ÇÁëfêî
        if (num % primeNum[counter] == 0)return 0;                                       //nÇ™ëfêîÉäÉXÉgÇÃêîéöÇ≈ÇÕÇ»Ç≠ÅA"ëfêîÉäÉXÉg[counter]"Ç≈äÑÇËêÿÇÍÇÈÇ»ÇÁëfêîÇ≈ÇÕÇ»Ç¢
        if (num < (primeNum[counter + 1] * primeNum[counter + 1]))return 1;//nÇ™"nÇÃïΩï˚ç™ÅÉëfêîÉäÉXÉg[counter+1]"Ç‹Ç≈äÑÇËêÿÇÍÇÈÇ±Ç∆Ç™ñ≥ÇØÇÍÇŒëfêî
    }                                                                                                             //Ç∑Ç◊ÇƒÇÃèåèÇ…ìñÇƒÇÕÇ‹ÇÁÇ»Ç¢èÍçáÅAéüÇÃëfêîÇ≈éZèoÇééÇ›ÇÈ
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
    int currentPrime = 0;
    for (int currentNum = 0; a + d * (currentNum + 1) <= CPP2_PRIME_UPPER_LIMIT; currentNum++) {
        if (checkPrime(a+d*currentNum)==1) {
            currentPrime += 1;
            if (currentPrime == n)return a+d*currentNum;
        }
    }
    cout << "error:Upper limit of prime number is 1000000. "<<endl << n << "th prime number is not exist in range from up to 1000000." << endl;//îÕàÕäOÉGÉâÅ[
    return -1;
}


int main() {
 cout << nth_prime(367, 186, 151) << endl;
    cout << nth_prime(179, 10, 203) << endl;
    cout << nth_prime(271, 37, 39) << endl;
    cout << nth_prime(103, 230, 1) << endl;
    cout << nth_prime(27, 104, 185) << endl;
    cout << nth_prime(253, 50, 85) << endl;
    cout << nth_prime(1, 1, 1) << endl;
    cout << nth_prime(9075, 337, 210) << endl;
    cout << nth_prime(307, 24, 79) << endl;
    cout << nth_prime(331, 221, 177) << endl;
    cout << nth_prime(259, 170, 40) << endl;
    cout << nth_prime(269, 58, 102) << endl;

return 0;
}