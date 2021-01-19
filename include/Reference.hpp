// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_REFERENCE_HPP_
#define INCLUDE_REFERENCE_HPP_
#include <string>

class Reference {
 public:
  explicit Reference(std::string reference_);
  std::string get_url();
  std::string get_host();
  std::string get_port();
  std::string get_target();

 private:
  std::string reference;
};

#endif  // INCLUDE_REFERENCE_HPP_
