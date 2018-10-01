#ifndef LIB_LIBRARY_H __attribute__((visibility("default")));
#define LIB_LIBRARY_H

//#define MYSHARED_API
extern "C"{
    LIB_LIBRARY_H int Add(int a, int b);
}
void hello();

#endif