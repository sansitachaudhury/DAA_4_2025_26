#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long countop = 0;
int maxdep = 0;

void complexRec(int n, int depth) {
    maxdep = max(maxdep, depth);

    if (n <= 2) {
        countop++;
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            countop++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        countop++;
    }

   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       countop++;
   } 
   else {
       reverse(small.begin(), small.end());
       countop++;
   }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    int n = 100;
    
//exec time
    auto start = high_resolution_clock::now();
    complexRec(n, 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "exec time(ms): " << duration.count() << endl;
    cout << "n = " << n << endl;
    cout << "no of operations: " << countop << endl;
    cout << "depth of tree:" << maxdep << endl;


    return 0;
}



//recurrence relation: T(n) = 3T(n/2) + 2n
//time complexity: O(log2(3)) (Case 1 of Master's Theorem was applied)
