#pragma once
#include <string>
#pragma comment(lib, "BitSync.lib")

namespace BitSync {

	void init_ctx();

	std::tuple<int, std::string, std::string, std::string> license_ctx(std::string license);
	std::string filestream(std::string license);

}


