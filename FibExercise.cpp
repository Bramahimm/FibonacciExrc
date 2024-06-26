#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int rekursif(int n) {
    if (n <= 1)
        return n;
    else
        return rekursif(n - 1) + rekursif(n - 2);
}

int dinamic(int n) {-
    vector<int> angka(n + 1);
    angka[0] = 0;
    ankga[1] = 1;
    for (int i = 2; i <= n; ++i) {
        angka[i] = angka[i - 1] + angka[i - 2];
    }
    return angka[n];
}

int main() {
    int nilai[] = {10, 25, 30, 40, 50};
    
    for (int n : nilai) {
        auto start = chrono::high_resolution_clock::now();
        cout << "Fibonacci ke-" << n << " dengan rekursif: " << rekursif(n) << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Waktu eksekusi (rekursif): " << elapsed.count() << " detik" << endl;

        start = chrono::high_resolution_clock::now();
        cout << "Fibonacci ke-" << n << " dengan dynamic programming: " << dinamic(n) << endl;
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Waktu eksekusi (dynamic programming): " << elapsed.count() << " detik" << endl;
        
        cout << "---------------------------------------------" << endl;
    }
    
    return 0;
}
