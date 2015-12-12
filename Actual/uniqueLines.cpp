#include<iostream>
#include<vector>
#include <string>
#include <cassert>


std::vector<std::string>
printUniqueLines() 
{
  std::vector<std::string> linesStore;
  std::string input;

  while(std::getline(std::cin, input)) {
    bool matches = false;

    for(int i = 0; i < linesStore.size(); i++) {
      if(0 == linesStore[i].compare(input)) {
        matches = true;
        break;
      }
    }

    if(false == matches) {
      linesStore.push_back(input);
      std::cout << input << "\n";
    }
  }
  
  return linesStore;
}


/* Purpose: To check if the lines printed to std::cout
 * are all distinct.
 * Details: All the given input are unique
 * Test input: input1.txt
 */
void test1() {

  std::vector<std::string> store = printUniqueLines(); 

  for(int i = 0 ; i <  store.size(); i++) {
    for(int j = i+1; j <  store.size(); j ++) {
      assert(0 != store[i].compare(store[j]));
    }
  }

}

/* Purpose: To check if the printUniqueLines method 
 * prints just one line when all the input lines are equal.
 * Details: All the given input are equal.
 * Test input: input2.txt
 */
void test2() {

  std::vector<std::string> store = printUniqueLines(); 
  assert(1 == store.size());

}

/* Purpose: To check if the printUniqueLines method 
 * prints nothing when an empty file is  given.
 * Details: The input file is empty
 * Test input: input3.txt
 */
void test3() {

  std::vector<std::string> store = printUniqueLines(); 
  assert(0 == store.size());
}

/* Purpose: To check if the printUniqueLines method 
 * can handle unique lines but the line contain   whitespaces. 
 * Details: The testcase contains different version of ABC based on where the  whitespace is included
 * Test input: input4.txt
 */
void test4() {

  std::vector<std::string> store = printUniqueLines(); 

  for(int i = 0 ; i <  store.size(); i++) {
    for(int j = i+1; j <  store.size(); j ++) {
      assert(0 != store[i].compare(store[j]));
    }
  }
}

/* Purpose: To check if the printUniqueLines method 
 * can print just one line when all
 * the inputs are identical but containing whitespaces
 * Details: The testcase contains equal line but with whitespace included
 * Test input: input5.txt
 */
void test5() {
  std::vector<std::string> store = printUniqueLines(); 
  assert(1 == store.size());
}


int main(int argc, char** argv)
{

  //test1();
  //test2();
  //test3();
  //test4();
  //test5();

  printUniqueLines(); 
  return 0;
}
