#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include <climits>

const int32_t DEC_BASE = 10;
const int32_t NUM_OF_TRIALS = 1;

int32_t 
length(const int32_t n)
{
    int32_t num = n, len = 1;

    while (true) {
        int32_t rem = num / DEC_BASE;
        if (0 == rem) break;
        else {
            num = rem;
            len++;
        }
    }
    return len;
}

bool
is_parlindome(const int32_t n)
{
    bool    b = true;
    int32_t num = n, num_digits = length(n);
    int32_t left = (num_digits - 1), right = 1;
    int32_t l_digit = 0, r_digit = 0;

    for (int32_t ctr = 0; ctr < num_digits / 2; ctr++) {
        int32_t l_div = std::pow(DEC_BASE, left--), l_mod = DEC_BASE;
        int32_t r_mod = std::pow(DEC_BASE, right++), r_div = std::pow(DEC_BASE, ctr);
        
        l_digit = std::floor(num / l_div); l_digit = l_digit % l_mod;
        r_digit = num % r_mod; r_digit = std::floor(r_digit / r_div);

        if (l_digit != r_digit) {
            b = false;
            break;
        }
    }
    
    return b;
}

int main(void)
{
    std::vector<int32_t> parlindomes;

#ifdef __DEBUG
    int32_t random_bnd = 0;

    std::cout << "Enter the bound: ";
    std::cin >> random_bnd;
#else
    using std::chrono::high_resolution_clock;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    std::random_device  rand_dev;
    const int32_t       seed = rand_dev();
    int32_t             random_bnd = 0;
    std::mt19937        generator(seed);
    duration<double,std::milli> elapsed;

    std::uniform_int_distribution<int32_t> dist(1, INT32_MAX/100); 

    for (int32_t loop = 1; loop <= NUM_OF_TRIALS; loop++) {
        random_bnd = dist(generator);    

        std::cout << random_bnd << std::endl;
        auto start = high_resolution_clock::now();
        for (int32_t n = 1; n <= random_bnd; n++) {
            if (true == is_parlindome(n)) {
                parlindomes.push_back(n);
            }
        }
        auto end = high_resolution_clock::now();
        elapsed = end - start;
    }

    std::cout << "The parlindome numbers <= " << random_bnd << std::endl;
    for (std::vector<int32_t>::const_iterator itr = parlindomes.begin(); itr != parlindomes.end(); itr++) {
        std::cout << *itr << ",";
    }
    std::cout << std::endl;

    std::cout << "The total elapsed time for " << random_bnd << " integers is " << elapsed.count()/NUM_OF_TRIALS << " msec" << std::endl;
#endif

    return 1;
}