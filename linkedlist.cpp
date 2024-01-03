#include <iostream>
#include <string>
using namespace std;
// Struktur simpul linked list
struct TaskNode {
    std::string task;
    int priority;
    TaskNode* next;
};

// Pointer kepala linked list
TaskNode* head = nullptr;

// Menambahkan tugas ke linked list
string addTask(string task, int priority) {

    TaskNode* newNode = new TaskNode;
    newNode->task = task;
    newNode->priority = priority;
    newNode->next = nullptr;
    cout << "Masukan nama tugas ke list : ";
    cin.ignore();
    getline(cin, newNode->task);
    if (head == nullptr || priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } else {
        TaskNode* current = head;
        while (current->next != nullptr && priority > current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    string kalimat = "Tugas Ditambahkan : " + newNode->task + " (Prioritas: " + to_string(priority) + ")";
    return kalimat;
}

// Menghapus tugas dari linked list
void removeTask(const std::string& task) {
    TaskNode* current = head;
    TaskNode* prev = nullptr;

    while (current != nullptr && current->task != task) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }

        delete current;
        std::cout << "Tugas dihapus: " << task << std::endl;
    } else {
        std::cout << "Tugas tidak ditemukan: " << task << std::endl;
    }
}

// Menampilkan daftar tugas
void displayTasks() {
    if (head == nullptr) {
        std::cout << "To-Do List kosong." << std::endl;
    } else {
        std::cout << "To-Do List:" << std::endl;
        TaskNode* current = head;
        while (current != nullptr) {
            std::cout << "  " << current->task << " (Prioritas: " << current->priority << ")" << std::endl;
            current = current->next;
        }
    }
}

int main() {
    cout << "Fitur :\n";
    cout << "1. Tambahkan List Tugas\n";
    cout << "2. Tampilkan List Tugas\n";
    cout << "3. Hapus Tugas Dari List\n";
    int pilihan;
    do{
        
        cout << "Pilih Fitur yang ingin digunakan 1/2/3 : ";
        cin >> pilihan;
        switch(pilihan){
        case 1:{
            string namaTugas;
            int prioritas;
            cout << "Tingkat prioritas ? ";
            cin >> prioritas;
            cout << addTask(namaTugas, prioritas) << endl;
            break;
        }case 2:{
            displayTasks();
            cout << endl;
            break;
        }case 3:{
            string hapus;
            cout << "Hapus Tugas dari daftar list : ";
            cin >> hapus;
            removeTask(hapus);
            cout << endl;
            break;
        }
        default:
            cout << "Berhenti\n";
            break;
        }
    }while(pilihan < 4);
    return 0;
}