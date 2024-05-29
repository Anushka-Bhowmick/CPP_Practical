#include <iostream>
using namespace std;

class Celsius {
    private:
        double temperature;
    public:
        Celsius(double temp = 0) {
            temperature = temp;
        }

        double toFahrenheit() {
            return (temperature * 9/5) + 32;
        }

        void setTemperature(double temp) {
            temperature = temp;
        }

        double getTemperature() {
            return temperature;
        }
};

class Fahrenheit {
    private:
        double temperature;
    public:
        Fahrenheit(double temp = 0) : temperature(temp) {}

        double toCelsius() {
            return (temperature - 32) * 5/9;
        }

        void setTemperature(double temp) {
            temperature = temp;
        }

        double getTemperature() {
            return temperature;
        }
};

int main() {
    double temp;

    cout << "Enter temperature in Celsius: ";
    cin >> temp;
    Celsius c(temp);
    cout << "Temperature in Fahrenheit: " << c.toFahrenheit() << endl;

    cout << "Enter temperature in Fahrenheit: ";
    cin >> temp;
    Fahrenheit f(temp);
    cout << "Temperature in Celsius: " << f.toCelsius() << endl;

    return 0;
}
