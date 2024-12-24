#include <iostream>
#include "function.cpp"
using namespace std;

int main() {
    Student s; // Varsayılan kapasite 200
    s.readFromCSV();

    string input;
    cout << "Bir deger girin (0, 1 veya dosya adi): ";
    getline(cin, input);

    if (input.empty()) {
        s.print(); // Parametresiz çağırma
    } else {
        s.print(input); // Parametreli çağırma
    }

    return 0;
}
