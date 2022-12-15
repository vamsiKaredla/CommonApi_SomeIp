// HelloWorldStubImpl.hpp
#ifndef HELLOWORLDSTUBIMPL_H_
#define HELLOWORLDSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldStubDefault.hpp>

class HelloWorldStubImpl: public v1_0::commonapi::HelloWorldStubDefault {
public:
    HelloWorldStubImpl();
    virtual ~HelloWorldStubImpl();
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sayHelloReply_t _return);
    virtual bool hasElement(const uint32_t _id) const;
    COMMONAPI_EXPORT virtual void registerSelectiveEventHandlers();
    COMMONAPI_EXPORT virtual void unregisterSelectiveEventHandlers();
};
#endif /* HELLOWORLDSTUBIMPL_H_ */
