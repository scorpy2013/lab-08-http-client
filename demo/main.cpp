//
// Created by alexscorpy on 22.01.2021.
//
#include <HTTPClient.hpp>

int main(int argc, char* argv[]) {
  HTTPClient client(argc, argv);
  return client.Start();
}
//./cmake-build-debug/tests  http://localhost:8080/v1/api/suggest
//{\"input\":\"hel\"}
