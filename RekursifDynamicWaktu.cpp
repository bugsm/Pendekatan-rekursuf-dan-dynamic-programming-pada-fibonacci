#include <iostream>
#include <chrono>
#include <vector>
using namespace std;


unsigned long long fibonacci_recursive(int n) {
    if (n <= 1) return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}


unsigned long long fibonacci_dp(int n) {
    if (n <= 1) return n;
    vector<unsigned long long> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    vector<int> test_values = {10, 25, 30, 40, 50};
    
    cout << "n\tRekursif (ms)\tDP (ms)\n";
    for (int n : test_values) {
        
        auto start_recursive = chrono::high_resolution_clock::now();
        fibonacci_recursive(n);
        auto end_recursive = chrono::high_resolution_clock::now();
        auto duration_recursive = chrono::duration_cast<chrono::milliseconds>(end_recursive - start_recursive).count();
        
        
        auto start_dp = chrono::high_resolution_clock::now();
        fibonacci_dp(n);
        auto end_dp = chrono::high_resolution_clock::now();
        auto duration_dp = chrono::duration_cast<chrono::milliseconds>(end_dp - start_dp).count();
        
        cout << n << "\t" << duration_recursive << "\t\t" << duration_dp << "\n";
    }

    return 0;
}
