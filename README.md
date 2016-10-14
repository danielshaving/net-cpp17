leveldb: A key-value store
Authors: Sanjay Ghemawat (sanjay@google.com) and Jeff Dean (jeff@google.com)

The code under this directory implements a system for maintaining a
persistent key/value store.

See doc/index.html for more explanation.
See doc/impl.html for a brief overview of the implementation.

The public interface is in include/*.h.  Callers should not include or
rely on the details of any other header files in this package.  Those
internal APIs may be changed without warning.

Guide to header files:

include/db.h
Main interface to the DB: Start here
    
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
