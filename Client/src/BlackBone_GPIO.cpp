#include "BlackBone_GPIO.h"


BlackBone_GPIO::BlackBone_GPIO()
{

}

std::string BlackBone_GPIO::exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result +=buffer.data();
    }
    return result;
}


void BlackBone_GPIO::setup(const std::string port, const GPIO SIG )
{

    //Check if string is in correct format
 	if(SIG == GPIO::IN || SIG == GPIO::OUT )
    {
    		int n_port = pinToIO[port];
            std::string  folderr;
            folderr = GPIO_PATH + "/gpio" + std::to_string(n_port);
            struct stat sb;
            // if(!(stat(folderr.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode) ))
            // {
    		// std::fstream fs;
    		// fs.open(GPIO_PATH + "/export" ,std::fstream::in | std::fstream::out | std::fstream::app);
      //       fs << port;
    		// fs.close();
            // }
            exec(("echo "+ std::to_string(n_port) + " > " + GPIO_PATH + "/export").c_str());
            std::string dir = GPIO_PATH + "/gpio" + std::to_string(n_port);
            std::fstream fs;
            fs.open(dir + "/direction" ,std::fstream::in | std::fstream::out | std::fstream::app);
            std::cout << "Test" << std::endl;
            if(SIG ==  GPIO::IN)
            {
                fs << "in";
            }
            else if(SIG ==  GPIO::OUT)
            {               
                fs << "out";
            }
            fs.close();
    }
}

void BlackBone_GPIO::output(const std::string port, const GPIO SIG )
{
        std::string dir = GPIO_PATH + "/gpio" + std::to_string(pinToIO[port]);
    	std::fstream fs;
        if(SIG == GPIO::HIGH || SIG == GPIO::LOW )
        {
        	fs.open(dir + "/value" ,std::fstream::in | std::fstream::out | std::fstream::app);
            if( SIG == GPIO::HIGH )
            {
        		                    
                fs << 1;

            }
            if( SIG == GPIO::LOW )
            {
                fs << 0;
           	}
            fs.close();
        }
}

unsigned BlackBone_GPIO::input(const std::string port)
{
        std::fstream fs;
        std::string dir = GPIO_PATH + "/gpio" + std::to_string(pinToIO[port]);
        fs.open(dir + "/value" ,std::fstream::in | std::fstream::out | std::fstream::app);
        std::string input;
        getline(fs, input);
        return atoi(input.c_str());

}

