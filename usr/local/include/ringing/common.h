// -*- C++ -*- common.h - Common macros and so on.
// Copyright (C) 2001 Martin Bright <martin@boojum.org.uk>

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// $Id: common.h,v 1.4 2003/03/07 01:59:04 ras52 Exp $

#ifndef RINGING_COMMON_H
#define RINGING_COMMON_H
#define RINGING_INSIDE_COMMON_H

#ifdef _MSC_VER
// Getting the GNU Autotools, and even the configure script, working with 
// Microsoft Visual Studio is complicated (not in the least by the fact
// that both parties refuse to believe in the existence of the other), and
// some Unix-like wrapper such as MinGW or Cygwin is needed in which to run
// the Autotools.  This 
#include <ringing/common-msvc.h>
#else
#include <ringing/common-am.h>
#endif

#include <ringing/macros.h>

#undef RINGING_INSIDE_COMMON_H
#endif // RINGING_COMMON_H
