//G21328035  Sajana pamudita

#include <iostream>
using namespace std;

// Struct for order details
struct Order {
    string potatoSize;  // Potato size (S, M, L)
    string toppings;    // To store toppings
    string extras;      // To store extras
    float totalCost;    // Total cost for recent orders
};

// Define constants for size prices
const float smallSizePrice = 5.00; // Price for small baked potato
const float mediumSizePrice = 8.50;
const float largeSizePrice = 10.25;


// Define constants for topping prices
const float cheesePrice= 1.00;  // Price for cheese topping
const float butterPrice = 0.40;
const float garilButterPrice = 0.50;
const float beansPrice = 0.75;
const float currySaucePrice= 1.20;
const float mushroomePrice = 0.80;
const float onionPrice = 0.40;
const float extrassCheesePrice = 1.50;

// Define constants for extra item prices
const float saladBoxPrice = 1.50;
const float hotDogPrice= 4.00;
const float fizzyDrinkPrice= 1.20;
const float waterPrice = 0.80;
const float teaPrice = 1.00;
const float coffeePrice = 1.20;

// Function Prototypes
void mainMenu(float &credits, Order recentOrders[], int &orderIndex, int &orderCount); // Displays the main menu
void addCredits(float &credits);  // Allows the user to add credits
void addCredits2(float &credits, float &value, Order recentOrders[], int &orderIndex, int &orderCount, Order &currentOrder);
void newOrder(float &credits, Order recentOrders[], int &orderIndex, int &orderCount);
void toppings(float &credits, float &value, Order &currentOrder);// Handles Size selection
void moreToppings(float &credits, float &value, Order &currentOrder);// Allows multiple toppings
void finalBill(float &credits, float &value, Order recentOrders[], int &orderIndex, int &orderCount, Order &currentOrder);// Displays the finalBill
void extraMenu(float &credits, float &value, Order &currentOrder);// Displays the extras menu
void displayRecentOrders(Order recentOrders[], int orderCount);// Displays the recentOrders
char validYN(char &yesNo);
void exitProgram();

// Main Function
int main() {
    float credits = 0.00;               // Initialize user credits
    Order recentOrders[10];             // Array to store up to 10 recent orders
    int orderIndex = 0;                 // Current index in the recentOrders array
    int orderCount = 0;                 // Total number of orders placed
    mainMenu(credits, recentOrders, orderIndex, orderCount); // Display the main menu
    return 0;
}

// Displays the main menu
void mainMenu(float &credits, Order recentOrders[], int &orderIndex, int &orderCount) {
    int choice;

    cout << "===============================" << endl;
    cout << "Hot Potato" << endl;
    cout << "===============================" << endl;
    cout << "MAIN MENU" << endl;
    cout << "1. Add Credits (current credits = " << credits << " credits)" << endl;
    cout << "2. New Order" << endl;
    cout << "3. Recent Orders" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";


while(true) {  // Loop until a valid choice is entered
        cin >> choice;  // Take input for size choice

        if (cin.fail()) {  // Check if the input is invalid (non-numeric)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number: ";

        }
        else if (choice >= 1 && choice <= 4) {  // Check if the choice is valid (1, 2, 3 or 4)
            break;  // Exit the loop if valid input is entered
        }
        else {  // If the choice is out of range (1-4)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number (1-4): ";
        }
    }

    switch (choice) {
        case 1:
            addCredits(credits);
            mainMenu(credits, recentOrders, orderIndex, orderCount);
            break;
        case 2:
            newOrder(credits, recentOrders, orderIndex, orderCount);
            mainMenu(credits, recentOrders, orderIndex, orderCount);
            break;
        case 3:
            displayRecentOrders(recentOrders, orderCount);
            mainMenu(credits, recentOrders, orderIndex, orderCount);
            break;
        case 4:
            exitProgram();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            mainMenu(credits, recentOrders, orderIndex, orderCount);
            break;
    }
}

// Adds credits to the user's balance
void addCredits(float &credits) {
    float additionalCredits;
    cout << "Enter the amount of credits to add: ";
    cin >> additionalCredits;

    if (additionalCredits <= 0) {
        cout << "Invalid amount. Please enter a positive value." << endl;
        addCredits(credits);
        return;
    }

    credits += additionalCredits;
    cout << "Credits successfully added! Current balance: " << credits << " credits." << endl;
}

