// -*- C++ -*- streamutils.h - Utilities to cope with old iostream libraries
// Copyright (C) 2002, 2003, 2005, 2007, 2009 
// Richard Smith <richard@ex-parrot.com>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// Part of this file is taken from the boost lexical_cast library,
// version 1.28.0 [see http://www.boost.org/ for details], and is under
// the following copyright:

//  Copyright Kevlin Henney, 2000, 2001, 2002. All rights reserved.
//
//  Permission to use, copy, modify, and distribute this software for any
//  purpose is hereby granted without fee, provided that this copyright and
//  permissions notice appear in all copies and derivatives.
//
//  This software is provided "as is" without express or implied warranty.

// $Id$

#ifndef RINGING_STREAMUTILS_H
#define RINGING_STREAMUTILS_H

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_ONCE
#pragma once
#endif

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#if RINGING_OLD_INCLUDES
#include <istream.h>
#else
#include <istream>
#endif
#include <string>

#include <ringing/lexical_cast.h>

// This exists because Visual Studio 6's default STL (an old version of the
// Dinkumware STL) has a bug in it's implementation of istream<>::getline.
// If we're using that STL, this provides a work around.  This overload gets
// chosen in preference to std::getline because it is non-templated.
#if defined(_MSC_VER) && _MSC_VER <= 1200 && defined(_YVALS) && (!defined(_CPPLIB_VER) || _CPPLIB_VER < 306)
RINGING_API istream& getline( istream& in, string &str, char c = '\n' );
#endif

#endif
