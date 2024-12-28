#include <iostream>
#include "Graph.h"

using namespace std;

void createGraph(Graph& G) {
    FirstVertex(G) = NULL;
}

bool isEmpty(Graph G) {
    return FirstVertex(G) == NULL;
}

adrVertex createVertex(string expertiseGroup) {
    adrVertex V = new Vertex;
    ExpertiseGroups(V) = expertiseGroup;
    NextVertex(V) = NULL;
    FirstEdge(V) = NULL;
    return V;
}

adrEdge createEdge(string name) {
    adrEdge E = new Edge;
    Name(E) = name;
    NextEdge(E) = NULL;
    return E;
}

void addVertex(Graph& G, string expertiseGroup) {
    adrVertex newVertex = createVertex(expertiseGroup);

    if (isEmpty(G)) {
        FirstVertex(G) = newVertex;
    } else {
        adrVertex temp = FirstVertex(G);
        while (NextVertex(temp) != NULL) {
            temp = NextVertex(temp);
        }
        NextVertex(temp) = newVertex;
    }
}

adrVertex findVertex(Graph G, string expertiseGroup) {
    adrVertex V = FirstVertex(G);
    while (V) {
        if (ExpertiseGroups(V) == expertiseGroup) {
            return V;
        }
        V = NextVertex(V);
    }
    return NULL;
}

void insertEdge(adrVertex& V, string name) {
    adrEdge E = createEdge(name);
    NextEdge(E) = FirstEdge(V);
    FirstEdge(V) = E;
}

void addEdge(Graph& G, string expertiseGroup, string name) {
    adrVertex V = findVertex(G, expertiseGroup);
    if (!V) {
        addVertex(G, expertiseGroup);
        V = findVertex(G, expertiseGroup);
    }
    insertEdge(V, name);
}

void displayGroupMembers(Graph& G, string expertiseGroup) {
    adrVertex V = findVertex(G, expertiseGroup);
    if (V) {
        cout << "Kelompok Keilmuan : " << expertiseGroup << "\n";
        adrEdge E = FirstEdge(V);
        while (E) {
            cout << "  - " << Name(E) << "\n";
            E = NextEdge(E);
        }
    } else {
        cout << "Kelompok Keilmuan Belum Terbentuk.\n";
    }
}

void displayAllGroups(Graph G) {
    adrVertex V = FirstVertex(G);
    while (V) {
        cout << "Kelompok Keilmuan : " << ExpertiseGroups(V) << "\n" << "  - ";
        adrEdge E = FirstEdge(V);
        while (E) {
            cout << Name(E) << " ";
            E = NextEdge(E);
        }
        V = NextVertex(V);
    }
}


void deleteEdge(Graph& G, string name) {
    adrVertex V = FirstVertex(G);
    while (V) {
        adrEdge E = FirstEdge(V);
        while (E) {
            if (Name(E) == name) {
                adrEdge temp = E;
                E = NextEdge(E);
                delete temp;
            } else {
                E = NextEdge(E);
            }
        }
        V = NextVertex(V);
    }
}

void deleteVertex(Graph& G, string expertiseGroup) {
    adrVertex V = findVertex(G, expertiseGroup);

    if (V) {
        adrVertex temp = V;
        V = NextVertex(V);
        adrEdge E = FirstEdge(temp);
        while (E) {
            adrEdge tempEdge = E;
            E = NextEdge(E);
            delete tempEdge;
        }

        delete temp;
    } else {
        cout << "Kelompok Keilmuan Belum Terbentuk.\n";
    }
}

void menu() {
    Graph G;
    createGraph(G);
    int choice;
    do {
        cout << "\n<------------------  Menu  ------------------>\n \n";
        cout << "1. Tambah Anggota / Kelompok Keilmuan\n";
        cout << "2. Tampilkan Anggota / Kelompok Keilmuan\n";
        cout << "3. Hapus Anggota / Kelompok Keilmuan\n";
        cout << "0. keluar\n";
        cout << "\n<--------------------------------------------> \n";
        cout << "Pilih : ";
        cin >> choice;

        system("cls");

        switch (choice) {
        case 1: {
            int subChoice;
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Tambah Kelompok Keilmuan\n";
            cout << "2. Tambah Angota ke Kelompok Keilmuan\n";
            cout << "3. Tambah Angota dan Kelompok Keilmuan\n";
            cout << "\n<--------------------------------------------> \n";
            cout << "Pilih : ";
            cin >> subChoice;

            if (subChoice == 1) {
                string group;
                cout << "Masukkan Nama Kelompok Keilmuan : ";
                cin.ignore();
                getline(cin, group);
                addVertex(G, group);
            } else if (subChoice == 2) {
                string group, name;
                cout << "Masukkan Nama Kelompok Keilmuan : ";
                cin.ignore();
                getline(cin, group);
                cout << "Masukkan Nama Anggota \t:";
                getline(cin, name);
                addEdge(G, group, name);
            } else if (subChoice == 3) {
                string group, name;
                int total;
                cout << "Masukkan Nama Kelompok Keilmuan : ";
                cin.ignore();
                getline(cin, group);
                cout << "Masukkan Jumlah Orang \t:";
                cin >> total;
                for (int i = 1; i <= total; i++) {
                    cout << "Masukkan Nama orang ke " << i << " \t: ";
                    cin.ignore();
                    getline(cin, name);
                    addEdge(G, group, name);
                }
            }

            system("cls");
            cout << "\n Data Berhasil Disimpan! \n";
            break;
        }
        case 2: {
            int subChoice;
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Tampilkan Anggota Berdasarkan Kelompok Keilmuan\n";
            cout << "2. Tampilkan Anggota Berdasarkan Nama\n";
            cout << "3. Tampilkan Semua\n";
            cout << "\n<--------------------------------------------> \n";
            cout << "Pilih : ";
            cin >> subChoice;

            if (subChoice == 1) {
                /*...*/
            } else if (subChoice == 2) {
                /*...*/
            } else if (subChoice == 3) {
                /*...*/
            }

            break;
        }
        case 3: {
            int subChoice;
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Hapus Anggota Dari Kelompok Keilmuan\n";
            cout << "2. Hapus Kelompok Keilmuan\n";
            cout << "\n<--------------------------------------------> \n";
            cout << "Pilih : ";

            cin >> subChoice;

            if (subChoice == 1) {
                /*...*/
            } else if (subChoice == 2) {
                /*...*/
            }

            system("cls");
            cout << "\n Data Berhasil Dihapus! \n";
            break;
        }
        case 0:
            cout << "Keluar...\n";
            break;
        default:
            cout << "Pilihan salah! Silakan Coba Lagi.\n";
        }
    } while (choice != 0);
}
