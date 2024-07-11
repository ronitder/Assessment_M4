#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a food item
class FoodItem {
public:
    string name;
    double price;

    FoodItem(string name, double price) : name(name), price(price) {}
};

// Class to represent the food ordering system
class FoodOrderingSystem {
private:
    vector<FoodItem> menu;
    string customerName;
    double totalBill;

    void displayMenu() {
        cout << "Menu:\n";
        for (int i = 0; i < menu.size(); ++i) {
            cout << i + 1 << ". " << menu[i].name << " - $" << menu[i].price << endl;
        }
    }

    void takeOrder() {
        int choice, quantity;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice < 1 || choice > menu.size()) {
            cout << "Invalid choice! Please try again.\n";
            return;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity < 1) {
            cout << "Invalid quantity! Please try again.\n";
            return;
        }

        totalBill += menu[choice - 1].price * quantity;
        cout << "Item added to your bill.\n";
    }

    void generateBill() {
        cout << "Total Bill: $" << totalBill << endl;
    }

public:
    FoodOrderingSystem() : totalBill(0.0) {
        // Initialize menu with some items
        menu.push_back(FoodItem("Burger", 5.99));
        menu.push_back(FoodItem("Pizza", 8.99));
        menu.push_back(FoodItem("sandwich", 6.99));
        menu.push_back(FoodItem("rolls", 4.99));
    }

    void run() {
        cout << "Enter your name: ";
        getline(cin, customerName);

        char continueOrdering;
        do {
            displayMenu();
            takeOrder();
            cout << "Do you want to continue ordering? (y/n): ";
            cin >> continueOrdering;
            cin.ignore();
        } while (continueOrdering == 'y' || continueOrdering == 'Y');

        generateBill();
    }
};

int main() {
    FoodOrderingSystem system;
    system.run();
    return 0;
}
