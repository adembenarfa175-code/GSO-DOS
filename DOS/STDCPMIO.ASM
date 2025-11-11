;	SCCSID = @(#)stdcpmio.asm	1.1 85/04/10
;
; Standard device IO for GSODOS (first 12 function calls)
;

.xlist
.xcref
include stdsw.asm
include dosseg.asm
.cref
.list

TITLE   STDCPMIO - device IO for GSODOS
NAME    STDCPMIO

include cpmio.asm
