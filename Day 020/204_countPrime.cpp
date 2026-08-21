#include <iostream>
#include <vector>
using namespace std;
int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> isPrime(n, true);
        // 2 is the only even prime
        isPrime[0] = false;
        isPrime[1] = false;
        // Mark even numbers as not prime
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }
        // Check only odd numbers
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {

                // Start from i*i
                // Jump by 2*i to skip even multiples
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }
        // Count primes
        int count = 1;  // Count 2
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
int main() {
    cout << countPrimes(50);
    return 0;
}
