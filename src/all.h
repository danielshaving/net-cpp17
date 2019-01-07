#pragma once
#include <inttypes.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <mutex>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <functional>
#include <algorithm>
#include <memory>
#include <condition_variable>
#include <thread>
#include <sys/types.h>
#include <signal.h>
#include <string>
#include <iosfwd> 
#include <string>
#include <set>
#include <errno.h>
#include <array>
#include <utility>
#include <limits.h>
#include <stdint.h>
#include <sys/stat.h>
#include <atomic>
#include <stdarg.h>
#include <limits.h>
#include <any>
#include <string_view>
#include <experimental/filesystem>
#include <ratio>
#include <chrono>
#ifdef _LUA
#include <lua.hpp>
#endif

#ifdef _WIN64
#include <WinSock2.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
typedef SSIZE_T ssize_t;
#define IOV_TYPE WSABUF
#define STRCMP _stricmp
#define MEMCMP _strnicmp
#else
#define IOV_TYPE struct iovec
#define STRCMP strcasecmp
#define MEMCMP strncasecmp
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <sys/syscall.h>
#include <arpa/inet.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <poll.h>
#include <netdb.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pwd.h>
#include <dirent.h>
#include <sys/times.h>
#endif

#ifdef __APPLE__
#include <sys/event.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <libkern/OSByteOrder.h>
//#include <zlib.h>

#define htobe16(x) OSSwapHostToBigInt16(x)
#define htole16(x) OSSwapHostToLittleInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)
#define le16toh(x) OSSwapLittleToHostInt16(x)

#define htobe32(x) OSSwapHostToBigInt32(x)
#define htole32(x) OSSwapHostToLittleInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)
#define le32toh(x) OSSwapLittleToHostInt32(x)

#define htobe64(x) OSSwapHostToBigInt64(x)
#define htole64(x) OSSwapHostToLittleInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
#define le64toh(x) OSSwapLittleToHostInt64(x)
#endif

#ifdef __linux__
#include <sys/sendfile.h>
#include <sys/epoll.h>
#include <linux/tcp.h>
#include <sys/timerfd.h>
#include <sys/eventfd.h>
#include <endian.h>
#include <sys/un.h>
#include <sys/utsname.h>
#endif


