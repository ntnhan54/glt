#ifndef GLT_LIGHT_H
#define GLT_LIGHT_H

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

/* $Id: light.h,v 2.3 2007/05/06 16:46:24 nigels Exp $ */

/*! \file
    \brief OpenGL Light Source Class
    \ingroup GLT
*/

#include <glt/gl.h>

#include <iosfwd>

#include <math/vector3.h>
#include <glt/color.h>

///////////////////////////// GltLight ///////////////////////////////////////

/*! \class GltLight
    \brief OpenGL Light Source Class
    \ingroup GLT

    Convenient manipulation of OpenGL lightsource configuration.
*/

class GltLight
{
public:

    GltLight(const GLenum light = GL_LIGHT0,const bool getIt = false); ///< Constructor
    ~GltLight();                                                       ///< Destructor

    void get();                                     ///< Get the current OpenGL light settings
    void set() const;                               ///< Set the current OpenGL light settings

    GLenum   &light();                              ///< OpenGL light source identifier
    bool     &enabled();                            ///< Enabled
    GltColor &ambient();                            ///< Ambient contribution
    GltColor &diffuse();                            ///< Diffuse contribution
    GltColor &specular();                           ///< Specular contribution
    Vector4  &position();                           ///< Light source position
    Vector4  &spotDirection();                      ///< Spotlight direction
    GLfloat  &spotExponent();                       ///< Spotlight exponent
    GLfloat  &spotCutoff();                         ///< Spotlight cutoff radius
    GLfloat  &attenutationConstant();               ///< Constant attenuation factor
    GLfloat  &attenutationLinear();                 ///< Linear attenuation factor
    GLfloat  &attenutationQuadratic();              ///< Quadratic attenuation factor

    const GLenum   &light() const;                  ///< OpenGL light source identifier
    const bool     &enabled() const;                ///< Enabled
    const GltColor &ambient() const;                ///< Ambient contribution
    const GltColor &diffuse() const;                ///< Diffuse contribution
    const GltColor &specular() const;               ///< Specular contribution
    const Vector4  &position() const;               ///< Light source position
    const Vector4  &spotDirection() const;          ///< Spotlight direction
    const GLfloat  &spotExponent() const;           ///< Spotlight exponent
    const GLfloat  &spotCutoff() const;             ///< Spotlight cutoff radius
    const GLfloat  &attenutationConstant() const;   ///< Constant attenuation factor
    const GLfloat  &attenutationLinear() const;     ///< Linear attenuation factor
    const GLfloat  &attenutationQuadratic() const;  ///< Quadratic attenuation factor

private:

    GLenum  _light;
    bool    _enabled;

    GltColor _ambient;
    GltColor _diffuse;
    GltColor _specular;
    Vector4  _position;
    Vector4  _spotDirection;
    GLfloat  _spotExponent;
    GLfloat  _spotCutoff;
    GLfloat  _attenuationConstant;
    GLfloat  _attenuationLinear;
    GLfloat  _attenuationQuadratic;

    const static GltColor _ambientDefault;
    const static GltColor _diffuseDefault;
    const static GltColor _specularDefault;
    const static Vector4  _positionDefault;
    const static Vector4  _spotDirectionDefault;
    const static GLfloat  _spotExponentDefault;
    const static GLfloat  _spotCutoffDefault;
    const static GLfloat  _attenuationConstantDefault;
    const static GLfloat  _attenuationLinearDefault;
    const static GLfloat  _attenuationQuadraticDefault;
};

#endif
