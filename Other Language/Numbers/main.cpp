#include <iostream>
#include <bitset>

int main(int argc, char** argv) {
	int num = 0;
	
	
	std::cout << "Input A Number: ";
	std::cin >> num;
	
	std::bitset<sizeof(char) * CHAR_BIT> binary(num);
	
	std::cout << "dec: " << num << std::endl;
	std::cout << "bin: " << binary << std::endl;
	std::cout << "oct: " << std::oct << num << std::endl; 
	std::cout << "hex: " << std::hex << num << std::endl; 
	return 0;
}
