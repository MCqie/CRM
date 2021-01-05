#include <iostream>
#include <WINSOCK2.H>
#define PORT           5150
#define MSGSIZE        1024
SOCKADDR_IN local;
#pragma comment(lib, "ws2_32.lib")
using namespace std;
using std::string;
int main() {
    WSADATA wsaData;
    SOCKADDR_IN client;
    char szMessage[MSGSIZE];
    int ret;
    int iaddrSize = sizeof(SOCKADDR_IN);
    WSAStartup(0x0202, &wsaData);
    SOCKET s_server = socket(AF_INET, SOCK_STREAM, 0);
    local.sin_family = AF_INET;
    local.sin_port = htons(PORT);
    local.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(s_server,(struct sockaddr *) &local, sizeof(SOCKADDR_IN));
    listen(s_server, 1);
    SOCKET csoc=accept(s_server,(struct sockaddr *) &client, &iaddrSize);
    printf("Accepted client:%s:%d\n", inet_ntoa(client.sin_addr),
           ntohs(client.sin_port));

    while (TRUE) {
        ret = recv(csoc, szMessage, MSGSIZE, 0);
        szMessage[ret] = '\0';
        printf("Received [%d bytes]: '%s'\n", ret, szMessage);
    }
    return 0;
}