#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
 public:
  void deposit(std::string&);
  void withdraw(std::string&);
  void view(std::string&);
  void create(std::string&);
};

#endif /* ACCOUNT_H */