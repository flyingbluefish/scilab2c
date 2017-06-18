/* Copyright (C) 2016 - IIT Bombay - FOSSEE

 This file must be used under the terms of the CeCILL.
 This source file is licensed as described in the file COPYING, which
 you should have received as part of this distribution.  The terms
 are also available at
 http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 Author: Siddhesh Wani
 Organization: FOSSEE, IIT Bombay
 Email: toolbox@scilab.in
*/


#include "sum.h"

void i8columnsuma(int8 *in, int lines, int columns, int8 * out) {
  int i = 0;

  /*
  ** First assign first row, just in case
  ** out contains non-zero's elements.
  */
  for (i = 0 ; i < lines; ++i)
    {
      out[i] = (int8)in[i];
    }
  /*
  ** Then accumulate in each row.
  */
  for (i = lines ; i < lines * columns ; ++i)
    {
      out[i % lines] = (int8)i8adds(out[i % lines] , in[i]);
    }
}
