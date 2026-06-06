#include <iostream>
using namespace std;

class LibraryUser {
public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
};

class KidUser : public LibraryUser {
    int age;
    string bookType;

public:
    void setAge(int a) { age = a; }
    void setBookType(string bt) { bookType = bt; }

    void registerAccount() override {
        if (age < 12)
            cout << "You have successfully registered under a Kids Account\n";
        else
            cout << "Sorry, Age must be less than 12 to register as a kid\n";
    }

    void requestBook() override {
        if (bookType == "Kids")
            cout << "Book Issued successfully, please return the book within 10 days\n";
        else
            cout << "Oops, you are allowed to take only kids books\n";
    }
};

class AdultUser : public LibraryUser {
    int age;
    string bookType;

public:
    void setAge(int a) { age = a; }
    void setBookType(string bt) { bookType = bt; }

    void registerAccount() override {
        if (age > 12)
            cout << "You have successfully registered under an Adult Account\n";
        else
            cout << "Sorry, Age must be greater than 12 to register as an adult\n";
    }

    void requestBook() override {
        if (bookType == "Fiction")
            cout << "Book Issued successfully, please return the book within 7 days\n";
        else
            cout << "Oops, you are allowed to take only adult Fiction books\n";
    }
};

int main() {
    KidUser kid;

    kid.setAge(10);
    kid.registerAccount();

    kid.setAge(18);
    kid.registerAccount();

    kid.setBookType("Kids");
    kid.requestBook();

    kid.setBookType("Fiction");
    kid.requestBook();

    cout << endl;

    AdultUser adult;

    adult.setAge(5);
    adult.registerAccount();

    adult.setAge(23);
    adult.registerAccount();

    adult.setBookType("Kids");
    adult.requestBook();

    adult.setBookType("Fiction");
    adult.requestBook();

    return 0;
}
