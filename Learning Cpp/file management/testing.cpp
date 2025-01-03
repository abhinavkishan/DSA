#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream writefile("./files/output_test.txt");
    if (writefile.is_open()) {
        writefile << "This is a line.\n";
        writefile << "This is another line.\n";
        writefile.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }

    // fstream readfile("./files/users.csv");
    fstream readfile;
    readfile.open("./files/users.csv", ios::in | ios::out | ios::app);
    if (readfile.is_open()) {
        string line;
        getline(readfile, line);
        while (getline(readfile, line)) {
            cout << line << '\n';
            string username = line.substr(0, line.find(','));
            string password = line.substr(line.find(',') + 1);
            cout << "Username: " << username << '\n';
            cout << "Password: " << password << '\n';
        }
        // readfile.seekp(0, ios::end);
        // readfile << "newuser,newpassword\n";
        readfile.close();

    } else {
        cout << "Unable to open file for reading.\n";
    }

    fstream readfile2("./files/users.csv");
    if(readfile2.is_open()) {
        readfile2.seekp(0, ios::end);
        readfile2 << "newuser,newpassword\n";
        readfile2.close();
    }

    return 0;
}