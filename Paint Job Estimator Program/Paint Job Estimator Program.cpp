#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Constants
const double SQFT_PER_GALLON = 110.0;
const double SQFT_PER_LABOR_HOUR = 110.0 / 8.0; // i.e., 8 hours per 110 sqft
const double LABOR_RATE = 25.0;

// Gets number of rooms from user (must be ??1)
int getRooms() {
    int rooms;
    do {
        cout << "Enter number of rooms to be painted (>= 1): ";
        cin >> rooms;
        if (rooms < 1)
            cout << "  Error: number of rooms must be at least 1.\n";
    } while (rooms < 1);
    return rooms;
}

// Gets wall space in square feet for a room (must be ??0)
double getSqFt(int roomNumber) {
    double sqft;
    do {
        cout << "Enter square feet for room #" << roomNumber << " (>= 0): ";
        cin >> sqft;
        if (sqft < 0)
            cout << "  Error: square footage cannot be negative.\n";
    } while (sqft < 0);
    return sqft;
}

// Gets paint price per gallon (must be >= $10.00)
double getPricePerGallon() {
    double price;
    do {
        cout << "Enter price per gallon of paint (>= $10.00): ";
        cin >> price;
        if (price < 10.0)
            cout << "  Error: price must be at least $10.00.\n";
    } while (price < 10.0);
    return price;
}

// Calculates gallons needed, rounding up to next whole gallon
// Preconditions: sqft >= 0
// Postcondition: returns integer gallons >= 0
int gallonsForRoom(double sqft) {
    return static_cast<int>(ceil(sqft / SQFT_PER_GALLON));
}

// Calculates labor hours required (may be fractional)
// Preconditions: sqft >= 0
double laborHoursForRoom(double sqft) {
    return (sqft / SQFT_PER_GALLON) * 8.0;
}

// Displays final estimate with totals
void displayEstimate(int totalRooms, int totalGallons,
    double totalLaborHours, double paintCost,
    double laborCost)
{
    cout << "\nEstimate for Painting " << totalRooms << " room";
    if (totalRooms > 1) cout << "s";
    cout << ":\n";
    cout << "Gallons of paint to purchase: " << totalGallons << "\n";
    cout << "Number of hours required to paint: " << totalLaborHours << "\n";
    cout << "Cost of Paint: $" << fixed << setprecision(2) << paintCost << "\n";
    cout << "Cost of Labor: $" << fixed << setprecision(2) << laborCost << "\n";
    cout << "Total cost for job: $" << fixed << setprecision(2)
        << (paintCost + laborCost) << "\n";
}

int main() {
    int totalRooms = getRooms();

    int totalGallons = 0;
    double totalLaborHours = 0.0;
    double totalPaintCost = 0.0;
    double totalLaborCost = 0.0;

    for (int i = 1; i <= totalRooms; ++i) {
        double sqft = getSqFt(i);
        double pricePerGallon = getPricePerGallon();

        int gallons = gallonsForRoom(sqft);
        double laborHrs = laborHoursForRoom(sqft);

        totalGallons += gallons;
        totalLaborHours += laborHrs;
        totalPaintCost += gallons * pricePerGallon;
        totalLaborCost += laborHrs * LABOR_RATE;
    }

    displayEstimate(totalRooms, totalGallons, totalLaborHours,
        totalPaintCost, totalLaborCost);

    return 0;
}
