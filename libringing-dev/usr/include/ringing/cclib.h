// -*- C++ -*- cclib.h - Central Council Method libraries
// Copyright (C) 2001, 2004, 2010, 2017 Mark Baner <mark@standard8.co.uk> and
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

// $Id$

#ifndef RINGING_CCLIB_H
#define RINGING_CCLIB_H

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_ONCE
#pragma once
#endif

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#include <ringing/library.h>

RINGING_START_NAMESPACE

RINGING_USING_STD

// cclib : Implement Central Council Method libraries
class RINGING_API cclib : public library {
public:
  // cclib::ref is (effectively) the line number in the current version
  // of the library.  It is not persistent as the library is updated.
  RINGING_DECLARE_LIBRARY_FACET( ref, int );

  static void registerlib(void);
  cclib(const string& filename);

private:
  class impl;
};

RINGING_END_NAMESPACE

#endif
