/**********************************************************************************************************************
 * Bukhtagram                                                                                                         *
 *                                                                                                                    *
 * Author: Bukhta Mykyta                                                                                              *
 *                                                                                                                    *
 * Copyright ©2023 Bukhta Mykyta                                                                                      *
 *                                                                                                                    *
 * This software is distributed under the following license:                                                          *
 *                                                                                                                    *
 * 1. This code may not be modified, redistributed, or used to create derivative works.                               *
 * 2. Any use of this code for commercial purposes is prohibited without prior written permission of the author.      *
 * 3. The author is not liable for any damages caused by the use of this software.                                    *
 * 4. Copies of this license or references to it must be included in all copies or significant parts of the software. *
 *                                                                                                                    *
 * For permission for commercial use, contact the author at the following address: nikita.bukhta.dev@gmail.com.       *
 **********************************************************************************************************************                                                                                                                    *
 */

#include "Logger.hpp"

std::string get_func_name(const std::string &func_info) {
    uint64_t end = func_info.find_first_of('(');
    uint64_t begin = func_info.find_last_of(':', end) + 1;

    return func_info.substr(begin, end - begin);
}

std::string get_class_name(const std::string &class_info) {
    uint64_t begin = class_info.find_last_of(':') + 1;

    return class_info.substr(begin);
}