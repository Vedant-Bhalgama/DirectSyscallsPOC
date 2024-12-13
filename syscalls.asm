.code
	NtOpenProcess proc
			mov r10, rcx
			mov eax, 26h
			syscall
			ret
	NtOpenProcess endp

	NtAllocateVirtualMemory proc
			mov r10, rcx
			mov eax, 18h
			syscall
			ret
	NtAllocateVirtualMemory endp

	NtWriteVirtualMemory proc
			mov r10, rcx
			mov eax, 3ah
			syscall
			ret
	NtWriteVirtualMemory endp


	NtCreateThreadEx proc
			mov r10, rcx
			mov eax, 00c2h
			syscall
			ret
	NtCreateThreadEx endp

end
