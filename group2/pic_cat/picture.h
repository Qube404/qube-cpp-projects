#ifndef GUARD_picture_h
#define GUARD_picture_h

#include <algorithm>
#include <ostream>
#include <vector>
#include <string>

#include "ptr.h"

class Picture;

// ---------------------------------------------------------------------- //

class PicBase {
friend std::ostream& operator<<(std::ostream&, const Picture&);
friend class FramePic;
friend class HCatPic;
friend class VCatPic;
friend class StringPic;

private:
    typedef std::vector<std::string>::size_type ht_sz;
    typedef std::string::size_type wd_sz;

    virtual wd_sz width() const = 0;
    virtual ht_sz height() const = 0;
    virtual void display(std::ostream&, ht_sz, bool) const = 0;

protected:
    static void pad(std::ostream& os, wd_sz beg, wd_sz end);
};

// ---------------------------------------------------------------------- //

class Picture {
friend Picture frame(const Picture&);
friend Picture hcat(const Picture&, const Picture&);
friend Picture vcat(const Picture&, const Picture&);
friend std::ostream& operator<<(std::ostream&, const Picture&);

public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<PicBase> p;
    Picture(PicBase* ptr): p(ptr) {}
};



Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

// ---------------------------------------------------------------------- //

class StringPic: public PicBase {
friend class Picture;

private:
    std::vector<std::string> data;    
    StringPic(const std::vector<std::string>& v): data(v) {}

    wd_sz width() const;
    ht_sz height() const { return data.size(); }
    void display(std::ostream&, ht_sz, bool) const;
};

// ---------------------------------------------------------------------- //

class FramePic: public PicBase {
friend Picture frame(const Picture&);

private:
    Ptr<PicBase> p;
    FramePic(const Ptr<PicBase>& pic): p(pic) {}

    wd_sz width() const { return p->width() + 4; }
    ht_sz height() const { return p->height() + 4;}
    void display(std::ostream&, ht_sz, bool) const;
};

// ---------------------------------------------------------------------- //

class VCatPic: public PicBase {
friend Picture vcat(const Picture&, const Picture&);

private:
    Ptr<PicBase> top, bottom;
    VCatPic(const Ptr<PicBase>& t, const Ptr<PicBase>& b): top(t), bottom(b) {}

    wd_sz width() const { return std::max(top->width(), bottom->width()); }
    ht_sz height() const { return top->height() + bottom->height(); }
    void display(std::ostream&, ht_sz, bool) const;
};

// ---------------------------------------------------------------------- //

class HCatPic: public PicBase {
friend Picture hcat(const Picture&, const Picture&);

private:
    Ptr<PicBase> left, right;
    HCatPic(const Ptr<PicBase>& l, const Ptr<PicBase>& r): left(l), right(r) {}

    wd_sz width() const { return left->width() + right->width(); }
    ht_sz height() const { return std::max(left->height(), right->height()); }
    void display(std::ostream&, ht_sz, bool) const;
};

#endif
