// Copyright 2020 Your Name <your_email>

#include <HTTP_Client.hpp>

int main(int argc, char* argv[]) {
  HTTP_Client client(argc, argv);
  return client.Start();
}
//./cmake-build-debug/tests  http://localhost:8080/v1/api/suggest
//{\"input\":\"hel\"}
