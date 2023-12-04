#include <iostream>
#include <cmath>

using namespace std;

class Investment {
private:
    float principalAmount;
    float annualInterestRate;
    int numberOfYears;
    int compoundFrequency;

public:
    // Constructor
    Investment(float principal, float rate, int years, int frequency) {
        principalAmount = principal;
        annualInterestRate = rate / 100.0;  // Convert percentage to decimal
        numberOfYears = years;
        compoundFrequency = frequency;
    }

    // Method to calculate compound interest
    float calculateCompoundInterest() {
        float interest = 1 + (annualInterestRate / compoundFrequency);
        float totalAmount = principalAmount * pow(interest, compoundFrequency * numberOfYears);
        return totalAmount - principalAmount;
    }

    // Method to calculate total amount
    float calculateTotalAmount() {
        return principalAmount + calculateCompoundInterest();
    }

    // Method to display investment details
    void displayInvestmentDetails() {
        cout << "Principal Amount: " << principalAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate * 100 << "%" << endl;  // Convert back to percentage for display
        cout << "Number of Years: " << numberOfYears << endl;
        cout << "Compound Frequency: " << compoundFrequency << endl;
        cout << "Compound Interest: " << calculateCompoundInterest() << endl;
        cout << "Total Amount: " << calculateTotalAmount() << endl;
    }
};

int main() {
    cout << "Welcome to Airgead Banking Investment Calculator" << endl;

    float principal;
    float rate;
    int years;
    int frequency;

    cout << "Enter the principal amount: ";
    cin >> principal;

    cout << "Enter the annual interest rate (in percentage): ";
    cin >> rate;

    cout << "Enter the number of years: ";
    cin >> years;

    cout << "Enter the compound frequency (e.g., 12 for monthly): ";
    cin >> frequency;

    Investment investment(principal, rate, years, frequency);
    investment.displayInvestmentDetails();

    return 0;
}
