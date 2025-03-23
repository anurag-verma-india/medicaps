#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;

    // Constructor
    Item(int item_value, int item_weight)
        : value(item_value), weight(item_weight) {
    }
};

// Comparison function to sort Item according to
// value/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n) {
    //    sorting Item on basis of ratio
    sort(arr, arr + n, cmp);

    /*
    for (int i = 0; i < n; i++) {
        cout << arr[i].value << "  " << arr[i].weight << " :
    " << ((double)arr[i].value / arr[i].weight) << endl;
    }
    */

    int curWeight = 0;
    double finalvalue = 0.0;  // Result (value in Knapsack)

    // Looping through all Items
    for (int i = 0; i < n; i++) {
        // If adding Item won't overflow, add it completely
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item, add fractional part of it
        else {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

// Driver code
int main() {
    int W = 40;  //    Weight of knapsack
    Item arr[] = {{500, 30}, {100, 20}};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\nMaximum value we can obtain = "
         << fractionalKnapsack(W, arr, n) << "\n";
    return 0;
}
