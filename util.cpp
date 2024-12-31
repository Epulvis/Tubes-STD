#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

int getIntInput(const string& message) {
    string input;
    while (true) {
        try {
            cout << message;
            getline(cin, input);
            int value = stoi(input);
            return value;
        } catch (const invalid_argument&) {
            cout << "Input tidak valid. Harap masukkan angka." << endl;
        } catch (...) {
            cout << "Ada kesalahan. Silakan coba lagi." << endl;
        }
    }
}

string getStringInput(const string& message) {
    string input;
    while (true) {
        try {
            cout << message;
            getline(cin, input);

            if (input.empty()) {
                throw runtime_error("Input tidak valid. Harap masukkan lagi.");
            }

            return input;
        } catch (const runtime_error& e) {
            cout << e.what() << endl;
        } catch (...) {
            cout << "Ada kesalahan. Silakan coba lagi." << endl;
        }
    }
}
