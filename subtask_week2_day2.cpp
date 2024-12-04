#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;
 
struct CarSensorData {
    double speed;
    double fuelLevel;
    double engineTemp;
    array<double, 4> tirePressure;
    CarSensorData(double speed, double fuelLevel, double engineTemp, array<double, 4> tirePressure) {
        this->speed = speed;
        this->fuelLevel = fuelLevel;
        this->engineTemp = engineTemp;
        this->tirePressure = tirePressure;
    }
};
 
double increasespeed(double a) {
    return a + 10.0;
}
 
double decreasefuel(double a) {
    return a*0.95;
}
 
int change(int a) {
    return 30.0;
}
 
class HMIDashboard {
    vector<double> speed;
    vector<double> fuel;
    vector<double> temp;
    array<double, 4> press;
 
public:
    CarSensorData readCarSensorData(CarSensorData car) {  
        speed.push_back(car.speed);
        fuel.push_back(car.fuelLevel);
        temp.push_back(car.engineTemp);
        press = car.tirePressure;
 
        manipulateSpeed(car);  
        decFuel(car);          
        heating(car);          
        stimulate(car);        
 
        return car;
    }
 
    void manipulateSpeed(CarSensorData& car) {
       
        transform(speed.begin(), speed.end(), speed.begin(), increasespeed);
        car.speed = speed.front();  
    }
 
    void decFuel(CarSensorData& car) {
       
        transform(fuel.begin(), fuel.end(), fuel.begin(), decreasefuel);
        car.fuelLevel = fuel.front();  
    }
 
    void heating(CarSensorData& car) {
       
        transform(temp.begin(), temp.end(), temp.begin(), [](double a) { return a + 2.0; });
        car.engineTemp = temp.front();  
    }
 
    bool b=false;
    void stimulate(CarSensorData& car) {
        for(auto i:car.tirePressure){
             if(i>=30){
                b=true;
            }else{
                b=false;
                break;
            }
        }
       
        for (int i = 0; i < press.size(); i++) {
            if (press[i] < 30) {
                press[i] = change(press[i]);  
            }
        }
        car.tirePressure = press;  
    }
 
    void display(const CarSensorData& car) const {
        cout << "Speed: " << setw(10) << car.speed << " km/h" << endl;
        cout << "Fuel level: " << car.fuelLevel << " %" << endl;
        cout << "Engine Temperature: " << setprecision(3) << car.engineTemp << " °C" << endl;
        cout << "Tire pressure: ";
        for (auto i : car.tirePressure) {
            cout <<setprecision(3)<< i << " PSL,";
        }
        cout << endl;
        cout<<"Tire safe: "<<boolalpha<<b<<endl;
    }
};
 
int main() {
    HMIDashboard hmi;
    CarSensorData car1(100, 80, 95.0, {19.0, 32.5, 44.77, 1.88});
    CarSensorData car = hmi.readCarSensorData(car1);
    hmi.display(car);  
}
 
























