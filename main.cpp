//*****************************************************************************
//
//  prog3.cpp
//  CSCI 463 Assignment 3
//
//  Created by Daniel Widing (z1838064)
//
//*****************************************************************************
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

#include "hex.h"
#include "memory.h"

/**
 * Handles args, creates memory, runs memory test, loads file into memory 
 * 
 * @param argc: number of command line arguments
 * @param argv: array of argument values
 * 
 * @return 0: if executed without failure
 **/
int  main(int argc, char** argv)
{
	//Outputs usage error if improper argument amount
	if (argc != 3)
	{
		std::cerr << "Invalid argument count.\nUsage: {hex_bytes_to_use} {file}\n";
		exit(0);
	}

	else if (std::stoul(argv[1], 0, 16) < std::stoul("0x1000", 0, 16) || std::stoul(argv[1], 0, 16) > std::stoul("0x10000", 0, 16))
	{
		std::cerr << "Invalid memory amount. Must be between \"0x1000\" and \"0x10000\"\nUsage: {hex_bytes_to_use} {file}\n";
		exit(0);
	}

	//Creates empty memory of provided size and dumps memory
	memory mem(std::stoul(argv[1], 0, 16)); 
	mem.dump(); 

	//Outputs usage error if unable to load file, dumps loaded file in memory otherwise
	if (!mem.load_file(argv[2]))
	{
		std::cerr << "Unable to load file.\nUsage: {hex_bytes_to_use} {file}\n";
		exit(0);
	}
	mem.dump(); 

	std::cout << mem.get_size() << std::endl; 
	std::cout << hex32(mem.get8(0)) << std::endl; 
	std::cout << hex32(mem.get16(0)) << std::endl; 
	std::cout << hex32(mem.get32(0)) << std::endl; 

	std::cout << hex0x32(mem.get8(0)) << std::endl; 
	std::cout << hex0x32(mem.get16(0)) << std::endl; 
	std::cout << hex0x32(mem.get32(0)) << std::endl; 
	
	std::cout << hex8(mem.get8(0)) << std::endl; 
	std::cout << hex8(mem.get16(0)) << std::endl; 
	std::cout << hex8(mem.get32(0)) << std::endl; 
	std::cout << hex0x32(mem.get32(0x1000)) << std::endl; 

	//Sets bits at different addresses and then dumps memory
	mem.set8(0x10, 0x12); 
	mem.set16(0x14, 0x1234); 
	mem.set32(0x18, 0x87654321); 
	mem.dump(); 
	
	return 0; 
}

