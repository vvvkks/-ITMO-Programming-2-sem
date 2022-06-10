#define CURL_STATICLIB
#include <iostream>
#include "curl/curl.h"
#include "json/json.h"
#include "nlohmann/json.hpp"
#include "windows.h"
#include <chrono>
#include "lab2.h"
#include <string>
#include <thread>
#include <vector>
#include <signal.h>32



#ifdef _DEBUG

#pragma comment (lib, "curl/libcurl_a_debug.lib")
#else

#pragma comment (lib, "curl/libcurl_a.lib")

#endif

#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")
#pragma comment (lib,"advapi32.lib")

static const int gop = 34;

std::vector<std::vector<double>> values;
std::vector<std::string> names;

using json = nlohmann::json;
size_t curlWriteFunc(char* data, size_t size, size_t nmemb, std::string* buffer)
{
    size_t result = 0;

    if (buffer != NULL)
    {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;

}

void sleep() {
    std::chrono::seconds sec(10);
    std::this_thread::sleep_for(sec);
}

void park(int) {
    std::cout << "Average: \n";
    for (int i = 0; i < gop; ++i) {
        double sum = 0;
        for (auto x : values[i]) { sum += x; }
        std::cout << '\t' << names[i] << ' ' << sum / values[i].size() << std::endl;
    }
    std::cout << "Medium: \n";
    for (int i = 0; i < gop; ++i) {
        sort(values[i].begin(), values[i].end());
        std::cout << '\t' << names[i] << ' ' << values[i][values[i].size() / 2] << std::endl;
    }
}


int main()
{
    values.resize(gop);
    names.resize(gop);
    std::string curlBuffer;

    const char* url = "https://www.cbr-xml-daily.ru/daily_json.js";
    CURL* curl = curl_easy_init();
    char curlErrorBuffer[CURL_ERROR_SIZE];
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curlErrorBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, url);

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteFunc);

    while (1) {
        if (curl) {

            CURLcode curlResult = curl_easy_perform(curl);
            if (curlResult == CURLE_OK)
            {
                auto ok = json::parse(curlBuffer);
                size_t count = 0;
                for (auto& [key, value] : ok["Valute"].items()) {
                    std::cout << key << " : " << value["Value"] << "\n";
                    names[count] = key;
                    values[count].push_back(value["Value"].get<double>());
                    count++;
                }

            }
            else {
                std::cout << "Ошибка(" << curlResult << "): " << curlErrorBuffer << std::endl;
            }
            curlBuffer.clear();
        }
        std::cout << '\n';
        sleep();
        signal(SIGINT, park);
    }
}