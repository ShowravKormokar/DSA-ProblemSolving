// Leetcode problem 2043 -> Simple Bank System
#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    vector<long long> balance;

public:
    // Constructor
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 < 1 || account1 > balance.size() ||
            account2 < 1 || account2 > balance.size())
            return false; // invalid account

        if (balance[account1 - 1] < money)
            return false; // insufficient balance

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > balance.size())
            return false;
        if (balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account < 1 || account > balance.size())
            return false;

        balance[account - 1] += money;
        return true;
    }
};

// Example Run
int main()
{
    vector<long long> bal = {10, 100, 20, 50, 30};
    Bank bank(bal);

    cout << boolalpha;
    cout << bank.withdraw(3, 10) << endl;    // true
    cout << bank.transfer(5, 1, 20) << endl; // true
    cout << bank.deposit(5, 20) << endl;     // true
    cout << bank.transfer(3, 4, 15) << endl; // true
    cout << bank.withdraw(10, 50) << endl;   // false
}
