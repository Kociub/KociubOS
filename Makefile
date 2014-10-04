all:
	nasm -f elf32 bootloader.asm -o bootloader.o
	gcc -m32 -c kernel.c -o kernel.o
	mkdir -p build
	ld -m elf_i386 -T link.ld -o build/kernel bootloader.o kernel.o
