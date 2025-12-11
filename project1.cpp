
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;
class Transaction
{
protected:
    float amount;
    string date, category;

public:
    Transaction() : amount(0) {}
    void setDetails(float amt, string dt, string cat)
    {
        amount = amt;
        date = dt;
        category = cat;
    }
    float getAmount() const { return amount; }
    string getCategory() const { return category; }
    string getDate() const { return date; }
};
class Income : public Transaction
{
    string source;

public:
    void recordIncome(float amt, string dt, string cat, string src)
    {
        setDetails(amt, dt, cat);
        source = src;
    }
    friend class SmartAnalyzer;
};
class Expense : public Transaction
{
    string type; // Fixed / Variable
public:
    void recordExpense(float amt, string dt, string cat, string tp)
    {
        setDetails(amt, dt, cat);
        type = tp;
    }
    friend class SmartAnalyzer;
};
class BudgetPlanner
{
    float totalIncome;
    float totalExpense;
    float monthlyLimit;

public:
    BudgetPlanner() : totalIncome(0), totalExpense(0), monthlyLimit(0) {}
    void setBudget(float income, float expense, float limit)
    {
        totalIncome = income;
        totalExpense = expense;
        monthlyLimit = limit;
    }
    void calculateBudget()
    {
        cout << "\n--- Budget Report ---\n";
        cout << "Total Income: Rs." << totalIncome << endl;
        cout << "Total Expense: Rs." << totalExpense << endl;
        cout << "Monthly Limit: Rs." << monthlyLimit << endl;
        if (totalExpense > monthlyLimit)
        {
            cout << "Warning: Over Budget by Rs." << totalExpense - monthlyLimit << endl;
        }
        else
        {
            cout << "You are within budget. Savings: Rs." << monthlyLimit - totalExpense << endl;
        }
    }
    float operator-(const BudgetPlanner &b)
    {
        return b.totalIncome - b.totalExpense;
    }
};
class FileManager
{
public:
    void saveToFile(const vector<Expense> &expenses, const vector<Income> &
                                                         incomes)
    {
        ofstream file("data.txt");
        for (const auto &e : expenses)
            file << "E " << e.getAmount() << " " << e.getDate() << " " << e.getCategory() << "\n";

        for (const auto &i : incomes)
            file << "I " << i.getAmount() << " " << i.getDate() << " " << i.getCategory() << "\n";
        file.close();
    }
};
class SmartAnalyzer
{
public:
    void analyzeTrends(const vector<Expense> &expenses)
    {
        map<string, float> categorySpend;
        for (const auto &e : expenses)
            categorySpend[e.getCategory()] += e.getAmount();
        cout << "\n--- Smart Suggestions ---\n";
        for (auto &[cat, amt] : categorySpend)
        {
            if (amt > 5000) // AI logic can be more advanced later
                cout << "High spend on " << cat << ": Rs." << amt << ". Consider reducing it.\n";
        }
    }
};
int main()
{
    vector<Expense> expenses;
    vector<Income> incomes;
    BudgetPlanner planner;
    FileManager fileMgr;
    SmartAnalyzer analyzer;
    int choice;
    while (true)
    {
        cout << "\n--- Personal Expense Tracker ---\n";
        cout << "1. Add Income\n2. Add Expense\n3. Plan Budget\n4. SmartSuggestions\n5.Exit\nEnter choice : ";
        cin >>choice;
        if (choice == 1)
        {
            float amt;
            string dt, cat, src;
            cout << "Amount: ";
            cin >> amt;
            cout << "Date (YYYY-MM-DD): ";
            cin >> dt;
            cout << "Category: ";
            cin >> cat;
            cout << "Source: ";
            cin >> src;
            Income temp;
            temp.recordIncome(amt, dt, cat, src);
            incomes.push_back(temp);
        }
        else if (choice == 2)
        {
            float amt;
            string dt, cat, tp;
            cout << "Amount: ";
            cin >> amt;
            cout << "Date (YYYY-MM-DD): ";
            cin >> dt;
            cout << "Category: ";
            cin >> cat;
            cout << "Type (Fixed/Variable): ";
            cin >> tp;
            Expense temp;
            temp.recordExpense(amt, dt, cat, tp);
            expenses.push_back(temp);
        }
        else if (choice == 3)
        {
            float income = 0, expense = 0, limit;
            for (const auto &i : incomes)
                income += i.getAmount();
            for (const auto &e : expenses)
                expense += e.getAmount();
            cout << "Enter Monthly Limit: ";
            cin >> limit;
            planner.setBudget(income, expense, limit);
            planner.calculateBudget();
        }
        else if (choice == 4)
        {
            analyzer.analyzeTrends(expenses);
        }
        else if (choice == 5)
        {
            fileMgr.saveToFile(expenses, incomes);
            cout << "Data saved. Exiting.\n";
            break;
        }
        else
        {
            cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}
