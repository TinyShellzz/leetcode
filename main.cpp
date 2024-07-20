#include <iostream>
#include <vector>
#include "utils/ListNode.h"
#include "utils/basic_algorithms_example.h"
#include "utils/to_string.h"
#include "utils/TreeNode.h"

int main(int argc, char *argv[]) {
    TreeNode tree = "4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2";

    cout << tree.toString() << endl;

    return 0;
}