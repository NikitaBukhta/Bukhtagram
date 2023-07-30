#include "Logger.hpp"

std::string get_func_name(std::string func_info) {
    uint64_t end = func_info.find_first_of('(');
    uint64_t begin = func_info.find_last_of(':', end) + 1;

    return func_info.substr(begin, end - begin);
}

std::string get_class_name(std::string class_info) {
    uint64_t begin = class_info.find_last_of(':') + 1;

    return class_info.substr(begin);
}