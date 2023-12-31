
#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag
 *
 * @plus_flag: on if plus_flag
 * @space_flag: hashtag_flag
 * @hashtag_flag: if_flag
 * @zero_flag: if_flag
 * @minus_flag: if_flag
 *
 * @width: field
 * @precision: field precision
 *
 * @h_modifier: h_modifier
 * @1_modifier: on 1_modifier
 *
*/

typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int hashtag_flag	: 1
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier	: 1;
	unsigned int 1_modifier	: 1;

} params_t;
/**
 * struct specifier - struct token
 *
 * @specifier:format token
 * @f: the function
*/

typedef struct specifier;
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);
int _printf(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

int print_from_to(char *start, char *stop,char *exc);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t *params, va_list ap);
char *get_precision(char *p, params_t *params, va_list ap);
int _printf(const char *format, ...);


#endif
