#pragma once

#include <string>

using std::string;

void SStringPrintf(string* output, const char* format, ...);
void StringAppendF(string* output, const char* format, ...);
string StringPrintf(const char* format, ...);
