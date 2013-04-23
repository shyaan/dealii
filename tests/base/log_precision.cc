//----------------------------  log_precision.cc  ---------------------------
//    $Id$
//    Version: $Name$ 
//
//    Copyright (C) 2005, 2006, 2007, 2013 by the deal.II authors
//
//    This file is subject to QPL and may not be  distributed
//    without copyright and license information. Please refer
//    to the file deal.II/doc/license.html for the  text  and
//    further information on this license.
//
//----------------------------  log_precision.cc  ---------------------------

// test that we can set the precision of LogStream objects

#include "../tests.h"
#include <deal.II/base/logstream.h>
#include <fstream>
#include <iomanip>
#include <limits>

int main ()
{
  std::ofstream logfile("log_precision/output");
  deallog << std::setprecision(3);
  deallog.attach(logfile);
  deallog.depth_console(0);
  deallog.threshold_double(1.e-10);

  deallog << numbers::PI << std::endl;

  // test with a different precision
  deallog.precision(12);
  deallog << numbers::PI << std::endl;

  // ensure that the precision of the underlying file stream object remained
  // unchanged
  deallog.get_file_stream() << numbers::PI << std::endl;
  
  return 0;
}

