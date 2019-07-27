//
// Created by q1e123 on 27.07.2019.
//

#ifndef MILS_BUILTIN_H
#define MILS_BUILTIN_H

int mils_cd(char **args);
int mils_help(char **args);
int mils_exit(char **args);

char *builtin_str[];

int (*builtin_funcs[])(char**);

int num_builtins();
#endif //MILS_BUILTIN_H
