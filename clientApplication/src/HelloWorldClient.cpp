//HelloWorlClient.cpp

#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>

using namespace v1_0::commonapi;

int main() {
	// getting the pointer of generic runtime object(used to create proxies and stubs)
	std::shared_ptr <CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
	
	// client has to call function of instance of interface in the service application 
	// Building a proxy for interface in the client for a particular instance (2nd parameter)
	std::shared_ptr<HelloWorldProxy<>> myProxy =
		runtime->buildProxy<HelloWorldProxy>("local","test");
	
	//proxy provides the isAvailable() API returns true when service is available
	std::cout<<"checking availability" <<std::endl;
	while(!myProxy->isAvailable())
		usleep(10);
	std::cout<<"Available..."<<std::endl;
	
	CommonAPI::CallStatus callStatus;
	std::string returnMessage;
	
	//check HelloWorldProxy.hpp to check how the fucntion should be called
	myProxy->sayHello("Bob",callStatus,returnMessage);
	std::cout<<"Got message:"<<returnMessage<<"\n";
	return 0;
}