// Starts a new order and calculates the total cost
void newOrder(float &credits, Order recentOrders[], int &orderIndex, int &orderCount) {
    float value = 0.0;
    Order currentOrder;
    toppings(credits, value, currentOrder);

    char yesNo;
    cout << "Would you like to add another extra? (Y/N): ";
    validYN(yesNo);

    if (yesNo == 'Y' || yesNo == 'y') {
        extraMenu(credits, value, currentOrder);
    }

    finalBill(credits, value, recentOrders, orderIndex, orderCount, currentOrder);
}

// Handles selection of baked potato size
void toppings(float &credits, float &value, Order &currentOrder) {
    int choice;
     cout << "===============================" << endl;
    cout << "\nSelect a size for your 🥔️baked potato:\n" << endl;
     cout << "===============================" << endl;
    cout << "1. Small           (" << smallSizePrice << " credits)" << endl;
    cout << "2. Medium          (" << mediumSizePrice << " credits)" << endl;
    cout << "3. Large           (" << largeSizePrice << " credits)" << endl;
    cout << "Enter your choice: ";


   while(true) {  // Loop until a valid choice is entered
        cin >> choice;  // Take input for size choice

        if (cin.fail()) {  // Check if the input is invalid (non-numeric)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number: ";

        }
        else if (choice >= 1 && choice <= 3) {  // Check if the choice is valid (1, 2, 3 or 4)
            break;  // Exit the loop if valid input is entered
        }
        else {  // If the choice is out of range (1-4)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number (1-3): ";
        }
    }

   if (choice == 1) {
        value += smallSizePrice;
        cout<<"\n You have selected a small baked potato. \n " ;
        currentOrder.potatoSize += "Small, ";
    } else if (choice == 2) {
        value += mediumSizePrice;
        cout<<"You have selected a medium baked potato. \n " ;
        currentOrder.potatoSize += "Medium, ";
    } else if (choice == 3) {
        value += largeSizePrice;
        cout<<"You have selected a large baked potato. \n " ;
        currentOrder.potatoSize += "Large, ";
    } else {
        cout << "Invalid choice. Please select again. \n" ;
        toppings(credits, value,currentOrder);
        return;
    }

    moreToppings(credits, value, currentOrder);
}

