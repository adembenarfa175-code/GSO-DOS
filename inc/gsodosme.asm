BITS 64

;	SCCSID = @(#)GSOdosmes.asm	1.1 85/04/10
;
; Standard device IO for GSODOS (first 12 function calls)
;
debug=0
.xlist
.xcref
include mssw.asm
include dosseg.asm
.cref
.list

TITLE   GSODOSMES - DOS OEM dependancies
NAME    GSODOSMES

include dosmes.asm
