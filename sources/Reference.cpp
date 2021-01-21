// Copyright 2020 Your Name <your_email>

#include <Reference.hpp>
#include <utility>

Reference::Reference(std::string reference)
    : reference_(std::move(reference)) {}
std::string Reference::GetUrl() { return reference_; }

std::string Reference::GetHost() {
  if (reference_.find("http://") == 0) {
    reference_ = reference_.substr(7);
  }
  std::string result;
  for (char it : reference_) {
    if (it == ':') {
      break;
    }
    result += it;
  }
  return result;
}
std::string Reference::GetPort() {
  if (reference_.find("http://") == 0) reference_ = reference_.substr(7);
  std::string result;
  unsigned i = 0;
  for (; i < reference_.size(); ++i) {
    if (reference_[i] == ':') {
      break;
    }
  }
  for (unsigned j = i + 1; j < reference_.size(); ++j) {
    if (reference_[j] == '/') {
      break;
    }
    result += reference_[j];
  }

  return result;
}
std::string Reference::GetTarget() {
  if (reference_.find("http://") == 0) reference_ = reference_.substr(7);
  std::string result;
  unsigned i = 0;
  for (; i < reference_.size(); ++i) {
    if (reference_[i] == '/') break;
  }
  for (unsigned j = i; j < reference_.size(); ++j) {
    result += reference_[j];
  }

  return result;
}
