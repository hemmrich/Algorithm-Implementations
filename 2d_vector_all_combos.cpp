/*Given a vector of vector of strings. Compute all possible combinations of strings taking
exactly one string from each vector.
  Example:
       Given the input
            {{“az”, “b”, “c”},  {“1”}, {“X”, “Y”}}
       the expected output is
            { {“az”, “1”, “X”},
              {“az”, “1”, “Y”},
              {“b”, “1”, “X”},
              {“b”, “1”, “Y”},
              {“c”, “1”, “X”},
              {“c”, “1”, “Y”} }
*/

#include <iostream>
#include <vector>

using namespace std;

//# combinations = #row1 * #row2 * #row3
//visit each combination once
//runtime - O(m^n), where m is length of longest subvector and n is number of subvectors
void combination_helper(vector<vector<string>>& strings, 
vector<vector<string>>& result, vector<string>& current, int count) {
  if(count == strings.size()) {
    //if(count == 0)
      //result = current;       
    //else

    result.push_back(current);
    return;
  }
        
  vector<string> &tmp = strings[count];
  for(int i = 0; i < tmp.size(); ++i) {
    current.push_back(tmp[i]);
    combination_helper(strings, result, current, count + 1);
    current.pop_back();
  }
}

vector<vector<string>> string_combinations(vector<vector<string>>& strings) {
  vector<vector<string>> result;
  vector<string> current;

  if (strings.size() == 0) {
     return result;
  }
  combination_helper(strings, result, current, 0);

  return result;
}

int main() {

  //should have 2*3*3*5 = 90 combinations
  vector<vector<string>> v {
    {"row0col0", "row0col1"},
    {"row1col0", "row1col1", "row1col2"},
    {"row2col0", "row2col1", "row2col2"},
    {"row3col0", "row3col1", "row3col2", "row3col3", "row3col4"},
  };

  vector<vector<string>> result = string_combinations(v);

  cout << "result.size() = " << result.size() << endl;

  for(int i = 0; i < result.size(); i++) {
    for(int j = 0; j < result[i].size(); j++) {
      cout << "'" << result[i][j] << "', ";
    }
    cout << endl;
  }
  cout << endl;
}


// strings =  { {“1”} }
// strings = {}  result = {}
// strings = {{}}, result = {{}}




