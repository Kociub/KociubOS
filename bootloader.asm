bits 32
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002            ;magic
        dd 0x00                  ;flags
        dd - (0x1BADB002 + 0x00) ;checksum. should be zero

global start
extern kmain	        ;kmain is defined in the c file

start:
  cli 			;block interrupts
  call kmain
  hlt		 	;halt the CPU
