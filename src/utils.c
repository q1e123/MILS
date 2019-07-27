//
// Created by q1e123 on 26.07.2019.
//

#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../include/utils.h"
#include "../include/errors.h"
#include "../include/builtin.h"

char *readline(){
	char *line = NULL;
	ssize_t bufsize = 0;
	getline(&line,&bufsize,stdin);
	return line;
}

void bufgrow(char *buf, int *bufsize, const int grow){
	*bufsize += grow;
	buf = realloc(buf, *(bufsize) * sizeof(char*));
	if(!buf){
		err_alloc();
	}
}

#define TOK_BUFSIZE 64

char **split(char *line,const char *DELIM){
	int bufsize = TOK_BUFSIZE;
	int pos = 0;
	char **toks = malloc(bufsize * sizeof(char*));
	char *tok;

	if(!toks){
		err_alloc();
	}
	tok = strtok(line,DELIM);

	while (tok){
		toks[pos++] = tok;
		if(pos>=bufsize){
			bufgrow(toks,bufsize,64);
		}
		tok = strtok(NULL,DELIM);
	}
	toks[pos] = NULL;
	return  toks;
}

void pwait(pid_t pid,int status){
	pid_t wpid;
	do{
		wpid = waitpid(pid,&status,WUNTRACED);
	}while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

int launch(char **args){
	pid_t pid = fork();
	int status;

	if(pid == 0){
		if(execvp(args[0],args) == -1){
			err_child();
		}else if(pid<0){
			err_fork();
		}else{
			pwait(pid,status);
		}
	}
}

int exec(char **args){
	if(args[0] == NULL){
		return 1;
	}

	for(int i = 0;i<num_builtins();++i){
		if(!strcmp(args[0],builtin_str[i])){
			return (*builtin_funcs[i])(args);
		}
	}
	return launch(args);
}