#include "hashTable.h"
#include <iostream>
#include <functional>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
	if (argc != 2){
		std::cout << "Uso: " << argv[0] << " <arquivo .csv>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];

	hashTable<int,int> hash([](int i) { return i % NUMBER_OF_BUCKETS; });
	std::ifstream file(filename);
	std::string line;
	unsigned size = 0;
	while (std::getline(file, line)){
		int key = std::stoi(line.substr(0, line.find(',')));
		int value = std::stoi(line.substr(line.find(',') + 1));
		hash.insert(key, value);
		size++;
	}

	std::cout << "old size = " << size << std::endl;
	std::cout << "new size = " << hash.getSize() << std::endl;

	for (size_t i = 0; i < NUMBER_OF_BUCKETS; i++){
		for (auto elem : hash.getTable()[i]){
			std::cout << std::get<0>(elem) << "," << std::get<1>(elem) << std::endl;
		}
	}

	return 0;
}
