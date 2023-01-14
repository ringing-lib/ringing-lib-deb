// -*- C++ -*- multtab.h - A precomputed multiplication table of rows
// Copyright (C) 2002, 2003, 2004, 2008, 2010, 2017 
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

#ifndef RINGING_MULTTAB_H
#define RINGING_MULTTAB_H

#include <ringing/common.h>

#if RINGING_HAS_PRAGMA_ONCE
#pragma once
#endif

#if RINGING_HAS_PRAGMA_INTERFACE
#pragma interface
#endif

#include <ringing/row.h>
#include <ringing/group.h>
#if RINGING_OLD_INCLUDES
#include <iosfwd.h>
#include <vector.h>
#include <algo.h>
#include <iterator.h>
#include <functional.h>
#else
#include <iosfwd>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#endif

RINGING_START_NAMESPACE

RINGING_USING_STD

class multtab;
class sqmulttab;

RINGING_START_DETAILS_NAMESPACE 

// These would all be member classes of multtab,
// but that causes compiler problems in MSVC-5.
class multtab_row_t
{
public:
  multtab_row_t() : n(0u) {}
  bool isrounds() const { return n == 0; }
  size_t index() const { return n; }

  static multtab_row_t from_index( size_t idx ) { 
    return multtab_row_t(idx);
  }

  bool operator==( multtab_row_t const& o ) const { return n == o.n; }
  bool operator!=( multtab_row_t const& o ) const { return n != o.n; }

  RINGING_FAKE_COMPARATORS( multtab_row_t )

  struct cmp : binary_function<multtab_row_t, multtab_row_t, bool> 
  {
    bool operator()( multtab_row_t const& x, 
                     multtab_row_t const& y ) const
    { return x.n < y.n; }
  };

  friend class RINGING_PREFIX multtab;
  friend class multtab_row_iterator;
  friend struct cmp;

protected:
  multtab_row_t( size_t n ) : n(n) {}
 
private:
  size_t n; 
};


// Iterate through the rows in the table
class RINGING_API multtab_row_iterator 
  : public RINGING_STD_CONST_ITERATOR( forward_iterator_tag, multtab_row_t )
{
 public:
  // These typedefs are needed to compile get the code to 
  // compile in gcc-2.95.x.
  typedef forward_iterator_tag iterator_category;
  typedef multtab_row_t value_type;
  typedef ptrdiff_t difference_type;
  typedef const multtab_row_t *pointer;
  typedef const multtab_row_t &reference;
  
  const multtab_row_t &operator*() const  { return r; }
  const multtab_row_t *operator->() const { return &r; }
  
  multtab_row_iterator &operator++() { ++r.n; return *this; }
  multtab_row_iterator operator++(int) 
    { multtab_row_iterator tmp(*this); ++*this; return tmp; }  
  bool operator==( const multtab_row_iterator &other ) const
    { return r.index() == other.r.index(); }
  bool operator!=( const multtab_row_iterator &other ) const
    { return r.index() != other.r.index(); }

 private:  
  friend class RINGING_PREFIX multtab;
  multtab_row_iterator( int n ) { r.n = n; }

 private:
  multtab_row_t r;
};

class sqmulttab_row_t;
class multtab_post_col_t;
class multtab_pre_col_t;

multtab_row_t operator*( multtab_row_t r, multtab_post_col_t c );
multtab_row_t operator*( multtab_pre_col_t c, multtab_row_t r );
sqmulttab_row_t operator*( sqmulttab_row_t l, sqmulttab_row_t r );

class multtab_post_col_t
{
private:
  multtab_post_col_t( size_t n, multtab const* t )
    : n(n), t(t) 
  {}
  
  friend multtab_row_t 
  operator*( multtab_row_t r, multtab_post_col_t c );

  friend class RINGING_PREFIX multtab;
  friend class sqmulttab_row_t;

public:
  multtab_post_col_t() : n(0), t(NULL) {}

