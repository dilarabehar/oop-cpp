#pragma once
#include <windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
#pragma comment(lib, "user32.lib")
class Licance
{
public:
	int serialKey{};

	
    static int createKey(SYSTEM_INFO siSysInfo, const char* s);
    static int create_db(const char* s);
    static int table4Key(const char* s);
    static int controlKey(const char* s, int key);
    static int callback(void* NotUsed, int argc, char** argv, char** ColName);
    
};


/*
typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;          // Obsolete field...do not use
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;
*/

