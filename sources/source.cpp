// Copyright 2020 Your Name <your_email>

#include <HTTP_Client.hpp>

int main(int argc, char* argv[]) {
//./cmake-build-debug/tests  http://localhost:8080/v1/api/suggest
  HTTP_Client client(argc, argv);
  return client.Start();
}
