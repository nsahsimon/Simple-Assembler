all: assembler
#./assembler test.asm

assembler: assembler.c asm_parser.o
	clang assembler.c asm_parser.c -o assembler
#gcc assembler.c asm_parser.o -o assembler

# Generate asm_parser.o object file
asm_parser.o: asm_parser.c
	clang -c asm_parser.c -o asm_parser.o

clean:
# remove all the object files
	rm -rf *.o
# remove all the executable files
	rm -rf *.exe

clobber: clean
# remove the assembler executable file
	rm -rf assembler 

