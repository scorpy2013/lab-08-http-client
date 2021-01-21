// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_REFERENCE_HPP_
#define INCLUDE_REFERENCE_HPP_
#include <string>

class Reference {
 public:
  explicit Reference(std::string reference);
  std::string GetUrl();
  std::string GetHost();
  std::string GetPort();
  std::string GetTarget();

 private:
  std::string reference_;
};

#endif  // INCLUDE_REFERENCE_HPP_
