#pragma once
#include <string>
#pragma comment(lib, "BitSync.lib")

namespace BitSync {

	bool init_ctx();

	std::string license_ctx(std::string license);
	std::string filestream(std::string license);
	std::string data(std::string license);
	std::string callback(std::string msg);


	std::string get_response_success();
	std::string get_response_invalid();
	std::string get_response_expired();
	std::string get_response_hwid();

	enum values {

		INVALID,
		EXPIRED,
		HWID,
		SUCCESS,
		UNKNOWN

	};
}