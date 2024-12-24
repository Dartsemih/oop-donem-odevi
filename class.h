#ifndef CLASS_H
#define CLASS_H

#include <string>
using namespace std;

class Student {
private:
    string* AD;
    float* ogrno;
    float* Arasinav;
    float* ikinciSinav;
    float* Odev;
    float* Final;
    int* Devam;
    int Count;          // Öğrenci sayısı
    int capacity;       // Maksimum kapasite

public:
    Student(int max_capacity = 200);  // Constructor
    ~Student();                       // Destructor

    void readFromCSV();
    double average(int index) const;
    void print() const;               // Parametresiz yazdırma fonksiyonu
    void print(const string& input);  // Parametreli yazdırma fonksiyonu
    void printToFile(const string& filename); // Dosyaya yazdırma fonksiyonu
};

#endif

