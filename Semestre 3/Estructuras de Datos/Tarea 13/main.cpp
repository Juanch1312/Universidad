#include "avltree.h"

using namespace std;

int main() {
  int i,total,num;
  AVLTree<int> myTree;
  default_random_engine generator(chrono::system_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> distribution(0,100000);
  auto dice=bind (distribution,generator);
  std::cout << "How many number do you want to introduce in the tree? "<<std::endl;
  std::cin >> total;
  std::cout << std::endl << "Inserting random data: " << std::endl;
  for(i=0;i<total;i++){
      num=dice();
      std::cout << "Date: " << num << std::endl;
      myTree.insertData(num);
  }
  std::cout << std::endl << "Preorder: "<<std::endl;
  myTree.parsePreOrder();
  std::cout << std::endl;
  cout << "Inorder: "<<std::endl;
  myTree.parseInOrder();
  std::cout << std::endl;
  std::cout << "Postorder: "<<std::endl;
  myTree.parsePostOrder();
  std::cout << std::endl << std::endl;
  std::cout << "Size of the left sub tree: " << myTree.getHeightLeft() << std::endl;
  std::cout << "Size of the right sub tree: " << myTree.getHeightRight() << std::endl;
  return 0;
}
