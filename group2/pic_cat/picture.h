#include <vector>
#include <string>

#include "ptr.h"

class PicBase {};

class StringPic: public PicBase {};
class FramePic: public PicBase {};
class VCatPic: public PicBase {};
class HCatPic: public PicBase {};

class Picture {
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<PicBase> p;
};
