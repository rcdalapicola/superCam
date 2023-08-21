#include <vector>
#include <string>

namespace sc {
    void test();
    void sortString(std::vector<std::string>& stringList);
    void printStrings(const std::vector<std::string>& inputList);
    unsigned char* mainGL(int windowWidth, int windowHeight);
    void process(unsigned int image, int rows, int columns, int channels);
}