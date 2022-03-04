#include <boost/asio/io_context.hpp>
#include <iostream>
#include "./src/server/webserver.h"

int main(){
    boost::asio::io_context context;
    WebServer Server(context,8080);
    Server.Run();
    return 0;
}
