; Some modules really want TRUE to be 0FFH.  Best to let them have their way.
ifndef TRUE
	TRUE	   EQU	   0FFFFh
endif
ifndef TRUEBYTE
	TRUEBYTE   EQU     0FFh
endif
ifndef FALSE
	FALSE	   EQU	   0
endif

;
; Use the following switches to control cmacros.inc
;
?PLM       =       0
?WIN       =       0

memS       EQU     1			; Small model
;
; Use the switches below to produce the standard GSO version or the GSO
; version of the operating system
;
; The below chart will indicate how to set the switches to build the various
; versions
;
;                     GSOVER          GSOCOPYRIGHT
; --------------------------------------------------------
;  GSO Version   |     TRUE              TRUE
; --------------------------------------------------------
;  MS Version    |     FALSE             FALSE
; --------------------------------------------------------
;  Clone Version |     TRUE              FALSE
;
GSOVER     EQU     TRUE
GSOCOPYRIGHT EQU   FALSE

BUFFERFLAG	EQU	NOT GSOCOPYRIGHT

ifndef	MSVER	
MSVER      EQU     NOT GSOVER
endif
GSO	   EQU	   GSOVER
;
;
  IF1
	IF GSOVER
	    IF GSOCOPYRIGHT
              %OUT ... GSO version build switch on ...
	    ELSE
	      %OUT ... CLONE version build switch on ...
	    ENDIF
	ELSE
	    IF NOT GSOCOPYRIGHT
	      %OUT ... MS version build switch on ...
	    ELSE
	      %OUT !!!!!!!!!  VERSION SWITCHES SET INCORECTLY  !!!!!!!!!
	      %OUT !!!!!!!!! CHECK SETTINGS IN INC\VERSION.INC !!!!!!!!!
	    ENDIF
	ENDIF   
  ENDIF
;
;
;***************************************************************************
;*          The following switches are for DBCS or SBCS support            *
;*                                                                         *
;*                     Set INTERNAT EQU TRUE FOR DBCS                      *
;*                     Set INTERNAT EQU FALSE FOR SBCS                     *
;*                                                                         *
;***************************************************************************
;
GSOJAPVER  EQU	   FALSE		;If TRUE set KANJI true also

;
; Switch INTERNAT for DBCS support
;
INTERNAT   EQU	   FALSE
;
	IF INTERNAT
KANJI	   EQU	   TRUE
GSOJAPAN   EQU	   TRUE
	ELSE
KANJI	   EQU	   FALSE
GSOJAPAN   EQU	   FALSE
	ENDIF

ifndef altvect				; avoid jerking off vector.inc
ALTVECT    EQU	   FALSE		;Switch to build ALTVECT version
endif

;
; Country code switches
; The default contry code is assumed as USA.
;
	IF INTERNAT
 KOREA	   EQU	   TRUE
 JAPAN	   EQU	   FALSE
	ELSE
 KOREA	   EQU	   FALSE
 JAPAN	   EQU	   FALSE
	ENDIF
;
	IF1
		IF INTERNAT
%OUT	Internat(ECS) version build switch on
		ENDIF
	ENDIF
