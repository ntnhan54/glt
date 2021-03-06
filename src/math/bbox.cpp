#include "bbox.h"

/*! \file
    \ingroup Math

    $Id: bbox.cpp,v 2.2 2004/05/03 03:44:50 nigels Exp $

    $Log: bbox.cpp,v $
    Revision 2.2  2004/05/03 03:44:50  nigels
    Added bounding box destructor
    Some reformatting of header

    Revision 2.1  2004/02/16 02:45:58  nigels
    Whitespace differences

    Revision 2.0  2004/02/08 19:44:12  nigels
    Migrate to CVS on sourceforge, revision incremented to 2.0

    Revision 1.2  2004/02/08 14:13:21  jgasseli
    Sorry, first commit included some minor changes to the Makefiles to make GLT compile without
    errors on my puter.

    - Jacques.

    Revision 1.19  2003/03/06 12:26:08  nigels
    *** empty log message ***

*/

#include <iostream>
using namespace std;

#include <math/matrix4.h>
#include <glt/viewport.h>

BoundingBox::BoundingBox()
: _defined(false)
{
}

BoundingBox::BoundingBox(const Vector &min,const Vector &max)
: _defined(true), _min(min), _max(max)
{
}

BoundingBox::~BoundingBox()
{
}

      bool   &BoundingBox::defined()       { return _defined; }
const bool    BoundingBox::defined() const { return _defined; }

      Vector &BoundingBox::min()           { return _min;     }
const Vector &BoundingBox::min() const     { return _min;     }
      Vector &BoundingBox::max()           { return _max;     }
const Vector &BoundingBox::max() const     { return _max;     }

Vector
BoundingBox::center() const
{
    return (_min+_max)*0.5;
}

real BoundingBox::width()  const { return _max[0] - _min[0]; }
real BoundingBox::height() const { return _max[1] - _min[1]; }
real BoundingBox::depth()  const { return _max[2] - _min[2]; }

void
BoundingBox::points(std::vector<Vector> &p) const
{
    p.clear();
    p.reserve(8);
    p.push_back(Vector(_min.x(), _min.y(), _min.z()));
    p.push_back(Vector(_min.x(), _min.y(), _max.z()));
    p.push_back(Vector(_min.x(), _max.y(), _min.z()));
    p.push_back(Vector(_min.x(), _max.y(), _max.z()));
    p.push_back(Vector(_max.x(), _min.y(), _min.z()));
    p.push_back(Vector(_max.x(), _min.y(), _max.z()));
    p.push_back(Vector(_max.x(), _max.y(), _min.z()));
    p.push_back(Vector(_max.x(), _max.y(), _max.z()));
}

void
BoundingBox::reset()
{
    _defined = false;
}

BoundingBox &
BoundingBox::operator+=(const Vector &p)
{
    if (!_defined)
    {
        _min = _max = p;
        _defined = true;
    }
    else
    {
        _min.vmin(p);
        _max.vmax(p);
    }

    return *this;
}

BoundingBox &
BoundingBox::operator+=(const vector<Vector> &p)
{
    if (!p.size())
        return *this;

    uint32 i = 0;

    if (!_defined)
    {
        _min = _max = p.front();
        _defined = true;
        i = 1;
    }

    for (; i<p.size(); i++)
    {
        _min.vmin(p[i]);
        _max.vmax(p[i]);
    }

    return *this;
}

BoundingBox &
BoundingBox::operator+=(const BoundingBox &box)
{
    if (!_defined && box._defined)
    {
        _min = box._min;
        _max = box._max;
        _defined = true;
        return *this;
    }

    if (_defined && box._defined)
    {
        _min.vmin(box._min);
        _max.vmax(box._max);
    }

    return *this;
}

BoundingBox &
BoundingBox::operator*=(const BoundingBox &box)
{
    if (_defined && box._defined)
    {
        _min.vmax(box._min);
        _max.vmin(box._max);

        if
        (
            _min.x()>_max.x() ||
            _min.y()>_max.y() ||
            _min.z()>_max.z()
        )
            _defined = false;
    }
    else
        _defined = false;

    return *this;
}

bool
BoundingBox::operator==(const BoundingBox &box) const
{
    if (!_defined && !box._defined)
        return true;

    if (_defined && box._defined)
        return _min==box._min && _max==box._max;
    else
        return false;
}

bool
BoundingBox::inside(const Vector &pos) const
{
    if (pos.x()<_min.x() || pos.x()>_max.x()) return false;
    if (pos.y()<_min.y() || pos.y()>_max.y()) return false;
    if (pos.z()<_min.z() || pos.z()>_max.z()) return false;

    return true;
}

bool
BoundingBox::intersects(const BoundingBox &box) const
{
    if (!_defined || !box._defined)
        return false;

    if (_min.x() > box._max.x()) return false;
    if (_min.y() > box._max.y()) return false;
    if (_min.z() > box._max.z()) return false;

    if (_max.x() < box._min.x()) return false;
    if (_max.y() < box._min.y()) return false;
    if (_max.z() < box._min.z()) return false;

    return true;
}

bool
BoundingBox::project(const Matrix &model,const Matrix &proj,const GltViewport &view)
{
    bool ok = true;

    vector<Vector> pnt;
    points(pnt);

    reset();
    for (uint32 j=0; j<pnt.size(); j++)
    {
        ok &= pnt[j].project(model,proj,view);
        operator+=(pnt[j]);
    }

    return ok;
}

ostream &
operator<<(ostream &os, const BoundingBox &b)
{
    os << b.min() << " - " << b.max();
    return os;
}

BoundingBox sum(const BoundingBox &a,const BoundingBox &b)
{
    BoundingBox tmp(a);
    tmp += b;
    return tmp;
}

BoundingBox intersection(const BoundingBox &a,const BoundingBox &b)
{
    BoundingBox tmp(a);
    tmp *= b;
    return tmp;
}

