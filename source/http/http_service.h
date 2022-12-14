#pragma once

#include "platform/SharedPtr.h"
#include "core/socket.h"
#include "parsed_url.h"

namespace GSH {

    class HttpService 
    {
    public:
        struct HttpResponse
        {
            SharedPtr<ParsedUrl> request_uri;
            char *body;
            char *status_code;
            int status_code_int;
            char *status_text;
            char *request_headers;
            char *response_headers;
        };

    public:
        HttpService();
        ~HttpService() = default;
        HttpService(HttpService &other) = delete;
        void operator=(const HttpService &) = delete;

        static HttpService& GetInstance();
        bool init(const char* ssid, const char* password, nsapi_security security=NSAPI_SECURITY_WPA_WPA2);

        HttpResponse* http_request(char* http_headers, SharedPtr<ParsedUrl> purl);

        HttpResponse* http_get(const char *url, char *custom_headers);
        HttpResponse* http_post(const char *url, char *custom_headers, char *post_data);

    private:
        Socket m_Socket;
    };

}