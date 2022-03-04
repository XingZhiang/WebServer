#include "../server/webserver.h"
#include <boost/asio/io_context.hpp>
int main(){
    boost::asio::io_context context;
    WebServer server(context, 8080);
    server.Run();
    return 0;
}
