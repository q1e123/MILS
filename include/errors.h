//
// Created by q1e123 on 26.07.2019.
//

#ifndef MILS_ERRORS_H
#define MILS_ERRORS_H

void perr(const char *msg);

void err_alloc();
void err_child();
void err_fork();

void err_usage(char *msg);
#endif //MILS_ERRORS_H
