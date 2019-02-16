[bits 16]
;org 100h
	CR     EQU	0dh
	LF      EQU	0ah
	MAX   EQU    0ffh ; 0-max
segment code 

..start: 
	mov ax,data ; Move segment address of data segment into AX
	mov ds,ax ; Copy address from AX into DS
	mov ax,stack ; Move segment address of stack segment into AX
	mov ss,ax ; Copy address from AX into SS
	mov sp,stacktop ; Point SP to the top of the stack
	
	;push dx
	;mov dx, codedumpstr
	;call print_string
	;pop dx
	;mov cx, cs
	;push ds
	;mov bx, ss
	;mov ds, bx
	;mov bx, sp
	;mov bx, word [bx + 18]
	;pop ds
	;sub bx, 3
	;call address_dump
	
	call print_register_detail
	call dump_all
	
	
	mov ax, 4c00h
	int 21h
	ret
print_register_detail:
	pusha
	push si
	push di
	
	push dx
	
	;mov ax, ax
	mov dx,  axstr
	call print_string
	call print_num_detail
	
	mov dx,  bxstr
	call print_string
	mov ax, bx
	call print_num_detail
	
	mov dx,  cxstr
	call print_string
	mov ax, cx
	call print_num_detail
	
	
	mov dx,  dxstr
	call print_string
	pop dx
	mov ax, dx
	call print_num_detail
	
	mov dx,  sistr
	call print_string
	mov ax, si
	call print_num_detail
	
	mov dx,  distr
	call print_string
	mov ax, di
	call print_num_detail
	
	mov dx,  bpstr
	call print_string
	mov ax, bp
	call print_num_detail
	
	mov dx,  spstr
	call print_string
	mov ax, sp
	add ax, 22
	call print_num_detail
	
	mov dx,  csstr
	call print_string
	mov ax, cs
	call print_num_detail
	
	mov dx,  dsstr
	call print_string
	mov ax, ds
	call print_num_detail
	
	mov dx,  esstr
	call print_string
	mov ax, es
	call print_num_detail
	
	mov dx,  ssstr
	call print_string
	mov ax, ss
	call print_num_detail
	
	mov dx,  ipstr
	call print_string
	push ds
	mov ax, ss
	mov ds, ax
	mov bx, sp
	add bx, 22
	;call debug_stack
	mov ax, [bx] ; get return address
	sub ax, 3 ; get ip before call
	pop ds
	call print_num_detail
	
	mov dx,  flagstr
	call print_string
	pushf
	pop ax
	call print_num_detail
	
	pop di
	pop si
	popa
	ret
print_num_detail:
	pusha
	mov cx, 30h
	
	mov dx,  base2str
	call print_string
	call print_ax_withprefix_bin
	
	mov dx,  base8str
	call print_string
	call print_ax_withprefix_oct
	
	mov dx,  base10str
	call print_string
	call print_ax_withprefix_dec
	
	mov dx,  base16str
	call print_string
	call print_ax_withprefix_hex
	
	call print_newline
	
	popa
	ret
address_dump: ; cx is the section, bx is address
	pusha
	
	mov dx, bx
	
	push ds
	mov bx, cx
	mov ds, bx
	mov bx, dx
	lea bx, [bx]
	pop ds
	call print_address_header
	call print_hex_dump
	
	; print line
	mov cx, 75
print_addrhead_line_dump_end:
    mov dl, '='
	mov ah, 2
	int 21h
	loop print_addrhead_line_dump_end
	call print_newline
	
	popa
	ret
print_address_header: ; cx is the section, bx is the address
	pusha
	
	push bx
	push dx
	mov dx, addressdumpstr
	call print_string
	pop dx
	mov ax, cx
	mov bl, 10h
	call print_ax_withprefix
	mov dl, ':'
	mov ah, 2
	int 21h
	pop bx
	mov ax, bx
	mov bl, 10h
	call print_ax_withprefix
	call print_newline
	
	; print space
	mov cx, 11
