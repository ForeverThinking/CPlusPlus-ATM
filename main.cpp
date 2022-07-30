#include "account.hpp"

std::string get_name() {
  std::string surname = "";
  std::string initial = "";

  std::cout << "Please enter your surname: ";
  std::cin >> surname;
  std::cout << std::endl;

  std::cout << "Please enter your first initial: ";
  std::cin >> initial;
  std::cout << std::endl;

  std::string file_name = surname + initial;

  return file_name;
};

int main(int argc, char** argv) {
  Account my_acc;
  std::string username;
  int choice = 0;

  std::cout << "Welcome to the virtual ATM\n";
  username = get_name();

  while (choice != 5) {
    std::cout << "Please select an option:\n";
    std::cout << "1. Create your account\n";
    std::cout << "2. View your account\n";
    std::cout << "3. Make a withdrawal\n";
    std::cout << "4. Make a deposit\n";
    std::cout << "5. Exit\n";
    std::cin >> choice;

    switch (choice) {
      case 1:
        my_acc.create(username);
        break;

      case 2:
        my_acc.view(username);
        break;

      case 3:
        my_acc.withdraw(username);
        break;

      case 4:
        my_acc.deposit(username);
        break;

      case 5:
        std::cout << "Exiting...\n";
        break;

      default:
        std::cout << "I'm sorry, I didn't understand that input.\n";
        break;
    }
  }

  return 0;
}
