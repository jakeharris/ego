#include <string>
#include <sstream>
#include <vector>

namespace ego {
  class Helpers {
    public:
    std::vector<std::string> &separate(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
  
    std::vector<std::string> separate(const std::string &s, char delim) {
        std::vector<std::string> elems;
        separate(s, delim, elems);
        return elems;
    }
  };
}

