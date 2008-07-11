/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008-2008 - INRIA - Allan SIMON
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include "matrixTranspose.h"

void dtransposea ( double* in , int lines1 , int column1, double* out ){
	
	int newCoord = 0 ;
	int index    = 0 ;
	
	for(index = 0 ; index <  lines1 * column1 ; index++)
	{
		newCoord	= index % column1 * lines1 + ( index / column1);

		out[newCoord]	= in[index];
	}
	
	
}
