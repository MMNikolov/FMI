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

        if (currentDevice != nullptr && currentDevice->GetId() == (unsigned)deviceId)
        {
            // O(1) swap with the last element
            this->connections[i] = this->connections[this->countConnections - 1];

            // Clear the last element safely
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

void Server::loadLog(const char *fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file for reading.");
    }

    free();
    this->countConnections = 0;
    this->currentTime = 0; // Рестартираме времето
    this->connections = new Connection[this->capacity];

    char type[50];
    unsigned id;
    char name[100];

    // Четем формат: <type> <id> <name> <specific_field> <connected_at>
    while (file >> type >> id >> name)
    {
        if (this->countConnections >= this->capacity)
            break;

        if (strcmp(type, "mobile") == 0)
        {
            int battery;
            unsigned connectedAt;
            file >> battery >> connectedAt;

            // Създаваме устройство с изричното ID и го записваме в масива
            MobileDevice md(id, name, battery);
            this->connections[this->countConnections++] = Connection(md.clone(), connectedAt);
        }
        else if (strcmp(type, "desktop") == 0)
        {
            char url[256];
            unsigned connectedAt;
            file >> url >> connectedAt;

            DesktopDevice dd(id, name, url);
            this->connections[this->countConnections++] = Connection(dd.clone(), connectedAt);
        }
    }

    file.close();
}

void Server::printServerState() const
{
    for (unsigned i = 0; i < this->countConnections; ++i)
    {
        if (this->connections[i].getDevice())
        {
            this->connections[i].getDevice()->print(std::cout);
        }
    }
}

void Server::free()
{
    delete[] this->connections;
    this->connections = nullptr; // Closes the vulnerability
}
