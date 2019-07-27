#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"

void init(){
	printf("Mother I Love Shell\n\n");
}

void loop(){
	char *line;
	char **args;
	int status;

	status = 1;

	while (status){
		printf("$ ");


		line = readline();
		args = split(line," \t\r\n\a");
		status = exec(args);

		free(line);
		free(args);
	}

}

int main() {
	init();
	loop();

	return EXIT_SUCCESS;
}