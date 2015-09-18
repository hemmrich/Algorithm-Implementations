// You have a function rand5() that generates a random integer from 1 to 5
// Use it to write a function rand7() that generates a random int from 1 to 7

#include <iostream>
#include <cstdlib>

using namespace std;


int rand5() {
    return (rand() % 5) + 1;
}

int rand7() {
    // create 5x5 table of values 1-7,
    // if any of the last 4 values of the table are chosen,
    // reroll (the last 4 would make # 1-4 more likely than others)
    
    int rand1 = rand5();
    int rand2 = rand5();

    int table[][5] = {{1, 2, 3, 4, 5},
                      {6, 7, 1, 2, 3},
                      {4, 5, 6, 7, 1},
                      {2, 3, 4, 5, 6},
                      {7, -1, -1, -1, -1}};

    if(table[rand1 - 1][rand2 - 1] == -1)
        return rand7();
    
    return table[rand1 - 1][rand2 - 1];
}

int rand7_wrong() {
    //wrong because there are:
    //4 pairs of rand5() that % 7 = 0, 5
    //3 pairs of rand5() that % 7 = 1, 2, 3, 4
    //5 pairs of rand5() that % 7 = 6
    //6 most likely, then 0, 5, then 1, 2, 3, 4
    // --> 25 pairs of rand5() --> not % 7, so this is wrong
    // (there is no 5^n that % 7 = 0, so can't sum up rand5() calls)
    // check prime factorization to show this

    int rand1 = rand5();
    int rand2 = rand5();

    return ((rand1 + rand2) % 7) + 1;

}

int main() {
    int counter[7];
    memset(counter, 0, sizeof(counter));
    int num_runs = 10000000;

    for(int i = 0; i < num_runs; i++) {
        counter[rand7() - 1]++;
    }

    cout << "Correct method: " << endl;
    for(int i = 0; i < 7; i++) {
        float perc = float(counter[i]) / num_runs * 100;
        cout << i + 1 << " came up " << perc << "\% of the time" << endl;
    }

    int counter_wrong[7];
    memset(counter_wrong, 0, sizeof(counter_wrong));
    for(int i = 0; i < num_runs; i++)
        counter_wrong[rand7_wrong() - 1]++;

    cout << endl << "Incorrect method: " << endl;
    for(int i = 0; i < 7; i++) {
        float perc = float(counter_wrong[i]) / num_runs * 100;
        cout << i + 1 << " came up " << perc << "\% of the time" << endl;
    }
}


