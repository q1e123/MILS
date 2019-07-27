//
// Created by q1e123 on 26.07.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "../include/errors.h"

void perr(const char *msg){
	fprintf(stderr,"MILS: ");
	fprintf(stderr,msg);
	fprintf(stderr,"\n\n");
	exit(EXIT_FAILURE);
}

void err_alloc(){
	perr("ALLOCATION ERROR!");
}

void err_child(){
	perror("MILS: child error ->");
}

void err_fork(){
	perr("MILS: fork error ->");
}

void err_usage(char *msg){
	fprintf(stderr,"Usage: ");
	fprintf(stderr,msg);
	fprintf(stderr,"\n\n");
}