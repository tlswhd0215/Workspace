MAIN SEGMENT
	ASSUME CS:MAIN, DS:MAIN
;
	MOV	AX, CS
	MOV	DS, AX
	MOV	AX, 1010H
	ADD	AX, 203CH
	MOV	RESULT, AX
	MOV	AH, 4CH
	INT	21H
;
RESULT DW ?
MAIN ENDS
	END