#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <vector>

static const std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

std::string base64_encode(unsigned char const *bytes_to_encode, unsigned int in_len);

std::string getSockKey(std::string server_request);

std::string getSockAccept(std::string client_key);

void SendWebSockAccept(int client);

std::string DecodeWebSocket(const char buffer[], const size_t length);

std::string EncodeWebSocket(char message[], size_t length);

bool unit_test();

struct client
{
    int fd;
    std::string name;
};

#endif