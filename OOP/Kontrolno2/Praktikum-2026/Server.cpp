#include "Server.hpp"

Server::Server(unsigned capacity, unsigned timeout)
    : capacity(capacity), timeout(timeout), countConnections(0), currentTime(0)
{
    this->connections = new Connection[this->capacity];
}

Server::~Server()
{
    free();
}

bool Server::connect(const Device &device)
{
    if (this->countConnections >= this->capacity)
    {
        return false; // Server is full
    }

    // clone() creates a deep copy. The Connection takes ownership of this pointer.
    this->connections[this->countConnections++] = Connection(device.clone(), this->currentTime);

    return true;
}

bool Server::disconnect(int deviceId)
{
    for (unsigned i = 0; i < this->countConnections; ++i)
    {
        Device *currentDevice = this->connections[i].getDevice();

        if (currentDevice->GetId() == (unsigned)deviceId)
        {
            // Compact the array by shifting elements left
            for (unsigned j = i; j < this->countConnections - 1; ++j)
            {
                this->connections[j] = this->connections[j + 1];
            }

            // Clear the last element to prevent double-free dangling pointers
            this->connections[this->countConnections - 1] = Connection();
            this->countConnections--;

            return true;
        }
    }

    return false;
}

void Server::tick(unsigned cnt)
{
    this->currentTime += cnt;

    // Iterate backwards. When removing elements from a dynamic array,
    // going forward skips elements due to the left-shift compression.
    for (int i = this->countConnections - 1; i >= 0; --i)
    {
        if (this->connections[i].getDevice() != nullptr)
        {
            unsigned timeConnected = this->currentTime - this->connections[i].getTick();

            if (timeConnected >= this->timeout)
            {
                disconnect(this->connections[i].getDevice()->GetId());
            }
        }
    }
}

void Server::saveLog(const char *fileName) const
{
    std::ofstream file(fileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file for writing.");
    }

    for (unsigned i = 0; i < this->countConnections; ++i)
    {
        Device *dev = this->connections[i].getDevice();
        if (dev != nullptr)
        {
            file << dev->GetType() << " "
                 << dev->GetId() << " "
                 << dev->GetName() << " ";

            if (strcmp(dev->GetType(), "mobile") == 0)
            {
                MobileDevice *md = dynamic_cast<MobileDevice *>(dev);
                file << md->GetBattery() << " ";
            }
            else if (strcmp(dev->GetType(), "desktop") == 0)
            {
                DesktopDevice *dd = dynamic_cast<DesktopDevice *>(dev);
                file << dd->GetURL() << " ";
            }

            file << this->connections[i].getTick() << "\n";
        }
    }
    file.close();
}

void Server::free()
{
    delete[] this->connections;
}
