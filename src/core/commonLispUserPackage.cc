/*
    File: commonLispUserPackage.cc
*/

/*
Copyright (c) 2014, Christian E. Schafmeister
 
CLASP is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.
 
See directory 'clasp/licenses' for full details.
 
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
/* -^- */

#include "foundation.h"
#include "object.h"
#include "lisp.h"
#include "symbol.h"
#include "commonLispUserPackage.h"
#include "multipleValues.h"
#include "package.h"

namespace cluser
{



#pragma GCC visibility push(default)
#define CommonLispUserPkg_SYMBOLS
#define DO_SYMBOL(cname,idx,pkgName,lispName,export) core::Symbol_sp cname = UNDEFINED_SYMBOL;
#include "symbols_scraped_inc.h"
#undef DO_SYMBOL
#undef CommonLispUserPkg_SYMBOLS
#pragma GCC visibility pop



    void initialize_commonLispUserPackage()
    {
	list<string> lnicknames = { "USER", "CL-USER" };
	list<string> luse = { "COMMON-LISP", "CORE" };
	_lisp->makePackage("COMMON-LISP-USER",lnicknames,luse);
	// We don't have to create the COMMONLISPUSER symbols here - it's done in bootStrapCoreSymbolMap
    }


};
