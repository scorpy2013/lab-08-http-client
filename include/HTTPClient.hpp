// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HTTPCLIENT_HPP_
#define INCLUDE_HTTPCLIENT_HPP_
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Reference.hpp"

namespace beast = boost::beast;  // from <boost/beast.hpp>
namespace http = beast::http;    // from <boost/beast/http.hpp>
namespace net = boost::asio;     // from <boost/asio.hpp>
using tcp = net::ip::tcp;        // from <boost/asio/ip/tcp.hpp>

struct Request {
  std::string url;
  std::string host;
  std::string port;
  std::string target;
  std::string request;
  int version;
};

class HTTPClient {
 private:
  void PrepareCommandLine();
  int argc_;
  char** argv_;
  Request parts;

 public:
  HTTPClient(int argc, char* argv[]);
  int Start();
};

#endif  // INCLUDE_HTTPCLIENT_HPP_
