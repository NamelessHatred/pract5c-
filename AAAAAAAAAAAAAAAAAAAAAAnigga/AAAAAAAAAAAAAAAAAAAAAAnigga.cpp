#include <iostream>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accNumber, double initialBalance) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Сумма " << amount << " успешно зачислена на счёт." << std::endl;
        }
        else {
            std::cout << "Ошибка: вносимая сумма должна быть положительной." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << "Сумма " << amount << " успешно списана со счета." << std::endl;
            }
            else {
                std::cout << "Ошибка: недостаточно средств на счете." << std::endl;
            }
        }
        else {
            std::cout << "Ошибка: запрашиваемая сумма должна быть положительной." << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * interestRate * (1.0 / 12);
    }

    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if (amount > 0 && amount <= from.balance) {
            from.balance -= amount;
            to.balance += amount;
            std::cout << "Перевод на сумму " << amount << " успешно выполнен." << std::endl;
            return true;
        }
        else {
            std::cout << "Ошибка: недостаточно средств для перевода." << std::endl;
            return false;
        }
    }
};

int main() {
    BankAccount acc1(12345, 1000.0);
    BankAccount acc2(54321, 500.0);

    transfer(acc1, acc2, 300.0);

    std::cout << "Баланс acc1: " << acc1.getBalance() << std::endl;
    std::cout << "Баланс acc2: " << acc2.getBalance() << std::endl;

    return 0;
}