#include <iostream>
#include <string>
using namespace std;

class DRUG {
protected:
    string category;
    string dateOfManufacture;
    string companyName;

public:
    void setCategory(string cat) {
        category = cat;
    }

    void setDateOfManufacture(string date) {
        dateOfManufacture = date;
    }

    void setCompanyName(string company) {
        companyName = company;
    }

    string getCategory() {
        return category;
    }

    string getDateOfManufacture() {
        return dateOfManufacture;
    }

    string getCompanyName() {
        return companyName;
    }
};

class TABLET : public DRUG {
private:
    string tabletName;
    double price;

public:
    void setTabletName(string name) {
        tabletName = name;
    }

    void setPrice(double p) {
        price = p;
    }

    string getTabletName() {
        return tabletName;
    }

    double getPrice() {
        return price;
    }
};

class PainReliever : public TABLET {
private:
    int dosageUnits;
    string sideEffects;
    int useWithinDays;

public:
    void setDosageUnits(int units) {
        dosageUnits = units;
    }

    void setSideEffects(string effects) {
        sideEffects = effects;
    }

    void setUseWithinDays(int days) {
        useWithinDays = days;
    }

    int getDosageUnits() {
        return dosageUnits;
    }

    string getSideEffects() {
        return sideEffects;
    }

    int getUseWithinDays() {
        return useWithinDays;
    }
};

int main() {
    PainReliever pr;
    string category, dateOfManufacture, companyName, tabletName, sideEffects;
    double price;
    int dosageUnits, useWithinDays;

    cout << "Enter Category: ";
    getline(cin, category);
    pr.setCategory(category);

    cout << "Enter Date of Manufacture (DD-MM-YYYY): ";
    getline(cin, dateOfManufacture);
    pr.setDateOfManufacture(dateOfManufacture);

    cout << "Enter Company Name: ";
    getline(cin, companyName);
    pr.setCompanyName(companyName);

    cout << "Enter Tablet Name: ";
    getline(cin, tabletName);
    pr.setTabletName(tabletName);

    cout << "Enter Price: ";
    cin >> price;
    pr.setPrice(price);
    cin.ignore();  

    cout << "Enter Dosage Units (1, 2, or 3): ";
    cin >> dosageUnits;
    pr.setDosageUnits(dosageUnits);

    cin.ignore();  
    cout << "Enter Side Effects: ";
    getline(cin, sideEffects);
    pr.setSideEffects(sideEffects);

    cout << "Enter Use Within Days (10, 20, or 30): ";
    cin >> useWithinDays;
    pr.setUseWithinDays(useWithinDays);

    cout << "\nCategory: " << pr.getCategory() << endl;
    cout << "Date of Manufacture: " << pr.getDateOfManufacture() << endl;
    cout << "Company Name: " << pr.getCompanyName() << endl;
    cout << "Tablet Name: " << pr.getTabletName() << endl;
    cout << "Price: $" << pr.getPrice() << endl;
    cout << "Dosage Units: " << pr.getDosageUnits() << endl;
    cout << "Side Effects: " << pr.getSideEffects() << endl;
    cout << "Use Within Days: " << pr.getUseWithinDays() << endl;

    return 0;
}