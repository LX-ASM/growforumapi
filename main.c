#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
 
int main(void)
{
  char *veri;
  char *data;
  printf("Veri Girin: ");
  scanf("%c", &veri);  
  CURL *curl;
  CURLcode res;
  data = strcat("https://growforum.tk/api/?data=", veri);
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, data);
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    curl_easy_cleanup(curl);
  }
  printf("Sonuç: %d", res);
  return 0;
}
