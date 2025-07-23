#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Constants
const double SQFT_PER_GALLON = 110.0;
const double LABOR_PER_SQFT = 8.0 / 110.0;  // labor hours per square foot
const double LABOR_RATE = 25.0;

// Function prototypes
int getRooms();
double getSqFt();             // single prompt for square footage per room
double getPricePerGallon();   // single prompt for paint cost per gallon
int gallonsForRoom(double sqft);
double laborHoursForRoom(double sqft);
void displayEstimate(int rooms, int gallons, double laborHrs, double paintCost, double laborCost);

int main() {
    int totalRooms = getRooms();
    double sqft = getSqFt();                  // asked once
    double pricePerGallon = getPricePerGallon();  // asked once

    // compute for one room and multiply
    int gallonsPerRoom = gallonsForRoom(sqft);
    double laborHrsPerRoom = laborHoursForRoom(sqft);

    // totals:
    int totalGallons = gallonsPerRoom * totalRooms;
    double totalLaborHours = laborHrsPerRoom * totalRooms;
    double totalPaintCost = totalGallons * pricePerGallon;
    double totalLaborCost = totalLaborHours * LABOR_RATE;

    cout << fixed << setprecision(2);
    displayEstimate(totalRooms, totalGallons, totalLaborHours, totalPaintCost, totalLaborCost);
    return 0;
}

// Prompt for number of rooms (>= 1)
int getRooms() {
    int rooms;
    do {
        cout << "Enter number of rooms to be painted (>= 1): ";
        cin >> rooms;
        if (rooms < 1) cout << "  Error: must enter at least 1 room.\n";
    } while (rooms < 1);
    return rooms;
}

// Prompt square footage per room (>= 0)
double getSqFt() {
    double sqft;
    do {
        cout << "Enter square feet of wall space per room (>= 0): ";
        cin >> sqft;
        if (sqft < 0) cout << "  Error: square footage cannot be negative.\n";
    } while (sqft < 0);
    return sqft;
}

// Prompt paint price per gallon (>= $10)
double getPricePerGallon() {
    double price;
    do {
        cout << "Enter price per gallon of paint (>= $10.00): ";
        cin >> price;
        if (price < 10.0) cout << "  Error: price must be at least $10.00.\n";
    } while (price < 10.0);
    return price;
}

// Compute gallons needed (per room), rounding up
int gallonsForRoom(double sqft) {
    return static_cast<int>(ceil(sqft / SQFT_PER_GALLON));
}

// Compute labor hours needed (per room)
double laborHoursForRoom(double sqft) {
    return sqft * LABOR_PER_SQFT;
}

// Display final estimate
void displayEstimate(int rooms, int gallons, double laborHrs, double paintCost, double laborCost) {
    cout << "\nEstimate for Painting " << rooms << " room" << (rooms > 1 ? "s" : "") << ":\n";
    cout << "Gallons of paint to purchase: " << gallons << "\n";
    cout << "Total labor hours required: " << laborHrs << "\n";
    cout << "Cost of Paint: $" << paintCost << "\n";
    cout << "Cost of Labor: $" << laborCost << "\n";
    cout << "Total cost for job: $" << (paintCost + laborCost) << "\n";
}
