#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"

#include <vector>


bool non_neg_prefix_sum(const std::vector<int>& lst, int n) {
    int prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        prefix_sum += lst[i];
        if (prefix_sum < 0) {
            return false;  
        }
    }
    return true;  
}

bool non_pos_prefix_sum(const std::vector<int>& lst, int n) {
    int prefix_sum = 0;
    for (int i = 0; i < n; ++i) {
        prefix_sum += lst[i];
        if (prefix_sum > 0) {
            return false;  
        }
    }
    return true; 
}

// Unit tests
TEST_CASE("Test non_neg_prefix_sum") {
    CHECK(non_neg_prefix_sum({1, -1, 1, -1}, 4) == true);  
    CHECK(non_neg_prefix_sum({1, -1, -1, 1}, 4) == false); 
    CHECK(non_neg_prefix_sum({1, 1, -1, -1, 1}, 5) == true); 
    CHECK(non_neg_prefix_sum({-1, 1, -1, 1}, 4) == false); 
    CHECK(non_neg_prefix_sum({}, 0) == true);  
    CHECK(non_neg_prefix_sum({1}, 1) == true);  
    CHECK(non_neg_prefix_sum({-1}, 1) == false); 
    CHECK(non_neg_prefix_sum({1, 1, 1}, 3) == true); 
    CHECK(non_neg_prefix_sum({-1, -1, -1}, 3) == false); 
    CHECK(non_neg_prefix_sum({1, -1, 1, -1, 1}, 5) == true); 
}

TEST_CASE("Test non_pos_prefix_sum") {
    CHECK(non_pos_prefix_sum({1, -1, 1, -1}, 4) == false);  
    CHECK(non_pos_prefix_sum({1, -1, -1, 1}, 4) == false);  
    CHECK(non_pos_prefix_sum({-1, -1, 1, 1}, 4) == true);  
    CHECK(non_pos_prefix_sum({1, 1, -1, -1}, 4) == false);  
    CHECK(non_pos_prefix_sum({}, 0) == true);                
    CHECK(non_pos_prefix_sum({1}, 1) == false);             
    CHECK(non_pos_prefix_sum({-1}, 1) == true);              
    CHECK(non_pos_prefix_sum({1, 1, 1}, 3) == false);       
    CHECK(non_pos_prefix_sum({-1, -1, -1}, 3) == true);     
    CHECK(non_pos_prefix_sum({1, -1, 1, -1, 1}, 5) == false); 
}







