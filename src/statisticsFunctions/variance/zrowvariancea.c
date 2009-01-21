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

#include "variance.h"

void zrowvariancea(doubleComplex *in, int lines, int columns, doubleComplex* out){
    
    int i = 0 ;

 
    doubleComplex* transp = (doubleComplex*) malloc ( sizeof (doubleComplex) *(unsigned int) (lines*columns));
         /*FIXME : NEED TO REVIEW TRANSPOSE COMPLEX FONCTIONS , they need to not do the conjugate
         automaticaly */    
    ztransposea ( in , lines , columns , transp ) ;
    
    for ( i = 0 ; i < columns *lines ; i++) 
             transp[i] = DoubleComplex ( zreals (transp[i] ) , zimags(transp[i]));
    
    for ( i = 0; i < columns ; i++)
    {

    
    out[i] = zvariancea ( transp + i*lines , lines ) ;
    }

    free (transp);
}