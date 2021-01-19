#include <iostream>
#include "triemap.cpp"
#include <fstream>

int main() {
    TrieMap<int> map;
    map["to"] = 7;
  	map["tea"] = 3;
  	map["ted"] = 4;
  	map["ten"] = 12;
  	map["A"] = 15;
  	// map["i"] = 11;
  	map["in"] = 5;
  	map["inn"] = 9;
	TrieMap<int> map2(map);
	//map2.exportToDot(std::cout);
	map["innn"] = 15;
	map2 = map;
	// map2.exportToDot(std::cout);
	// map2.remove("innn");
	// map2.exportToDot(std::cout);
	// map2.remove("inn");
	// map2.exportToDot(std::cout);
	map2.remove("innn");
	map2.exportToDot(std::cout);
    return 0;
}