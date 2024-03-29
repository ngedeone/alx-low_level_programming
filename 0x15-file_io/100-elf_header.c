#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 98;
    }

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(header)) != sizeof(header)) {
        fprintf(stderr, "Error: could not read ELF header from file %s\n", argv[1]);
        close(fd);
        return 98;
    }

    // Check magic number
    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: file %s is not an ELF file\n", argv[1]);
        close(fd);
        return 98;
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (header.e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  Data:                              ");
    switch (header.e_ident[EI_DATA]) {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[EI_OSABI]) {
        case ELFOSABI_NONE: printf("UNIX - System V\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header.e_type) {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  Entry point address:               0x%lx\n", header.e_entry);

    close(fd);
    return 0;
}
