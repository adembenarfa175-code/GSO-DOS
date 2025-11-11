BITS 64

;	SCCSID = @(#)stdproc.asm	1.1 85/04/10
;
; Pseudo EXEC system call for GSODOS
;

.xlist
.xcref
include stdsw.asm
.cref
.list

TITLE   STDPROC - process maintenance for GSODOS
NAME    STDPROC

include proc.asm
