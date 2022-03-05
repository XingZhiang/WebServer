/* @File   :wenserver.cpp
 * @Auther :xza
 */

#include "webserver.h"
#include <boost/asio/io_context.hpp>
#include <iostream>
#include <mutex>

using  boost::asio::ip::tcp;

WebServer::WebServer(boost::asio::io_context& context, Config& config)
:_context(context),_port(config.port){
    _ep = tcp::endpoint(tcp::v4(), _port);
}

void WebServer::Run(){
     std::cout<<"Server is listen on "<<this->_port<<std::endl;
    try{
        tcp::acceptor acceptor(this->_context,this->_ep);
        while(true){
            tcp::socket socket(this->_context);
            acceptor.accept(socket);
        }
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}


