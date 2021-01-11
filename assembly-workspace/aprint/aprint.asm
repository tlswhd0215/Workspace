main segment
assume cs:main
;
mov dl, 'A'
mov ah, 2
;
mov ah,4ch
int 21h

main ends
end