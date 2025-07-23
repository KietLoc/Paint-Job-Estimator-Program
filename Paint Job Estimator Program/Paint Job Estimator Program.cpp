#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Constants
const double SQFT_PER_GALLON = 110.0;
const double LABOR_PER_SQFT = 8.0 / 110.0; // hours per square foot
const double LABOR_RATE = 25.0;

// Function prototypes

// Prompts the user to enter the number of rooms (>= 1). Returns the valid count.
int getRooms();

// Prompts for square feet of room #roomNumber (>= 0). Returns square footage.
double getSqFt(int roomNumber);

// Prompts for paint price per gallon (>= $10.00). Returns valid price.
double getPricePerGallon();

// Calculates number of gallons needed (ceiling of sqft / 110). Returns integer gallons.
int gallonsForRoom(double sqft);

// Calculates labor hours needed (sqft * LABOR_PER_SQFT). Returns hours.
double laborHoursForRoom(double sqft);

// Displays the full estimate: #rooms, gallons, labor, paint cost, labor cost, total.
void displayEstimate(int totalRooms, int totalGallons,
    double totalLaborHours, double paintCost,
    double laborCost);

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

    // Setup formatting for money and hours
    cout << fixed << setprecision(2);
    displayEstimate(totalRooms, totalGallons, totalLaborHours,
        totalPaintCost, totalLaborCost);

    return 0;
}

// Function definitions

int getRooms() {
    int rooms;
    do {
        cout << "Enter number of rooms to be painted (>= 1): ";
        cin >> rooms;
        if (rooms < 1)
            cout << "  Error: must enter at least 1 room.\n";
    } while (rooms < 1);
    return rooms;
}

double getSqFt(int roomNumber) {
    double sqft;
    do {
        cout << "Enter square feet for room #" << roomNumber << " (>= 0): ";
        cin >> sqft;
        if (sqft < 0)
            cout << "  Error: square feet cannot be negative.\n";
    } while (sqft < 0);
    return sqft;
}

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

int gallonsForRoom(double sqft) {
    return static_cast<int>(ceil(sqft / SQFT_PER_GALLON));
}

double laborHoursForRoom(double sqft) {
    return sqft * LABOR_PER_SQFT;
}

void displayEstimate(int totalRooms, int totalGallons,
    double totalLaborHours, double paintCost,
    double laborCost)
{
    cout << "\nEstimate for Painting " << totalRooms << " room"
        << (totalRooms > 1 ? "s" : "") << ":\n";
    cout << "Gallons of paint to purchase: " << totalGallons << "\n";
    cout << "Number of hours required to paint: " << totalLaborHours << "\n";
    cout << "Cost of Paint: $" << paintCost << "\n";
    cout << "Cost of Labor: $" << laborCost << "\n";
    cout << "Total cost for job: $" << (paintCost + laborCost) << "\n";
}
