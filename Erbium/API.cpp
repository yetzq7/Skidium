#include "pch.h"
#include <thread>
#include <chrono>
#include <iostream>
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include "matchmaker.h"
#include "./Erbium/Public/Configuration.h"
#pragma comment(lib, "Ws2_32.lib")
#endif

// unproper but wtv
// credits to the random reddit post that helped me soon

void Match(const char* url)
{
    std::thread([url]()
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        #ifdef _WIN32
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            std::cout << "failed!\n";
            return;
        }

        addrinfo hints{};
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        addrinfo* result = nullptr;

        if (getaddrinfo("127.0.0.1", "1111", &hints, &result) != 0)
        {
            WSACleanup();
            return;
        }

        SOCKET sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (sock == INVALID_SOCKET)
        {
            freeaddrinfo(result);
            WSACleanup();
            return;
        }

        if (connect(sock, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR)
        {
            closesocket(sock);
            freeaddrinfo(result);
            WSACleanup();
            return;
        }

        const char* request = "POST HTTP/1.1\r\n"
                              "Host: 127.0.0.1\r\n"
                              "Content-Length: 0\r\n"
                              "Connection: close\r\n"
                              "\r\n";

        send(sock, request, (int)strlen(request), 0);

        char buffer[1024];
        recv(sock, buffer, sizeof(buffer), 0);

        closesocket(sock);
        freeaddrinfo(result);
        WSACleanup();

        std::cout << "[SKIDIUM] Posted to \n", FConfiguration::MatchmakerURL;
#endif
    }).detach();
}