#include "ssmnbackendapi.h"
#include "config.h"
#include "curlrequest.h"
#include "logging.h"

using namespace ssmn;

SsmnBackendApi::SsmnBackendApi()
{
    ssmn::CurlRequest::init();
}

SsmnBackendApi::~SsmnBackendApi()
{
    ssmn::CurlRequest::deinit();
}

void SsmnBackendApi::remoteRegister() {
    if (mRemotePort > 0) {
        if (!mRemoteAddress.empty()) {
            BOOST_LOG(info) << "Sending register to " << mRemoteAddress;
                // fill headers
            std::vector<std::string> headersList = {
//                "Authorization: " + sessionKey,
                "User-Agent: SSMNPCClient/V1.0",
                "Content-Type: application/x-www-form-urlencoded"
            };

           CURLcode retValue = CURLE_OK;
           std::string postData = "ip_address=" + mLocalAddress + "&title=test&action=register_server";
           std::string readBuffer = CurlRequest::PostUrl(mRemoteAddress, postData, headersList, &retValue,
                3, 20000L);

            BOOST_LOG(info) << "result: " << readBuffer.c_str();
        } else {
            BOOST_LOG(error) << "Remote address is empty!";
        }
    } else {
        BOOST_LOG(error) << "Remote port is empty!";
    }
}

void SsmnBackendApi::remoteUnregister() {
    if (mRemotePort > 0) {
        if (!mRemoteAddress.empty()) {
            BOOST_LOG(info) << "Sending Unregister to " << mRemoteAddress << ":" << mRemotePort;
                            // fill headers
            std::vector<std::string> headersList = {
//                "Authorization: " + sessionKey,
                "User-Agent: SSMNPCClient/V1.0",
                "Content-Type: application/x-www-form-urlencoded"
            };

            CURLcode retValue = CURLE_OK;
            std::string postData = "ip_address=" + mLocalAddress + "&title=test&action=unregister_server";
            std::string readBuffer = CurlRequest::PostUrl(mRemoteAddress, postData, headersList, &retValue,
                 3, 20000L);

            BOOST_LOG(info) << "result: " << readBuffer.c_str();
        } else {
            BOOST_LOG(error) << "Remote address is empty!";
        }
    } else {
        BOOST_LOG(error) << "Remote port is empty!";
    }
}