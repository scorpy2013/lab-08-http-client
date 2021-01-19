// Copyright 2020 Your Name <your_email>

#include <Reference.hpp>
#include <utility>

Reference::Reference(std::string reference_)
    : reference(std::move(reference_)) {}
std::string Reference::get_url() { return reference; }

std::string Reference::get_host() {
  if (reference.find("http://") == 0) {
    reference = reference.substr(7);
  }
  std::string result;
  for (char i : reference) {
    if (i == ':') {
      break;
    }
    result += i;
  }
  return result;
}
std::string Reference::get_port() {
  if (reference.find("http://") == 0) reference = reference.substr(7);
  std::string result;
  unsigned i = 0;
  for (; i < reference.size(); ++i) {
    if (reference[i] == ':') {
      break;
    }
  }
  for (unsigned j = i + 1; j < reference.size(); ++i) {
    if (reference[i] == '/') {
      break;
    }
    result += reference[i];
  }

  return result;
}
std::string Reference::get_target() {
  if (reference.find("http://") == 0) reference = reference.substr(7);
  std::string result;
  unsigned i = 0;
  for (; i < reference.size(); ++i) {
    if (reference[i] == '/') break;
  }
  for (unsigned j = i; j < reference.size(); ++i) {
    result += reference[i];
  }

  return result;
}
