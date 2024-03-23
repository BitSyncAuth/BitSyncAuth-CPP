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

std::string appid = skCrypt("6175E58F666D8370B7366A98E6D3F8ECA16920A492D67E4B85D342042EDAB3CD").decrypt();
std::string enckey = skCrypt("10436219D855955E9C02C3A5C8849A202F772DAF183C8683E7722DD286ACE6E0A7FD4550A587567E4DB24A26A24932BE939C12989EE7DA3C62A77F03790894D9").decrypt();



