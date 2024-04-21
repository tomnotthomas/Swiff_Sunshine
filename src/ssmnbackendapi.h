#ifndef SSMN_BACKEND_API
#define SSMN_BACKEND_API

#include <string>
#include <cstdint>

namespace ssmn {
    class SsmnBackendApi {
        public:
            static SsmnBackendApi* instance() {
                static SsmnBackendApi api;
                return &api;
            }

            void setRemoteAddress(const std::string& address, std::uint16_t port)
            {
              mRemoteAddress = address;
              mRemotePort = port;
            }

            void setLocalAddress(const std::string& address) {
                mLocalAddress = address;
            }

            void remoteRegister();
            void remoteUnregister();
        private:
            explicit SsmnBackendApi();
            ~SsmnBackendApi();
            SsmnBackendApi(const SsmnBackendApi&) = delete;
            SsmnBackendApi(SsmnBackendApi&&) noexcept = delete;
            SsmnBackendApi& operator = (const SsmnBackendApi&) = delete;
            SsmnBackendApi& operator = (SsmnBackendApi&&) noexcept = delete;

            std::string mRemoteAddress;
            std::string mLocalAddress;
            std::uint16_t mRemotePort = 0;
    };
} // namespace ssmn

#endif /* SSMN_BACKEND_API */