print_addrhead_space:
    mov dl, ' '
	mov ah, 2
	int 21h
	loop print_addrhead_space
	
	; print hex char header
	mov cx, 16
print_addrhead_hex:
	push cx
	mov ax, 16
	sub ax, cx
	mov cx, ax
	; if ax < 16
	cmp ax, 16
	jge no_prefix_print_addrhead
	mov dl, '0'
	mov ah, 2
	int 21h
no_prefix_print_addrhead:
	mov ax, cx
	call print_ax_hex
	mov dl, ' '
	mov ah, 2
	int 21h
	pop cx
	loop print_addrhead_hex
	
	; print split space
	;mov dl, ' '
	;mov ah, 2
	;int 21h
	
	; print hex char header
	mov cx, 16
print_addrhead_hex_char:
	push cx
	mov ax, 16
	sub ax, cx
	mov cx, ax
	mov ax, cx
	call print_ax_hex
	pop cx
	loop print_addrhead_hex_char
	
	call print_newline
	
	; print line
	mov cx, 75
print_addrhead_line:
    mov dl, '='
	mov ah, 2
	int 21h
	loop print_addrhead_line
	
	call print_newline
	
	popa
	ret
print_hex_dump:
	pusha
	mov dx, cx
	;mov ax, 05678h
	push ax
	;mov ax, 01234h
	push ax
	mov cx, 0
print_hex_dump_start:
	cmp cx, MAX
	jg print_hex_dump_exit
	
	pusha
	add cx, bx
	push ds
	mov ax, ss
	mov ds, ax
	mov bx, sp
	
	; 34, 36 taint analysis
	;mov dx, 05678h
	mov [bx+18], dx ;34
	;mov cx, 01234h
	mov [bx+20], cx ;36
	
	;mov word ptr [bx+10], ax
	
	;mov word ptr [bx+12], ax
	pop ds
	;push ds
	;call debug_stack
	;pop ds
	
	popa
	
	;call debug_stack
	call print_address
	push ds
	push bx
	push cx
	push dx
	mov ds, dx
	add bx, cx
	mov al, byte [bx]
	pop dx
	pop cx
	pop bx
	pop ds
	push bx
	mov bl, 10h
	call print_hex_char
	pop bx
	push  dx
	mov dl, ' '
	mov al, 0
	mov ah, 02
	int 21h
	pop dx
	call print_printable_char_slashn
	inc cx
	jmp print_hex_dump_start
print_hex_dump_exit:
	pop ax
	pop ax
	popa
	ret
	
print_address:
	pusha
	mov ax, cx
	xor dx, dx
	mov bx, 16
	div bx
	cmp dx, 0
	jnz print_address_no
	pusha
	push ds
	mov bx, ss
	mov ds, bx
	mov bx, sp
	mov ax, word [bx+36]
	pop ds
	mov bl, 10h
	call print_ax_withprefix
	mov dl, ':'
	mov ah, 2
	int 21h
	push ds
	mov bx, ss
	mov ds, bx
	mov bx, sp
	mov ax, word [bx+38]
	pop ds
	mov bl, 10h
	call print_ax_withprefix
	mov dl, ' '
	mov ah, 2
	int 21h
	mov dl, ' '
	mov ah, 2
	int 21h
	popa
print_address_no:
	popa
	ret
	
get_wordnum_max: ; ax = number, bl = base
	push bx
	push cx
	push dx
	mov bh, 0
	xor cx, cx
get_wordnum_max_start:
	cmp ax, 0
	jz get_wordnum_max_end
	xor dx, dx
	mov bh, 0
	div bx
	inc cx
	jmp get_wordnum_max_start
get_wordnum_max_end:
	mov ax, cx
	pop dx
	pop cx
	pop bx
	ret
	
print_hex_char: ; al is the char
	pusha
	; prefix = base
	xor ah,ah
	mov bl, 10h
	push ax
	call get_wordnum_max
	
	; print stack
	mov bx, ax
	pop ax
	cmp bx, 2
	jge no_prefix
	push ax
	mov dl, '0'
	mov ah, 2
	int 21h
	pop ax
