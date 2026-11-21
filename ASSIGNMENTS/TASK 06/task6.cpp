#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented;

public:
    Vehicle(string reg, double rate)
        : registration(reg), dailyRate(rate), rented(false) {}

    virtual double rentalCharge(int days) const = 0;

    virtual void display() const {
        cout << registration
             << " Rate: " << dailyRate
             << " Status: "
             << (rented ? "Rented" : "Available");
    }

    bool rent() {
        if (rented)
            return false;

        rented = true;
        return true;
    }

    double returnVehicle(int days, int lateDays) {
        if (!rented)
            return 0;

        double total = rentalCharge(days) + lateDays * 500;

        rented = false;

        return total;
    }

    virtual ~Vehicle() {}
};

// Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate)
        : Vehicle(reg, rate) {}

    double rentalCharge(int days) const override {
        return dailyRate * days;
    }
};

// Motor Vehicle
class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDate;

public:
    MotorVehicle(string reg, double rate,
                 double fuel, string date)
        : Vehicle(reg, rate),
          fuelLevel(fuel),
          serviceDate(date) {}
};

// Two Wheeler
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate,
               double fuel, string date)
        : MotorVehicle(reg, rate, fuel, date) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + 100;
    }
};

// Car
class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string reg, double rate, double fuel,
        string date, int seatCount)
        : MotorVehicle(reg, rate, fuel, date),
          seats(seatCount) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + 200;
    }
};

// Electric Car
class ElectricCar : public Car {
private:
    double batteryCapacity;
    double chargePerKWh;

public:
    ElectricCar(string reg, double rate,
                double battery, double chargeRate,
                string date, int seatCount)
        : Car(reg, rate, battery, date, seatCount),
          batteryCapacity(battery),
          chargePerKWh(chargeRate) {}

    double rentalCharge(int days) const override {
        return dailyRate * days +
               batteryCapacity * chargePerKWh;
    }
};

// New Vehicle Type: Electric Bus
class ElectricBus : public Vehicle {
private:
    double batteryCapacity;
    double chargePerKWh;
    int seats;

public:
    ElectricBus(string reg, double rate,
                double battery, double chargeRate,
                int seatCount)
        : Vehicle(reg, rate),
          batteryCapacity(battery),
          chargePerKWh(chargeRate),
          seats(seatCount) {}

    double rentalCharge(int days) const override {
        return dailyRate * days +
               batteryCapacity * chargePerKWh +
               seats * 10;
    }
};

int main() {

    Bicycle b("B101", 300);

    TwoWheeler t("T201", 500, 10, "2026-12-01");

    Car c("C301", 1500, 40, "2026-12-05", 5);

    ElectricCar e("E401", 2000, 40, 12,
                  "2026-12-10", 5);

    ElectricBus bus("EB501", 5000, 100, 10, 40);

    Vehicle* fleet[] = {&b, &t, &c, &e, &bus};

    cout << "RENTING VEHICLES" << endl;

    for (Vehicle* v : fleet) {
        if (v->rent())
            cout << "Rented successfully" << endl;
    }

    cout << endl;

    cout << "RETURNING VEHICLES" << endl;

    cout << "Bicycle charge: "
         << b.returnVehicle(2, 0) << endl;

    cout << "TwoWheeler charge: "
         << t.returnVehicle(2, 1) << endl;

    cout << "Car charge: "
         << c.returnVehicle(2, 0) << endl;

    cout << "ElectricCar charge: "
         << e.returnVehicle(2, 1) << endl;

    cout << "ElectricBus charge: "
         << bus.returnVehicle(2, 0) << endl;

    cout << endl;

    cout << "FLEET LIST" << endl;

    for (Vehicle* v : fleet) {
        v->display();
        cout << endl;
    }

    return 0;
}
