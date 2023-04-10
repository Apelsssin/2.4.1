#include <iostream>
#include <fstream>
#include <string>
class Address {
private:
    std::string town;
    std::string street;
    int house;
    int flat;
public:
    Address() {
        town = "Неизвестно";
        street = "Неизвестно";
        house = 0;
        flat = 0;
    }
    std::string get_town() { return town; }
    std::string get_street() { return street; }
    int get_house() { return house; }
    int get_flat() { return flat; }
    void set(std::string town, std::string street, int house, int flat) {
        this->town = town;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
};
void sort(std::string arr_s[], int arr_c[], int N) {
    bool change = false;
    int ch;
    do {
        std::string st;
        for (int i = 0; i < N - 1; ++i) {
            int k = arr_s[i].compare(arr_s[i + 1]);
            if (k == 1) {
                st = arr_s[i];
                arr_s[i] = arr_s[i + 1];
                arr_s[i + 1] = st;
                ch = arr_c[i];
                arr_c[i] = arr_c[i + 1];
                arr_c[i + 1] = ch;
                change = true;
            }
            else change = false;

        }
    } while (change);
}
int main()
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    int N;
    fin >> N;
    Address* address = new Address[N];
    std::string t;
    std::string s;
    std::string h;
    std::string f;
    for (int i = 0; i < N; ++i) {
        fin >> t >> s >> h >> f;
        address[i].set(t, s, stoi(h), stoi(f));
    }
    std::string* arr_s = new std::string[N];
    int* arr_c = new int[N];
    for (int i = 0; i < N; ++i) {
        arr_s[i] = address[i].get_town();
        arr_c[i] = i;
    }
    sort(&arr_s[0], &arr_c[0], N);
    fout << N << std::endl;
    for (int j = 0; j < N; j++) {
        int i = arr_c[j];
        fout << address[i].get_town() << ", " << address[i].get_street()
            << ", " << address[i].get_house() << ", " << address[i].get_flat() << std::endl;
    }
    delete[] address;
    delete[] arr_s;
    delete[] arr_c;
    fout.close();
    fin.close();
}