no_prefix:
	push dx
	push bx
	xor dx,dx
	mov bl, 10h
	call print_ax
	pop bx
	pop dx
	
	popa
	ret
print_printable_char_slashn:
	pusha
	; compare to cx & print \n
	push ax
	push bx
	push dx
	mov ax, cx
	inc ax
	xor dx, dx
	mov bx, 16
	div bx
	cmp dx, 0
	jnz print_slashn_no
	pop dx
	pop bx
	pop ax
	call print_printable_line
	call print_newline
	jmp print_slashn_no_exit
print_slashn_no:
	pop dx
	pop bx
	pop ax
print_slashn_no_exit:
	popa
	ret
	
print_printable_line:
	pusha
	mov ax, cx
	mov cx, 0
print_printable_line_start:
	cmp cx, 15
	jg print_printable_line_exit
	push ax
	push ds
	push bx
	mov ds, dx
	add bx, ax
	sub bx, 15
	add bx, cx
	mov al, byte [bx]
	pop bx
	pop ds
	call print_printable_char
	pop ax
	inc cx
	jmp print_printable_line_start
print_printable_line_exit:
	popa
	ret
	
print_printable_char: ; al is character
	pusha
	cmp al, 32
	jl print_nonprintable_char
	cmp al, 126
	jg print_nonprintable_char
	mov dl, al
	mov al, 0
	mov ah, 2
	int 21h
	jmp print_printable_char_end
print_nonprintable_char:
	mov dl, '.'
	mov al, 0
	mov ah, 2
	int 21h
print_printable_char_end:
	popa
	ret

print_string: ; ds:dx = string
	push dx
	push ax
	mov ah, 09h
	int 21h
	pop ax
	pop dx
	ret
print_newline: ; just print new line
	push dx
	push ax
	mov dl, CR
	mov ah, 02h
	int 21h
	mov dl, LF
	int 21h
	pop ax
	pop dx
	ret
print_ax_withprefix_hex:
	pusha
	;mov ax, cx
	mov bl, 10h
	call print_ax_withprefix
	popa
	ret
print_ax_withprefix_dec:
	pusha
	;mov ax, cx
	mov bl, 0ah
	call print_ax_withprefix
	popa
	ret
print_ax_withprefix_oct:
	pusha
	;mov ax, cx
	mov bl, 8h
	call print_ax_withprefix
	popa
	ret
print_ax_withprefix_bin:
	pusha
	;mov ax, cx
	mov bl, 2h
	call print_ax_withprefix
	popa
	ret
print_ax_hex:
	pusha
	;mov ax, cx
	mov bl, 10h
	call print_ax
	popa
	ret
print_ax_dec:
	pusha
	;mov ax, cx
	mov bl, 0ah
	call print_ax
	popa
	ret
print_ax_oct:
	pusha
	;mov ax, cx
	mov bl, 8h
	call print_ax
	popa
	ret
print_ax_bin:
	pusha
	;mov ax, cx
	mov bl, 2h
	call print_ax
	popa
	ret
get_ax_logbasecountmax: ; bl = base
	;pusha
	push bx
	push cx
	push dx
	mov bh, 0
	xor cx, cx
	mov ax, 0ffffh
get_wordbase_max_start:
	cmp ax, 0
	jz get_wordbase_max_end
	xor dx, dx
	mov bh, 0
	div bx
	inc cx
	jmp get_wordbase_max_start
get_wordbase_max_end:
	mov ax, cx
	pop dx
	pop cx
	pop bx
	ret
print_prefix0: ; cx = count
	pusha
	mov cx, ax
	cmp cx, 0
	jz exit_print_prefix0
start_print_prefix0:
	mov dl, '0'
	mov ah, 2
	int 21h
	loop start_print_prefix0
exit_print_prefix0:
	popa
	ret
