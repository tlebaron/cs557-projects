** Content of the files **
- exec_code.c is C code to execute execve("/bin/shh"). Used to create the shellcode
- a.out is the compiled exec_code.c
- exploit.py print the exploit payload to crack the vuln executable
- mprotect.c is C code to execute mprotect(&stack, stack_len, all permission)
- shellcode.c is the C code to create and test the shellcode to execute execve("/bin/shh")
- shell is the compiled shellcode.c
- tmp is the printed payload from exploit.py
- vuln.c is a simple buffer overflow with gets which allow to overwrite the ret address
- vuln is the compiled vuln.c with canaries disabled
