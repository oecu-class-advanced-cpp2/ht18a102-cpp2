#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000
#define PrimeNumMAX 168

//CPP2_PRIME_UPPER_LIMIT 1000000の判定に必要な素数のリスト
int primeNum[PrimeNumMAX] =
{
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 
101, 103, 107, 109, 113, 127, 131, 137, 139, 
149, 151, 157, 163, 167, 173, 179, 181, 191, 
193, 197, 199, 211, 223, 227, 229, 233, 239,
241, 251, 257, 263, 269, 271, 277, 281, 283, 
293, 307, 311, 313, 317, 331, 337, 347, 349, 
353, 359, 367, 373, 379, 383, 389, 397, 401,
409, 419, 421, 431, 433, 439, 443, 449, 457, 
461, 463, 467, 479, 487, 491, 499, 503, 509, 
521, 523, 541, 547, 557, 563, 569, 571, 577, 
587, 593, 599, 601, 607, 613, 617, 619, 631, 
641, 643, 647, 653, 659, 661, 673, 677, 683, 
691, 701, 709, 719, 727, 733, 739, 743, 751, 
757, 761, 769, 773, 787, 797, 809, 811, 821, 
823, 827, 829, 839, 853, 857, 859, 863, 877,
881, 883, 887, 907, 911, 919, 929, 937, 941, 
947,953, 967, 971, 977, 983, 991, 997
};

//素数を判定する
//int num=チェックする数字
//素数なら1を返す
/*
numが1以外かつ、あらかじめ用意した素数リストに存在していない場合、numを素数で割っていく。いずれかの素数で割り切れた場合は素数ではない
*/
int is_Prime(int num) {
    //1ならば素数ではない
    if (num <= 1)return 0;
    for (int counter = 0; counter < PrimeNumMAX; counter++) {

        //素数リストにnumがあれば素数
        if (num == primeNum[counter])return 1;

        //素数リストの数字でnumが割り切れれば素数ではない
        if (num % primeNum[counter] == 0)return 0;

        //確認はnumが次に確認する素数の2乗より小さい所まででよい（ここまでに割り切れない場合素数）
        if (num < (primeNum[counter+1] * primeNum[counter+1]))return 1;
    }
}

//ディリクレの算術級数定理
//a から始まり d ずつ増える等差数列のn番目の素数を返す
int nth_prime(int a, int d,int n) {
    int currentPrime = 0;
    for (int currentNum = 0; a + d * (currentNum + 1) <= CPP2_PRIME_UPPER_LIMIT;currentNum++) {
        if (is_Prime(a+d*currentNum)==1) {
            currentPrime += 1;
            if (currentPrime == n)return a+d*currentNum;
        }
    }

    //エラー
    std::cout << "error:Upper limit of prime number is 1000000. " << std::endl;
    return -1;
}

int main() {
    std::cout << nth_prime(367,186,151) << " 92809" << std::endl;
    std::cout << nth_prime(179, 10, 203) <<" 6709"<< std::endl;
    std::cout << nth_prime(271, 37, 39) <<" 12037"<< std::endl;
    std::cout << nth_prime(103, 230, 1) <<" 103"<< std::endl;
    std::cout << nth_prime(27, 104, 185) <<" 93523"<< std::endl;
    std::cout << nth_prime(253, 50, 85) << " 14503"<<std::endl;
    std::cout << nth_prime(1, 1, 1) << " 2"<<std::endl;
    std::cout << nth_prime(9075, 337, 210)<<" 899429"<< std::endl;
    std::cout << nth_prime(307, 24, 79) <<" 5107"<< std::endl;
    std::cout << nth_prime(331, 221, 177) <<" 412717"<< std::endl;
    std::cout << nth_prime(259, 170, 40) <<" 22699"<< std::endl;
    std::cout << nth_prime(269, 58, 102) << " 25673" << std::endl;
}
