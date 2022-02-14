#ifndef LOG
#define LOG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void logError(char* palavra);
void logAviso(char* palavra); //Warning
void logSucesso(char* palavra);
void logDestaqueC(char* palavra); // Ciano
void logDestaqueB(char* palavra); // Blue
void logDestaqueP(char* palavra); // Purple

#endif