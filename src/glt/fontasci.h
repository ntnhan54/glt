#ifndef GLT_FONTASCI_H
#define GLT_FONTASCI_H

/*
  GLT OpenGL C++ Toolkit (LGPL)
  Copyright (C) 2000-2007 Nigel Stewart

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

/* $Id: fontasci.h,v 2.2 2007/05/06 16:46:24 nigels Exp $ */

/*! \file
    \brief   Ascii OpenGL Font Interface
    \ingroup GLT
*/

#include <glt/config.h>
#include <glt/font.h>

/*! \class GltFontAscii
    \brief GLT ASCII font class
    \ingroup GLT

    Fonts here are borrowed from the collection
    by Yossi Gil:
    http://www.simtel.net/pub/simtelnet/msdos/screen/fntcol16.zip
*/

class GltFontAscii : public GltFont
{
public:
    /// Constructor
    GltFontAscii(void *data = NULL);
    /// Destructor
    ~GltFontAscii();

    void init(void *);
    void clear();

    bool print(const GltChar ch) const;
    bool print(const GltString &str) const;

    //
    // Convert between raw font data and a GLTF buffer
    //

    static bool  makeHeader(std::string &header,const int width,const int height);
    static void *getHeader(const void * const h,int &width,int &height);

private:

//    bool print(const char ch) const;
//    bool print(const std::string &str) const;

    void compileLists(void *);

    int   _width;
    int   _height;
    int   _listBase;
};

#endif
