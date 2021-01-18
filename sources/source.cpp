// Copyright 2020 Your Name <your_email>

#include <HTTP_Client.hpp>

int main(int argc, char* argv[]) {
  argc=3;
  HTTP_Client client(argc, argv);
  return client.Start();
}

