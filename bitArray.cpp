#include <iostream>
#include <cmath>

using namespace std;

class BitArray {
private:
   void byteToDec();


   void updateElement(int index, bool val) {
      int byteIndex = index / 8;
      int byteOffset = index % 8;

      //array[byteIndex]
   }


public:
   int numElts;
   int numBytes;
   unsigned char* array; //unsigned char == byte

   BitArray(int numElements, bool defaultValue = 0) {
      numElts = numElements;
      numBytes = ceil(numElts / 8.0f); //number of bytes needed to represent numElts
      array = new unsigned char[numBytes];

      for(int i = 0; i < numElts; i++)
         updateElement(i, defaultValue);
   }

};

int main() {
   BitArray b1 = BitArray(5);
   cout << "b1 size: " << b1.numElts << ", bytes needed: " << b1.numBytes << endl;
   BitArray b2 = BitArray(8);
   cout << "b2 size: " << b2.numElts << ", bytes needed: " << b2.numBytes << endl;
   BitArray b3 = BitArray(15);
   cout << "b3 size: " << b3.numElts << ", bytes needed: " << b3.numBytes << endl;
}