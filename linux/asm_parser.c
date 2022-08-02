#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"

/* to do - implement all the functions in asm_parser.h */

int read_asm_file(char* filename, char program [ROWS][COLS]){
	printf("Reading %s\n", filename);
	int row_index;
	int col_index;
 	FILE *asmFile;
	asmFile = fopen(filename, "r");
	if(!asmFile) {
		printf("error2: read_asm_file() failed\n", filename);
		return 2;
	}
	
	//Getting the characters in each line
	for(row_index = 0; row_index < ROWS; row_index ++) {
		if( fgets(program[row_index], COLS, asmFile) == NULL ) {

		program[row_index][0] = '\0';
		}
		
		//get index first occurrence index of '\n' - newline character
		int first_index;
		int count;
		for(count = 0; count < COLS; count++) {
			if(program[row_index][count] == '\n') {
				//replacing the first occuring '\n' with '\0'
				program[row_index][count] = '\0';
				break;
			} else if(count == COLS - 1) {
				program[row_index][COLS - 1] = '\0';
				break;
			} else {
				
			}
		}
		
		printf("%s\n", program[row_index]);
	}
	
	return 0;
	
}

int parse_instruction   (char* instr, char* instr_bin_str) {
	printf("Parsing instruction... : %s\n", instr);
	//Make sure the instructin is a valid one
	if(instr[0] != '\0'){
		char* rest = (char*)malloc(sizeof(instr));
		char* opcode = strtok_r(instr, " ", &rest);
		printf("OPCODE: %s\t ,REST: %s\n", opcode, rest);
		
		//Perform appropriate operations for the different opcodes
			if(0 == strcmp(opcode, "ADD")){
				//do something
				printf("parsing ADD instruction...\n");
				parse_add(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "AND")){
				//do something
				printf("parsing AND instruction...\n");				
				parse_and(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "MUL")){
				//do something
				printf("parsing MUL instruction...\n");
				parse_mul(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "SUB")){
				//do something
				printf("parsing SUB instruction...\n");
				parse_sub(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "DIV")){
				//do something
				printf("parsing DIV instruction...\n");
				parse_div(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "OR")){
				//do something
				printf("parsing OR instruction...\n");
				parse_or(instr, instr_bin_str);
			}
			else if(0 == strcmp(opcode, "XOR")){
				//do something
				printf("parsing XOR instruction...\n");
				parse_xor(instr, instr_bin_str);
			}
			else {
				printf("error3: parse_instruction() failed\n");
				return 3;
			}
			
//			extracting registers
			printf("Parsing registers: \n");
//			char registerNums[3];
			int regIndex;
			for(regIndex = 0; regIndex < 3; regIndex++) {
				char registerNum = rest[1];
				switch(regIndex) {
					case 0:
						parse_reg(registerNum, instr_bin_str, 4);
						break;
					case 1:
						parse_reg(registerNum, instr_bin_str, 7);
						break;
					//SUB-OPCODE
					case 2:
						parse_reg(registerNum, instr_bin_str, 13);
						break;
				}
				
//				memcpy(&registerNums[regIndex], &registerNum, sizeof(char));
				printf("reg%d : %c \t", regIndex + 1 , registerNum);
//				Uncomment the line below. This might not work!!!
//				char* token = strtok_r(rest, " ", &rest);	
				strtok_r(rest, " ", &rest);
			
			}
			printf("\n");
			
		return 0;
	} else {
		printf("error3: parse_instruction() failed.\n");
		return 3;
	}
	
}

int parse_add (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '0';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '0';
	instr_bin_str[12] = '0';
	
	return 0;
	
}

int parse_mul (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '0';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '0';
	instr_bin_str[12] = '1';
	
	return 0;

	
}

int parse_sub (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '0';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '1';
	instr_bin_str[12] = '0';
	
	return 0;

}

int parse_div (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '0';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '1';
	instr_bin_str[12] = '1';
	
	return 0;

}

int parse_and (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '1';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '0';
	instr_bin_str[12] = '0';
	
	return 0;	
	
}

int parse_or (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '1';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '1';
	instr_bin_str[12] = '0';
	
	return 0;

}

