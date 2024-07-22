#include <cstddef>
#include <functional>
#include <iostream>
#include <string>
#include <cstring>
#include <string_view>
#include <unordered_map>

using std::vector;
 /**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int highest = 0;
        int start = 0;

        if (s.length() == 0) {
            return 0;
        }
        int characters[256];
        memset(characters, -1, sizeof(characters));
//            std::cout << "test: " << characters[2] << std::endl;

//        std::unordered_map<char, int> characters;
        for (int i = 0; i < (int)s.length(); ++i) {
//            std::cout << "i: " << i << std::endl;
              auto index = characters[std::uint8_t(s[i])]; 
//            std::cout << "index: " << index << std::endl;
              if (index > -1 && index >= start) {
//                std::cout << s[i] << std::endl;
                auto length = i - start;
//                std::cout << "length: " << length << std::endl;
                if (length > highest) {
                    highest = length;
                }
                start = index + 1;
//                std::cout << "start: " << start << std::endl;
            }
            characters[std::uint8_t(s[i])] = i;
        }

        int length = s.length() - start;
//        std::cout << "last length: " << length << std::endl;
        if (length > highest) {
            highest = length;
        }

        return highest;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::int16_t medianIndex1 = -1;
        std::int16_t medianIndexLeft1 = -1;
        std::int16_t medianIndexRight1 = -1;
        double median1 = 0.0;

        auto length1 = nums1.size();
        if (length1 > 0) {
            if (length1 % 2 != 0) {
                medianIndex1 = length1 / 2; 
                medianIndexRight1 = medianIndexLeft1 = medianIndex1;
                median1 = nums1[medianIndex1];
            } else {
                medianIndexRight1 = length1 / 2;
                medianIndexLeft1 = medianIndexRight1 - 1;
                median1 = (double(nums1[medianIndexLeft1] + nums1[medianIndexRight1]))/2;
            }
        }
        
        std::int16_t medianIndex2 = -1;
        std::int16_t medianIndexLeft2 = -1;
        std::int16_t medianIndexRight2 = -1;
        double median2 = 0.0;

        auto length2 = nums2.size();
        if (length2 > 0) {
            if (length2 % 2 != 0) {
                medianIndex2 = length2 / 2;
                medianIndexRight2 = medianIndexLeft2 = medianIndex2;
                median2 = nums2[medianIndex2];
//                std::cout << "1-median2: " << median2 << std::endl;
            } else {
                medianIndexRight2 = length2 / 2;
                medianIndexLeft2 = medianIndexRight2 - 1;
                median2 = (double(nums2[medianIndexLeft2] + nums2[medianIndexRight2]))/2;
//                std::cout << "2-median2: " << median2 << std::endl;
            }
        }
        
        if (length1 == 0 && length2 == 0) {
            return 0.0;
        }

        if (median2 == median1) {
            return median1;
        }

        std::cout << medianIndexLeft2 << " " << medianIndexLeft1 << " " << medianIndexRight2 << " " << medianIndexRight1 << std::endl; 
        if (medianIndexLeft2 < medianIndexLeft1 && medianIndexRight2 > medianIndexRight1) {
            return median1;
        }

        if (length1 == 0) {
            return median2;
        }

        if (length2 == 0) {
            return median1;
        }

        if (length2 == 1 && length1 == 1) {
            return (median1 + median2) / 2;
        }

        auto lengthToCut = length2/2;
        if (lengthToCut == 0) {
            lengthToCut = 1;
        }

        if (median2 < median1) {
            std::vector<int> new_nums1(nums1.begin(), nums1.begin()+(length1 - lengthToCut));
            std::vector<int> new_nums2(nums2.begin()+(lengthToCut), nums2.end());
            
            std::cout << "1 size: " << new_nums1.size() << " " << new_nums2.size() << std::endl;
            std::cout << "1 value: " << new_nums1[0] << " " << new_nums2[0] << std::endl;
            if (nums1.size() == 1) {
                new_nums1.clear();
            }
            if (nums2.size() == 1) {
                new_nums2.clear();
            }
            return findMedianSortedArrays(new_nums1, new_nums2);
        } else {
            std::vector<int> new_nums1(nums1.begin()+(lengthToCut), nums1.end());
            std::vector<int> new_nums2(nums2.begin(), nums2.begin()+(lengthToCut));

            if (nums1.size() == 1) {
                new_nums1.clear();
            }
            if (nums2.size() == 1) {
                new_nums2.clear();
            }

            std::cout << "2 size: " << new_nums1.size() << " " << new_nums2.size() << std::endl;
            std::cout << "2 value: " << new_nums1[0] << " " << new_nums2[0] << std::endl;

            return findMedianSortedArrays(new_nums1, new_nums2);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto curr = l1;
        
        do {
            if (l2) {
                curr->val += l2->val + carry;
            } else {
                curr->val += carry;
            }
            
            if (curr->val >= 10) {
                carry = curr->val / 10;
                curr->val %= 10;
            } else {
                carry = 0;
            }
 
            if (!curr->next) { 
              if (l2 && l2->next) {
                curr->next = l2->next;
                l2 = nullptr;
              } else {
                if (carry) {
                    curr->next = new ListNode(carry);
                }
                break;
              }
            }
            curr = curr->next;
            if (l2) {
                l2 = l2->next;        
            } 

        } while (curr);

        return l1;
    }


};

int main(int argc, char **argv) {
    Solution s;
#if 0
    std::cout << "ans: " << s.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << "ans: " << s.lengthOfLongestSubstring("bbbb") << std::endl;
    std::cout << "ans: " << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << "ans: " << s.lengthOfLongestSubstring("dvdf") << std::endl;
    std::cout << "ans: " << s.lengthOfLongestSubstring("abba") << std::endl;
    std::cout << "ans: " << s.lengthOfLongestSubstring("au") << std::endl;

    std::vector<int> a = {1, 2};
    std::vector<int> b = {-1, 3};
    std::cout << "ans: " << s.findMedianSortedArrays(a, b) << std::endl;
    std::cout << "ans: " << s.findMedianSortedArrays(b, a) << std::endl;
#endif
    
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    auto ans = s.addTwoNumbers(l1, l2);
    std::cout << ans->val << ans->next->val << ans->next->next->val; 

    return 0;
}