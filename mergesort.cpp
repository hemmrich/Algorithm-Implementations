#include <iostream>

using namespace std;

void merge(int* arr, int* tmp, int left, int mid, int right) {
   int leftEnd, numElts, tempInt;
   leftEnd = mid - 1;
   tempInt = left;
   numElts = right - left + 1;

   //merge two arrays in sorted order
   while((left <= leftEnd) && (mid <= right)) {
      if(arr[left] <= arr[mid]) {
         tmp[tempInt] = arr[left];
         tempInt++;
         left++;
      }
      else {
         tmp[tempInt] = arr[mid];
         tempInt++;
         mid++;
      }
   }

   //if left partition is larger than right, add remaining elts
   while(left <= leftEnd) {
      tmp[tempInt] = arr[left];
      left++;
      tempInt++;
   }

   //if right partition is larger than left, add remaining elts
   while(mid <= right) {
      tmp[tempInt] = arr[mid];
      mid++;
      tempInt++;
   }

   //copy into array
   for(int i = 0; i < numElts; i++) {
      arr[right] = tmp[right];
      right--;
   }
}



void mergesort(int* arr, int* tmp, int left, int right) {

   if(right <= left)
      return;
   int midpoint = (right + left) / 2;
   mergesort(arr, tmp, left, midpoint); //sort left half
   mergesort(arr, tmp, midpoint + 1, right); //sort right half
   merge(arr, tmp, left, midpoint + 1, right); //merge sorted parts
}


int main() {
   int arr[] = {5, 4, 1, 7, 8, 9, 0, 3, 2};
   int tmp[sizeof(arr)/sizeof(arr[0])];
   mergesort(arr, tmp, 0, sizeof(arr)/sizeof(arr[0]));

   for(int i = 0; i < )
}

