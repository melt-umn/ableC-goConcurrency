/* Primitive value / type definitions and interface for value/list operations.
 * Original Authors: Ken Schiller, Patrick Stephen, Quinn Radich
 * Current Author: Patrick Stephen
 */

#ifndef VALUE_H
#define VALUE_H

#include <stdbool.h>

/**************
* Structures. *
**************/

// Enumerated type for the different types of tokens.
typedef enum {
    charType,
    signedCharType,
    unsignedCharType,
    shortType,
    unsignedShortType,
    intType,
    unsignedIntType,
    longType,
    unsignedLongType,
    longlongType,
    unsignedLongLongType,
    floatType,
    doubleType,
    longDoubleType,
    boolType,
    pointerType
} VALUE_TYPE;

// Union struct to hold the value for any type of token.
typedef struct __Value {
    VALUE_TYPE type; 
    union {

        char charValue;
        signed char signedCharValue;
        unsigned char unsignedCharValue;

        short shortValue;
        //short int shortIntValue;
        //signed short signedShortValue;
        //signed short int signedShortIntValue;
        unsigned short unsignedShortValue;
        //unsigned short int unsignedShortIntValue;

        int intValue;
        //signed signedValue;
        //signed int signedIntValue;
        //unsigned unsignedValue;
        unsigned int unsignedIntValue;

        long longValue;
        //long int longIntValue;
        //signed long signedLongValue;
        //signed long int signedLongIntValue;
        unsigned long unsignedLongValue;
        //unsigned long int unsignedLongIntValue;
        long long longLongValue;
        //long long int longLongIntValue;
        //signed long long signedLongLongValue;
        //signed long long int signedLongLongIntValue;
        unsigned long long unsignedLongLongValue;
        //unsigned long long int unsignedLongLongIntValue;
        
        float floatValue;
        double doubleValue;
        long double longDoubleValue;
        
        bool boolValue;
        
        struct __Value *pointerValue;
    };
} Value;

#endif