#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v, int start = 0, int end = 0) {
  if(start == 0 && end == 0) {
    for(int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
    cout << endl;
  }
  else {
    for(int i = start; i <= end; i++)
      cout << v[i] << " ";
    cout << endl;
  }
}

int partition(vector<int>& v, int left, int right) {
  int pivot = v[right];
  int p_index = left;

  for(int i = left; i < right; i++) {
    if(v[i] <= pivot) {
      swap(v[i], v[p_index]);
      p_index++;
    }
  }
  swap(v[p_index], v[right]);
  return p_index;
}


void quicksort(vector<int>& v, int left, int right) {

  if(left >= right) return;

  int pivot = partition(v, left, right);

  quicksort(v, left, pivot - 1);
  quicksort(v, pivot + 1, right);
}


int main() {
  // vector<int> v {5, 3, 2, 1, 4};
  vector<int> v {5, 3, 1, 2, 4, 34, 6, -5, 2, 4, 6, 1, 6, 3, 5, 34, 12, 45, 23, 0, -1, 5};

  print(v);
  cout << endl;

  quicksort(v, 0, v.size() - 1);

  cout << endl;
  print(v);
}