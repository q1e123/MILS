//
// Created by q1e123 on 27.07.2019.
//

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/builtin.h"
#include "../include/errors.h"

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_funcs[])(char**)={
	&mils_cd,
	&mils_help,
	&mils_exit
};

int mils_cd(char **args){
	if(args[1] == NULL){
		err_usage("cd <PATH>");
	}else{
		if(chdir(args[1]) != 0){
			perr("cd error");
		}
	}
	return 1;
}
int mils_help(char **args){
	char *msg = ""
	        "Mother I Love Shell\n"
                "Shell made by q1e123\n"
		"Type a program name and its argument and hint enter\n"
                "Built in functions:\n";

	printf(msg);
	for(int i=0;i<num_builtins();++i){
		printf(" %s\n",builtin_str[i]);
	}

	return 1;
}
int mils_exit(char **args){
	return EXIT_SUCCESS;
}

int num_builtins(){
	return sizeof(builtin_str)/ sizeof(char*);
}