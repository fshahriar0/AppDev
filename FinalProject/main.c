#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "libcurl.lib")
#include "appdev.h"
#include <stdio.h>
#include <curl/curl.h>

int main(void)
{
    CURL* curl;
    CURLcode res;

    char poststring[200];
    combo c = minmax(); //generate a combo of min/max values
    sprintf(poststring, "min=%d&max=%d", c.min, c.max); //make post string


    /* In windows, this inits the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL); 

    /* get a curl handle */
    curl = curl_easy_init();
    if (curl) {
        
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e2305278/echo.php");
        
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststring);

        
        res = curl_easy_perform(curl);
        
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}