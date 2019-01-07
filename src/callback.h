#pragma once
#include "all.h"
class Buffer;
class TcpConnection;
class Connector;
class TcpClient;
class ThreadPool;
class Acceptor;
class Channel;
class TimerQueue;
class Poll;
class Epoll;
class Thread;
class Timer;
class Select;

typedef std::shared_ptr<Timer> TimerPtr;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
typedef std::weak_ptr<TcpConnection> WeakTcpConnectionPtr;
typedef std::shared_ptr<Connector> ConnectorPtr;
typedef std::shared_ptr<TcpClient> TcpClientPtr;
typedef std::shared_ptr<ThreadPool> ThreadPoolPtr;
typedef std::unique_ptr<Acceptor> AcceptorPtr;
typedef std::shared_ptr<Channel> ChannelPtr;
typedef std::shared_ptr<TimerQueue> TimerQueuePtr;
typedef std::shared_ptr<Poll> PollPtr;
typedef std::shared_ptr<Epoll> EpollPtr;
typedef std::shared_ptr<Select> SelectPtr;
typedef std::shared_ptr<Thread> ThreadPtr;
typedef std::function<void()> TimerCallback;
typedef std::function<void(const TcpConnectionPtr&)> ConnectionCallback;
typedef std::function<void(const TcpConnectionPtr&)> DisConnectionCallback;
typedef std::function<void(const std::any &)> ConnectionErrorCallback;
typedef std::function<void(const TcpConnectionPtr&)> CloseCallback;
typedef std::function<void(const TcpConnectionPtr&)> WriteCompleteCallback;
typedef std::function<void(const TcpConnectionPtr&, size_t)> HighWaterMarkCallback;
typedef std::function<void(const TcpConnectionPtr&, Buffer*)> MessageCallback;








