#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(LinkedList* pArrayListPassenger, int* flagCargados);//hecho
int controller_loadFromBinary(LinkedList* pArrayListPassenger, int* flagCargados);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);//hecho
int controller_sortPassenger(LinkedList* pArrayListPassenger);//hecho
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


#endif
