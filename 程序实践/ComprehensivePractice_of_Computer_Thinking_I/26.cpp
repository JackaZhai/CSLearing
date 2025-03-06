#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void generateRing(vector<int>& ring, vector<bool>& used, int n) {
    if (ring.size() == n) {
        if (isPrime(ring.back() + ring[0])) {
            for (int i = 0; i < n; i++) {
                cout << ring[i];
                if (i < n - 1) cout << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 2; i <= n; i++) {
        if (!used[i] && isPrime(ring.back() + i)) {
            ring.push_back(i);
            used[i] = true;
            generateRing(ring, used, n);
            used[i] = false;
            ring.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> ring;
    vector<bool> used(n + 1, false);

    ring.push_back(1);
    used[1] = true;

    generateRing(ring, used, n);

    return 0;
}