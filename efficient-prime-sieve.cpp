#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <cmath>
#include <bitset>
#include <string>

using namespace std;

#define INF 0x8f8f8f8f
#define ull unsigned long long
#define ll long long
#define uint unsigned int

vector<int> primes;

void get_primes_with_sieve( int limit )
{
    vector<int> numbers( limit + 1 );

    for ( int i = 2; i <= limit; ++i )
    {
        // All numbers with value 0 in numbers array can be considered as primes
        if ( numbers[i] == 0 )
        {
            // Number is prime
            numbers[i] = i;   
            primes.push_back(i);            // Push this number to prime list
        }
 
        for (size_t j = 0; 
            j < primes.size() &&            // Iterate through all primes in primes list
            primes[j] <= numbers[i] &&      // the current prime has to be less than the currently investigated number
            i * primes[j] <= limit;             // make sure i * current_prime does not exceed limit
            ++j)
        {
            // Mark all numbers i * [every single prime] as non prime

            // The benefit of this algorithm is that no non-prime number will ever be 
            // marked more than once in the second for loop
            
            numbers[i * primes[j]] = primes[j]; 
        }
    }
}


int main()
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );

    get_primes_with_sieve( 100 );
}