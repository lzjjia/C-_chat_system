#pragma once
#include "const.h"	
//CServer就是用来处理对端的连接，当对端有链接到来，再交给Httpconnection去管理
class  HttpConnection;
class CServer:public std::enable_shared_from_this<CServer>
{
public:
    CServer(boost::asio::io_context& ioc, unsigned short& port);
    void Start();
private:
    tcp::acceptor  _acceptor;
    net::io_context& _ioc;
    
};

