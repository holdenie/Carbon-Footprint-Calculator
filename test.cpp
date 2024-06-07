#include <iostream>

using namespace std;

const double CAR_EMISSION_FACTOR = 8.887; // kg CO2 per gallon
const double BUS_EMISSION_FACTOR = 0.089; // kg CO2 per mile
const double ELECTRICITY_EMISSION_FACTOR = 0.233; // kg CO2 per kWh
const double WASTE_EMISSION_FACTOR = 0.43; // kg CO2 per kg of WASTE_EMISSION_FACTOR
const double kgToLiter = 0.9860;

double calculateCarFootprint(double mpg, double milesDriven){
   return milesDriven * (1/mpg) * CAR_EMISSION_FACTOR;
}

double calculateBusFootprint(double miles){
  return miles * BUS_EMISSION_FACTOR;
}

double calculateElecFootprint(double kwh){
  return kwh / 31 * 7 * ELECTRICITY_EMISSION_FACTOR;
}

double calculateWasteFootprint(double waste){
  return waste / 31 * 7 * WASTE_EMISSION_FACTOR;
}

double calculateSwimmingPool(double kg){
  return kg * 545.184 * 0.5;
}
int main() {
  double carMileage, carMiles, busMiles, elecUsage, wasteProd;
    cout << "What is your car's gas mileage?" << endl;
    cin >> carMileage;
    cout << "How many miles do you drive per week?" << endl;
    cin >> carMiles;
    cout << "For how many miles do you drive the bus per week?" << endl;
    cin >> busMiles;
    cout << "What is your monthy electricity usage in kWh?" << endl;
    cin >> elecUsage;
    cout << "How many kg of waste do you produce per month?" << endl;
    cin >> wasteProd;
    double carFootprint = calculateCarFootprint(carMileage, carMiles);
    double busFootprint = calculateBusFootprint(busMiles);
    double elecFootprint = calculateElecFootprint(elecUsage);
    double wasteFootprint = calculateWasteFootprint(wasteProd);
    double total = carFootprint + busFootprint + elecFootprint + wasteFootprint;
    double swimmingPool = calculateSwimmingPool(total);
    cout << "You're producing " << total << "kg of C02 per week"<< endl;
    cout << "That's " << swimmingPool << " water bottles per week!" << endl;
    return 0;
}
