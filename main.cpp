#include <iostream>
#include <string>
#include <iomanip>
#include <limits> 

using namespace std;

int main() {
    const int originalInventoryCount = 50;
    const double originalCashAmount = 200.0;

    // name
    string customerName;
    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    double runningSubtotal = 0.0;
    int totalQuantity = 0;
    string foodName = "";
    string sizeLabel = "";
    double unitPrice = 0.0;
    int quantity = 0;

    char itemChoice;
    char sizeChoice;

    while (true) {
 
        cout << "\nDrink              Small (S)   Medium (M)   Large (L)" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "A. Apple Juice     $2.50       $3.50        $4.50" << endl;
        cout << "B. Beer            $5.00       $7.00        $9.00" << endl;
        cout << "C. Coffee          $2.00       $2.75        $3.25" << endl;
        cout << "D. Lemonade        $2.25       $3.00        $3.75" << endl;
        cout << "E. Checkout" << endl;
        cout << "------------------------------------------------------" << endl;

        while (true) {
            cout << "\nSelect an item (A, B, C, D, E): ";
            cin >> itemChoice;

            if (itemChoice == 'A' || itemChoice == 'a' ||
                itemChoice == 'B' || itemChoice == 'b' ||
                itemChoice == 'C' || itemChoice == 'c' ||
                itemChoice == 'D' || itemChoice == 'd' ||
                itemChoice == 'E' || itemChoice == 'e') {
                break;
            }
            cout << "Invalid choice. Please enter A, B, C, D, or E." << endl;
        }

        if (itemChoice == 'E' || itemChoice == 'e') {
            break;
        }

        while (true) {
            cout << "Select a size (S, M, L): ";
            cin >> sizeChoice;

            if (sizeChoice == 's' || sizeChoice == 'S' ||
                sizeChoice == 'm' || sizeChoice == 'M' ||
                sizeChoice == 'l' || sizeChoice == 'L') {
                break;
            }
            cout << "Invalid size. Please enter S, M, or L." << endl;
        }

        if (itemChoice == 'A' || itemChoice == 'a') {
            foodName = "Apple Juice";
            if (sizeChoice == 's' || sizeChoice == 'S') {
                sizeLabel = "Small";
                unitPrice = 2.50;
            }
            else if (sizeChoice == 'm' || sizeChoice == 'M') {
                sizeLabel = "Medium";
                unitPrice = 3.50;
            }
            else if (sizeChoice == 'l' || sizeChoice == 'L') {
                sizeLabel = "Large";
                unitPrice = 4.50;
            }
        }
        else if (itemChoice == 'B' || itemChoice == 'b') {
            foodName = "Beer";
            if (sizeChoice == 's' || sizeChoice == 'S') {
                sizeLabel = "Small";
                unitPrice = 5.00;
            }
            else if (sizeChoice == 'm' || sizeChoice == 'M') {
                sizeLabel = "Medium";
                unitPrice = 7.00;
            }
            else if (sizeChoice == 'l' || sizeChoice == 'L') {
                sizeLabel = "Large";
                unitPrice = 9.00;
            }
        }
        else if (itemChoice == 'C' || itemChoice == 'c') {
            foodName = "Coffee";
            if (sizeChoice == 's' || sizeChoice == 'S') {
                sizeLabel = "Small";
                unitPrice = 2.00;
            }
            else if (sizeChoice == 'm' || sizeChoice == 'M') {
                sizeLabel = "Medium";
                unitPrice = 2.75;
            }
            else if (sizeChoice == 'l' || sizeChoice == 'L') {
                sizeLabel = "Large";
                unitPrice = 3.25;
            }
        }
        else if (itemChoice == 'D' || itemChoice == 'd') {
            foodName = "Lemonade";
            if (sizeChoice == 's' || sizeChoice == 'S') {
                sizeLabel = "Small";
                unitPrice = 2.25;
            }
            else if (sizeChoice == 'm' || sizeChoice == 'M') {
                sizeLabel = "Medium";
                unitPrice = 3.00;
            }
            else if (sizeChoice == 'l' || sizeChoice == 'L') {
                sizeLabel = "Large";
                unitPrice = 3.75;
            }
        }

        while (true) {
            cout << "Enter Quantity: ";
            cin >> quantity;

            if (!cin.fail() && quantity > 0) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid quantity. Please enter a positive integer." << endl;
        }

        double itemSubtotal = quantity * unitPrice;
        runningSubtotal += itemSubtotal;
        totalQuantity += quantity;

        cout << "Successfully added " << quantity << " " << sizeLabel << " " << foodName << "(s) to your order!\n";
    }

    if (totalQuantity == 0) {
        cout << "\nNo items selected. Exiting program." << endl;
        return 0;
    }

    char member;
    while (true) {
        cout << "Member (Y/N): ";
        cin >> member;
        if (member == 'y' || member == 'Y' || member == 'n' || member == 'N') {
            break;
        }
        cout << "Invalid input. Please enter y or n." << endl;
    }

    double subtotal = runningSubtotal;

    if (member == 'y' || member == 'Y') {
        cout << "\nMember Discount (10%) applied!" << endl;
        subtotal = subtotal * 0.90;
    }
    else {
        cout << "\nNot a member." << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\n--- Order Summary for " << customerName << " ---" << endl;
    cout << "Total Quantity Ordered: " << totalQuantity << endl;
    cout << "Subtotal:               $" << subtotal << endl;

    double arStateTax = subtotal * 0.065;
    double faulknerTax = subtotal * 0.005;
    double conwayTax = subtotal * 0.02125;
    double totalTax = arStateTax + faulknerTax + conwayTax;

    cout << "\n=== Tax Breakdown Table ===" << endl;
    cout << left << setw(25) << "Tax Name" << setw(10) << "Rate" << setw(10) << "Amount" << endl;
    cout << "=============================================" << endl;
    cout << left << setw(25) << "Arkansas State Tax" << setw(10) << "6.500%" << "$" << setw(9) << arStateTax << endl;
    cout << left << setw(25) << "Faulkner County Tax" << setw(10) << "0.500%" << "$" << setw(9) << faulknerTax << endl;
    cout << left << setw(25) << "Conway Municipal Tax" << setw(10) << "2.125%" << "$" << setw(9) << conwayTax << endl;
    cout << "=============================================" << endl;
    cout << left << setw(25) << "Total Tax" << setw(10) << "9.125%" << "$" << setw(9) << totalTax << endl;

    double tip15 = subtotal * 0.15;
    double tip20 = subtotal * 0.20;
    double tip25 = subtotal * 0.25;

    cout << "\nTip Selection          Amount" << endl;
    cout << "=============================" << endl;
    cout << "A. 15%                 $" << tip15 << endl;
    cout << "B. 20%                 $" << tip20 << endl;
    cout << "C. 25%                 $" << tip25 << endl;
    cout << "D. Other Amount" << endl;

    char tipChoice;
    cout << "\nWhat tip do you choose? ";
    cin >> tipChoice;

    double tipAmount = 0.0;
    if (tipChoice == 'A' || tipChoice == 'a') {
        tipAmount = tip15;
    }
    else if (tipChoice == 'B' || tipChoice == 'b') {
        tipAmount = tip20;
    }
    else if (tipChoice == 'C' || tipChoice == 'c') {
        tipAmount = tip25;
    }
    else if (tipChoice == 'D' || tipChoice == 'd') {
        cout << "How much would you like to tip? $";
        cin >> tipAmount;
    }
    else {
        cout << "Invalid choice. Tip set to $0.00." << endl;
        tipAmount = 0.0;
    }

    double finalTotal = subtotal + totalTax + tipAmount;

    cout << "\n==========================================" << endl;
    cout << left << setw(25) << "Customer:" << right << setw(11) << customerName << endl;
    cout << left << setw(25) << "Subtotal:" << "$" << right << setw(10) << subtotal << endl;
    cout << left << setw(25) << "Sales Tax:" << "$" << right << setw(10) << totalTax << endl;
    cout << left << setw(25) << "Tip Amount:" << "$" << right << setw(10) << tipAmount << endl;
    cout << "==========================================" << endl;
    cout << left << setw(25) << "TOTAL DUE:" << "$" << right << setw(10) << finalTotal << endl;
    cout << "==========================================" << endl;

    int currentInventory = originalInventoryCount - totalQuantity;
    double currentCashAmount = originalCashAmount + finalTotal;

    cout << "\n=== Inventory Audit Table ===" << endl;
    cout << left << setw(15) << "Item" << setw(16) << "Initial Count" << setw(22) << "After Transaction" << endl;
    cout << left << setw(15) << "All Drinks" << setw(16) << originalInventoryCount << setw(22) << currentInventory << endl;
    cout << left << setw(15) << "Cash ($)" << setw(16) << originalCashAmount << setw(22) << currentCashAmount << endl;

    return 0;
}
