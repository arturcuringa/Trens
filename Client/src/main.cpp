#include <iostream>
#include "socket.h"
#include "analog.h"
#include "BlackBone_GPIO.h"
#include <unistd.h>

#define IP "192.168.7.1"
#define PORT 4555
#define UP "P9_14"
#define DOWN "P9_16"
#define PLAY "P9_27"

int main()
{
	Socket s(IP, PORT);
	Operation op;
	BlackBone_GPIO _GPIO;
	_GPIO.setup(UP, GPIO::IN);
	_GPIO.setup(DOWN, GPIO::IN);
	_GPIO.setup(PLAY, GPIO::IN);


	int menu_bar = 1;
	while(true)
	{
		system("clear");
		if(menu_bar == 0)
			std::cout <<"\33[30;47m(1) Turn on all trains\33[0m\n";
		else
			std::cout <<"(1) Turn on all trains\n";

		if(menu_bar == 1)
			std::cout <<"\33[30;47m(2) Turn on specific train[1-7]\33[0m\n";
		else
			std::cout <<"(2) Turn on specific train[0-6]\n";

		if(menu_bar == 2)
			std::cout <<"\33[30;47m(3) Turn off specific train[1-7]\33[0m\n";
		else
			std::cout <<"(3) Turn off specific train[1-7]\n";

		if(menu_bar == 3)
			std::cout <<"\33[30;47m(4) Change train[1-7] speed\33[0m\n";
		else
			std::cout <<"(4) Change train[1-7] speed\n";

		if(menu_bar == 4)
			std::cout <<"\33[30;47m(5) Turn off controll\33[0m\n";
		else
			std::cout <<"(5) Turn off controll\n";
		
		if(_GPIO.input(UP))
		{	
			if(menu_bar == 0)
				menu_bar = 6;
			else menu_bar = (menu_bar -1)%7;
		}else if(_GPIO.input(DOWN))
		{
			menu_bar = (menu_bar + 1) % 7;
		}


		if(_GPIO.input(PLAY))
		{
			if(menu_bar == 0)
			{
				op.op = 0;
				op.id = 0;
				op.value = 0;
				s.setMensage(op);
				if(s.send() < 0 )
				{
					std::cout << "Error in send()" << std::endl;
					return -1;
				}
			}
			if(menu_bar == 1 || menu_bar == 2)
			{
				int x = 0;
				usleep(60000);
				while(_GPIO.input(PLAY) == 0)
				{
					usleep(60000);
					system("clear");
					std::cout << "Choose the train number [1-7]:\n " << x + 1<< std::endl;
					if(_GPIO.input(UP))
					{
						if(x == 0)
							x = 6;
						else x = (x -1)%7;
					}else if(_GPIO.input(DOWN))
					{
						x = (x + 1) % 7;
					}else if(_GPIO.input(PLAY))
					{
						break;
					}
					

				}
				op.op = menu_bar;
				op.id = x;

				s.setMensage(op);
				if(s.send() < 0 )
				{
					std::cout << "Error in send()" << std::endl;
					return -1;
				}
				usleep(60000);
			}
			if(menu_bar == 3)
			{
				int x = 0;
				usleep(60000);
				while(_GPIO.input(PLAY) == 0)
				{
					usleep(60000);
					system("clear");
					std::cout << "Choose the train number [1-7]:\n " << x + 1<< std::endl;
					if(_GPIO.input(UP))
					{
						if(x == 0)
							x = 6;
						else x = (x -1)%7;
					}else if(_GPIO.input(DOWN))
					{
						x = (x + 1) % 7;
					}else if(_GPIO.input(PLAY))
					{
						break;
					}
					

				}
				usleep(60000);
				system("clear");
				std::cout << "Choose the train velocity [10-1000]: "<< std::endl;
				int value;
				while(_GPIO.input(PLAY) == 0)
				{	
					usleep(1000);			
					value = readAnalog(1);
					std::cout <<"\33[2K\r" << value;
				}
				op.op = menu_bar;
				op.id = x;
				op.value = value;
				s.setMensage(op);
				if(s.send() < 0 )
				{
					std::cout << "Error in send()" << std::endl;
					return -1;
				}
				usleep(60000);
			}
			if(menu_bar == 4)
			{
				op.op = 4;
				op.id = 0;
				op.value = 0;
				s.setMensage(op);
				if(s.send() < 0 )
				{
					std::cout << "Error in send()" << std::endl;
					return -1;
				}
				return 0;
				
			}
			
		}

		usleep(60000);
	}

}