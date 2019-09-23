segment .data
	mensaje_division_0 db "Error: division por cero", 0
segment .bss
	__esp resd 1
segment .text
global main
extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean
main:
	mov [__esp], esp
	push dword 6
	push dword 5
	pop edx
	pop eax
	add eax, edx
	mov edx, 10
	cmp eax, edx
	jg es_mayor_0
	mov edx, 0
	jmp imprimir_y_almacenar_0
es_mayor_0:
	mov edx, 1
imprimir_y_almacenar_0:
	push edx
	call print_int
	add esp, 4
	push dword 4
	push dword 4
	pop edx
	pop eax
	add eax, edx
	mov edx, 10
	cmp eax, edx
	jg es_mayor_1
	mov edx, 0
	jmp imprimir_y_almacenar_1
es_mayor_1:
	mov edx, 1
imprimir_y_almacenar_1:
	push edx
	call print_int
	add esp, 4
	jmp fin
division_0:
	push dword mensaje_division_0
	call print_string
fin:
	mov esp, [__esp]
	ret
