#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    int transactionID;
    string description;
    double amount;
    string type; // "Income" or "Expense"
    string date;

    Transaction(int id, string desc, double amt, string typ, string dt)
        : transactionID(id), description(desc), amount(amt), type(typ), date(dt) {}

    void displayTransaction() {
        cout << "ID: " << transactionID << ", Description: " << description 
             << ", Amount: $" << amount << ", Type: " << type 
             << ", Date: " << date << endl;
    }
};

class FinancialAccount {
private:
    vector<Transaction> transactions;

public:
    void addTransaction(int id, string description, double amount, string type, string date) {
        Transaction newTransaction(id, description, amount, type, date);
        transactions.push_back(newTransaction);
    }

    void viewTransactions() {
        for (const auto& transaction : transactions) {
            transaction.displayTransaction();
        }
    }

    void generateReport() {
        double totalIncome = 0;
        double totalExpense = 0;
        for (const auto& transaction : transactions) {
            if (transaction.type == "Income") {
                totalIncome += transaction.amount;
            } else if (transaction.type == "Expense") {
                totalExpense += transaction.amount;
            }
        }
        double netBalance = totalIncome - totalExpense;
        cout << "\n--- Financial Report ---" << endl;
        cout << "Total Income: $" << totalIncome << endl;
        cout << "Total Expenses: $" << totalExpense << endl;
        cout << "Net Balance: $" << netBalance << endl;
    }

    void calculateProfitLoss() {
        double totalIncome = 0;
        double totalExpense = 0;
        for (const auto& transaction : transactions) {
            if (transaction.type == "Income") {
                totalIncome += transaction.amount;
            } else if (transaction.type == "Expense") {
                totalExpense += transaction.amount;
            }
        }
        double profitLoss = totalIncome - totalExpense;
        cout << "\n--- Profit and Loss Statement ---" << endl;
        if (profitLoss > 0) {
            cout << "Profit: $" << profitLoss << endl;
        } else if (profitLoss < 0) {
            cout << "Loss: $" << -profitLoss << endl;
        } else {
            cout << "Break-even (No profit, no loss)" << endl;
        }
    }
};

int main() {
    FinancialAccount account;
    int choice, id;
    string description, type, date;
    double amount;

    do {
        cout << "\n1. Add Transaction\n2. View Transactions\n3. Generate Report\n4. Calculate Profit/Loss\n5. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character after choice input

        switch (choice) {
        case 1:
            cout << "Enter transaction ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter description: ";
            getline(cin, description);
            cout << "Enter amount: $";
            cin >> amount;
            cin.ignore();
            cout << "Enter type (Income/Expense): ";
            getline(cin, type);
            cout << "Enter date (YYYY-MM-DD): ";
            getline(cin, date);
            account.addTransaction(id, description, amount, type, date);
            break;
        case 2:
            account.viewTransactions();
            break;
        case 3:
            account.generateReport();
            break;
        case 4:
            account.calculateProfitLoss();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