  bool operator==( multtab_post_col_t const& o ) const { return n == o.n; }
  bool operator!=( multtab_post_col_t const& o ) const { return n != o.n; }

  bool null() const { return !t; } // Is it default constructed
  size_t col_index() const { return n; }

  RINGING_FAKE_COMPARATORS( multtab_post_col_t )

  struct cmp : binary_function<multtab_post_col_t, multtab_post_col_t, bool>  
  {
    bool operator()( multtab_post_col_t const& x, 
                     multtab_post_col_t const& y ) const
    { return x.n < y.n; }
  };

  friend struct cmp;

private:
  size_t n; 
  multtab const* t;
};

class multtab_pre_col_t
{
private:
  multtab_pre_col_t( size_t n, multtab const* t ) 
    : n(n), t(t) 
  {}
  
  friend multtab_row_t 
  operator*( multtab_pre_col_t c, multtab_row_t r );

  friend class RINGING_PREFIX multtab;

public:
  multtab_pre_col_t() : n(0), t(NULL) {}

  bool operator==( multtab_pre_col_t const& o ) const { return n == o.n; }
  bool operator!=( multtab_pre_col_t const& o ) const { return n != o.n; }

  bool null() const { return !t; } // Is it default constructed
  size_t col_index() const { return n; }

  RINGING_FAKE_COMPARATORS( multtab_pre_col_t )


  struct cmp : binary_function<multtab_pre_col_t, multtab_pre_col_t, bool>
  {
    bool operator()( multtab_pre_col_t const& x, 
                     multtab_pre_col_t const& y ) const
    { return x.n < y.n; }
  };

  friend struct cmp;

private:
  size_t n; 
  multtab const* t;
};

class sqmulttab_row_t : public multtab_row_t {
public:
  sqmulttab_row_t() : t(0) {}

  operator multtab_post_col_t() const;

  friend sqmulttab_row_t operator*( sqmulttab_row_t l, sqmulttab_row_t r );

private:
  friend class RINGING_PREFIX sqmulttab;

  sqmulttab_row_t( size_t n, sqmulttab const* t ) 
    : multtab_row_t(n), t(t) 
  {}

  sqmulttab const* t; 
};

RINGING_END_DETAILS_NAMESPACE

// --------------------------------------------------------------
// 
// The main multiplication table class
//
class RINGING_API multtab
{
public:
  // A swap function and assignment operator
  void swap( multtab &other );
  multtab &operator=( const multtab &other );

  // Initialises a multiplication table with the rows in the 
  // range [first, last).
  template < class InputIterator >
  multtab( InputIterator first, InputIterator last )
    : rows( make_vector( first, last ) )
  { table.resize( rows.size() ); }

  // As above but use factor out some part-end.
  template < class InputIterator >
  multtab( InputIterator first, InputIterator last, const row &partend )
    : pends( partend )
  { init( make_vector( first, last ) ); }

  // ... And more complicated part end groups.
  template < class InputIterator >
  multtab( InputIterator first, InputIterator last, const group& partends )
    : pends( partends )
  { init( make_vector( first, last ) ); }

  // ... And a group at the other end (e.g. for whole-course comps)
  template < class InputIterator >
  multtab( InputIterator first, InputIterator last, const group& partends, 
           const group& postgroup )
    : pends( partends ), postgroup( postgroup )
  { init( make_vector( first, last ) ); }

  typedef RINGING_DETAILS_PREFIX multtab_row_t      row_t;
  typedef RINGING_DETAILS_PREFIX multtab_post_col_t post_col_t;
  typedef RINGING_DETAILS_PREFIX multtab_pre_col_t  pre_col_t;

  int bells() const;

  // Primarily for debugging.  Prints out the multiplication table
  void dump( ostream &os ) const;
  
