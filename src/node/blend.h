#ifndef NODE_BLEND_H
#define NODE_BLEND_H

/*

  GLT OpenGL C++ Toolkit (LGPL)
  Copyright (C) 2000-2003 Nigel Stewart

  Email:  nigels@nigels.com
  WWW:    http://www.nigels.com/glt/
  Forums: http://sourceforge.net/forum/?group_id=36869

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

/*! \file
    \brief   OpenGL Blending Node
    \ingroup Node
*/

#include <glt/gl.h>

#include <node/shapes.h>

///////////////////////////// GltBlend ///////////////////////////////////////

/*! \class   GltBlend
    \brief   OpenGL Blending Node
    \ingroup Node
*/

class GltBlend : public GltShapes
{
public:

    /// Constructor
    GltBlend(
        const GLenum sfactor = GL_SRC_ALPHA,
        const GLenum dfactor = GL_ONE_MINUS_SRC_ALPHA);

    /// Destructor
    virtual ~GltBlend();

    virtual void draw() const;

private:
    GLenum _sfactor;
    GLenum _dfactor;
};

#endif
