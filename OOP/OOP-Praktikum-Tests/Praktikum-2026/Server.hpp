#pragma once

#include "MobileDevice.hpp"
#include "DesktopDevice.hpp"
#include "Connection.hpp"

class Server
{
public:
    Server(unsigned capacity, unsigned timeout);

    //no need for copy ctors
    Server(const Server& other) = delete;
    Server& operator=(const Server& other) = delete;

    ~Server();

    //methods
    bool connect(const Device& device);
    bool disconnect(int DeviceId);
    void tick(unsigned cnt = 1);
    void saveLog(const char* fileName) const;
    void loadLog(const char* fileName);

    //abstract methods
    void printServerState() const;

private:
    unsigned capacity;
    unsigned timeout;
    unsigned countConnections;
    unsigned currentTime;
    Connection* connections;

    void free();
};
