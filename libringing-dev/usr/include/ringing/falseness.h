// -*- C++ -*- falseness.h - Class for falseness table
// Copyright (C) 2001, 2002, 2003, 2008, 2010, 2011
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

#ifndef RINGING_FALSENESS_H
#define RINGING_FALSENESS_H

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_ONCE
#pragma once
#endif

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#include <ringing/row.h>
#if RINGING_OLD_INCLUDES
#include <vector.h>
#else
#include <vector>
#endif

RINGING_START_NAMESPACE

RINGING_USING_STD

class method;
class group;

// The set of lead-heads that are false against the lead starting with rounds.
class RINGING_API falseness_table
{
public:
  // Contains just the trivial falseness (a row is false against itself)
  falseness_table();

  // What gets included in the falseness table?
  enum
  {
    in_course_only     = 0x01,
    no_fixed_treble    = 0x02,
    half_lead_only     = 0x04,
    out_of_course_only = 0x08
  };

  // Falseness table for the method.  
  falseness_table( const method &m, int flags = 0 );

  // Inter-method falseness table for a pair of methods,
  //   F(A,B) = { a b^-1 : a in A, b in B }. 
  // The order of A and B is important.  The lead of method A 
  // starting from rounds, is false against the leads of method B 
  // starting from each lead-head in the set F(A,B).
  falseness_table( const method &a, const method &b, int flags = 0 );
  falseness_table( const method &a, const vector<row> &b, int flags = 0 );
  falseness_table( const vector<row> &a, const vector<row> &b, int flags = 0 );

  // Assignment and swapping
  void swap( falseness_table &other ) { t.swap( other.t ); }

  // Iterators
  typedef row value_type;
  typedef vector<row>::const_iterator const_iterator;
  const_iterator begin() const { return t.begin(); }
  const_iterator end() const   { return t.end(); }

  // Number of elements
  size_t size() const { return t.size(); }

  // Use the falseness table as the generator set for a group
  group generate_group() const;

private:
  void init( vector<row> const& m1, vector<row> const& m2 );

  vector<row> t;
  int flags;
};

// The set of course heads that are false against the plain course
class RINGING_API false_courses
{
public:
  // Contains just the trivial falseness (a row is false against itself)
  false_courses();

  // What gets included in the list of false course heads?
  enum
  {
    in_course_only   = 0x01,
    tenors_together  = 0x02
  };

  // false course heads for the method.  
  false_courses( const method &m, int flags = 0 );

  // Assignment and swapping
  void swap( false_courses &other ) { t.swap( other.t ); }

  // Iterators
  typedef row value_type;
  typedef vector<row>::const_iterator const_iterator;
  const_iterator begin() const { return t.begin(); }
  const_iterator end() const   { return t.end(); }

  // The FCH symbols.
  string symbols() const;
  static void optimise(int bells); // 0 to disable

  // Number of elements
  size_t size() const { return t.size(); }

  // Look up a single symbol
  static string lookup_symbol( row const& fch );

private:
  class initialiser;
  friend class initialiser;

  vector<row> t;
  int flags;
  row lh;
};

RINGING_END_NAMESPACE

// specialise std::swap
RINGING_DELEGATE_STD_SWAP( falseness_table )
RINGING_DELEGATE_STD_SWAP( false_courses )

#endif
