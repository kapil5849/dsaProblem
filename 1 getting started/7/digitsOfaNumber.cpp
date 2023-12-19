#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nod = 0;
    int temp = n;
    while (temp!=0) {
        temp = temp / 10;
        nod++;
    }

    int div = pow(10, nod - 1); // 10 ^ (nod - 1)

    while (div!=0) {
        int q = n / div;
        cout << q << endl;
        n = n % div;
        div = div / 10;
    }

    return 0;
}
