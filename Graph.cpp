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

void displayGroupByName(Graph G, string name) {
    adrVertex V = FirstVertex(G);
    cout << name << " Mengikuti Kelompok Keilmuan : " << endl;
    while (V) {
        bool found = false;
        adrEdge E = FirstEdge(V);
        while (E) {
            if (Name(E) == name) {
                found = true;
                break;
            }
            E = NextEdge(E);
        }
        if (found) {
            cout << "- " << ExpertiseGroups(V) << endl;
        }
        V = NextVertex(V);
    }
}

void displayAllGroups(Graph G) {
    adrVertex V = FirstVertex(G);
    while (V) {
        cout << "Kelompok Keilmuan : " << ExpertiseGroups(V) << "\n  Mahasiswa: ";
        adrEdge E = FirstEdge(V);

        bool first = true;
        while (E) {
            if (!first) {
                cout << ", ";
            }
            cout << Name(E);
            first = false;
            E = NextEdge(E);
        }
        cout << "\n";
        V = V->NextVertex;
    }
}

void deleteEdgeInAllVertex(Graph& G, string name) {
    adrVertex V = FirstVertex(G);

    while (V) {
        adrEdge prev = NULL;
        adrEdge curr = FirstEdge(V);

        while (curr) {
            if (Name(curr) == name) {
                if (prev == NULL) {
                    FirstEdge(V) = NextEdge(curr);
                } else {
                    NextEdge(prev) = NextEdge(curr);
                }
                adrEdge temp = curr;
                curr = NextEdge(curr);
                delete temp;
            } else {
                prev = curr;
                curr = NextEdge(curr);
            }
        }
        V = NextVertex(V);
    }
    cout << "Penghapusan edge dengan nama " << name << " di semua vertex selesai.\n";
}


string deleteEdge(Graph& G, string expertiseGroup, string name) {
    adrVertex V = findVertex(G, expertiseGroup);
    if (V) {
        adrEdge prev = NULL;
        adrEdge curr = FirstEdge(V);

        while (curr) {
            if (Name(curr) == name) {
                if (prev == NULL) {
                    FirstEdge(V) = NextEdge(curr);
                } else {
                    NextEdge(prev) = NextEdge(curr);
                }
                delete curr;
                return name + " berhasil dihapus dari Kelompok Keilmuan " + expertiseGroup + ".\n";
            }

            prev = curr;
            curr = NextEdge(curr);
        }
        return "Nama tidak ditemukan di Kelompok Keilmuan " + expertiseGroup + ".\n";
    } else {
        return "Kelompok Keilmuan tidak ditemukan.\n";
    }
}


string deleteVertex(Graph& G, string expertiseGroup) {
    if (!isEmpty(G)){
        adrVertex prev = NULL;
        adrVertex curr = FirstVertex(G);

        while (curr && ExpertiseGroups(curr) != expertiseGroup) {
            prev = curr;
            curr = NextVertex(curr);
        }

        if (curr == NULL) {
            return "Kelompok Keilmuan " + expertiseGroup + " tidak ditemukan.\n";
        }

        adrEdge edge = FirstEdge(curr);
        while (edge) {
            adrEdge tempEdge = edge;
            edge = NextEdge((edge));
            delete tempEdge;
        }

        if (prev == NULL) {
            FirstVertex(G) = NextVertex(curr);
        } else {
            NextVertex(prev) = NextVertex(curr);
        }

        delete curr;
        return "Kelompok Keilmuan '" + expertiseGroup + "' berhasil dihapus.\n";
    } else {
        return  "Graph kosong.\n";
    }
}


void menu() {
    Graph G;
    createGraph(G);
    int choice, total, subChoice;
    string group, name;
    do {
        cout << "\n<------------------  Menu  ------------------>\n \n";
        cout << "1. Tambah Anggota / Kelompok Keilmuan\n";
        cout << "2. Tampilkan Anggota / Kelompok Keilmuan\n";
        cout << "3. Hapus Anggota / Kelompok Keilmuan\n";
        cout << "0. keluar\n";
        cout << "\n<--------------------------------------------> \n";
        choice = getIntInput("Pilih : ");
        system("cls");

        switch (choice) {
        case 1: {
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Tambah Kelompok Keilmuan\n";
            cout << "2. Tambah Anggota ke Kelompok Keilmuan\n";
            cout << "3. Tambah Anggota dan Kelompok Keilmuan\n";
            cout << "\n<--------------------------------------------> \n";
            subChoice = getIntInput("Pilih : ");

            switch (subChoice) {
                case 1:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    addVertex(G, group);
                    system("cls");
                    cout << "\n Data Berhasil Disimpan! \n";
                    break;
                case 2:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    name = getStringInput("Masukkan Nama Anggota \t\t: ");
                    addEdge(G, group, name);
                    system("cls");
                    cout << "\n Data Berhasil Disimpan! \n";
                    break;
                case 3:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    total = getIntInput("Masukkan Jumlah Orang \t\t: ");
                    for (int i = 1; i <= total; i++) {
                        name = getStringInput("Masukkan Nama orang ke " + to_string(i) + " \t: ");
                        addEdge(G, group, name);
                    }
                    system("cls");
                    cout << "\n Data Berhasil Disimpan! \n";
                    break;
                default:
                    cout << "Pilihan salah! Silakan Coba Lagi.\n";
            }
            break;
        }
        case 2: {
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Tampilkan Anggota Berdasarkan Kelompok Keilmuan\n";
            cout << "2. Tampilkan Anggota Berdasarkan Nama\n";
            cout << "3. Tampilkan Semua\n";
            cout << "\n<--------------------------------------------> \n";
            subChoice = getIntInput("Pilih : ");

            switch (subChoice) {
                case 1:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    displayGroupMembers(G, group);
                    break;
                case 2:
                    name = getStringInput("Masukkan Nama Anggota yang ingin dicari : ");
                    displayGroupByName(G, name);
                    break;
                case 3:
                    displayAllGroups(G);
                    break;
                default:
                    cout << "Pilihan salah! Silakan Coba Lagi.\n";
            }
            break;
        }
        case 3: {
            cout << "\n<-------------------------------------------->\n \n";
            cout << "1. Hapus Anggota Dari Kelompok Keilmuan\n";
            cout << "2. Hapus Kelompok Keilmuan\n";
            cout << "3. Hapus Anggota Dari Semua Kelompok Keilmuan\n";
            cout << "\n<--------------------------------------------> \n";
            subChoice = getIntInput("Pilih : ");

            switch (subChoice) {
                case 1:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    name = getStringInput("Masukkan Nama Anggota \t\t: ");
                    system("cls");
                    cout << deleteEdge(G, group, name);
                    break;
                case 2:
                    group = getStringInput("Masukkan Nama Kelompok Keilmuan : ");
                    system("cls");
                    cout << deleteVertex(G, group);
                    break;
                case 3:
                    name = getStringInput("Masukkan Nama Anggota yang ingin dihapus: ");
                    system("cls");
                    deleteEdgeInAllVertex(G, name);
                    break;
                default:
                    cout << "Pilihan salah! Silakan Coba Lagi.\n";
            }
            break;
        }
        case 0:
            cout << "Keluar...\n";
            break;
        }
    } while (choice != 0);
}
