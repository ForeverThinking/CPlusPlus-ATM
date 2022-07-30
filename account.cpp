#include "account.hpp"

#include <fstream>
#include <string>

struct account_data {
  std::string name;
  int account_value;
};

/*
    Method to retrieve account struct data from file
*/
account_data* retrieve_data(std::string& file_name) {
  std::ifstream file(file_name, std::ios::in);

  if (file) {
    account_data* data = new account_data;
    std::string title;
    file >> title >> data->name >> title >> title >> data->account_value;
    file.close();
    return data;
  } else {
    std::cout << "ERROR: File was not found or is not able to open."
              << std::endl;
    std::cout << std::endl;
    account_data* data = nullptr;
    return data;
  }
};

/*
    Method to save account struct data to file
*/
void save_data(account_data* data, std::string& file_name) {
  std::ofstream file(file_name, std::ios::out);

  if (file) {
    file << "Name: " << data->name << '\n';
    file << "Account Value: " << data->account_value << '\n';
    file << std::endl;
    file.close();
  } else {
    std::cout << "Failed to open " << file_name << std::endl;
    std::cout << std::endl;
  }
};

/*
    Method to create new accound file
*/
void Account::create(std::string& file_name) {
  std::ofstream file(file_name);
  file << "Name: " + file_name << std::endl;
  file << "Account Value: " << std::to_string(0) << std::endl;

  file.close();

  std::cout << "Account created" << std::endl;
  std::cout << std::endl;
}

/*
    Method to view contents of account file
*/
void Account::view(std::string& file_name) {
  // Local variable
  account_data* data;

  data = retrieve_data(file_name);

  if (data != nullptr) {
    std::cout << "Name: " << data->name << '\n';
    std::cout << "Account Value: " << data->account_value << '\n';
    std::cout << std::endl;
  }

  delete data;
};

/*
    Method to withdraw an amount from account
*/
void Account::withdraw(std::string& file_name) {
  // Local variables
  account_data* user_data;
  double amount = 0.0;

  user_data = retrieve_data(file_name);

  if (user_data != nullptr) {
    std::cout << "Please enter the amount to withdraw: ";
    std::cin >> amount;
    std::cout << std::endl;

    user_data->account_value -= amount;

    save_data(user_data, file_name);

    std::cout << "You have withdrawn " << amount << std::endl;
    std::cout << "Your new account is " << user_data->account_value
              << std::endl;
    std::cout << std::endl;
  }

  delete user_data;
};

/*
    Method to deposit amount into account
*/
void Account::deposit(std::string& file_name) {
  // Local variables
  account_data* user_data;
  double amount = 0.0;

  user_data = retrieve_data(file_name);

  if (user_data != nullptr) {
    std::cout << "Please enter amount to deposit: ";
    std::cin >> amount;
    std::cout << std::endl;

    user_data->account_value += amount;

    save_data(user_data, file_name);

    std::cout << "You have deposited " << amount << std::endl;
    std::cout << "Your new account is " << user_data->account_value
              << std::endl;
    std::cout << std::endl;
  }

  delete user_data;
};
