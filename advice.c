#include<stdio.h> // for the puts() function
#include<sys/socket.h> // for the socket(), bind(), and send() functions
#include<arpa/inet.h> // for the htons() function
#include<string.h> // for the strlen() function
#include<stdlib.h> // for the rand() function
#include<unistd.h> //for the close() function


int main(int argc, char *argv[])
{
	char *advice[] = 
	{
		"Take smaller bites\r\n",
		"Go for the tight jeans.  No they do NOT make you look fat.\r\n.",
		"one word: inappropriate\r\n",
		"Just for today, be honest.  Tell your boss waht you *really* think\r\n",
		"You might want to rethink that haircut\r\n"

	};

	//Create a socket
	int listener_d = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in name;
	name.sin_family = PF_INET;

	//Bind the port to Socket 30000
	name.sin_port = (in_port_t)htons(30000);
	
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(listener_d, (struct sockaddr *) &name, sizeof(name));
	
	//Set the listener queue depth to 10
	listen(listener_d, 10);
	
	puts("Waiting for connection");
	
	while(1)
		{
			struct sockaddr_storage client_addr;

			unsigned int address_size = sizeof(client_addr);

			//Accept connection from client
			int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);

			char *msg = advice[rand() % 5];

			//Begin talking to the client
			send(connect_d, msg, strlen(msg), 0);

			close(connect_d);
		}
	return 0;
}