#include <iostream>

using namespace std;

//generates all primes between 2 and upperLimit
bool* generatePrimes(int upperLimit) {
   
   //instantiate and initialize array
   bool* numbers = new bool[upperLimit];
   for(int i = 0; i < upperLimit; i++) {
      if(i == 0 || i == 1)
         numbers[i] = false;
      else
         numbers[i] = true;
   }

   for(int i = 2; i < upperLimit; i++) {
      if(numbers[i]) //if prime number 
         for(int j = 2*i; j < upperLimit; j += i) //cross out all multiples of prime #
            numbers[j] = false;
   }

   for(int i = 0; i < upperLimit; i++)
      if(numbers[i])
         cout << i << " is a prime number" << endl;

   return numbers;
}



int main() {
   generatePrimes(10000);
}