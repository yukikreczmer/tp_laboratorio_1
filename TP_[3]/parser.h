#ifndef PARSER_H_
#define PARSER_H_
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_UltimoId(FILE* pFile);
#endif
