#include <ostream>
#include <vector>
#include <string>

#include "ptr.h"

class PicBase {
protected:
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

private:
    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual ht_sz disply(std::ostream&, ht_sz, bool) const = 0;
};

class StringPic: public PicBase {
private:
    std::vector<std::string> data;    
    StringPic(const std::vector<std::string>& v): data(v) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

class FramePic: public PicBase {
private:
    Ptr<PicBase> p;
    FramePic(const Ptr<PicBase>& pic): p(pic) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

class VCatPic: public PicBase {
private:
    Ptr<PicBase> top, bottom;
    VCatPic(const Ptr<PicBase>& t, const Ptr<PicBase>& b): top(t), bottom(b) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

class HCatPic: public PicBase {
private:
    Ptr<PicBase> left, right;
    HCatPic(const Ptr<PicBase>& l, const Ptr<PicBase>& r): left(l), right(r) {}

    wd_sz width() const;
    ht_sz height() const;
    void display(std::ostream&, ht_sz, bool) const;
};

class Picture {
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<PicBase> p;
};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream operator<<(std::ostream&, const Picture&);
