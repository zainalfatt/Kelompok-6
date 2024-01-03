#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Mahasiswa
{
public:
    void data();
};

typedef struct
{
    int tanggal;
    string NIM;
    char nama[20];
    string prodi;
    string pembayaran; 

} MHS;

MHS data_mahasiswa[5];
MHS temp;
int n, i, b, cari;

void Mahasiswa::data()
{
    cout << "================================================================" << endl;
    cout << "           PROGRAM SORTING DAN SEARCHING PEMBAYARAN UKT        " << endl;
    cout << "================================================================" << endl;

    cout << "Masukkan banyak data = ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Data ke-" << (i + 1) << ":" << endl;

        cout << "Masukkan tanggal      : ";
        cin >> data_mahasiswa[i].tanggal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan NIM          : ";
        cin >> data_mahasiswa[i].NIM;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan Nama         : ";
        cin.getline(data_mahasiswa[i].nama, sizeof(data_mahasiswa[i].nama));
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan prodi        : ";
        getline(cin, data_mahasiswa[i].prodi);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan pembayaran   : Rp. ";
        cin >> data_mahasiswa[i].pembayaran;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << endl;
    }

    cout << "Data Mahasiswa" << endl;
    cout << "==============================================================================" << endl;
    cout << "|     Tanggal\t|\tNIM\t|\tNama\t|\tprodi\t|\tJumlah pembayaran\t|" << endl;
    cout << "==============================================================================" << endl;

    for (b = 0; b < n; b++)
    {
        cout << "|\t" << data_mahasiswa[b].tanggal << "\t|\t" << data_mahasiswa[b].NIM << "\t|\t" << data_mahasiswa[b].nama << "\t|\t" << data_mahasiswa[b].prodi << "\t|\t" << data_mahasiswa[b].pembayaran << "\t|" << endl;
        cout << "===================================================================================================================" << endl;
    }

    for (i = 0; i < n; i++)
    {
        for (b = 0; b < n - 1; b++)
        {
            if (data_mahasiswa[b].tanggal > data_mahasiswa[b + 1].tanggal)
            {
                temp.tanggal = data_mahasiswa[b].tanggal;
                data_mahasiswa[b].tanggal = data_mahasiswa[b + 1].tanggal;
                data_mahasiswa[b + 1].tanggal = temp.tanggal;

                strcpy(temp.nama, data_mahasiswa[b].nama);
                strcpy(data_mahasiswa[b].nama, data_mahasiswa[b + 1].nama);
                strcpy(data_mahasiswa[b + 1].nama, temp.nama);

                temp.prodi = data_mahasiswa[b].prodi;
                data_mahasiswa[b].prodi = data_mahasiswa[b + 1].prodi;
                data_mahasiswa[b + 1].prodi = temp.prodi;

                temp.NIM = data_mahasiswa[b].NIM;
                data_mahasiswa[b].NIM = data_mahasiswa[b + 1].NIM;
                data_mahasiswa[b + 1].NIM = temp.NIM;

                temp.pembayaran = data_mahasiswa[b].pembayaran;
                data_mahasiswa[b].pembayaran = data_mahasiswa[b + 1].pembayaran;
                data_mahasiswa[b + 1].pembayaran = temp.pembayaran;
            }
        }
    }

    cout << endl;

    cout << "Setelah data diurutkan berdasarkan Tanggal : " << endl;
    cout << "==============================================================================" << endl;
    cout << "|     Tanggal\t|\tNIM\t|\tNama\t|\tprodi\t|\tJumlah pembayaran\t|" << endl;
    cout << "==============================================================================" << endl;

    for (b = 0; b < n; b++)
    {
        cout << "|\t" << data_mahasiswa[b].tanggal << "\t|\t" << data_mahasiswa[b].NIM << "\t|\t" << data_mahasiswa[b].nama << "\t|\t" << data_mahasiswa[b].prodi << "\t|\t" << data_mahasiswa[b].pembayaran << "\t|" << endl;
        cout << "===================================================================================================================" << endl;
    }

    cout << endl;
    cin.ignore();
    cout << "Masukkan NIM untuk mencari : ";
    string cari_str;
    getline(cin, cari_str);
    bool found = false;
    for (b = 0; b < n; b++)
    {
        if (data_mahasiswa[b].NIM == cari_str)
        {
            cout << "Pembayaran Tanggal :" << data_mahasiswa[b].tanggal << endl;
            cout << "NIM                :" << data_mahasiswa[b].NIM << endl;
            cout << "Nama               :" << data_mahasiswa[b].nama << endl;
            cout << "Prodi              :" << data_mahasiswa[b].prodi << endl;
            cout << "Jumlah Pembayaran  : Rp." << data_mahasiswa[b].pembayaran << endl;
            cout << "================================================================ :" << data_mahasiswa[b].tanggal << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Data tidak ditemukan" << endl;
    }
}

int main()
{
    Mahasiswa x;
    x.data();
    return 0;
}
