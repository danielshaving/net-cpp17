
针对中文,演示Markdown的各种语法

大标题

大标题一般显示工程名,类似html的<h1>
你只要在标题下面跟上=====即可

中标题

中标题一般显示重点项,类似html的<h2>
你只要在标题下面输入------即可

小标题

小标题类似html的<h3>
小标题的格式如下 ### 小标题
注意#和标题字符中间要有空格

标题的等级表示法

关于标题的等级表示法，共分为六个等级，显示的文本大小依次减小。不同等级之间以井号#的个数来标识。一级标题有一个#，二级标题有两个#，以此类推。
    #一级标题
    ##二级标题
    ###三级标题
    ####四级标题
    #####五级标题
    ######六级标题
注意!!!下面所有语法的提示我都先用小标题提醒了!!!

单行文本框

这是一个单行的文本框,只要两个Tab再输入文字即可

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
