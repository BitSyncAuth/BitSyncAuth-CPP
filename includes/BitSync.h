#pragma once
#include <string>
#include "includes/skCrypter.h"
#pragma comment(lib, "BitSync.lib")

namespace BitSync {

	void init_ctx();
	void set_data(std::string&& id, std::string&& pubkey);

	std::tuple<int, std::string, const std::string*, const std::string*> license_ctx(std::string license);
	std::string filestream(std::string license);
}

std::string appid = skCrypt("your_appid").decrypt();
std::string enckey = skCrypt("your_enckey").decrypt();
