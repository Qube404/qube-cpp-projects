#include <string>

#include "picture.h"

using namespace std;

void PicBase::pad(std::ostream& os, wd_sz beg, wd_sz end) {
    while (beg != end) {
        os << " ";
        ++beg;
    }
}

Picture frame(const Picture& pic) {
    return new FramePic(pic.p);
}

Picture frame(const Picture& pic, char c, char f, char s) {
    return new FramePic(pic.p, c, f, s);
}

Picture hcat(const Picture& l, const Picture& r) {
    return new HCatPic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b) {
    return new VCatPic(t.p, b.p);
}

Picture::Picture(const vector<string>& v): p(new StringPic(v)) {}

std::ostream& operator<<(std::ostream& os, const Picture& picture) {
    const PicBase::ht_sz ht = picture.p->height();

    for (PicBase::ht_sz i = 0; i != ht; i++) {
        picture.p->display(os, i, false);
        os << endl;
    }

    return os;
}

PicBase::wd_sz StringPic::width() const {
    PicBase::wd_sz n = 0;
    for (PicBase::ht_sz i = 0; i != data.size(); ++i) {
        n = max(n, data[i].size());
    }

    return n;
}

void StringPic::display(ostream& os, ht_sz row, bool do_pad) const {
    wd_sz start = 0;

    if (row < height()) {
        os << data[row];
        start = data[row].size();
    }

    if (do_pad) {
        pad(os, start, width());
    }
}

void VCatPic::display(ostream& os, ht_sz row, bool do_pad) const {
    wd_sz w = 0;
    if (row < top->height()) {
        top->display(os, row, do_pad);
        w = top->width();
    } else if (row < height()) {
        bottom->display(os, row - top->height(), do_pad);
        w = bottom->width();
    }

    if (do_pad) {
        pad(os, w, width());
    }
}

void HCatPic::display(ostream& os, ht_sz row, bool do_pad) const {
    left->display(os, row, do_pad || row < right->height());
    right->display(os, row, do_pad);
}

void FramePic::display(ostream& os, ht_sz line, bool do_pad) const {
    if (line >= height()) {
        if (do_pad) {
            pad(os, 0, width());
        }
    } else {
        if (line == 0 || line == height() - 1) {
            os << c << string(width() - 2, f) << c;
        } else if (line == 1 || line == height() - 2) {
            os << s;
            pad(os, 1, width() - 1);
            os << s;
        } else {
            os << s << ' ';
            p->display(os, line - 2, true);
            os << ' ' << s;
        }
    }
}