// Allows the user to add multiple toppings
void moreToppings(float &credits, float &value, Order &currentOrder) {
    int toppingChoice;
    char yesNo;

    cout << "===============================" << endl;
    cout << "\nSelect a topping:\n" << endl;
    cout << "===============================" << endl;
    cout << "1.🧀  Cheese                     (" << cheesePrice << " credits)" << endl;
    cout << "2.🧈  Butter                     (" << butterPrice << " credits)" << endl;
    cout << "3.🧄️🧈️Garlic Butter              (" << garilButterPrice << " credits)" << endl;
    cout << "4.🫛  Beans                      (" << beansPrice  << " credits)" << endl;
    cout << "5.🥘  Curry Sauce                (" << currySaucePrice << " credits)" << endl;
    cout << "6.🍄  Mushrooms                  (" << mushroomePrice << " credits)" << endl;
    cout << "7.🧅  Onions                     (" << onionPrice << " credits)" << endl;
    cout << "8.🧀🧀Extra Special Cheese       (" << extrassCheesePrice<< " credits)" << endl;
    cout << "Enter your choice: ";



    while(true) {  // Loop until a valid choice is entered
        cin >> toppingChoice;  // Take input for size choice

        if (cin.fail()) {  // Check if the input is invalid (non-numeric)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number: ";

        }
        else if (toppingChoice >= 1 && toppingChoice <= 8) {  // Check if the choice is valid (1, 2, 3 or 4)
            break;  // Exit the loop if valid input is entered
        }
        else {  // If the choice is out of range (1-4)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
           cin.clear();
           cin.ignore(100,'\n');
            cout << "Please Enter a Number (1-8): ";
        }
    }

     switch (toppingChoice) {
    case 1: value += cheesePrice; cout << "You have added 🧀 Cheese to your baked potato. \n " << endl;
    currentOrder.toppings += "Cheese, "; break;
        cout<<endl;
    case 2: value += butterPrice; cout << "You have added 🧈  Butter to your baked potato. \n " << endl;
    currentOrder.toppings += "Butter, "; break;
    case 3: value += garilButterPrice; cout << "You have added 🧄️🧈️ Garlic Butter to your baked potato. \n " << endl;
    currentOrder.toppings += "Garlic Butter, "; break;
    case 4: value += beansPrice; cout << "You have added 🫛 Beans to your baked potato. \n " << endl;
    currentOrder.toppings += "Beans, "; break;
    case 5: value += currySaucePrice; cout << "You have added 🥘   Curry Sauce to your baked potato. \n " << endl;
    currentOrder.toppings += "Curry Sauce, "; break;
    case 6: value += mushroomePrice; cout << " You have added 🍄  Mushrooms  to your baked potato. \n " << endl;
    currentOrder.toppings += "Mushrooms, "; break;
    case 7: value += onionPrice; cout << "Onions You have added 🧅Onions  to your baked potato. \n " << endl;
    currentOrder.toppings += "Onions, "; break;
    case 8: value += extrassCheesePrice; cout << "You have added 🧀🧀Extra Special Cheese  to your baked potato.\n " << endl;
    currentOrder.toppings += "Extra Special Cheese , "; break;
        default: cout << "Invalid choice. No topping added." << endl; break;
    }

    cout << "Would you like to add another topping? (Y/N): ";
    validYN(yesNo);

    if (yesNo == 'Y' || yesNo == 'y') {
        moreToppings(credits, value, currentOrder);
    }
}

// Displays the extras menu
void extraMenu(float &credits, float &value, Order &currentOrder) {

    int extraChoice;
    char yesNo;

    cout << "===============================" << endl;
    cout << "\nSelect an extra:\n" << endl;
    cout << "===============================" << endl;
    // Display options for extras with their prices
    cout << "1.🥗 Salad Box                       (" << saladBoxPrice << " credits)" << endl;
    cout << "2.🌭 Hot Dog                         (" << hotDogPrice << " credits)" << endl;
    cout << "3.🥤 Can of Fizzy Drink              (" << fizzyDrinkPrice << " credits)" << endl;
    cout << "4.🍶 Bottle of Water                 (" << waterPrice << " credits)" << endl;
    cout << "5.🍵 Tea                             (" << teaPrice << " credits)" << endl;
    cout << "6.☕ Coffee                          (" <<  coffeePrice << " credits)" << endl;
    cout << "Enter your choice: ";

        while(true) {  // Loop until a valid choice is entered
        cin >> extraChoice;  // Take input for size choice

        if (cin.fail()) {  // Check if the input is invalid (non-numeric)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Please Enter a Number: ";

        }
        else if (extraChoice >= 1 && extraChoice<= 6) {  // Check if the choice is valid (1, 2, 3 or 4)
            break;  // Exit the loop if valid input is entered
        }
        else {  // If the choice is out of range (1-4)
            cout << endl;
            cout << "Invalid Choice! Please try again." << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "Please Enter a Number (1-6): ";
        }
    }


    switch (extraChoice) {
        case 1: value += saladBoxPrice; cout << "You have added 🥗  Salad Box to your baked potato. \n" << endl;
         currentOrder.extras += "Salad Box, "; break;
        case 2: value += hotDogPrice  ; cout << "You have added 🌭 Hot Dog  to your baked potato. \n" << endl;
         currentOrder.extras += "Hot Dog, "; break;
        case 3: value += fizzyDrinkPrice; cout << "You have added 🥤 Can of Fizzy Drink  to your baked potato. \n" << endl;
        currentOrder.extras += "Can of Fizzy Drink, "; break;
        case 4: value += waterPrice; cout << "You have added 🍶 Bottle of Water  to your baked potato. \n " << endl;
        currentOrder.extras += " Bottle of Water, "; break;
        case 5: value += teaPrice; cout << "You have added 🍵 Tea to your baked potato. \n " << endl;
        currentOrder.extras += " Tea , "; break;
        case 6: value +=  coffeePrice; cout << "You have added .☕ Coffee  to your baked potato. \n" << endl;
        currentOrder.extras += " Coffee , "; break;
        default: cout << "Invalid choice. No extra added." << endl; break;
    }
    cout << "Would you like to add another extra? (Y/N): ";
    validYN(yesNo);

    if (yesNo == 'Y' || yesNo == 'y') {
        extraMenu(credits, value, currentOrder);
    }
}

