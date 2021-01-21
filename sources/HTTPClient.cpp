// Copyright 2020 Your Name <your_email>

#include "HTTPClient.hpp"

HTTPClient::HTTPClient(int argc, char* argv[]) : argc_(argc), argv_(argv) {}

int HTTPClient::Start() {
  if (argc_ != 3) {
    std::cerr << "Usage: http-client-sync <url> "
                 "<request>\n"
              << "Example:\n"
              << "    ./cmake-build-debug/tests  "
                 "http://localhost:8080/v1/api/suggest "
              << R"({\"input\":\"<user_input>\"})"
                 "\n";
    return EXIT_FAILURE;
  }

  try {
    PrepareCommandLine();

    net::io_context ioc;
    tcp::resolver resolver{ioc};
    beast::tcp_stream stream(ioc);

    auto const results = resolver.resolve(parts.host, parts.port);
    stream.connect(results);

    http::string_body::value_type body = parts.request;

    http::request<http::string_body> req{http::verb::post, parts.target,
                                         parts.version};
    req.set(http::field::host, parts.host);
    req.body() = body;
    req.prepare_payload();
    req.set(http::field::content_type, "text/plain");

    http::write(stream, req);

    boost::beast::flat_buffer buffer;

    http::response<http::string_body> res;

    http::read(stream, buffer, res);
    std::cout << res.body() << std::endl;

    beast::error_code ec;
    stream.socket().shutdown(tcp::socket::shutdown_both, ec);

    if (ec && ec != beast::errc::not_connected) {
      throw beast::system_error{ec};
    }
  } catch (std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void HTTPClient::PrepareCommandLine() {
  Reference reference(argv_[1]);
  parts.url = reference.GetUrl();
  parts.host = reference.GetHost();
  parts.port = reference.GetPort();
  parts.target = reference.GetTarget();
  parts.request = argv_[2];
  parts.version = 11;
}
