#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

//return length 32 string
string int_to_bin(uint32_t n) {
    string bits(sizeof(n) * 8, '0');
    int index = sizeof(n) * 8 - 1;

    while(n) {
        if(n % 2) //== 1
            bits[index] = '1';
        index--;            
        n /= 2;
    }
    return bits;
}

uint32_t bin_to_int(string bits) {
    uint32_t result = 0;
    int power = 0;
    for(int i = bits.length() - 1; i >= 0; i--, power++) {
        if(bits[i] == '1')
            result += pow(2, power);
    }
    return result;
}

uint32_t reverse_bits(uint32_t n) {
    string bits = int_to_bin(n);
    reverse(bits.begin(), bits.end());
    return bin_to_int(bits);
}

int main() {
   uint32_t n = 1;
   assert(reverse_bits(n) == 2147483648);

   n = 15;
   assert(reverse_bits(n) == 4026531840);

   n = 0;
   assert(reverse_bits(n) == 0);

   cout << "Success!" << endl;
}
