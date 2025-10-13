//
// Name Vincent Leahy   
// Date 10/12/2025
// Bank Accounts Midterm Programming Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
using namespace std;


//Base Class BankAccount
class BankAccount 
{
protected:
    double balance;     //current balance 
    int numDeposits;    //number of deposists
    int numWithdrawals; //number of withdralws
    double annualInterestRate; //annual interest rates
    double monthlyServiceCharges; //monthly servie fees/penaltys 

public:
    //Constructor initializes all member variables
    BankAccount(double bal = 0.0, double rate = 0.0) 
    {
        balance = bal;
        annualInterestRate = rate;
        numDeposits = 0;
        numWithdrawals = 0;
        monthlyServiceCharges = 0.0;
    }

    //Adds money to the balance and increments deposit count
    virtual void deposit(double amount) 
    {
        balance += amount;
        numDeposits++;
    }

    //Subtracts money from the balance and increments withdrawal count
    virtual void withdraw(double amount) 
    {
        balance -= amount;
        numWithdrawals++;
    }

    //Calculates and applies monthly interest to the balance
    virtual void calcInt() 
    {
        double monthlyRate = annualInterestRate / 12;  //Convert to monthly rate
        double monthlyInterest = balance * monthlyRate; //Interest earned
        balance += monthlyInterest;                     //Add interest to balance
    }

    //Performs end-of-month processing
    virtual void monthlyProc() 
    {
        balance -= monthlyServiceCharges; //Deduct service charges
        calcInt();                        //Apply monthly interest

        //Reset monthly counters
        numDeposits = 0;
        numWithdrawals = 0;
        monthlyServiceCharges = 0.0;
    }

    //Getters (used for displaying account info)
    double getBalance() const 
    { return balance; }
    int getNumDeposits() const 
    { return numDeposits; }
    int getNumWithdrawals() const 
    { return numWithdrawals; }
    double getServiceCharges() const 
    { return monthlyServiceCharges; }
};


//Derived Class SavingsAccount (inherits from bank account, adds an active or inactive status based off the 25 minimum)
class SavingsAccount : public BankAccount 
{
private:
    bool status; //true = active, false = inactive

    //Updates the active/inactive status based on balance
    void updateStatus() 
    {
        status = (balance >= 25);
    }

public:
    //Constructor calls base constructor and sets status
    SavingsAccount(double bal = 0.0, double rate = 0.0)
        : BankAccount(bal, rate) 
    {
        status = (balance >= 25);
    }

    //Withdraw only if account is active
    void withdraw(double amount) override 
    {
        updateStatus();
        if (!status) 
        {
            cout << "Account inactive. Withdrawal denied.\n";
            return;
        }

        BankAccount::withdraw(amount);
        updateStatus(); //Recheck status after withdrawal
    }

    //Deposits always allowed (may reactivate account)
    void deposit(double amount) override 
    {
        BankAccount::deposit(amount);
        updateStatus(); //Check if deposit reactivates account
    }

    //Adds service charges for extra withdrawals and processes month
    void monthlyProc() override 
    {
        if (numWithdrawals > 4)
            monthlyServiceCharges += (numWithdrawals - 4); // $1 for each over 4
        BankAccount::monthlyProc(); //Run base class processing
        updateStatus();             //Update account activity status
    }
};


// Derived Class CheckingAccount (inherits fomr the BankAccount and adds a specific fee for overdrafts and monthly charges)
class CheckingAccount : public BankAccount 
{
public:
    //Constructor passes data to the base class
    CheckingAccount(double bal = 0.0, double rate = 0.0)
        : BankAccount(bal, rate) {}

    //Withdraw checks for overdraft and applies penalty if needed
    void withdraw(double amount) override 
    {
        if (balance - amount < 0) 
        {
            cout << "Insufficient funds. $15 service charge applied.\n";
            monthlyServiceCharges += 15.0; //Apply penalty
        } 
        else 

        {
            BankAccount::withdraw(amount); //Normal withdrawal
        }
    }

    //Adds monthly service fee and per-withdrawal charge
    void monthlyProc() override 
    {
        monthlyServiceCharges += 5.0 + (0.10 * numWithdrawals); //$5 + 10¢/withdrawal
        BankAccount::monthlyProc(); //Run base class processing
    }
};



//MAIN PROGRAM (Creates saving anbd checking account and allows users to make deposits/withdrawls, also displays a monthly summary for both accounts)
int main() 
{
    cout << fixed << setprecision(2); //Formatting money to two decimals

    double initBalance, rate;

    //Create Savings Account
    cout << "Enter initial balance for savings: $";
    cin >> initBalance;
    cout << "Enter annual interest rate (e.g. 0.05 for 5%): ";
    cin >> rate;
    SavingsAccount savings(initBalance, rate);

    //Create Checking Account
    cout << "\nEnter initial balance for checking: $";
    cin >> initBalance;
    cout << "Enter annual interest rate (e.g. 0.05 for 5%): ";
    cin >> rate;
    CheckingAccount checking(initBalance, rate);

    double depositAmt, withdrawAmt;

    //Savings transactions
    cout << "\nEnter amount to deposit to savings: $";
    cin >> depositAmt;
    savings.deposit(depositAmt);

    cout << "Enter amount to withdraw from savings: $";
    cin >> withdrawAmt;
    savings.withdraw(withdrawAmt);

    //Checking transactions
    cout << "\nEnter amount to deposit to checking: $";
    cin >> depositAmt;
    checking.deposit(depositAmt);

    cout << "Enter amount to withdraw from checking: $";
    cin >> withdrawAmt;
    checking.withdraw(withdrawAmt);

    //Process monthly updates for both accounts
    savings.monthlyProc();
    checking.monthlyProc();

    //Display results
    cout << "\n=== Savings Account Summary ===\n";
    cout << "Balance: $" << savings.getBalance() << endl;
    cout << "Deposits: " << savings.getNumDeposits() << endl;
    cout << "Withdrawals: " << savings.getNumWithdrawals() << endl;
    cout << "Service Charges: $" << savings.getServiceCharges() << endl;

    cout << "\n=== Checking Account Summary ===\n";
    cout << "Balance: $" << checking.getBalance() << endl;
    cout << "Deposits: " << checking.getNumDeposits() << endl;
    cout << "Withdrawals: " << checking.getNumWithdrawals() << endl;
    cout << "Service Charges: $" << checking.getServiceCharges() << endl;

    cout << "\nProgram complete.\n";

    return 0;
}