int parse_xor (char* instr, char* instr_bin_str) {
	//populate binary opcode fields
	instr_bin_str[0] = '0';
	instr_bin_str[1] = '1';
	instr_bin_str[2] = '0';
	instr_bin_str[3] = '1';
	
	//populate binary sub-opcode field
	instr_bin_str[10] = '0';
	instr_bin_str[11] = '1';
	instr_bin_str[12] = '1';
	
	return 0;
	
}

int parse_reg(char reg_num, char* instr_bin_str, int startIndex) {
	switch(reg_num){
		case '0':
			instr_bin_str[startIndex] = '0';
			instr_bin_str[startIndex + 1] = '0';
			instr_bin_str[startIndex + 2] = '0';
			break;
		case '1':
			instr_bin_str[startIndex] = '0';
			instr_bin_str[startIndex + 1] = '0';
			instr_bin_str[startIndex + 2] = '1';
			break;
		case '2':
			instr_bin_str[startIndex] = '0';
			instr_bin_str[startIndex + 1] = '1';
			instr_bin_str[startIndex + 2] = '0';
			break;
		case '3':
			instr_bin_str[startIndex] = '0';
			instr_bin_str[startIndex + 1] = '1';
			instr_bin_str[startIndex + 2] = '1';
			break;
		case '4':
			instr_bin_str[startIndex] = '1';
			instr_bin_str[startIndex + 1] = '0';
			instr_bin_str[startIndex + 2] = '0';
			break;
		case '5':
			instr_bin_str[startIndex] = '1';
			instr_bin_str[startIndex + 1] = '0';
			instr_bin_str[startIndex + 2] = '1';
			break;
		case '6':
			instr_bin_str[startIndex] = '1';
			instr_bin_str[startIndex + 1] = '1';
			instr_bin_str[startIndex + 2] = '0';
			break;
		case '7':
			instr_bin_str[startIndex] = '1';
			instr_bin_str[startIndex + 1] = '1';
			instr_bin_str[startIndex + 2] = '1';
			break;
		default: 
			printf("error5: parse_reg() failed\n");
			return 5;
			break;
	}
	return 0;
}

unsigned short int str_to_bin (char* instr_bin_str) {
   	char* str_part;
	int result = strtol(instr_bin_str, &str_part, 2);
	if(result == 0) {
		printf("error6: str_to_bin() failed\n");
		return 6;
	} 
	else {
		return result;
	}
   }
   
int write_obj_file (char* filename, unsigned short int program_bin[ROWS]) {
	printf("Writing generated object file...\n");
	int filenameLength = strlen(filename);
	if(sizeof(filename) == 0) {
		printf("error7: write_obj_file() failed");
		return 7;
	}
	printf("Input filename: %s, length: %d \n", filename, filenameLength);
	char objectFilename[strlen(filename)];
	char newExtension[4] = "obj";
//	int i;
//	for(i = 0; i < strlen(filename) - 3; i++) {
//		objectFilename[i] = filename[i];
//	}
	memcpy(objectFilename, filename, strlen(filename) - 3);
	strcat(objectFilename, newExtension);
	
//	objectFilename[filenameLength - 3] = 'b';
//	objectFilename[filenameLength - 2] = 'i';
//	objectFilename[filenameLength - 1] = 'n';
	printf("The ouput filename is: %s, length: %d \n", objectFilename, strlen(objectFilename));
	
	FILE *fptr = fopen(objectFilename, "wb");
	unsigned short int header = 51934; //decimal equivalent of 0xCADE
	printf("Size of header: %d\n", sizeof(header));
	fwrite(&header, sizeof(header), 1, fptr);
//	fclose(fptr);
//	return 0;
	unsigned short int address = 0;
	printf("Size of address: %d\n", sizeof(address));
	fwrite(&address, sizeof(address), 1, fptr);
	unsigned short int lines = 7;
	printf("Size of lines: %d\n", sizeof(lines));
	fwrite(&lines, sizeof(lines), 1, fptr);
	int line;
	for(line = 0; line < lines; line++) {
		printf("Writing line %d to file\n", line);
		unsigned short int instr = program_bin[line]; 
		fwrite(&instr, sizeof(instr), 1, fptr);
	}
	fclose(fptr);
	return 0;
}


   
