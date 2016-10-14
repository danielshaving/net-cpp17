
libxv tcp网络库=====

#include "xEventLoop.h"
#include "xTcpconnection.h"
#include "xTcpServer.h"
#include "xBuffer.h"

void onConnection(const xTcpconnectionPtr& conn,void *data)
{
  if (conn->connected())
  {
    
  }
}

void onMessage(const xTcpconnectionPtr& conn, xBuffer* buf,void *data)
{
  conn->send(buf);
}


int main()
{
	signal(SIGPIPE, SIG_IGN);
	xEventLoop loop;
	xTcpServer server;
	server.init(&loop,"127.0.0.1",1234,nullptr);
	server.setConnectionCallback(onConnection);
	server.setMessageCallback(onMessage);
	server.setThreadNum(0);
	server.start();
	loop.run();
	
	return 0;
}
