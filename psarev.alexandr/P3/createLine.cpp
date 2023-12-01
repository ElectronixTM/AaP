#include "createLine.hpp"
#include <cstring>

size_t psarev::createTaskLine(char* line1, const char* line2, size_t len1, size_t len2, char*& lineRes)
{
  size_t elemNum = 0;
  for (size_t i = 0; i < len2; i++) {
    if ((std::strchr(line1, line2[i]) == NULL) && (std::strchr(lineRes, line2[i]) == NULL)) {
      lineRes[elemNum++] = line2[i];
    }
  }

  for (size_t j = 0; j < len1; j++) {
    if ((std::strchr(line2, line1[j]) == NULL) && (std::strchr(lineRes, line1[j]) == NULL)) {
      lineRes[elemNum++] = line1[j];
      if (elemNum % 10 == 0) {
        char* extLineRes = new char[elemNum + 10] {};
        for (size_t k = 0; k < elemNum; k++) {
          extLineRes[k] = lineRes[k];
        }
        delete[] lineRes;
        lineRes = extLineRes;
      }
    }
  }
  return elemNum;
}
