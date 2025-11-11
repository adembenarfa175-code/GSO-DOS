BITS 64

;	SCCSID = @(#)GSOcpmio.asm	1.1 85/04/10
;
; Standard device IO for GSODOS (first 12 function calls)
;

.xlist
.xcref
include mssw.asm
include dosseg.asm
.cref
.list

TITLE	GSOCPMIO - device IO for GSODOS
NAME	GSOCPMIO

include cpmio.asm
