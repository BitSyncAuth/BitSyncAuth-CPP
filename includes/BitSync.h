#pragma once
#include <string>
#include "includes/skCrypter.h"
#pragma comment(lib, "BitSync.lib")

namespace BitSync {

	void init_ctx(std::string&& id);

	std::tuple<int, std::string, const std::string*, const std::string*, bool> license_ctx(std::string license);
	std::string filestream(std::string license);
	std::string log(std::string msg);
}

std::string appid = skCrypt("your_appid").decrypt();




