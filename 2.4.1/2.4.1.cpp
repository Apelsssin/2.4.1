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
    bool check(std::string str) {
        for (int i = 0; i < ((sizeof(str) / sizeof(char)) - 1); i++) {
            char ch = str[i];
        }
        return true;
    }
    void set(std::string town, std::string street, int house, int flat) {
        this->town = town;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
};
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
    fout << N << std::endl;
    for (int i = N - 1; i >= 0; i--) {
        fout << address[i].get_town() << ", " << address[i].get_street()
            << ", " << address[i].get_house() << ", " << address[i].get_flat() << std::endl;
    }
    delete[] address;
    fout.close();
    fin.close();
}
