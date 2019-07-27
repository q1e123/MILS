//
// Created by q1e123 on 26.07.2019.
//

#ifndef MILS_UTILS_H
#define MILS_UTILS_H

#define UI unsigned int

void bufgrow(char *buf, int *bufsize, const int grow);

char *readline();
char **split(char *line, const char *DELIM);

int launch(char **args);
void pwait(pid_t pid,int status);
int exec(char **args);

#endif //MILS_UTILS_H
