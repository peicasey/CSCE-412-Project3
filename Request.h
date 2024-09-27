#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <random>
#include <ctime>

class Request {
public:
    Request();

    std::string getIPIn() const;
    std::string getIPOut() const;
    int getTime() const;
    char getJobType() const;

private:
    std::string ipIn;   // IP Address (Incoming)
    std::string ipOut;  // IP Address (Outgoing)
    int time;           // Time for the request to be processed
    char jobType;       // Job type: 'P' for Processing, 'S' for Streaming

    std::string generateRandomIP() const;
    int generateRandomTime() const;
    char generateRandomJobType() const;
};

Request::Request() {
    ipIn = generateRandomIP();
    ipOut = generateRandomIP();
    time = generateRandomTime();
    jobType = generateRandomJobType();
}

// GETTER FUNCTIONS
std::string Request::getIPIn() const {
    return ipIn;
}

std::string Request::getIPOut() const {
    return ipOut;
}

int Request::getTime() const {
    return time;
}

char Request::getJobType() const {
    return jobType;
}

// HELPER FUNCTIONS
std::string Request::generateRandomIP() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 255);

    return std::to_string(dist(gen)) + "." +
           std::to_string(dist(gen)) + "." +
           std::to_string(dist(gen)) + "." +
           std::to_string(dist(gen));
}

int Request::generateRandomTime() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000); // random time between 1 and 1000 ms
    return dist(gen);
}

char Request::generateRandomJobType() const {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1); // 0 for 'P', 1 for 'S'

    return dist(gen) == 0 ? 'P' : 'S';
}

#endif
