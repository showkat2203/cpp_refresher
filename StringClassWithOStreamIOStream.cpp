#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* data;
    size_t size;

public:
    String() : data(nullptr), size(0) {}
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        strncpy(data, str, size);
        data[size] = '\0';
    }
    ~String() { delete[] data; }
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};

ostream& operator<<(ostream& out, const String& obj) {
    return out << obj.size << " " << obj.data << endl;
}

istream& operator>>(istream& inn, String& obj) {
    inn >> obj.size;
    inn.ignore();
    obj.data = new char[obj.size + 1];
    inn.getline(obj.data, obj.size + 1);
    return inn;
}

int main() {
    String x;
    cout << "Enter a string: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    String newStr("My Name is Showkat");
    cout << "Predefined string: " << newStr << endl;

    return 0;
}
