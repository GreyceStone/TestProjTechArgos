#include <iostream>
#include <fstream>
#include <thread>
#include <syslog.h>
#include <unistd.h>

void readDataFromFile() {
    std::ifstream inputFile("/tmp/indata.txt");
    std::ofstream outputFile("/tmp/outdata.txt", std::ios::app);

    if (!inputFile.is_open()) {
        syslog(LOG_ERR, "Failed to open input file");
        exit(EXIT_FAILURE);
    }

    if (!outputFile.is_open()) {
        syslog(LOG_ERR, "Failed to open output file");
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    syslog(LOG_INFO, "YourApplication started");

    std::thread dataThread(readDataFromFile);

    std::system("less /tmp/outdata.txt");

    dataThread.join();

    remove("/tmp/outdata.txt");
    
    syslog(LOG_INFO, "TestProject завершён");

    closelog();
}