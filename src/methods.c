/* 

        Copyright (C) 1995-2000
        Free Software Foundation, Inc.

   This file is part of GNU cfengine - written and maintained 
   by Mark Burgess, Dept of Computing and Engineering, Oslo College,
   Dept. of Theoretical physics, University of Oslo
 
   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version. 
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

*/

/*****************************************************************************/
/*                                                                           */
/* File: methods.c                                                           */
/*                                                                           */
/*****************************************************************************/

#include "cf.defs.h"
#include "cf.extern.h"


/*******************************************************************/

void CheckForMethod()

{ struct Item *ip;
  int i = 0;

if (strcmp(METHODNAME,"cf-nomethod") == 0)
   {
   return;
   }

if (! MINUSF)
   {
   FatalError("Input files claim to be a module but this is a parent process\n");
   }

Verbose("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n+\n");
Verbose("+ This is a private method: %s\n",METHODNAME);

if (METHODARGS == NULL)
   {
   FatalError("This module was declared a method but no MethodParameters declaration was given");
   }
else
   {
   Verbose("+\n+ Method argument prototype = (");

   i = 1;
   
   for (ip = METHODARGS; ip != NULL; ip=ip->next)
      {
      i++;
      }

   METHODARGV = (char **) malloc(sizeof(char *) * i); 
   
   i = 0;

   for (ip = METHODARGS; ip != NULL; ip=ip->next)
      {
      /* Fill this temporarily with the formal parameters */
      METHODARGV[i++] = ip->name;
      Verbose("%s ",ip->name);
      }

   METHODARGC = i;
   
   Verbose(")\n+\n");
   }
 
Verbose("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

Verbose("Looking for a data package for this method (%s)\n",METHODMD5);

Debug("Method package looks ok -- proceeding\n"); 
}
