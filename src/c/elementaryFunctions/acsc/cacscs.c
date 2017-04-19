// Copyright (C) 2017 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Organization: FOSSEE, IIT Bombay
// Author: Ashish Kamble
// Email: toolbox@scilab.in
#include <math.h>
#include "acsc.h"
#include "floatComplex.h"
#include "asin.h"
#include "division.h"

floatComplex cacscs(floatComplex x) 
{
 floatComplex xinv;
 xinv = crdivs(FloatComplex(1,0),x);
 return  casins(xinv);
}
