#include "class.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor
Student::Student(int max_capacity) : capacity(max_capacity), Count(0) {
    AD = new string[capacity];
    ogrno = new float[capacity];
    Arasinav = new float[capacity];
    ikinciSinav = new float[capacity];
    Odev = new float[capacity];
    Final = new float[capacity];
    Devam = new int[capacity];
}

// Destructor
Student::~Student() {
    delete[] AD;
    delete[] ogrno;
    delete[] Arasinav;
    delete[] ikinciSinav;
    delete[] Odev;
    delete[] Final;
    delete[] Devam;
}

// CSV Dosyasından Verileri Okuma
void Student::readFromCSV() {
    ifstream iFile("girdi.csv");
    if (!iFile.is_open()) {
        cout << "Girdi dosyasi acilamadi!" << endl;
        return;
    }

    string line;
    getline(iFile, line); // Başlık satırını atla

    while (getline(iFile, line) && Count < capacity) {
        stringstream ss(line);
        string temp;

        // AD
        getline(ss, temp, ',');
        AD[Count] = temp;

        // Öğrenci No
        getline(ss, temp, ',');
        ogrno[Count] = stof(temp);

        // Ara Sınav
        getline(ss, temp, ',');
        Arasinav[Count] = stof(temp);

        // İkinci Sınav
        getline(ss, temp, ',');
        ikinciSinav[Count] = stof(temp);

        // Ödev
        getline(ss, temp, ',');
        Odev[Count] = stof(temp);

        // Final
        getline(ss, temp, ',');
        Final[Count] = stof(temp);

        // Devam
        if (getline(ss, temp, ',')) {
            Devam[Count] = stoi(temp);
        } else {
            Devam[Count] = 0; // Varsayılan değer
        }

        Count++;
    }

    iFile.close();
    cout << "Veriler basariyla okundu. Toplam ögrenci: " << Count << endl;
}

// Ortalama Hesaplama
double Student::average(int index) const {
    if (index < 0 || index >= Count) {
        return 0.0;
    }
    return (Arasinav[index] * 0.2) + (ikinciSinav[index] * 0.2) +
           (Odev[index] * 0.2) + (Final[index] * 0.4);
}

// Parametresiz Yazdırma
void Student::print() const {
    for (int i = 0; i < Count; i++) {
        cout << "AD: " << AD[i] << endl;
        cout << "OgrNo: " << ogrno[i] << endl;
        cout << "Ara Sinav: " << Arasinav[i] << endl;
        cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
        cout << "Odev: " << Odev[i] << endl;
        cout << "Final: " << Final[i] << endl;
        cout << "Devam: " << Devam[i] << endl;
        cout << "Ortalama: " << average(i) << endl;
        cout << "---------------------------" << endl;
    }
}

// Parametreli Yazdırma
void Student::print(const string& input) {
    int sayac = 0;
    int sayac0 = 0;
    if (input == "0") {
        cout << "Ortalamasi 50'nin altinda olan ögrenciler:\n";
        for (int i = 0; i < Count; i++) {
            if (average(i) < 50) {
                cout << "AD: " << AD[i] << endl;
                cout << "OgrNo: " << ogrno[i] << endl;
                cout << "Ara Sinav: " << Arasinav[i] << endl;
                cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
                cout << "Odev: " << Odev[i] << endl;
                cout << "Final: " << Final[i] << endl;
                cout << "Devam: " << Devam[i] << endl;
                cout << "Ortalama: " << average(i) << endl;
                cout << "---------------------------" << endl;
                sayac++;
            }
        }
        cout << "Siniftan kalan sayisi: " << sayac << endl;
    } else if (input == "1") {
        cout << "Ortalamasi 50'nin üzerinde olan ögrenciler:\n";
        for (int i = 0; i < Count; i++) {
            if (average(i) >= 50) {
                sayac0++;
                cout << "AD: " << AD[i] << endl;
                cout << "OgrNo: " << ogrno[i] << endl;
                cout << "Ara Sinav: " << Arasinav[i] << endl;
                cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
                cout << "Odev: " << Odev[i] << endl;
                cout << "Final: " << Final[i] << endl;
                cout << "Devam: " << Devam[i] << endl;
                cout << "Ortalama: " << average(i) << endl;
                cout << "---------------------------" << endl;
            }
        }
        cout << "Siniftan gecen sayisi: " << sayac0 << endl;
    } else {
        printToFile(input); // Dosyaya yazdırma fonksiyonunu çağır
    }
}

// Dosyaya Yazdırma
void Student::printToFile(const string& filename) {
    cout << "Tüm veriler " << filename << " dosyasina yaziliyor...\n";
    ofstream oFile(filename);
    if (!oFile.is_open()) {
        cout << "Cikis dosyasi acilamadi!" << endl;
        return;
    }
    for (int i = 0; i < Count; i++) {
        oFile << "AD: " << AD[i] << endl;
        oFile << "OgrNo: " << ogrno[i] << endl;
        oFile << "Ara Sinav: " << Arasinav[i] << endl;
        oFile << "Ikinci Sinav: " << ikinciSinav[i] << endl;
        oFile << "Ödev: " << Odev[i] << endl;
        oFile << "Final: " << Final[i] << endl;
        oFile << "Devam: " << Devam[i] << endl;
        oFile << "Ortalama: " << average(i) << endl;
        oFile << "Ogrencinin geçme durumu: " << (average(i) < 50 ? "kaldi" : "geçti") << endl;
        oFile << "\n---------------------------" << endl;
    }
    oFile.close();
    cout << "Veriler basariyla " << filename << " dosyasina yazildi.\n";
}
