#include <iostream>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(const string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }

        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; i++) {
            t += prices[i];
        }

        return t * (100 - discount) / 100;
    }
};

int main() {
    // (a) Direct access
    Cart c1;
    c1.add("Rice", 60);
    c1.add("Dal", 120);

    cout << "Direct: " << c1.total() << endl;

    // (b) Access through pointer
    Cart c2;
    Cart* p = &c2;

    p->add("Oil", 180);

    cout << "Pointer: " << p->total() << endl;

    // (c) Access through reference
    Cart c3;
    Cart& r = c3;

    r.add("Milk", 50);

    cout << "Reference: " << r.total() << endl;

    // (d) Dynamic object using new and delete
    Cart* p4 = new Cart;

    p4->add("Bread", 40);

    cout << "Dynamic: " << p4->total() << endl;

    delete p4;

    // Method chaining using this pointer
    Cart c5;

    c5.add("Rice", 60)
      .add("Dal", 120)
      .setDiscount(10);

    cout << "Chaining: " << c5.total() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Cart {
    double amount;

public:
    Cart(double a) : amount(a) {}

    double total() const {
        return amount;
    }
};

int main() {
    Cart c1(250);
    Cart c2(500);
    Cart c3(350);

    Cart* carts[3] = {&c1, &c2, &c3};

    int highest = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > carts[highest]->total()) {
            highest = i;
        }
    }

    cout << "Highest cart total: "
         << carts[highest]->total() << endl;

    return 0;
}

#include <iomanip>
#include <iostream>
#include <string>

class Cart {
    std::string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(const std::string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }

        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; ++i) {
            t += prices[i];
        }

        return t * (100 - discount) / 100;
    }
};

int main() {
    Cart c;

    c.add("Rice", 60)
     .add("Dal", 120)
     .setDiscount(10);

    Cart* p = &c;

    p->add("Oil", 180);

    std::cout << std::fixed
              << std::setprecision(2)
              << p->total() << '\n';
}