  // Precompute the products of the set with the given row.
  pre_col_t compute_pre_mult( const row &x );   // (x * r) for all rows r
  post_col_t compute_post_mult( const row &x ); // (r * x) for all rows r
  post_col_t compute_post_mult( const change &c ) 
    { return compute_post_mult( row() * c ); }
  
  // Convert a row into a precomputed table offset & vice versa
  row_t find( const row &r ) const;
  row   find( const row_t &r ) const;

  // The number of rows in the table
  size_t size() const { return table.size(); }

  const group& partends() const { return pends; }
  size_t group_size() const { return pends.size(); }

  // Iterate through the rows in the multiplication table
  typedef RINGING_DETAILS_PREFIX multtab_row_iterator row_iterator;
  row_iterator begin_rows() const { return row_iterator(0); }
  row_iterator end_rows() const   { return row_iterator(size()); }

  // Operators to do optimised multiplication of rows:
  friend row_t RINGING_DETAILS_PREFIX operator*( row_t r, post_col_t c );
  friend row_t RINGING_DETAILS_PREFIX operator*( pre_col_t c, row_t r );

  friend RINGING_DETAILS_PREFIX sqmulttab_row_t 
  RINGING_DETAILS_PREFIX operator*( RINGING_DETAILS_PREFIX sqmulttab_row_t l, 
                                    RINGING_DETAILS_PREFIX sqmulttab_row_t r );

private:
  // A helper to do what the templated constructor of vector does
  // (we can't use that directly because MSVC doesn't have it).
  template < class InputIterator >
  static vector< row > make_vector( InputIterator first, InputIterator last )
  {
    vector< row > r;
    copy( first, last, back_inserter( r ) );
    return r;
  }

  // Each coset of the group generated by the part end has one member
  // which is used to represent the whole coset. 
  row make_representative( const row &r ) const;
  row make_post_representative( const row &r ) const;

  void init( const vector< row > &r );

  // Data members
  //
  // See CVS on 2010-02-06 for an implementation using single indirection
  // (i.e. with a vector<row_t> and indexing via table[c*N+r] instead of 
  // table[r][c]).  The version with a single indirection turned out to
  // perform marginally worse than this version with a double indirection.
  vector< vector< row_t > > table;
  vector< row > rows;
  group pends, postgroup;
  enum pre_or_post { pre_mult, post_mult };
  vector< pair< row, pre_or_post > > cols;
};

class sqmulttab : public multtab {
public:
  // Initialises a multiplication table with the rows in the 
  // range [first, last).
  template < class InputIterator >
  sqmulttab( InputIterator first, InputIterator last )
    : multtab( first, last )
  { sqinit(); }

  typedef RINGING_DETAILS_PREFIX sqmulttab_row_t row_t;

  typedef row_t post_col_t;
  typedef row_t pre_col_t;

  pre_col_t compute_pre_mult( const row &x ) { return find(x); }
  post_col_t compute_post_mult( const row &x ) { return find(x); }

  row_t find( const row &r ) const;
  row   find( const row_t &r ) const;

private:
  void sqinit();
};

RINGING_START_DETAILS_NAMESPACE

// Operators to do optimised multiplication of rows:
inline multtab_row_t operator*( multtab_row_t r, multtab_post_col_t c )
{ return c.t->table[ r.index() ][ c.n ]; }

inline multtab_row_t operator*( multtab_pre_col_t c, multtab_row_t r )
{ return c.t->table[ r.index() ][ c.n ]; }

inline sqmulttab_row_t operator*( sqmulttab_row_t l, sqmulttab_row_t r )
{ return sqmulttab_row_t
           ( l.t->table[ l.index() ][ r.index() ].index(), l.t ); }

// Conversion operator
inline sqmulttab_row_t::operator multtab_post_col_t() const
{ return multtab_post_col_t( index(), t ); }

RINGING_END_DETAILS_NAMESPACE

RINGING_END_NAMESPACE

RINGING_DELEGATE_STD_SWAP( multtab )

#endif // RINGING_MULTTAB_H

