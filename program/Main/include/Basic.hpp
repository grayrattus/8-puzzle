#ifndef Basic_HPP
#define Basic_HPP

#include <string>

using namespace std;

class Basic {
public:
    Basic();
    string giveVoice();
    Basic(const Basic& orig);
    virtual ~Basic();
private:

};

#endif