print_ax_withprefix: ; ax = number, bl = base
	pusha
	mov bh, 0
	xor cx, cx
	cmp ax, 0
	jnz start_divide10_withprefix
	call get_ax_logbasecountmax
	call print_prefix0
	jmp exit_print_out_withprefix
start_divide10_withprefix:
	cmp ax, 0
	jz start_print_out_withprefix
	xor dx, dx
	;mov bx, 0ah
	div bx
	push dx
	inc cx
	jmp start_divide10_withprefix
start_print_out_withprefix:
	pusha
	call get_ax_logbasecountmax
	sub ax, cx
	call print_prefix0
	popa
start_print_out_loop_withprefix:
	cmp cx, 0
	jle exit_print_out_withprefix
	pop ax
	mov bx,  hexstrtable
	xlat 
	mov dl, al
	mov ah, 02h
	int 21h
	loop start_print_out_loop_withprefix
exit_print_out_withprefix:
	popa
	ret
	
print_ax: ; ax = number, bl = base
	pusha
	mov bh, 0
	xor cx, cx
	cmp ax, 0
	jz output_zero
start_divide10:
	cmp ax, 0
	jz start_print_out
	xor dx, dx
	;mov bx, 0ah
	div bx
	push dx
	inc cx
	jmp start_divide10
start_print_out:
	cmp cx, 0
	jle exit_print_out
	pop ax
output_zero:
	mov bx, hexstrtable
	xlat 
	mov dl, al
	mov ah, 02h
	int 21h
	loop start_print_out
exit_print_out:
	popa
	ret
dump_all:
	pusha
	
	; stack dump
	push dx
	mov dx,  stackdumpstr
	call print_string
	pop dx
	mov cx, ss
	mov bx, sp
	add bx, 18
	call address_dump
	
	; pc code dump
	push dx
	mov dx,  codedumpstr
	call print_string
	pop dx
	mov cx, cs
	;call print_cssection_dump_getip
;print_cssection_dump_getip:
	;pop bx
	push ds
	mov bx, ss
	mov ds, bx
	mov bx, sp
	mov bx, word  [bx + 18]
	pop ds
	sub bx, 3
	;call print_register_detail
	;call debug_stack
	;int 3
	call address_dump
	
	; ss dump
	push dx
	mov dx,  ssstr2
	call print_string
	pop dx
	mov cx, ss
	mov bx, 0
	call address_dump
	
	; cs dump
	push dx
	mov dx,  csstr2
	call print_string
	pop dx
	mov cx, cs
	mov bx, 0
	call address_dump
	
	; ds dump
	push dx
	mov dx,  dsstr2
	call print_string
	pop dx
	mov cx, ds
	mov bx, 0
	call address_dump
	
	;es dump
	push dx
	mov dx,  esstr2
	call print_string
	pop dx
	mov cx, es
	mov bx, 0
	call address_dump
	
	popa
	ret
segment data 
	hexstrtable db '0123456789ABCDEF', 0
	axstr db 'AX = $'
	bxstr db 'BX = $'
	cxstr db 'CX = $'
	dxstr db 'DX = $'
	sistr db 'SI = $'
	distr db 'DI = $'
	bpstr db 'BP = $'
	spstr db 'SP = $'
	csstr db 'CS = $'
	dsstr db 'DS = $'
	esstr db 'ES = $'
	ssstr db 'SS = $'
	ipstr db 'IP = $'
	stackdumpstr db 'Stack dump at SP = $'
	codedumpstr db 'Code dump at IP = $'
	addressdumpstr db 'dump at = $'
	csstr2 db 'CS $'
	dsstr2 db 'DS $'
	esstr2 db 'ES $'
	ssstr2 db 'SS $'
	flagstr db 'FLAG = $'
	base2str db '2:$'
	base8str db 'b, 8:0o$'
	base10str db ', 10:$'
	base16str db ', 16:0x$'
segment stack stack 
        resb 64 
stacktop:

	