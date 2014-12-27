// -*- C++ -*- common-am.h.in - Common macros and so on.
// Copyright (C) 2001, 2002, 2003, 2008 Martin Bright <martin@boojum.org.uk>
// and Richard Smith <richard@ex-parrot.com>

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

// ******** INSTRUCTIONS
// This file is turned into common-am.h by the configure script.
// If you are editing this file by hand, you should change everything
// indicated by ***.  The expression @VARIABLE@ should be replaced by
// the value appropriate for your system.

// $Id: common-am.h.in,v 1.14 2008/05/15 16:36:56 ras52 Exp $

#ifndef RINGING_COMMON_AM_H
#define RINGING_COMMON_AM_H

// *** Define this to be the name of the package (i.e. ringing-lib)
// #define RINGING_PACKAGE ringing-lib
#define RINGING_PACKAGE "ringing-lib"

// *** Define this to be the version number of the package
#define RINGING_VERSION "0.4.0-pre"

// *** Define this to be 1 to use old-style standard C++ header names
// (<iostream.h>, <list.h> and so on) or 0 to use new-style ones
// (<iostream>, <list>).
#define RINGING_OLD_INCLUDES 0

// *** Define this to be 1 to use old-style standard C header names
// (<stdio.h> and so on) or 0 to use new-style ones (<cstdio>).
#define RINGING_OLD_C_INCLUDES 0

// *** Define this to be 1 if you want the Ringing Class Library to use
// exceptions, or 0 otherwise.
#define RINGING_USE_EXCEPTIONS 1

// *** Define this to be 1 if you want the Ringing Class Library to put
// its definitions in a namespace called `ringing', or 0 otherwise.
#define RINGING_USE_NAMESPACES 1

// *** Define this to be 1 if your standard include files (as indicated above
// by RINGING_HEADER_EXT) place their definitions in namespace `std', or 0
// if the definitions are in the global namespace.
#define RINGING_USE_STD 1

// *** Define this to be 1 if your compiler supports specialisation of 
// template functions, or 0 if it does not.
#define RINGING_USE_TEMPLATE_FUNCTION_SPECIALISATION 1

// *** Define this to be 1 if your compiler allows bases classes of 
// member classes to be protected member classes of a base of the outer class.
#define RINGING_PROTECTED_MEMBER_BASES 1

// *** Define this to be 1 if your compiler prematurely instantiates the 
// definitions of member functions (as well as their declarations) when
// it implicitly instantiates a class, or 0 otherwise.
#define RINGING_PREMATURE_MEMBER_INSTANTIATION 0

// *** Define this to be 1 if your STL only has pre-standard, non-templated
// iostreams, or to 0 if it has standard templated iostreams.
#define RINGING_HAVE_OLD_IOSTREAMS 0

// *** Define this to be 1 if your STL has a compliant std::iterator class
#define RINGING_HAVE_STD_ITERATOR 1

// *** Define this to be 1 if your STL has working {o,i}stringstream classes,
// or to 0 otherwise.
#define RINGING_USE_STRINGSTREAM 1

// *** Define this to be 1 if want to include termcap support
// or to 0 otherwise.
#define RINGING_USE_TERMCAP 0

// *** Define this to be 1 if want to include GNU readline support
// or to 0 otherwise.
#define RINGING_USE_READLINE 1

// *** Define this to be 1 if your copy of GNU readline has broken
// headers requiring <stdio.h> to be included before <readline/readline.h>
// or to 0 otherwise
#define RINGING_READLINE_NEEDS_STDIO_H 0

// *** Define this to be 1 if you want to support Windows DLLs
#define RINGING_AS_DLL 0

// *** Define this to be 1 if you have std::hash
#define RINGING_HAS_STD_HASH 0 //@HAS_STD_HASH@

// *** Define this to be 1 if you have long long
#define RINGING_HAVE_LONG_LONG 1

#endif

