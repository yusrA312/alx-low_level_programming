#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"
void display_elf_header(const char* filename) {
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(98);
	}

	Elf64_Ehdr elf_header;
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
		fprintf(stderr, "Error reading ELF header from: %s\n", filename);
		close(fd);
		exit(98);
	}

	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
		fprintf(stderr, "Not an ELF file: %s\n", filename);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", elf_header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", elf_header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d (Executable file)\n", elf_header.e_type);
	printf("  Entry point address:               0x%lx\n", elf_header.e_entry);

	close(fd);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	display_elf_header(argv[1]);

	return 0;
}

