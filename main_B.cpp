// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

int main()
{
	// creating socket
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	// specifying address
	sockaddr_in serverAddress;
    const char * temp {"localhost"};
    char hostname[128];
    gethostname(hostname, sizeof(hostname));
    struct hostent * ss = gethostbyname(hostname);
    if (ss == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
	serverAddress.sin_family = AF_INET;
    // bcopy((char *)ss->h_addr,(char *)&serverAddress.sin_addr.s_addr, ss->h_length);
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	// sending connection request
	connect(clientSocket, (struct sockaddr*)&serverAddress,
			sizeof(serverAddress));

	// sending data
    char check{'a'};
    std::string usr_msg{""};
    while("exit"!=usr_msg)
    {
        std::cin>>usr_msg;
        send(clientSocket,usr_msg.c_str() , usr_msg.length(), 0);
    }


	// closing socket
	close(clientSocket);

	return 0;
}
