#include "includes/dummy_class.h"
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

#include <functional>

#include <memory>
#include <set>

bool TestOneSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestOneSingle" << std::endl;
    return true;
}

bool TestTwoSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestTwoSingle" << std::endl;
    return true;
}

bool TestThreeSingle(std::unique_ptr<DummyClass> &dummy_class, const std::string &device_handle) {
    std::cout << "--->>--->> main::TestThreeSingle" << std::endl;
    return true;
}

bool TestSuiteOne(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteOne()" << std::endl;
    return true;
}

bool TestSuiteTwo(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteTwo()" << std::endl;
    return true;
}

bool TestSuiteThree(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device_blacklist = {}) {
    std::cout << "--->>--->> main:: TestSuiteThree()" << std::endl;
    return true;
}

bool SingleDevTest(std::unique_ptr<DummyClass> &dummy_class, const std::set<std::string> &device = {}) {
    std::cout << "======= main:: SingleDevTest " << std::endl;
    return true;
}

bool functionptr_test(int a, std::string x) {
    std::cout << "======= main::bool functionptr_test(a: " << a << ", string: " << x << ") CALLED! " << std::endl;
    return true;
}

bool functionptr_test_two(int a, std::string x) {
    std::cout << "======= main::bool functionptr_test_two(a: " << a << ", string: " << x << ") CALLED! " << std::endl;
    return true;
}

void usage(){
    std::cout<<"Usage:: \"./input_parse <dev> <test> \n";
}
// /////////////////////////
// args
// -device "/dev/sdb" or blank
// -devicelist "/dev/sdc, /dev/sdb"
// -test "A" (A or B or C or Blank)
// -blacklist "/dev/sdc, /dev/sdb"
// valgrind --leak-check=full --show-leak-kinds=all ./input_parse
// http://devdocs.io/cpp/language/main_function
// https://msdn.microsoft.com/en-us/library/17w5ykft.aspx
// http://courses.cms.caltech.edu/cs11/material/c/mike/misc/cmdline_args.html
// http://stackoverflow.com/questions/5272550/c-command-line-parameters
// http://stackoverflow.com/questions/15344714/convert-command-line-argument-to-string
// http://www.cplusplus.com/forum/articles/13355/
int main(int argc, char const *argv[]) {
    std::map<std::string, std::function<bool(std::unique_ptr<DummyClass> &, const std::set<std::string> &)>> function_map_;
    function_map_["A"] = TestSuiteOne;
    function_map_["B"] = TestSuiteTwo;
    function_map_["C"] = TestSuiteThree;
    function_map_["D"] = SingleDevTest;
    std::unique_ptr<DummyClass> dummy_class(new DummyClass());
    std::set<std::string> device_blacklist {};
    std::string target_device = "";

    if (argc < 2 || argc > 3) {
        std::cout<<"INCORRECT AMOUNT OF ARGUMENTS"<<std::endl;
        usage();
        exit(EXIT_FAILURE);
    }

    target_device = argv[1];
    if (target_device.empty()) {
         std::cout << "======= main:: cannot provide empty device! " << std::endl;
         return 1;
    }

    std::string target_test = argc == 3 ? argv[2] : "";
    if (!target_test.empty()) {
        std::transform(target_test.begin(), target_test.end(), target_test.begin(), ::tolower);
    } else {
        target_test = "default";
    }

    std::cout << "======= main:: target_test: " << target_test << std::endl;
    // auto algo_iter_ = algorithm_map_.find(primary_store_value.algorithm);
    // if (algo_iter_ != algorithm_map_.end()) {
    //     /// map pointer @algo_iter_->second points at a function
    //     /// dereference && call with appropriate parameters
    //     /// ex) second == &Sha1Integrity(std::string value_str, std::string tag_str)
    //     tag_cmp_result = (this->*(algo_iter_->second))(valueString, primary_store_value.tag); //NOLINT
    //     if (!tag_cmp_result) {
    //         results->push_back(it->Key());
    //     }
    // }
    // switch (target_test) {
    //     case "custom" : if (bracket_stack.top() == '[') {
    //                 bracket_stack.pop();
    //                 continue;
    //             }
    //     case '}' : if (bracket_stack.top() == '{') {
    //                 bracket_stack.pop();
    //                 continue;
    //             }
    //     case ')' : if (bracket_stack.top() == '(') {
    //                 bracket_stack.pop();
    //                 continue;
    //             }
    //     default: return false;


    // if (device_path == 1) {
    //     function_map_["A"] (dummy_class, device_blacklist);
    // } else if (device_path == 2) {
    //     function_map_["B"] (dummy_class, device_blacklist);
    // } else {
    //     std::cout << "======= nuffin"<< std::endl;
    // }

    return 0;
}