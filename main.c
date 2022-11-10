#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(void) {
	char str[16];
	char *output;
	CURL *curl = curl_easy_init();
	if(!curl)
		exit(1);

	while(fgets(str, sizeof(str), stdin) != NULL) {
		int i = 0;
		while(str[i] != '\0'){
				if ( str[i] == 0x0A ){
					memmove(&str[i], &str[i+1], strlen(str) - i);
				}
				i++;
		}
		output = curl_easy_escape(curl, str, 0);
		fputs(output,stdout);
		curl_free(output);
	}

	curl_easy_cleanup(curl);
	return(0);
}
