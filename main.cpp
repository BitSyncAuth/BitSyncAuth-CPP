#include <iostream>
#include <Windows.h>
#include <iostream>
#include "includes/BitSync.h"

/*This project contains code licensed to bitsync.cc, Please purchase a valid subscription before implementing this code

discord: https://discord.gg/DDrRr6jhG6 */

int main() {

    BitSync::init_ctx(appid.c_str());

    std::cout << skCrypt("\n   Enter key -> ");

    std::string key;
    std::cin >> key;
    
    auto resp = BitSync::license_ctx(key);

    if (std::get<0>(resp) == 0x4253) {

        std::cout << skCrypt("\n   Welcome : ") << std::get<1>(resp); 
        std::cout << skCrypt("\n   Product : ") << *std::get<2>(resp);
        std::cout << skCrypt("\n   Expiry : ") << *std::get<3>(resp);

        //BitSync::log(skCrypt("Hello World").decrypt()); 
        //BitSync::filestream(key); 
    }

    else {

        std::cout << skCrypt("\n   Error : ") << std::get<1>(resp); 
    }

    _getwch();
}
