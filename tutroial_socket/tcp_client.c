#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
	//create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify an address
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	// check the error for conection
	if (connection_status == -1) {
		printf("There is an error when connection\n");
	}

	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	// print out the data
	printf("The server send the data %s \n", server_response);
	
	close(socket);

	return 0;
}

