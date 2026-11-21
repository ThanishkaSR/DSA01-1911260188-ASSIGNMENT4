#include <iostream>
using namespace std;

class Account {
public:
    double rate() const {
        return 3.5;
    }

    ~Account() {
        cout << "Account destructor\n";
    }
};

class SeniorAccount : public Account {
    double* history = new double[100];

public:
    double rate() const {
        return 4.0;
    }

    ~SeniorAccount() {
        delete[] history;
        cout << "SeniorAccount destructor\n";
    }
};

int main() {
    Account* accounts[2] = {
        new Account,
        new SeniorAccount
    };

    for (Account* a : accounts) {
        cout << a->rate() << endl;
    }

    for (Account* a : accounts) {
        delete a;
    }

    Account copy = SeniorAccount();

    return 0;
}


#include <iostream>
#include <memory>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destructor\n";
    }
};

class SeniorAccount : public Account {
    double* history = new double[100];

public:
    double rate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destructor\n";
    }
};

int main() {
    unique_ptr<Account> accounts[2];

    accounts[0] = make_unique<Account>();
    accounts[1] = make_unique<SeniorAccount>();

    for (const auto& a : accounts) {
        cout << a->rate() << endl;
    }

    return 0;
}



#include <iostream>

struct Account {
    double rate() const {
        return 3.5;
    }

    virtual double vrate() const {
        return 3.5;
    }

    virtual ~Account() = default;
};

struct SeniorAccount : Account {
    double rate() const {
        return 4.0;
    }

    double vrate() const override {
        return 4.0;
    }
};

int main() {
    SeniorAccount s;

    Account* p = &s;

    Account copy = s;

    std::cout << p->rate() << ' '
              << p->vrate() << ' '
              << copy.vrate() << '\n';
}


#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() = default;
};

class SeniorAccount : public Account {
public:
    double rate() const override {
        return 4.0;
    }
};

int main() {
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());

    for (const auto& a : accounts) {
        cout << a->rate() << endl;
    }

    return 0;
}