void finalBill(float &credits, float &value, Order recentOrders[], int &orderIndex, int &orderCount, Order &currentOrder) {
    // Displaying the total order cost
    cout << "===============================" << endl;
    cout << "\nTotal order cost: " << value << " credits" << endl;

    // Check if the user has enough credits to complete the order
    if (credits >= value) {
        // Deduct the cost from the user's credits
        credits -= value;
        // Store the current order's total cost
        currentOrder.totalCost = value;

        // Add the current order to the recent orders array
        recentOrders[orderIndex] = currentOrder;
        orderIndex++;

        // Reset orderIndex if it exceeds the array size (10)
        if (orderIndex > 10) {
            orderIndex = 0;
        }

        // If 10 orders have been completed, reset orderCount
        if (orderCount == 10) {
            orderCount = 0;
        } else {
            // Increment the order count
            orderCount += 1;
        }

        // Display message confirming successful order completion
        cout << "Order completed! Remaining credits: " << credits << " credits.\n";
    } else {
        // If credits are insufficient, inform the user
        cout << "Insufficient credits! Please add more credits to complete your order.\n";
        cout << "===============================" << endl;

        // Prompt user to add more credits
        addCredits2(credits, value, recentOrders, orderIndex, orderCount, currentOrder);
    }

    // Ask the user if they want to place another order
    char yesNo;
    cout << "\nWould you like to place another order? (Y/N): ";
    validYN(yesNo);

    // If the user wants to place another order, initiate a new order
    if (yesNo == 'Y' || yesNo == 'y') {
        newOrder(credits, recentOrders, orderIndex, orderCount);
    } else {
        // If the user does not want to place another order, display a thank-you message and return to the main menu
        cout << "Thank you for using Hot Potato! Goodbye! 🤗️" << endl;
        cout << endl;
        mainMenu(credits, recentOrders, orderIndex, orderCount);
    }
}


// Adds credits when insufficient credits are available
void addCredits2(float &credits, float &value, Order recentOrders[], int &orderIndex, int &orderCount, Order &currentOrder) {
    float newCredits;
    cout << "\nHow many credits would you like to add? ";
    cin >> newCredits;

    credits += newCredits;
    finalBill(credits, value, recentOrders, orderIndex, orderCount, currentOrder);
}


// Displays recent orders
void displayRecentOrders(Order recentOrders[], int orderCount) {
    cout << "\nRecent Orders:\n" << endl;
    if (orderCount == 0) {
        cout << "No recent orders found." << endl;
        return;
    }

    for (int i = 0; i < orderCount; i++) {
        cout << "Order #" << i + 1 << ":\n";
        cout << "  Potato Size: " << recentOrders[i].potatoSize << endl;
        cout << "  Toppings: " << recentOrders[i].toppings << endl;
        cout << "  Extras: " << recentOrders[i].extras << endl;
        cout << "  Total Cost: " << recentOrders[i].totalCost << " credits\n" << endl;
    }
}

// Function to validate Yes/No user input
char validYN(char &yesNo) {
    while (true) {  // Loop until valid input is entered
        cin >> yesNo;
        if (yesNo == 'Y' || yesNo == 'y' || yesNo == 'N' || yesNo == 'n') {  // Check for valid input
            return yesNo;
        } else {
            cout << "Invalid input. Please enter 'Y' or 'N': ";

        }
    }
}

// Exits the program
void exitProgram() {
    cout << "\nExiting the program..." << endl;
    cout << "Thank you for using Hot Potato! Goodbye! 🤗" << endl;
    exit(0); // Terminate the program
}
