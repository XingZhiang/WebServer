/* @File   : webserver.h
 * @auther : xza
 */
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <boost/asio.hpp>
#include "../pool/threadpool.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/address_v4.hpp>
#include <boost/asio/ip/bad_address_cast.hpp>
#include <memory>
#include <mutex>
#include <unordered_map>
#include "../config/config.h"

// 使用boost::asio库进行网络连接
using boost::asio::ip::tcp;

class WebServer{
public:
    void Run();
    WebServer(boost::asio::io_context& context, Config& config) ;
    void AddClient();

private:
    boost::asio::io_context&  _context;
    uint64_t _port; // 端口号
    boost::asio::ip::tcp::endpoint _ep; // 端点
    // std::unordered_map<uint64_t, HttpConn> _users;
    std::unique_ptr<ThreadPool> _threadpool;

};

#endif // WEBSERVER_H
