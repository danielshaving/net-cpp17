#pragma once

#include "all.h"
#include "xBuffer.h"

#include "xCallback.h"
#include "xChannel.h"

class xEventLoop;
class xTcpconnection:boost::noncopyable,public std::enable_shared_from_this<xTcpconnection>
{
public:

	enum StateE { kDisconnected, kConnecting, kConnected, kDisconnecting };

	xTcpconnection(xEventLoop *loop,int sockfd,void *data);
	~xTcpconnection();

	xEventLoop			*getLoop();
	int 				getSockfd();


	void setState(StateE s) { state  = s; }

	void setConnectionCallback(const ConnectionCallback& cb)
	{ connectionCallback = cb; }

	void setMessageCallback(const MessageCallback& cb)
	{ messageCallback = cb; }

	void setWriteCompleteCallback(const WriteCompleteCallback& cb)
	{ writeCompleteCallback = cb; }

	void setHighWaterMarkCallback(const HighWaterMarkCallback& cb, size_t highWaterMark)
	{ highWaterMarkCallback = cb; this->highWaterMark  = highWaterMark; }

	void setCloseCallback(const CloseCallback& cb)
	{ closeCallback = cb; }

	void handleRead();
	void handleWrite();
	void handleClose();
	void handleError();

	void sendInLoop(const void* message, size_t len);
    void sendInLoop(std::string & message);
	void send(xBuffer* message);
	void send(std::string && message);

	bool disconnected() const { return state == kDisconnected; }
	bool connected();
	void forceCloseInLoop();
	void connectEstablished();
	const void *getContext()const{ return context;}
	void setContext(void * context) { this->context = context;}
	void connectDestroyed();
	void setData(void *data);
	void * getData() {return data;}
	void shutdown();
	void shutdownInLoop();
	void forceClose();
	void setPlayer(int64_t player_id) {this->player_id = player_id; }
	int64_t  getPlayer() { return player_id; }
	xBuffer * getSendBuff(){ return &sendBuff; }

private:
	xEventLoop 			  *loop;
	int 				  sockfd;


    xBuffer               recvBuff;
    xBuffer               sendBuff;
    ConnectionCallback    connectionCallback;
	MessageCallback 	  messageCallback;
	WriteCompleteCallback writeCompleteCallback;
	HighWaterMarkCallback highWaterMarkCallback;
	CloseCallback 		  closeCallback;
	size_t 				      highWaterMark;
	StateE 				  state;
	boost::scoped_ptr<xChannel> channel;
	void 				*data;
	void 				*context;
	int64_t		player_id = -1;

};
