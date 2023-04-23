#include <iostream>
#include <string>
using namespace std;

int program1(string soal[], string pilihan[][4], int size);
void program2(string soal[], string pilihan[][4], int size);

class setSoal {
    public:
        int soalDKP(string soal[], string pilihan[][4], int size) {
            return program1(soal, pilihan, size);
        }
};

int program1(string soal[], string pilihan[][4], int size) {
    string soalArray[] = { "1. Siapa nama asisten praktikum DKP modul 3?",
                           "2. Modul ke berapa yang menjelaskan tentang function dan method?",
                           "3. Pada tanggal berapa pertemuan perdana praktikum DKP dimulai?",
                           "4. Apa nama ruang yang digunakan saat praktikum DKP?",
                           "5. Apakah praktikum DKP menyenangkan dan bermanfaat?" };
    string pilihanArray[][4] = { { "A. Kak Fangki & Kak Daffa", "B. Kak Irham & Kak Irene", "C. Kak Refan & Kak Rafdan", "D. Kak Carlos & Kak Bintang" },
                                 { "A. Modul 1", "B. Modul 2", "C. Modul 3", "D. Modul 4" },
                                 { "A. 11 Maret 2023", "B. 27 Februari 2023", "C. 23 Februari 2023", "D. 25 Februari 2023" },
                                 { "A. Lab RPL", "B. Lab Multimedia", "C. A101", "D. A102" },
                                 { "A. Ya! Sangat!", "B. Ya..Biasa aja", "C. Tidak!", "D. Saya selalu bolos dan tidak pernah ikut praktikum" } };
    for (int i = 0; i < size; i++) {
        soal[i] = soalArray[i];
        for (int j = 0; j < 4; j++) {
            pilihan[i][j] = pilihanArray[i][j];
        }
    }
    program2(soal, pilihan, size);

    return size;
}

void program2(string soal[], string pilihan[][4], int size) {
    char kunciJawaban[] = { 'A', 'D', 'B', 'A', 'A' };
    char jawab;
    int nilai = 0;
    for (int i = 0; i < size; i++) {
        cout << "**************************\n";
        cout << soal[i] << "\n";
        cout << "**************************\n";
        for (int j = 0; j < 4; j++) {
            cout << pilihan[i][j] << "\n";
        }
        cin >> jawab;
        jawab = toupper(jawab);
        if (jawab == kunciJawaban[i]) {
            cout << "BETUL\n";
            nilai++;
        }
        else {
            cout << "SALAH\n";
            cout << "Jawaban: " << kunciJawaban[i] << "\n";
        }
    }
    cout << "**************************\n";
    cout << "HASIL\n";
    cout << "**************************\n";
    cout << "JAWABAN BENAR: " << nilai << "\n";
    cout << "JUMLAH PERTANYAAN: " << size << "\n";
    cout << "NILAI: " << (nilai/(double)size)*100 << "%";
}

int main()  {
    setSoal DKP;
    string soal[5];
    string pilihan[5][4];
    int size = 5;
    DKP.soalDKP(soal, pilihan, size);
}
