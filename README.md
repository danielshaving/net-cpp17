这是一个tcp网络库，比libevent吞吐量快30%左右，事件处理libevent略优，具体性能测试请参考libev benchmark手册 
这是libxv示例代码
#include "xEventLoop.h"
#include "xTcpconnection.h"
#include "xTcpServer.h"
#include "xBuffer.h"

void onConnection(const xTcpconnectionPtr& conn,void *data)
{
  if (conn->connected())
  {
    printf("connect success\n");
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
