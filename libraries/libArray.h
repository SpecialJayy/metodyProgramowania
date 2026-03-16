#ifndef LIBARRAY_H
#define LIBARRAY_H
#include <iosfwd>
#include <iostream>

void findMatch(double engineList[81][106][2], double unknownEngine[100][2]);

void applyEngine(double engineList[106][2], std::fstream& file);

void applyEngines(double engineList[81][106][2], std::fstream& file);

void printEngine(double engineList[106][2]);

void printEngines(double engineList[81][106][2]);


#endif //LIBARRAY_H