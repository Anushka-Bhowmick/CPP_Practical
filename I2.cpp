#include <iostream>
#include <string>

using namespace std;

class HOTEL {
private:
    string Hotel_name;
    string Hotel_type;
    string city;
    int Hotel_rate;

public:
    void setHotelName(string name) {
        Hotel_name = name;
    }

    void setHotelType(string type) {
        Hotel_type = type;
    }

    void setCity(string c) {
        city = c;
    }

    void setHotelRate(int rate) {
        Hotel_rate = rate;
    }

    string getHotelName() {
        return Hotel_name;
    }

    string getHotelType() {
        return Hotel_type;
    }

    string getCity() {
        return city;
    }

    int getHotelRate() {
        return Hotel_rate;
    }
};

class FLIGHT {
private:
    string flight_no;
    string source_city;
    string destination_city;
    int seat_no;

public:
    void setFlightNo(const string& flight) {
        flight_no = flight;
    }

    void setSourceCity(const string& source) {
        source_city = source;
    }

    void setDestinationCity(const string& destination) {
        destination_city = destination;
    }

    void setSeatNo(int seat) {
        seat_no = seat;
    }

    string getFlightNo() const {
        return flight_no;
    }

    string getSourceCity() const {
        return source_city;
    }

    string getDestinationCity() const {
        return destination_city;
    }

    int getSeatNo() const {
        return seat_no;
    }
};

class PASSENGER : public HOTEL, public FLIGHT {
private:
    string name;
    int age;
    string passenger_city;

public:
    void setName(const string& passenger_name) {
        name = passenger_name;
    }

    void setAge(int passenger_age) {
        age = passenger_age;
    }

    void setPassengerCity(const string& city) {
        passenger_city = city;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getPassengerCity() const {
        return passenger_city;
    }
};

int main() {
    PASSENGER passenger;
    string hotel_name, hotel_type, hotel_city;
    int hotel_rate;
    cout << "Enter Hotel Name: ";
    getline(cin, hotel_name);
    cout << "Enter Hotel Type: ";
    getline(cin, hotel_type);
    cout << "Enter Hotel City: ";
    getline(cin, hotel_city);
    cout << "Enter Hotel Rate: ";
    cin >> hotel_rate;
    cin.ignore();  

    passenger.setHotelName(hotel_name);
    passenger.setHotelType(hotel_type);
    passenger.setCity(hotel_city);
    passenger.setHotelRate(hotel_rate);

    string flight_no, source_city, destination_city;
    int seat_no;
    cout << "Enter Flight Number: ";
    cin >> flight_no;
    cout << "Enter Source City: ";
    cin.ignore();  
    getline(cin, source_city);
    cout << "Enter Destination City: ";
    getline(cin, destination_city);
    cout << "Enter Seat Number: ";
    cin >> seat_no;

    passenger.setFlightNo(flight_no);
    passenger.setSourceCity(source_city);
    passenger.setDestinationCity(destination_city);
    passenger.setSeatNo(seat_no);

    string passenger_name, passenger_city;
    int passenger_age;
    cout << "Enter Passenger Name: ";
    cin.ignore();  
    getline(cin, passenger_name);
    cout << "Enter Passenger Age: ";
    cin >> passenger_age;
    cout << "Enter Passenger City: ";
    cin.ignore();  
    getline(cin, passenger_city);

    passenger.setName(passenger_name);
    passenger.setAge(passenger_age);
    passenger.setPassengerCity(passenger_city);

    cout << "\nPassenger Details:" << endl;
    cout << "Passenger Name: " << passenger.getName() << endl;
    cout << "Passenger Age: " << passenger.getAge() << endl;
    cout << "Passenger City: " << passenger.getPassengerCity() << endl;
    cout << "Hotel Name: " << passenger.getHotelName() << endl;
    cout << "Hotel Type: " << passenger.getHotelType() << endl;
    cout << "Hotel City: " << passenger.getCity() << endl;
    cout << "Hotel Rate: $" << passenger.getHotelRate() << endl;
    cout << "Flight Number: " << passenger.getFlightNo() << endl;
    cout << "Source City: " << passenger.getSourceCity() << endl;
    cout << "Destination City: " << passenger.getDestinationCity() << endl;
    cout << "Seat Number: " << passenger.getSeatNo() << endl;

    return 0;
}