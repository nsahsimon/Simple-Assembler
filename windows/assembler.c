#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

int main(int argc, char** argv) {

   char* filename = NULL ;                 // name of ASM file
   char  program [ROWS][COLS];             // ASM file line-by-line
   char  program_bin_str [ROWS][17] ;      // instructions converted to a binary string
   unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)
   
   //Initializing array elements of prgram to null
   int i, j;
   for(i = 0; i < ROWS; i++) {
   		for(j = 0; j < COLS; j++ ) {
   			 program [i][j] = '\0';
		   }
   }
   
   //Initializing array elements of program_bin_str to null
   for(i = 0; i < ROWS; i++) {
   		for(j = 0; j < 17; j++ ) {
   			 program_bin_str [i][j] = '\0';
		   }
   }
   
   
   //checking if the assembly program filename is passed into the main function
   if(argc != 2) {
   	printf("error1: usage: ./assembler <assembly_file.asm>\n");
   	return 0;
   }
   
   
   //Retrieve the assembly program filename
   filename = argv[1];
   printf("Assembly program filename: %s\n", filename);
    
	//Read .asm file
	int val = read_asm_file(filename, program);
	
	//looping through all the rows in the assembly program
	int row_index;
	for(row_index = 0; row_index < ROWS; row_index++) {
		parse_instruction(program[row_index], program_bin_str[row_index]);
		int instr_as_bin = str_to_bin(program_bin_str[row_index]);
		program_bin[row_index] = instr_as_bin;
		printf("Instruction %d  : 0x%X\n", row_index + 1, program_bin[row_index]);
	}
	
	for(row_index = 0; row_index < ROWS; row_index++) {
		printf("0x%X\n",program_bin[row_index]);
	}	
	
	
	
	printf("Ready to write instructions to object file");
	write_obj_file(filename, program_bin);

}

