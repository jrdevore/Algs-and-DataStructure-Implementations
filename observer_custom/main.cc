#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include <algorithm>

#include "includes/input_parser.h"

// void ComputeIntervalUnions(SortingExercises *sorting_exerciser, int test_collection_size = 0) {
//     std::cout << "--->>--->> ch14-Sorting::ComputeIntervalUnions() - Randomized Input" << std::endl;
//     std::default_random_engine gen((std::random_device())());
//     for (int times = 0; times < 10; ++times) {
//         int n;
//         if (test_collection_size == 0) {
//             std::uniform_int_distribution<int> dis(1, 10000);
//             n = dis(gen);
//         } else {
//             n = test_collection_size;
//         }

//         std::vector<Interval> interval_list;
//         for (int i = 0; i < n; ++i) {
//             Interval temp;
//             std::uniform_int_distribution<int> zero_or_one(0, 1);
//             std::uniform_int_distribution<int> dis1(0, 9999);
//             temp.leftp.closed = zero_or_one(gen), temp.leftp.val = dis1(gen);
//             std::uniform_int_distribution<int> dis2(temp.leftp.val + 1,
//                                                     temp.leftp.val + 100);
//             temp.rightp.closed = zero_or_one(gen), temp.rightp.val = dis2(gen);
//             interval_list.emplace_back(temp);
//         }
//         // sorting_exerciser->PrintCollection(interval_list, "Intervals: ");
//         std::vector<Interval> ret = sorting_exerciser->ComputeIntervalUnions(interval_list);
//         // sorting_exerciser->PrintCollection(ret, "Interval Union Result: ");
//         for (size_t i = 1; i < ret.size(); ++i) {
//             assert(ret[i - 1].rightp.val < ret[i].leftp.val ||
//                   (ret[i - 1].rightp.val == ret[i].leftp.val && !ret[i - 1].rightp.closed &&
//                     !ret[i].leftp.closed));
//         }
//     }
// }

void TestInputParse(const std::string &input_file) {
    std::shared_ptr<InputParser> parser(new InputParser());
    parser->ReadFile(input_file);
}

void TestUserCreation() {
    std::vector<std::string> user_name_list {"Hello James", "Goodbye Jon", "Nurburgring"};
    std::vector<int> user_id_list {1, 2, 3};
    std::vector<std::pair<std::string, int>> user_list;
    user_list.reserve(user_name_list.size());
    std::vector<std::unique_ptr<User>> users = {};
    std::transform(user_name_list.begin(), user_name_list.end(), user_id_list.begin(),
                   std::back_inserter(user_list), [](std::string a, int b) {
                    return std::make_pair(a, b); });

    for (auto &x : user_list) {
        auto new_user(std::make_unique<User>(x.first, x.second));
        users.push_back(std::move(new_user));
    }

    for (auto &user : users) {
        std::cout << "--->>--->> main:: User( " << *user << " )" << std::endl;
        std::cout << "--->>--->> main::TOSTRING User( " << user->toString() << " )" << std::endl;
        if (user->Id() > 2) {
            user->SetId(100);
            std::cout << "--->>--->> main::UpdateID User( " << *user << " )" << std::endl;
        }
    }
}

void run_tests(const std::string &input_file) {
    TestUserCreation();
    TestInputParse(input_file);
}

// valgrind --leak-check=full --show-leak-kinds=all ./custom_observer
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cout << "--->>--->> main:: Incorrect Argument count "  << std::endl;
        return 1;
    }
    std::string input_file = argv[1];
    run_tests(input_file);
    // std::shared_ptr<User> first_user(new User("James", 1));
    // std::shared_ptr<UserService> first_service(new UserService("JService"));
    return 0;
}