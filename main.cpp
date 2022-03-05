#include <boost/asio/io_context.hpp>
#include <iostream>
#include "webserver.h"
#include "config.h"

int main(){
    Config config("./config.json");
    boost::asio::io_context context;
    WebServer Server(context,config);
    Server.Run();
    return 0;
}
