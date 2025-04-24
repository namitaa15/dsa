#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) {
        value = v;
        weight = w;
    }
};

// Compare function to sort by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // descending
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Step 1: Sort by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto item : items) {
        if (W >= item.weight) {
            // Take full item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take fractional part
            totalValue += item.value * ((double)W / item.weight);
            break; // knapsack full
        }
    }

    return totalValue;
}

// Driver
int main() {
    int W = 50;
    vector<Item> items = {
        Item(60, 10), Item(100, 20), Item(120, 30)
    };

    double maxVal = fractionalKnapsack(W, items);
    cout << "Maximum value in knapsack = " << fixed << setprecision(2) << maxVal << endl;

    return 0;
}
