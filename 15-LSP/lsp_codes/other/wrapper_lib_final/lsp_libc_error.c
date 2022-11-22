#include "lsp_error.h" 

static char dl_no_error [] = "No so error after most recent dl* call";

void *x_malloc (size_t size, ...) 
{
	void *lib_ret; 
	FETCH (size); 

	lib_ret = malloc (size); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("malloc:fatal:out of memory\n"); 
	}

	return (lib_ret); 
}

void *x_calloc (size_t nr_elements, size_t size_per_element, ...) 
{
	void *lib_ret; 
	FETCH (size_per_element); 

	lib_ret = calloc (nr_elements, size_per_element); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("calloc:fatal:out of memory\n"); 
	}
	
	return (lib_ret); 
}

void *x_realloc (void* ptr, size_t new_size, ...)
{
	void *lib_ret; 
	FETCH (new_size); 

	lib_ret = realloc (ptr, new_size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("realloc:Error in realloc\n");
	}

	return (lib_ret);
}

void *x_aligned_alloc (size_t alignment, size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	*(unsigned long int*)lib_ret = aligned_alloc (alignment, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR1 ("aligned_alloc");
	}

	return (lib_ret);
}

void *x_memalign (size_t alignment, size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	lib_ret = memalign (alignment, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR1 ("memalign");
	}

	return (lib_ret);
}

int x_posix_memalign (void **memptr, size_t alignment, size_t size, ...)
{
	int lib_ret; 
	FETCH (size); 

	lib_ret = posix_memalign (memptr, alignment, size); 

	if (*memptr == NULL)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("posix_memalign");
	}

	return (lib_ret);
}

void *x_valloc (size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	lib_ret = valloc (size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("valloc:Error in valloc");
	}

	return (lib_ret);
}

int x_mallopt (int param, int value, ...)
{
	int lib_ret; 
	FETCH (value); 

	lib_ret = mallopt (param, value); 

	if (lib_ret == 0)
	{
		HANDLE_LIB_ERROR2 ("mallopt:Error in mallopt\n");
	}

	return (lib_ret);
}

int x_mcheck (void (*abort_function) (enum mcheck_status status), ...)
{
	int lib_ret; 
	FETCH (abort_function); 

	lib_ret = mcheck (abort_function); 

	if (lib_ret == -1)
	{
		HANDLE_LIB_ERROR2 ("mcheck:Error in mcheck"); 
	}

	return (lib_ret);
}

int x_mcheck_pedantic (void (*abort_function) (enum mcheck_status status), ...)
{
	int lib_ret; 
	FETCH (abort_function); 

	lib_ret = mcheck_pedantic (abort_function); 

	if (lib_ret == -1)
	{
		HANDLE_LIB_ERROR2 ("mcheck_pedantic"); 
	}

	return (lib_ret);
}

inline void xi_mcheck_check_all (void)
{
	mcheck_check_all ();
}

inline enum mcheck_status xi_mprobe (void *ptr)
{
	mprobe (ptr);
}

inline void xi_mtrace (void)
{
	mtrace (); 
}

inline void xi_muntrace (void)
{
	muntrace ();
}

inline struct mallinfo xi_mallinfo (void)
{
	mallinfo ();
}

inline void *xi_alloca (size_t size, ...)
{
	alloca (size);
}

void x_free (void *ptr) 
{
	if (ptr != NULL) 
	{
		free (ptr); 
	}
}

void x_free2 (int nr_ptrs, ...) 
{
	int i; 
	void *ptr; 
	va_list ap; 

	va_start (ap, nr_ptrs); 
	
	for (i=0; i < nr_ptrs; i++)
	{
		ptr = va_arg (ap, void*); 
		xfree (ptr); 
	}

	va_end (ap); 
}

void x_free3 (void *ptr_arr[], int nr_elements) 
{
	int i; 

	for (i=0; i < nr_elements; i++) 
	{
		xfree (ptr_arr [i]); 
	}
}

inline void xi_cfree (void *ptr)
{
	cfree (ptr);
}

/*inline void xi_obstack_init (struct obstack *obstack_ptr)
{
	obstack_init (obstack_ptr); 
}*/

inline void *xi_obstack_alloc (struct obstack *obstack_ptr, int size)
{
	obstack_alloc (obstack_ptr, size);
}

inline void *xi_obstack_copy (struct obstack *obstack_ptr, void *address, int size)
{
	obstack_copy (obstack_ptr, address, size);
}

inline void *xi_obstack_copy0 (struct obstack *obstack_ptr, void *address, int size)
{
	obstack_copy0 (obstack_ptr, address, size);
}

inline void xi_obstack_free (struct obstack *obstack_ptr, void *object)
{
	obstack_free (obstack_ptr, object);
}

inline void xi_obstack_blank (struct obstack *obstack_ptr, int size)
{
	obstack_blank (obstack_ptr, size);
}

inline void xi_obstack_grow (struct obstack *obstack_ptr, void *data, int size)
{
	obstack_grow (obstack_ptr, data, size);
}

inline void xi_obstack_grow0 (struct obstack *obstack_ptr, void *data, int size)
{
	obstack_grow0 (obstack_ptr, data, size);
}

inline void xi_obstack_1grow (struct obstack *obstack_ptr, char c)
{
	obstack_1grow (obstack_ptr, c);
}

inline void xi_obstack_ptr_grow (struct obstack *obstack_ptr, void *data)
{
	obstack_ptr_grow (obstack_ptr, data);
}

inline void xi_obstack_int_grow (struct obstack *obstack_ptr, int data)
{
	obstack_int_grow (obstack_ptr, data); 
}

inline void xi_obstack_finish (struct obstack *obstack_ptr)
{
	obstack_finish (obstack_ptr);
}

inline int  xi_obstack_object_size (struct obstack *obstack_ptr)
{
	obstack_object_size (obstack_ptr);
}

inline	int  xi_obstack_room (struct obstack *obstack_ptr)
{
	obstack_room (obstack_ptr);
}

inline	void xi_obstack_1grow_fast (struct obstack *obstack_ptr, char c)
{
	obstack_1grow_fast (obstack_ptr, c);
}

inline	void xi_obstack_ptr_grow_fast (struct obstack *obstack_ptr, void *data)
{
	obstack_ptr_grow_fast (obstack_ptr, data);
}

inline	void xi_obstack_int_grow_fast (struct obstack *obstack_ptr, int data)
{
	obstack_int_grow_fast (obstack_ptr, data);
}

inline	void xi_obstack_blank_fast (struct obstack *obstack_ptr, int size)
{
	obstack_blank_fast (obstack_ptr, size);
}

inline	int  xi_obstack_alignment_mask (struct obstack *obstack_ptr)
{
	xi_obstack_alignment_mask (obstack_ptr);
}

inline int xi_obstack_chunk_size (struct obstack *obstack_ptr)
{
	obstack_chunk_size (obstack_ptr);
}

inline	int xi_islower (int c)
{
	islower (c);
}

inline	int xi_isupper (int c)
{
	isupper (c);
}

inline	int xi_isalpha (int c)
{
	isalpha (c);
}

inline	int xi_isdigit (int c)
{
	isdigit (c);
}

inline	int xi_isalnum (int c)
{
	isalnum (c);
}

inline	int xi_isxdigit (int c)
{
	isxdigit (c);
}

inline	int xi_ispunct (int c)
{
	ispunct (c);
}

inline	int xi_isspace (int c)
{
	isspace (c);
}

inline	int xi_isblank (int c)
{
	xi_isblank (c);
}

inline	int xi_isgraph (int c)
{
	isgraph (c);
}

inline	int xi_isprint (int c)
{
	isprint (c);
}

inline	int xi_iscntrl (int c)
{
	iscntrl (c);
}

inline	int xi_isascii (int c)
{
	isascii (c);
}

inline	int xi_toupper (int c)
{
	toupper (c);
}

inline	int xi_tolower (int c)
{	
	tolower (c);
}

inline	int xi_toascii (int c)
{
	toascii (c);
}

inline	int xi__tolower (int c)
{
	_tolower (c);
}	

inline	int xi__toupper (int c)
{
	_toupper (c);
}

inline wctype_t xi_wctype (const char *property)
{
	xi_wctype (property);
}

inline	wctype_t wctype (const char *property)
{
	wctype (property);
}

inline int xi_iswalpha (wint_t wc)
{
	iswalpha (wc);
}

inline int xi_iswcntrl (wint_t wc)
{
	iswcntrl (wc);
}

inline int xi_iswdigit (wint_t wc)
{
	iswdigit (wc);
}

inline int xi_iswalnum (wint_t wc)
{
	iswalnum (wc);
}

inline int xi_iswgraph (wint_t wc)
{
	iswgraph (wc);
}

inline int xi_iswlower (wint_t wc)
{
	iswlower (wc);
}

inline int xi_iswprint (wint_t wc)
{
	iswprint (wc);
}

inline int xi_iswpunct (wint_t wc)
{
	iswpunct (wc);
}

inline int xi_iswspace (wint_t wc)
{
	iswspace (wc);
}

inline int xi_iswupper (wint_t wc)
{
	iswupper(wc);
}

inline int xi_iswxdigit (wint_t wc)
{
	iswxdigit (wc);
}

inline int xi_iswblank (wint_t wc)
{
	iswblank (wc);
}

inline wctrans_t xi_wctrans (const char * property)
{
	wctrans (property);
}

inline wint_t xi_towctrans (wint_t wc , wctrans_t desc)
{
	toctrans (wc, desc);
}

inline wint_t xi_towlower (wint_t wc)
{
	towlower (wc);
}

inline wint_t xi_towupper (wint_t wc)
{
	towupper (wc);
}

size_t x_strlen (const char *str, ...) 
{
	size_t lib_ret; 
	FETCH (str); 

	lib_ret = strlen (str); 

	if (lib_ret < 0) 
	{
		HANDLE_LIB_ERROR2 ("strlen:Error in strlen\n"); 
	}

	return (lib_ret); 
}

size_t x_wcslen (const wchar_t *ws, ...)
{
	size_t lib_ret; 
	FETCH (ws);

	*(unsigned long int*) lib_ret = wcslen (ws); 

	if (lib_ret < 0)
	{
		HANDLE_LIB_ERROR2 ("wcslen:Error in wcslen\n"); 
	}

	return (lib_ret);
}

size_t x_strnlen (const char *str, size_t max_len, ...) 
{
	size_t lib_ret; 
	FETCH (max_len); 

	lib_ret = strnlen (str, max_len); 

	if (lib_ret < 0) 
	{
		HANDLE_LIB_ERROR2 ("strnlen:Error in strnlen\n"); 
	}

	return (lib_ret); 
}

size_t x_wcsnlen (const wchar_t *ws, size_t max_len, ...)
{
	size_t lib_ret; 
	FETCH (max_len);

	lib_ret = wcsnlen (ws, max_len); 

	if (lib_ret < 0)
	{
		HANDLE_LIB_ERROR2 ("wcsnlen:Error in wcsnlen\n"); 
	}

	return (lib_ret);
}

void *x_memcpy (void *dest, const void *src, size_t n, ...) 
{
	void *lib_ret; 
	FETCH (n); 

	lib_ret = memcpy (dest, src, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("memcpy:Error in memcpy\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wmemcpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	*(wchar_t**) lib_ret = wmemcpy (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wmemcpy:Error in wmemcpy\n");
	}

	return (lib_ret);
}

void *x_mempcpy (void *to, const void *from, size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	*(unsigned long int**) lib_ret = mempcpy (to, from, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("mempcpy:Error in mempcpy\n");
	}

	return (lib_ret);
}

wchar_t *x_wmempcpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	*(unsigned long int*) lib_ret = wmempcpy (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wmempcpy:Error in wmempcpy\n");
	}

	return (lib_ret);
}

void *x_memmove (void *dest, const void *src, size_t n, ...)
{
	void *lib_ret; 
	FETCH (n); 

	lib_ret = memmove (dest, src, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("memmove:Error in memmove\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wmemmove (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wmemmove (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wmemmove:Error in wmemmove\n");
	}

	return (lib_ret);
}

void *x_memccpy (void *dest, const void *src, int c, size_t n, ...)
{
	void *lib_ret; 
	FETCH (n); 

	lib_ret = memccpy (dest, src, c, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("memmcpy:Error in memmcpy\n");
	}

	return (lib_ret); 
}

void *x_memset (void *src, int c, size_t n, ...)
{
	void *lib_ret; 
	FETCH (n); 

	lib_ret = memset (src, c, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("memset:Error in memset\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wmemset (wchar_t *block, wchar_t wc, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wmemset (block, wc, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wmemset:Error in wmemset\n"); 
	}

	return (lib_ret);
}

char *x_strcpy (char *dest, const char *src, ...) 
{
	char *lib_ret; 
	FETCH (src); 

	lib_ret = strcpy (dest, src); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("strcpy:Error in strcpy\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wcscpy (wchar_t *wto, wchar_t *wfrom, ...)
{
	wchar_t *lib_ret; 
	FETCH (wfrom); 

	lib_ret = wcscpy (wto, wfrom); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcscpy:Error in wcscpy\n");
	}

	return (lib_ret);
}

char *x_strncpy (char *dest, const char *src, size_t n, ...) 
{
	char *lib_ret; 
	FETCH (n); 

	lib_ret = strncpy (dest, src, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("strncpy:Error in strncpy\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wcsncpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wcsncpy (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcsncpy:Error in wcsncpy\n");
	}

	return (lib_ret);
}

char *x_strdup (const char *string, ...)
{
	char *lib_ret; 
	FETCH (string); 

	lib_ret = strdup (string); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strdup:Error in strdup"); 
	}

	return (lib_ret);
}

wchar_t *x_wcsdup (const wchar_t *ws, ...)
{
	wchar_t *lib_ret; 
	FETCH (ws); 

	lib_ret = wcsdup (ws); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcsdup:Error in wcsdup\n");
	}

	return (lib_ret);
}

char *x_strndup (const char *string, size_t size, ...)
{
	char *lib_ret; 
	FETCH (size); 

	lib_ret = strndup (string, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strndup:Error in strndup\n"); 
	}

	return (lib_ret);
}

char *x_stpcpy (char *dest, const char *src, ...) 
{
	char *lib_ret; 
	FETCH (src); 

	lib_ret = stpcpy (dest, src); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("stpcpy:Error in stpcpy\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wcpcpy (wchar_t *wto, const wchar_t *wfrom, ...)
{
	wchar_t *lib_ret; 
	FETCH (wfrom); 

	lib_ret = wcpcpy (wto, wfrom); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcpcpy:Error in wcpcpy\n"); 
	}

	return (lib_ret);
}

char *x_stpncpy (char *dest, const char *src, size_t n, ...) 
{
	char *lib_ret; 
	FETCH (n); 

	lib_ret = stpncpy (dest, src, n); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("stpncpy:Error in stpncpy\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wcpncpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wcpncpy (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcpncpy:Error in wcpncpy\n");
	}

	return (lib_ret);
}

char *x_strdupa (const char *string, ...)
{
	char *lib_ret; 
	FETCH (string); 

	*(unsigned long int*)lib_ret = strdupa (string); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strdupa:Error in strdupa\n"); 
	}

	return (lib_ret);
}

char *x_strndupa (const char *string, size_t size, ...)
{
	char *lib_ret; 
	FETCH (size); 

	*(unsigned long int*)lib_ret = strndupa (string, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strndupa:Error in strndupa\n"); 
	}

	return (lib_ret);
}

char *x_strcat (char *to, const char *from, ...)
{
	char *lib_ret; 
	FETCH (from); 

	lib_ret = strcat (to, from); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strcat:Error in strcat"); 
	}

	return (lib_ret);
}

wchar_t *x_wcscat (wchar_t *wto, wchar_t *wfrom, ...)
{
	wchar_t *lib_ret; 
	FETCH (wfrom); 

	lib_ret = wcscat (wto, wfrom); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcscat:Error in wcscat\n");
	}

	return (lib_ret);
}

char *x_strncat (char *to, const char *from, size_t size, ...)
{
	char *lib_ret;
	FETCH (size); 

	lib_ret = strncat (to, from, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strncat:Error in strncat\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wcsncat (wchar_t *wto, const wchar_t *wfrom, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wcsncat (wto, wfrom, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcsncat:Error in wcsncat\n"); 
	}

	return (lib_ret);
}

inline void xi_bcopy (const void *src, void *dest, size_t n)
{
	bcopy (src, dest, n); 
}

inline void xi_bzero (void *s, size_t n)
{
	bzero (s, n); 
}

inline int xi_memcmp (const void *data_one, const void *data_two, size_t size)
{
	memcmp (data_one, data_two, size);
}

inline int xi_wmemcmp (const wchar_t *string_one, const wchar_t *string_two, size_t size)
{
	wmemcmp (string_one, string_two, size);
}

inline int xi_strcmp (const char *string_one, const char *string_two)
{
	strcmp (string_one, string_two); 
}

inline int xi_wcscmp (const wchar_t *string_one, const wchar_t *string_two)
{
	wcscmp (string_one, string_two);
}

inline int xi_strcasecmp (const char *string_one, const char *string_two)
{
	strcascmp (string_one, string_two);
}

inline int xi_wcscasecmp (const wchar_t *string_one, const wchar_t *string_two)
{
	wcscasecmp (string_one, string_two);
}

inline int xi_strncmp (const char *string_one, const char *string_two, size_t size)
{
	strncmp (string_one, string_two, size);
}

inline int xi_wcsncmp (const wchar_t *string_one, const wchar_t *string_two, size_t size)
{
	wcsncmp (string_one, string_two, size);
}

inline int xi_strncasecmp (const char *string_one, const char *string_two, size_t size)
{
	strncasecmp (string_one, string_two, size);
}

inline int xi_wcsncasecmp (const wchar_t *string_one, const wchar_t *string_two, size_t size)
{
	wcsncasecmp (string_one, string_two, size);
}

inline int xi_strverscmp (const char *string_one, const char *string_two)
{
	strverscmp (string_one, string_two);
}

inline int xi_bcmp (const void *data_one, const void *data_two, size_t size)
{
	bcmp (data_one, data_two, size);
}

inline int xi_strcoll (const char *string_one, const char *string_two)
{
	strcoll (string_one, string_two); 
}

inline int xi_wcscoll (const wchar_t *string_one, const wchar_t *string_two)
{
	wcscoll (string_one, string_two);
}

inline size_t xi_strxfrm (char *to, const char *from, size_t n)
{
	strxfrm (to,from, n);
}

inline size_t xi_wcsxfrm (wchar_t *to, const wchar_t *from, size_t n)
{
	wcsxfrm (to, from, n);
}

void *x_memchr (const void *block, int c, size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	lib_ret = memchr (block, c, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("memchr:Error in memchr\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wmemchr (const wchar_t *block, wchar_t wc, size_t size, ...)
{
	wchar_t *lib_ret; 
	FETCH (size); 

	lib_ret = wmemchr (block, wc, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wmemchr:Error in wmemchr\n"); 
	}

	return (lib_ret);
}

void *x_rawmemchr (const void *block, int c, ...)
{
	void *lib_ret; 
	FETCH (c); 

	*(unsigned long int*)lib_ret = rawmemchr (block, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("rawmemchr:Error in rawmemchr\n"); 
	}

	return (lib_ret);
}

void *x_memrchr (const void *block, int c, size_t size, ...)
{
	void *lib_ret; 
	FETCH (size); 

	*(unsigned long int*)lib_ret = memrchr (block, c, size); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("memrchr:Error in memrchr\n");
	}

	return (lib_ret);
}

char *x_strchr (const char *string, int c, ...)
{
	char *lib_ret;
	FETCH (c); 

	lib_ret = strchr (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strchr:Error in strchr\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wcschr (const wchar_t *wstring, int wc, ...)
{
	wchar_t *lib_ret; 
	FETCH (wc); 

	lib_ret = wcschr (wstring, wc); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcschr:Error in wcschr\n"); 
	}

	return (lib_ret);
}

char *x_strchrnul (const char *string, int c, ...)
{
	char *lib_ret; 
	FETCH (c); 

	*(unsigned long int*)lib_ret = strchrnul (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strchrnul:Error in strchrnul"); 
	}

	return (lib_ret);
}

wchar_t *x_wcschrnul (const char *string, int c, ...)
{
	wchar_t *lib_ret; 
	FETCH (c); 

	*(unsigned long int*) lib_ret = wcschrnul (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcschrnul:Error in wcschrnul\n");
	}

	return (lib_ret);
}

char *x_strrchr (const char *string, int c, ...)
{
	char *lib_ret; 
	FETCH (c); 

	lib_ret = strrchr (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strrchr:Error in strrchr\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wcsrstr (const wchar_t *string, wchar_t wc, ...)
{
	wchar_t *lib_ret; 
	FETCH (wc); 

	*(unsigned int*)lib_ret	= wcsrstr (string, wc); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcsrstr:Error in wcsrstr\n"); 
	}

	return (lib_ret);
}

char *x_strstr (const char *haystack, const char *needle, ...)
{
	char *lib_ret; 
	FETCH (needle); 

	lib_ret = strstr (haystack, needle); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strstr:Error in strstr\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wcsstr (const wchar_t *haystack, const wchar_t *needle, ...)
{
	wchar_t *lib_ret; 
	FETCH (needle); 

	lib_ret = wcsstr (haystack, needle); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcsstr:Error in wcsstr\n");
	}

	return (lib_ret);
}

wchar_t *x_wcswcs (const wchar_t *haystack, const wchar_t *needle, ...)
{
	wchar_t *lib_ret; 
	FETCH (needle); 

	*(unsigned long int*)lib_ret = wcswcs (haystack, needle); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcswcs:Error in wcswcs\n"); 
	}

	return (lib_ret);
}

char *x_strcasestr (const char *haystack, const char *needle, ...)
{
	char *lib_ret; 
	FETCH (needle); 

	*(unsigned long int*)lib_ret = strcasestr (haystack, needle); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strcasestr:Error in strcasestr\n"); 
	}

	return (lib_ret);
}

void *x_memmem (const void *haystack, size_t haystack_len, const void *needle, size_t needle_len, ...)
{
	void *lib_ret; 
	FETCH (needle_len); 

	*(unsigned long int*)lib_ret = memmem (haystack, haystack_len, needle, needle_len); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("memmem:Error in memmem\n"); 
	}

	return (lib_ret);
}

inline size_t xi_strspn (const char *string, const char *skip_set)
{
	strspn (string, skip_set); 
}

inline size_t xi_wcsspn (const wchar_t *string, const wchar_t *skip_set)
{
	wcsspn (string, skip_set);
}

inline size_t strcspn (const char *string, const char *stop_set)
{
	strcspn (string, stop_set); 
}

inline size_t wcscspn (const wchar_t *string, const wchar_t *stop_set)
{
	wcscspn (string, stop_set);
}

char *x_strpbrk (const char *string, const char *stop_set, ...)
{
	char *lib_ret; 
	FETCH (stop_set); 

	lib_ret = strpbrk (string, stop_set); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strpbrk:Error in strpbrk\n"); 
	}

	return (lib_ret); 
}

wchar_t *x_wcspbrk (const wchar_t *string, const wchar_t *stop_set, ...)
{
	wchar_t *lib_ret; 
	FETCH (stop_set); 

	lib_ret = wcspbrk (string, stop_set); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcspbrk:Error in wcspbrk\n"); 
	}

	return (lib_ret);
}

char *x_index (const char *string, int c, ...)
{
	char *lib_ret; 
	FETCH (c); 

	lib_ret = index (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("index:Error in index\n"); 
	}

	return (lib_ret);
}

char *x_rindex (const char *string, int c, ...)
{
	char *lib_ret; 
	FETCH (c); 

	lib_ret = rindex (string, c); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("rindex:Error in rindex\n");
	}

	return (lib_ret);
}

char *x_strtok (char *new_string, const char *delimiters, ...)
{
	char *lib_ret; 
	FETCH (delimiters); 

	lib_ret = strtok (new_string, delimiters); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strtok:Error in strtok\n"); 
	}

	return (lib_ret);
}

wchar_t *x_wcstok (wchar_t *string, const wchar_t *delimiters, wchar_t **save_ptr, ...)
{
	wchar_t *lib_ret; 
	FETCH (save_ptr); 

	lib_ret = wcstok (string, delimiters, save_ptr); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("wcstok:Error in wcstok\n"); 
	}

	return (lib_ret);
}

char *x_strtok_r (char *new_string, const char *delimiters, char **save_ptr, ...)
{
	char *lib_ret; 
	FETCH (save_ptr); 

	lib_ret = strtok_r (new_string, delimiters, save_ptr); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strtok_r:Error in strtok_r\n"); 
	}

	return (lib_ret);
}

char *x_strsep (char **string_ptr, const char *delimiters, ...)
{
	char *lib_ret; 
	FETCH (delimiters); 

	lib_ret = strsep (string_ptr, delimiters);

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strsep:Error in strsep\n");
	}

	return (lib_ret);
}

char *x_strfry (char *string, ...)
{
	char *lib_ret; 
	FETCH (string); 

	*(unsigned long int*) lib_ret = strfry (string); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("strfry:Error in strfry\n"); 
	}

	return (lib_ret);
}

void *x_memfrob (void *mem, size_t length, ...)
{
	void *lib_ret; 
	FETCH (length); 

	*(unsigned long int*) lib_ret = memfrob (mem, length); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("memfrob:Error in memfrob");
	}

	return (lib_ret);
}

inline long xi_a64l (char *str64)
{
	a64l (str64); 
}

inline char *xi_l64a (long int value)
{
	l64a (value);
}

error_t x_argz_create (char *const argv[], char **argz, size_t *argz_len, ...)
{
	error_t lib_ret; 
	FETCH (argz_len);

	lib_ret = argz_create (argv, argz, argz_len);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_len");
	}

	return (lib_ret);
}

error_t x_argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len, ...)
{
	error_t lib_ret; 
	FETCH (argz_len);

	lib_ret = argz_create_sep (string, sep, argz, argz_len);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_create_sep");
	}

	return (lib_ret);
}

error_t	x_argz_count (const char *argz, size_t arg_len, ...)
{
	error_t lib_ret; 
	FETCH (arg_len);

	lib_ret = argz_count (argz, arg_len);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_count");
	}

	return (lib_ret);
}

inline void xi_argz_extract (const char *argz, size_t argz_len, char **argv, ...)
{
	argz_extract (argz, argz_len, argv); 
}

inline void xi_argz_stringify (char *argz, size_t len, int sep)
{
	argz_stringify (argz, len, sep);
}

error_t	x_argz_add (char **argz, size_t *argz_len, const char *str, ...)
{
	error_t lib_ret; 
	FETCH (str);

	lib_ret = argz_add (argz, argz_len, str);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_add");
	}

	return (lib_ret);
}

error_t x_argz_add_sep (char **argz, size_t *argz_len, const char *string, int delim, ...)
{
	error_t lib_ret; 
	FETCH (delim);

	lib_ret = argz_add_sep (argz, argz_len, string, delim);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_add_sep");
	}

	return (lib_ret);
}

error_t x_argz_append (char **argz, size_t *argz_len, const char *buffer, size_t buffer_len, ...)
{
	error_t lib_ret; 
	FETCH (buffer_len);

	lib_ret = argz_append (argz, argz_len, buffer, buffer_len);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_append");
	}

	return (lib_ret);
}

inline void xi_argz_delete (char **argz, size_t *argz_len, char *entry)
{
	argz_delete (argz, argz_len, entry);
}

error_t x_argz_insert (char **argz, size_t *argz_len, char *before, const char *entry, ...)
{
	error_t lib_ret; 
	FETCH (entry);

	lib_ret = argz_insert (argz, argz_len, before, entry);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_insert");
	}

	return (lib_ret);
}

char *x_argz_next (const char *argz, size_t argz_len, const char *entry, ...)
{
	char *lib_ret; 
	FETCH (entry);

	lib_ret = argz_next (argz, argz_len, entry); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("argz_next:Error in argz_next\n"); 
	}

	return (lib_ret);
}

error_t	x_argz_replace (char **argz, size_t *argz_len, const char *string, const char *width, 
			unsigned int *replace_count, ...)
{
	error_t lib_ret; 
	FETCH (replace_count);

	lib_ret = argz_replace (argz, argz_len, string, width, replace_count);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("argz_replace");
	}

	return (lib_ret);
}

char *x_envz_entry (const char *envz, size_t envz_len, const char *name, ...)
{
	char *lib_ret;
	FETCH (name); 

	*(unsigned long int*) lib_ret = envz_entry (envz, envz_len, name); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("envz_entry:Error in envz_entry\n"); 
	}

	return (lib_ret);
}

char *x_envz_get (const char *envz, size_t envz_len, const char *name, ...)
{
	char *lib_ret; 
	FETCH (name); 

	*(unsigned long int*) lib_ret = envz_get (envz, envz_len, name); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR2 ("envz_get:Error in envz_get\n"); 
	}

	return (lib_ret);
}

error_t	x_envz_add (char **envz, size_t *envz_len, const char *name, const char *value, ...)
{
	error_t	lib_ret; 
	FETCH (value); 

	lib_ret = envz_add (envz, envz_len, name, value); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("envz_add"); 
	}

	return (lib_ret);
}

error_t	x_envz_merge (char **envz, size_t *envz_len, const char *envz2, size_t envz2_len, 
		      int override, ...)
{
	error_t lib_ret; 
	FETCH (override); 

	lib_ret = envz_merge (envz, envz_len, envz2, envz2_len, override); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("envz_merge"); 
	}

	return (lib_ret);
}

inline	void xi_envz_strip (char **envz, size_t *envz_len, ...)
{
	envz_strip (envz, envz_len);
}

inline int xi_atoi (const char *nptr)
{
	atoi (nptr); 
}

inline long xi_atol (const char *nptr)
{
	atol (nptr); 
}

inline long long xi_atoll (const char *nptr)
{
	atoll (nptr); 
}

FILE *x_tmpfile (int error_response, ...) 
{
	FILE *lib_ret; 
	
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
	va_end (ap); 
#endif

	lib_ret = tmpfile (); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR1("tmpfile"); 
	}

	return (lib_ret); 
}

char *x_getenv (const char *name, ...) 
{
	char *lib_ret; 
	FETCH (name); 

	lib_ret = getenv (name); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("getenv"); 
	}

	return (lib_ret); 
}

int x_setenv (const char *name, const char *value, int overwrite, ...) 
{
	int lib_ret; 
	FETCH (overwrite); 

	lib_ret = setenv (name, value, overwrite); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("setenv"); 
	}
	
	return (lib_ret); 
}

int x_unsetenv (const char *name, ...)
{
	int lib_ret; 
	FETCH (name); 

	lib_ret = unsetenv (name); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("unsetenv"); 
	}

	return (lib_ret); 
}

int x_putenv (char *string, ...)
{
	int lib_ret; 
	FETCH (string); 

	lib_ret = putenv (string); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("putenv"); 
	}

	return (lib_ret); 
}

inline int xi_setjmp (jmp_buf env)
{
	setjmp (env);
}

inline int xi_longjmp (jmp_buf env, int val)
{
	longjmp (env, val); 
}

struct passwd *x_getpwnam (const char *name, ...)
{
	struct passwd *lib_ret; 
	FETCH (name); 

	errno = 0; 
	lib_ret = getpwnam (name); 

	if ((lib_ret == NULL) && (errno != 0)) 
	{
		HANDLE_LIB_ERROR1 ("getpwnam"); 
	}

	return (lib_ret); 
}

inline void xi_exit (int status)
{
	exit (status); 
}

struct passwd *x_getpwuid (uid_t uid, ...) 
{
	struct passwd *lib_ret; 
	FETCH (uid); 

	errno = 0; 
	lib_ret = getpwuid (uid); 

	if ((lib_ret == NULL) && (errno != 0)) 
	{
		HANDLE_LIB_ERROR1 ("getpwuid"); 
	}

	return (lib_ret); 
}

int x_getpwnam_r (const char *name, struct passwd *pwd, char *buffer, size_t buffer_len, 
		  struct passwd **result, ...) 
{
	int lib_ret; 
	FETCH (result); 

	lib_ret = getpwnam_r (name, pwd, buffer, buffer_len, result); 

	if ((lib_ret != 0) && (*result == NULL)) 
	{	
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getpwnam_r"); 
	}

	return (lib_ret); 
}

int x_getpwuid_r (uid_t uid, struct passwd *pwd, char *buffer, size_t buffer_len, 
		  struct passwd **result, ...) 
{
	int lib_ret; 
	FETCH (result); 
	
	lib_ret = getpwuid_r (uid, pwd, buffer, buffer_len, result); 

	if ((lib_ret != 0) && (*result == NULL))
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getpwuid_r"); 
	}
	
	return (lib_ret); 
}

struct group *x_getgrnam (const char *name, ...) 
{
	struct group *lib_ret; 
	FETCH (name); 
	
	errno = 0; 
	lib_ret = getgrnam (name); 

	if ((lib_ret == NULL) && (errno != 0)) 
	{
		HANDLE_LIB_ERROR1 ("getgrnam"); 
	}

	return (lib_ret); 
}

struct group *x_getgrgid (gid_t gid, ...) 
{
	struct group *lib_ret; 
	FETCH (gid); 

	errno = 0; 
	lib_ret = getgrgid (gid); 

	if ((lib_ret == NULL) && (errno != 0)) 
	{
		HANDLE_LIB_ERROR1 ("getgrgid"); 
	}

	return (lib_ret); 
}

int x_getgrnam_r (const char *name, struct group *grp, char *buffer, size_t buffer_len, 
		 struct group **result, ...)
{
	int lib_ret; 
	FETCH (result); 
	
	lib_ret = getgrnam_r (name, grp, buffer, buffer_len, result); 

	if ((lib_ret != 0) && (*result == NULL))
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getgrnam_r"); 
	}
	
	return (lib_ret); 
}

int x_getgrgid_r (gid_t gid, struct group *grp, char *buffer, size_t buffer_len, 
		  struct group **result, ...)
{
	int lib_ret;
	FETCH (result); 

	lib_ret = getgrgid_r (gid, grp, buffer, buffer_len, result); 

	if ((lib_ret != 0) && (*result == NULL))
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getgrgid_r"); 
	}
	
	return (lib_ret); 
}

struct passwd *x_getpwent (int error_response, ...) 
{
	struct passwd *lib_ret; 

#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
	va_end (ap); 
#endif
	
	errno = 0; 
	lib_ret = getpwent (); 

	if ((lib_ret == NULL) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("getpwent"); 
	}

	return (lib_ret); 
}

inline void xi_setpwent (void) 
{
	setpwent (); 
}

inline void xi_endpwent (void) 
{
	endpwent (); 
}

struct spwd *x_getspnam (const char *name, ...)
{
	struct spwd *lib_ret; 
	FETCH (name); 
	
	errno = 0; 
	lib_ret = getspnam (name); 

	if ((lib_ret == NULL) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("getspnam"); 
	}

	return (lib_ret); 
}

struct spwd *x_getspent (int error_response, ...) 
{
	struct spwd *lib_ret; 

#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 
	
	errno = 0; 
	lib_ret = getspent (); 

	if ((lib_ret == NULL) && (errno != 0)) 
	{
		HANDLE_LIB_ERROR1 ("getspent"); 
	}

	return (lib_ret); 
}

inline void xi_setspent (void)
{
	setspent (); 
}

inline void xi_endspent (void) 
{
	endspent (); 
}

struct spwd *x_fgetspent (FILE *fp, ...) 
{
	struct spwd *lib_ret; 
	FETCH (fp); 

	errno = 0; 
	lib_ret = fgetspent (fp);

	if ((lib_ret == NULL) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("fgetspent"); 
	}

	return (lib_ret); 
}

struct spwd *x_sgetspent (const char *s, ...) 
{
	struct spwd *lib_ret; 
	FETCH (s); 

	errno = 0; 
	lib_ret = sgetspent (s); 

	if ((lib_ret == NULL) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("sgetspent"); 
	}

	return (lib_ret); 
}

int x_putspent (struct spwd *spw, FILE *fp, ...) 
{
	int lib_ret; 
	FETCH (fp); 

	errno = 0; 
	lib_ret = putspent (spw, fp); 

	if ((lib_ret == -1) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("putspent"); 
	}

	return (lib_ret); 
}

int x_lckpwdf (int error_response, ...) 
{
	int lib_ret; 

#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 
	
	errno = 0; 
	lib_ret = lckpwdf (); 

	if ((lib_ret == -1) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("lckpwdf"); 
	}

	return (lib_ret); 
}

int x_ulckpwdf (int error_response, ...) 
{
	int lib_ret; 

#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	errno = 0; 
	lib_ret = ulckpwdf (); 

	if ((lib_ret == -1) && (errno != 0))
	{
		HANDLE_LIB_ERROR1 ("ulckpwdf"); 
	}

	return (lib_ret); 
}

int x_getspent_r (struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		  struct spwd **result, ...) 
{
	int lib_ret; 
	FETCH (result); 

	lib_ret = getspent_r (sp_buffer, buffer, buffer_len, result); 

	if ((lib_ret != 0) && (*result == NULL)) 
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getspent_r"); 
	}

	return (lib_ret); 
}

int x_getspnam_r (const char *name, struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		  struct spwd **result, ...)
{
	int lib_ret; 
	FETCH (result); 

	lib_ret = getspnam_r (name, sp_buffer, buffer, buffer_len, result); 

	if ((lib_ret == -1) && (*result == NULL)) 
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("getspnam_r"); 
	}

	return (lib_ret); 
}

int x_fgetspent_r (FILE *fp, struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		   struct spwd **result, ...) 
{
	int lib_ret; 
	FETCH (result); 

	lib_ret = fgetspent_r (fp, sp_buffer, buffer, buffer_len, result); 

	if ((lib_ret == -1) && (*result == NULL)) 
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("fgetspent_r"); 
	}

	return (lib_ret); 
}

int x_sgetspent_r (const char *s, struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		   struct spwd **result, ...) 
{
	int lib_ret; 
	FETCH (result); 

	lib_ret = sgetspent_r (s, sp_buffer, buffer, buffer_len, result); 

	if ((lib_ret == -1) && (*result == NULL))
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("sgetspent_r"); 
	}

	return (lib_ret); 
}

char *x_crypt (const char *key, const char *salt, ...) 
{
	char *lib_ret; 
	FETCH (salt); 

	lib_ret = crypt (key, salt); 
	
	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("crypt:Error in crypt\n"); 
	}

	return (lib_ret); 

}

char *x_getpass (const char *prompt, ...) 
{
	char *lib_ret; 
	FETCH (prompt); 

	lib_ret = getpass (prompt); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR1 ("getpass"); 
	}

	return (lib_ret); 
}

int x_initgroups (const char *user, gid_t gid, ...) 
{
	int lib_ret; 
	FETCH (gid); 

	lib_ret = initgroups (user, gid); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("initgroups"); 
	}

	return (lib_ret); 
}

char *x_asctime (const struct tm *tm, ...)
{
	char *lib_ret; 
	FETCH (tm); 

	lib_ret = asctime (tm); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("asctime:Error in asctime\n"); 
	}

	return (lib_ret); 
}

char *x_asctime_r (const struct tm *tm, char *buffer, ...) 
{
	char *lib_ret; 
	FETCH (buffer); 

	lib_ret = asctime_r (tm, buffer); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("asctime_r:Error in asctime_r\n");
	}

	return (lib_ret); 
}

char *x_ctime (const time_t *timep, ...) 
{
	char *lib_ret; 
	FETCH (timep); 

	lib_ret = ctime (timep); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("ctime:Error in ctime\n"); 
	}

	return (lib_ret); 
}

char *x_ctime_r (const time_t *timep, char *buffer, ...)
{
	char *lib_ret; 
	FETCH (buffer); 

	lib_ret = ctime_r (timep, buffer);

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("ctime_r:Error in ctime_r\n"); 
	}

	return (lib_ret); 
}

struct tm *x_gmtime (const time_t *timep, ...) 
{
	struct tm *lib_ret; 
	FETCH (timep); 

	lib_ret = gmtime (timep); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("gmtime:Error in gmtime\n"); 
	}

	return (lib_ret); 
}

struct tm *x_gmtime_r (const time_t *timep, struct tm *result, ...) 
{
	struct tm *lib_ret; 
	FETCH (result); 

	lib_ret = gmtime_r (timep, result); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("gmtime_r:Error in gmtime_r\n"); 
	}

	return (lib_ret); 
}


struct tm *x_localtime (const time_t *timep, ...) 
{
	struct tm *lib_ret; 
	FETCH (timep); 

	lib_ret = localtime (timep); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("localtime:Error in localtime\n"); 
	}

	return (lib_ret); 
}

struct tm *x_localtime_r (const time_t *timep, struct tm *result, ...) 
{
	struct tm *lib_ret; 
	FETCH (result); 

	lib_ret = localtime_r (timep, result); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("localtime_r:Error in localtime_r\n"); 
	}

	return (lib_ret); 
}

time_t x_mktime (struct tm *tm, ...)
{
	time_t lib_ret; 
	FETCH (tm); 

	lib_ret = mktime (tm); 

	if ((long int) lib_ret == -1) 
	{
		HANDLE_LIB_ERROR2 ("mktime:Error in mktime\n"); 
	}

	return (lib_ret); 
}

size_t x_strftime (char *buffer, size_t buffer_len, const char *format, struct tm *tm, ...) 
{
	size_t lib_ret; 
	FETCH (tm); 

	lib_ret = strftime (buffer, buffer_len, format, tm); 
	
	if ((long int)lib_ret == -1)
	{
		HANDLE_LIB_ERROR2 ("strftime:Either buffer too small or empty string returned\n"); 
	}

	return (lib_ret); 
}

char *x_strptime (const char *buffer, const char *format, struct tm *tm, ...) 
{
	char *lib_ret; 
	FETCH (tm); 

	*(unsigned long int*)lib_ret = strptime (buffer, format, tm); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("strptime:Error in strptime\n"); 
	}

	return (lib_ret); 
}

char *x_setlocale (int category, const char *locale, ...)
{
	char *lib_ret; 
	FETCH (locale); 

	lib_ret = setlocale (category, locale); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("setlocale:Request cannot be fulfilled\n"); 
	}

	return (lib_ret); 
}

int x_adjtime (const struct timeval *delta, struct timeval *old_delta, ...) 
{
	int lib_ret; 
	FETCH (old_delta); 

	lib_ret = adjtime (delta, old_delta); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("adjtime"); 
	}

	return (lib_ret); 
}

clock_t x_clock (int error_response, ...) 
{
	clock_t lib_ret; 

#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
	va_end (ap); 
#endif 

	lib_ret = clock (); 

	if ((long int) lib_ret == -1) 
	{
		HANDLE_LIB_ERROR2 ("clock:Error in clock\n"); 
	}

	return (lib_ret); 
}

inline void xi_setbuf (FILE *fp, char *buffer)
{
	setbuf (fp, buffer); 
}

inline void xi_setbuffer (FILE *fp, char *buffer, size_t buffer_len)
{
	setbuffer (fp, buffer, buffer_len); 
}

inline void xi_setlinebuf (FILE *fp)
{
	setlinebuf (fp); 
}

int x_setvbuf (FILE *fp, char *buffer, int mode, size_t size, ...) 
{
	int lib_ret; 
	FETCH (size); 
	
	errno = 0; 
	lib_ret = setvbuf (fp, buffer, mode, size); 

	if (lib_ret == -1) 
	{
		if (errno == 0)
		{
			HANDLE_LIB_ERROR2 ("setvbuf:Error in setvbuf\n"); 
		}
		else
		{
			HANDLE_LIB_ERROR1 ("setvbuf"); 
		}
	}

	return (lib_ret); 
}

int x_fflush (FILE *stream, ...) 
{
	int lib_ret; 
	FETCH (stream); 

	lib_ret = fflush (stream); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("fflush"); 
	}

	return (lib_ret); 
}

int x_fileno (FILE *stream, ...) 
{
	int lib_ret; 
	FETCH (stream); 

	lib_ret = fileno (stream); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("fileno"); 
	}

	return (lib_ret); 
}

FILE *x_fdopen (int fd, const char *mode, ...)
{
	FILE *lib_ret; 
	FETCH (mode); 

	lib_ret = fdopen (fd, mode); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR1 ("fdopen"); 
	}

	return (lib_ret); 
}

acl_t x_acl_init(int count, ...)
{
     acl_t lib_ret; 
     FETCH (count); 
     
     lib_ret = acl_init (count); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_init"); 
     }
     
     return (lib_ret); 
}

acl_t x_acl_dup(acl_t acl, ...)
{
     acl_t lib_ret; 
     FETCH (acl); 
     
     lib_ret = acl_dup (acl); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_dup"); 
     }
     
     return (lib_ret); 
}

int x_acl_free(void *obj_p, ...)
{
     int lib_ret; 
     FETCH (obj_p);
     
     lib_ret = acl_free (obj_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_free"); 
     }
}

int x_acl_valid(acl_t acl, ...)
{
     int lib_ret; 
     FETCH (acl); 
     
     lib_ret = acl_valid (acl); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_valid"); 
     }
     
     return (lib_ret); 
}

int x_acl_copy_entry(acl_entry_t dest_d, acl_entry_t src_d, ...)
{
     int lib_ret; 
     FETCH (src_d); 
     
     lib_ret = acl_copy_entry (dest_d, src_d); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_copy_entry");
     }
     
     return (lib_ret); 
}
int x_acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p, ...)
{
     int lib_ret;  
     FETCH (entry_p); 
     
     lib_ret = acl_create_entry (acl_p, entry_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_create_entry"); 
     }
     
     return (lib_ret); 
}

int x_acl_delete_entry(acl_t acl, acl_entry_t entry_d, ...)
{
     int lib_ret; 
     FETCH (entry_d); 
	  
     lib_ret = acl_delete_entry (acl, entry_d); 
	  
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_delete_entry"); 
     }

     return (lib_ret);
}

int x_acl_get_entry(acl_t acl, int entry_id, acl_entry_t *entry_p, ...)
{
     int lib_ret; 
     FETCH (entry_p); 
     
     lib_ret = acl_get_entry (acl, entry_id, entry_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_get_entry"); 
     }
     
     return (lib_ret);
}

int x_acl_add_perm(acl_permset_t permset_d, acl_perm_t perm, ...)
{
     int lib_ret; 
     FETCH (perm); 
     
     lib_ret = acl_add_perm (permset_d, perm); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_add_perm"); 
     }
     
     return (lib_ret); 
}

int x_acl_calc_mask(acl_t *acl_p, ...)
{
    int lib_ret; 
    FETCH (acl_p); 
    
    lib_ret = acl_calc_mask (acl_p); 
    
    if (lib_ret == -1) 
    {
	HANDLE_LIB_ERROR1 ("acl_calc_mask");  
    }
    
    return (lib_ret); 
}

int x_acl_clear_perms(acl_permset_t permset_d, ...)
{
     int lib_ret; 
     FETCH (permset_d); 
     
     lib_ret = acl_clear_perms (permset_d); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_clear_perms"); 
     }
     
     return (lib_ret); 
}

int x_acl_delete_perm(acl_permset_t permset_d, acl_perm_t perm, ...)
{
     int lib_ret; 
     FETCH (perm); 
     
     lib_ret = acl_delete_perm (permset_d, perm); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_delete_perm"); 
     }
     
     return (lib_ret); 
}

int x_acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p, ...)
{
     int lib_ret; 
     FETCH (permset_p); 
     
     lib_ret = acl_get_permset (entry_d, permset_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_permset"); 
     }
     
     return (lib_ret); 
}

int x_acl_set_permset(acl_entry_t entry_d, acl_permset_t permset_d, ...)
{
     int lib_ret; 
     FETCH (permset_d); 
     
     lib_ret = acl_set_permset (entry_d, permset_d); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_set_permset"); 
     }
     
     return (lib_ret); 
}

void *x_acl_get_qualifier(acl_entry_t entry_d, ...)
{
     void *lib_ret; 
     FETCH (entry_d); 
     
     lib_ret = acl_get_qualifier (entry_d); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("acl_get_qualifier"); 
     }
     
     return (lib_ret); 
}

int x_acl_get_tag_type(acl_entry_t entry_d, acl_tag_t *tag_type_p, ...)
{
     int lib_ret; 
     FETCH (tag_type_p); 
     
     lib_ret = acl_get_tag_type (entry_d, tag_type_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_get_tag_type"); 
     }
     
     return (lib_ret); 
}

int x_acl_set_qualifier(acl_entry_t entry_d, const void *tag_qualifier_p, ...)
{
     int lib_ret; 
     FETCH (tag_qualifier_p); 
     
     lib_ret = acl_set_qualifier (entry_d, tag_qualifier_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_set_qualifier"); 
     }
     
     return (lib_ret); 
}

int x_acl_set_tag_type(acl_entry_t entry_d, acl_tag_t tag_type, ...)
{
     int lib_ret; 
     FETCH (tag_type); 
     
     lib_ret = acl_set_tag_type (entry_d, tag_type); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_set_tag_type"); 
     }
     
     return (lib_ret); 
}

ssize_t x_acl_copy_ext(void *buf_p, acl_t acl, ssize_t size, ...)
{
     ssize_t lib_ret; 
     FETCH (size); 
     
     lib_ret = acl_copy_ext (buf_p, acl, size); 
     
     if ((long int) lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_copy_ext"); 
     }
     
     return (lib_ret);
}

acl_t x_acl_copy_int(const void *buf_p, ...)
{
     acl_t lib_ret; 
     FETCH (buf_p); 
     
     lib_ret = acl_copy_int (buf_p); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_copy_int"); 
     }
     
     return (lib_ret); 
}

acl_t x_acl_from_text(const char *buf_p, ...)
{
     acl_t lib_ret;
     FETCH (buf_p); 
     
     lib_ret = acl_from_text (buf_p); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_from_text"); 
     }
     
     return (lib_ret); 
}

ssize_t x_acl_size(acl_t acl, ...)
{
     ssize_t lib_ret; 
     FETCH (acl); 
     
     lib_ret = acl_size (acl); 
     
     if ((long int) lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_size"); 
     }
     
     return (lib_ret); 
}

char *x_acl_to_text(acl_t acl, ssize_t *len_p, ...)
{
     char *lib_ret; 
     FETCH (len_p); 
     
     lib_ret = acl_to_text (acl, len_p);
     
     if (lib_ret == NULL)
     {
	  HANDLE_LIB_ERROR1 ("acl_to_text"); 
     }
     
     return (lib_ret);
}

int x_acl_delete_def_file(const char *path_p, ...)
{
     int lib_ret; 
     FETCH (path_p); 
     
     lib_ret = acl_delete_def_file (path_p); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_detele_def_file"); 
     }

     return (lib_ret); 
}

acl_t x_acl_get_fd(int fd, ...)
{
     acl_t lib_ret; 
     FETCH (fd); 
     
     lib_ret = acl_get_fd (fd); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_get_fd"); 
     }
     
     return (lib_ret);
}

acl_t x_acl_get_file(const char *path_p, acl_type_t type, ...)
{
     acl_t lib_ret;
     FETCH (type);
     
     lib_ret = acl_get_file (path_p, type); 
     
     if ((long int)lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_get_file"); 
     }
     
     return (lib_ret); 
}

int x_acl_set_fd(int fd, acl_t acl, ...)
{
     int lib_ret; 
     FETCH (acl); 
     
     lib_ret = acl_set_fd (fd, acl); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_set_fd"); 
     }
     
     return (lib_ret);
}

int x_acl_set_file(const char *path_p, acl_type_t type, acl_t acl, ...)
{
     int lib_ret; 
     FETCH (acl); 
     
     lib_ret = acl_set_file (path_p, type, acl); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("acl_set_file"); 
     }

     return (lib_ret);
}

DIR *x_opendir (const char *name, ...)
{
     DIR *lib_ret; 
     FETCH (name); 
     
     lib_ret = opendir (name); 
     
     if (lib_ret == NULL)
     {
	  HANDLE_LIB_ERROR1 ("opendir"); 
     }
     
     return (lib_ret);
}

DIR *x_fdopendir (int fd, ...)
{
     DIR *lib_ret; 
     FETCH (fd); 
     
     lib_ret = fdopendir (fd); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("fdopendir"); 
     }
     
     return (lib_ret);
}

struct dirent *x_readdir (DIR *dirp, ...)
{
     struct dirent *lib_ret; 
     FETCH (dirp); 
     
     errno = 0; 
     lib_ret = readdir (dirp); 
     
     if ((lib_ret == NULL) && (errno != 0)) 
     {
	  HANDLE_LIB_ERROR1 ("readdir"); 
     }
     
     return (lib_ret);
}

int x_readdir_r (DIR *dirp, struct dirent *entry, struct dirent **result, ...)
{
     int lib_ret; 
     FETCH (result); 
     
     lib_ret = readdir_r (dirp, entry, result); 
     
     if (lib_ret != 0) 
     {
	  errno = lib_ret; 
	  HANDLE_LIB_ERROR1 ("readdir_r"); 
     }
     
     return (lib_ret);
}

inline void xi_rewinddir (DIR *dirp)
{
     rewinddir (dirp);
}

inline void xi_seekdir (DIR *dirp, long int loc)
{
     seekdir (dirp, loc); 
}

long int x_telldir (DIR *dirp, ...) 
{
     long int lib_ret; 
     FETCH (dirp); 
     
     lib_ret = telldir (dirp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("telldir"); 
     }
     
     return (lib_ret); 
}

int x_dirfd (DIR *dirp, ...) 
{
     int lib_ret; 
     FETCH (dirp); 
     
     lib_ret = dirfd (dirp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("dirfd"); 
     }
     
     return (lib_ret); 
}

int x_closedir (DIR *dirp, ...)
{
     int lib_ret; 
     FETCH (dirp);
     
     lib_ret = closedir (dirp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("closedir"); 
     }
     
     return (lib_ret);
}

int x_ftw (const char *dir_path, int (*fn) (const char *f_path, const struct stat *sb, 
	  int type_flag), int nr_openfd, ...)
{
     int lib_ret; 
     FETCH (nr_openfd); 
     
     lib_ret = ftw (dir_path, fn, nr_openfd); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("ftw:Error in ftw\n"); 
     }
     
     return (lib_ret); 
}

int x_nftw (const char *dir_path, int (*fn) (const char *f_path, const struct stat *sb, 
	   int typeflag, struct FTW *ftw_buffer), int nr_openfd, int flags, ...)
{
     int lib_ret; 
     FETCH (flags); 
     
     lib_ret = nftw (dir_path, fn, nr_openfd, flags); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("nftw:Error in nftw\n"); 
     }
     
     return (lib_ret);
}

char *x_realpath (const char *path, char *resolved_path, ...) 
{
     char* lib_ret;
     FETCH (resolved_path); 
     
     lib_ret = realpath (path, resolved_path); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("realpath"); 
     }
     
     return (lib_ret); 
}

char *x_basename (char *path, ...) 
{
     char *lib_ret; 
     FETCH (path); 
     
     lib_ret = basename (path); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR2 ("basename:Error in basename\n"); 
     }
     
     return (lib_ret); 
}

char *x_dirname (char *path, ...)
{
     char *lib_ret; 
     FETCH (path); 
     
     lib_ret = dirname (path); 
     
     if (lib_ret == NULL)
     {
	  HANDLE_LIB_ERROR2 ("dirname:Error in dirname\n"); 
     }
     
     return (lib_ret);
}

int x_raise (int signal_number, ...) 
{
     int lib_ret; 
     FETCH (signal_number); 
     
     errno = 0; 
     lib_ret = raise (signal_number); 
     
     if (lib_ret == -1) 
     {
	  if (errno != 0) 
	  {
	       HANDLE_LIB_ERROR1 ("raise"); 
	  }
	  else
	  {
	       HANDLE_LIB_ERROR2 ("raise:Error in raise\n"); 
	  }
     }
     
     return (lib_ret); 
}

int x_siginterrupt (int signal_number, int flag, ...) 
{
     int lib_ret; 
     FETCH (flag); 
     
     lib_ret = siginterrupt (signal_number, flag); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("siginterrupt"); 
     }
     
     return (lib_ret);
}

int x_sigwait (const sigset_t *set, int *sig, ...) 
{
     int lib_ret; 
     FETCH (sig); 
     
     lib_ret = sigwait (set, sig); 
     if (lib_ret != 0) 
     {
	  lib_ret = errno; 
	  HANDLE_LIB_ERROR2 ("sigwait:Error in sigwait\n"); 
     }

     return (lib_ret);
}

int x_sigqueue (pid_t pid, int signal_number, const union sigval value, ...)
{
     int lib_ret; 
     FETCH (value); 
     
     lib_ret = sigqueue (pid, signal_number, value);
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("sigqueue"); 
     }
     
     return (lib_ret); 
}

int x_sigemptyset (sigset_t *set, ...)
{
    int lib_ret; 
    FETCH (set); 
    
    lib_ret = sigemptyset (set); 
    
    if (lib_ret == -1) 
    {
	HANDLE_LIB_ERROR1 ("sigemptyset");  
    }
    
    return (lib_ret); 
}

int x_sigfillset (sigset_t *set, ...)
{
     int lib_ret; 
     FETCH (set); 
     
     lib_ret = sigfillset (set); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("sigfillset"); 
     }
     
     return (lib_ret); 
}

int x_sigaddset (sigset_t *set, int signal_number, ...)
{
     int lib_ret; 
     FETCH (signal_number); 
     
     lib_ret = sigaddset (set, signal_number); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("sigaddset"); 
     }
     
     return (lib_ret); 
}

int x_sigdelset (sigset_t *set, int signal_number, ...)
{
     int lib_ret; 
     FETCH (signal_number); 
     
     lib_ret = sigdelset (set, signal_number); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("sigdelset"); 
     }
     
     return (lib_ret); 
}

int x_sigismember (sigset_t *set, int signal_number, ...)
{
     int lib_ret; 
     FETCH (signal_number); 
     
     lib_ret = sigismember (set, signal_number); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("sigismember"); 
     }
     
     return (lib_ret); 
}

int x_sigisemptyset (sigset_t *set, ...) 
{
     int lib_ret; 
     FETCH (set); 
     
     errno = 0; 
     lib_ret = sigisemptyset (set); 
     
     if (lib_ret == -1) 
     {
	  if (errno != 0) 
	  {
	       HANDLE_LIB_ERROR1 ("sigisemptyset"); 
	  }
	  else
	  {
	       HANDLE_LIB_ERROR2 ("sigisemptyset:Error in sigisemptyset\n");
	  }
     }
     
     return (lib_ret); 
}

int x_sigorset (sigset_t *dest, sigset_t *left, sigset_t *right, ...) 
{
     int lib_ret; 
     FETCH (right); 
     
     errno = 0; 
     lib_ret = sigorset (dest, left, right); 
     
     if (lib_ret == -1) 
     {
	  if (errno != 0) 
	  {
	       HANDLE_LIB_ERROR1 ("sigorset"); 
	  }
	  else
	  {
	       HANDLE_LIB_ERROR2 ("sigorset:Error in sigorset\n"); 
	  }
     }
     
     return (lib_ret); 
}

int x_sigandset (sigset_t *dest, sigset_t *left, sigset_t *right, ...) 
{
     int lib_ret; 
     FETCH (right); 
     
     errno = 0; 
     lib_ret = sigandset (dest, left, right); 
     
     if (lib_ret == -1) 
     {
	  if (errno != 0) 
	  {
	       HANDLE_LIB_ERROR1 ("sigandset"); 
	  }
	  else
	  {
	       HANDLE_LIB_ERROR2 ("sigandset:Error in sigandset\n"); 
	  }
     }
     
     return (lib_ret); 
}

inline char *xi_strsignal (int signal_number)
{
     strsignal (signal_number); 
}

inline void xi_psignal (int signal_number, const char *str)
{
	  psignal (signal_number, str); 
}

inline void xi_psiginfo (const siginfo_t *pinfo, const char *str)
{
     psiginfo (pinfo, str); 
}

inline unsigned int xi_sleep (unsigned int seconds) 
{
	sleep (seconds); 
}

int x_clock_getcpuclockid (pid_t pid, clockid_t *clock_id, ...)
{
	int lib_ret; 
	FETCH (clock_id); 

	lib_ret = clock_getcpuclockid (pid, clock_id); 
	
	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("clock_getcpuclockid"); 
	}

	return (lib_ret); 
	
}

int x_atexit (void (*exit_handler)(void), ...) 
{
	int lib_ret; 
	FETCH (exit_handler); 

	lib_ret = atexit (exit_handler); 

	if (lib_ret != 0)
	{
		HANDLE_LIB_ERROR2 ("atexit:Error in atexit\n"); 
	}

	return (lib_ret); 
}

int x_on_exit (void (*exit_handler) (int, void*), void *arg, ...) 
{
	int lib_ret; 
	FETCH (arg); 

	lib_ret = on_exit (exit_handler, arg); 

	if (lib_ret != 0)
	{
		HANDLE_LIB_ERROR2 ("on_exit:Error in on_exit\n"); 
	}

	return (lib_ret); 
}

pid_t x_waitpid (pid_t pid, int *status, int options, ...) 
{
	pid_t lib_ret; 
	FETCH (options); 

	lib_ret = waitpid (pid, status, options); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR2 ("waitpid:Error in waitpid\n"); 
	}

	return (lib_ret); 
	
}

char *x_ctermid (char *str, ...) 
{
	char *lib_ret; 
	FETCH (str); 

	lib_ret == ctermid (str); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR2 ("ctermid:Error in ctermid\n"); 
	}

	return (lib_ret); 
}

int x_tcgetpgrp (int fd, ...) 
{
	int lib_ret; 
	FETCH (fd); 

	lib_ret = tcgetpgrp (fd); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("tcgetpgrp"); 
	}

	return (lib_ret); 
}

int x_tcsetpgrp (int fd, pid_t pgrp, ...) 
{
	int lib_ret; 
	FETCH (pgrp); 

	lib_ret = tcsetpgrp (fd, pgrp); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("tcsetpgrp"); 
	}

	return (lib_ret); 
}

inline void xi_openlog (const char *indent, int option, int facility)
{
	openlog (indent, option, facility); 
}

inline void xi_closelog (void) 
{
	closelog (); 
}

inline int xi_setlogmask (int mask)
{
	setlogmask (mask);
}

struct utmp *x_getutent (int error_response, ...)
{
     struct utmp *lib_ret;
#ifdef DEBUG 
     char *src_file_name; 
     int src_nr_line; 
     va_list ap; 
     va_start (ap, error_response); 
     src_file_name = va_arg (ap, char*); 
     src_nr_line = va_arg (ap, int); 
     va_end (ap); 
#endif 
     
     lib_ret = getutent (); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("getutent"); 
     }
     
     return (lib_ret); 
}

struct utmp *x_getutid (struct utmp *ut, ...)
{
     struct utmp *lib_ret; 
     FETCH (ut); 
     
     lib_ret = getutid (ut); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("getutid");
     }
     
     return (lib_ret); 
}

struct utmp *x_getutline (struct utmp *ut, ...)
{
     struct utmp *lib_ret; 
     FETCH (ut); 
     
     lib_ret = getutline (ut); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("getutline"); 
     }
     
     return (lib_ret); 
}

struct utmp *x_pututline (struct utmp *ut, ...)
{
     struct utmp *lib_ret; 
     FETCH (ut); 
     
     lib_ret = pututline (ut); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("pututline"); 
     }
     
     return (lib_ret); 
}

inline void xi_setutent (void)
{
     setutent (); 
}

inline void xi_endutent (void)
{
     endutent (); 
}

int x_utmpname (const char *file, ...)
{
     int lib_ret; 
     FETCH (file); 
     
     lib_ret = utmpname (file); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR1 ("utmpname");
     }
     
     return (lib_ret); 
}

int x_getutline_r(struct utmp *ut, struct utmp *ubuf, struct utmp **ubufp, ...)
{
     int lib_ret; 
     FETCH (ubufp); 
     
     lib_ret = getutline_r (ut, ubuf, ubufp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("getutline_r:Error in getutline_r\n"); 
     }
     
     return (lib_ret); 
}

int x_getutent_r(struct utmp *ubuf, struct utmp **ubufp, ...)
{
     int lib_ret; 
     FETCH (ubufp); 
     
     lib_ret = getutent_r (ubuf, ubufp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("getutent_r:Error in getutent_r\n"); 
     }
     
     return (lib_ret); 
}

int x_getutid_r(struct utmp *ut, struct utmp *ubuf, struct utmp **ubufp, ...)
{
     int lib_ret; 
     FETCH (ubufp); 
     
     lib_ret = getutid_r (ut, ubuf, ubufp); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("getutid_r:Error in getutid_r\n"); 
     }
     
     return (lib_ret); 
}

char *x_getlogin(int error_response, ...)
{
     char *lib_ret; 
#ifdef DEBUG 
     char *src_file_name; 
     int src_nr_line; 
     va_list ap; 
     va_start (ap, error_response); 
     src_file_name = va_arg (ap, char*); 
     src_nr_line = va_arg (ap, int); 
     va_end (ap); 
#endif 
     
     lib_ret = getlogin (); 
     
     if (lib_ret == NULL) 
     {
	  HANDLE_LIB_ERROR1 ("getlogin"); 
     }
     
     return (lib_ret);
}

int x_getlogin_r(char *buf, size_t bufsize, ...)
{
     int lib_ret; 
     FETCH (bufsize); 
     
     lib_ret = getlogin_r (buf, bufsize); 
     
     if (lib_ret == -1) 
     {
	  HANDLE_LIB_ERROR2 ("getlogin_r:Error in getlogin_r\n"); 
     }
     
     return (lib_ret);
}

inline void xi_updwtmp(const char *wtmp_file, const struct utmp *ut)
{
     updwtmp (wtmp_file, ut); 
}

inline void xi_logwtmp(const char *line, const char *name, const char *host)
{
     logwtmp (line, name, host); 
}

char *x_dlerror (void) 
{
	char *lib_ret; 

	lib_ret = dlerror (); 

	if (lib_ret != NULL) 
	{
		return (lib_ret); 
	}
	else
	{
		return (dl_no_error); 
	}
}

void *x_dlopen (const char *file_name, int flag, ...)
{
	void *lib_ret; 
	char *error_message; 
	FETCH (flag); 

	lib_ret = dlopen (file_name, flag); 

	if (lib_ret == NULL) 
	{
		error_message = x_dlerror (); 
		HANDLE_LIB_ERROR2 ("%s\n", error_message); 		
		xdlerror (); 
	}

	return (lib_ret); 
}

void *x_dlsym (void *handle, const char *symbol, ...) 
{
	void *lib_ret; 
	char *error_message; 
	FETCH (symbol); 

	lib_ret = dlsym (handle, symbol); 

	if (lib_ret == NULL) 
	{
		error_message = x_dlerror (); 
		HANDLE_LIB_ERROR2 ("error_message"); 
		xdlerror (); 
	}

	return (lib_ret); 
}

int x_dlclose (void *handle, ...) 
{
	int lib_ret; 
	char *error_message; 
	FETCH (handle); 

	lib_ret = dlclose (handle); 

	if (lib_ret == -1) 
	{
		error_message = x_dlerror(); 
		HANDLE_LIB_ERROR2 ("%s\n", error_message); 
		xdlerror (); 
	}

	return (lib_ret); 
}

FILE *x_popen (const char *command, const char *type, ...) 
{
	FILE *lib_ret; 
	FETCH (type); 

	lib_ret = popen (command, type); 

	if (lib_ret == NULL) 
	{
		HANDLE_LIB_ERROR1 ("popen"); 	
	}

	return (lib_ret); 
}

int x_pclose (FILE *stream, ...) 
{
	int lib_ret; 
	FETCH (stream); 

	lib_ret = pclose (stream); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("pclose"); 
	}

	return (lib_ret); 
}

int x_mkfifo (const char *path_name, mode_t mode, ...) 
{
	int lib_ret; 
	FETCH (mode); 

	lib_ret = mkfifo (path_name, mode); 
	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mkfifo"); 
	}

	return (lib_ret); 
}

key_t x_ftok (const char *path_name, int proj_id, ...) 
{
	key_t lib_ret; 
	FETCH (proj_id); 

	lib_ret = ftok (path_name, proj_id); 

	if ((int) lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("ftok"); 
	}

	return (lib_ret); 
}

int x_mq_getattr (mqd_t mq_des, struct mq_attr *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = mq_getattr (mq_des, attr); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_getattr"); 
	}

	return (lib_ret); 
}

int x_mq_setattr (mqd_t mq_des, struct mq_attr *new_attr, struct mq_attr *old_attr, ...)
{
	int lib_ret; 
	FETCH (old_attr); 

	lib_ret = mq_setattr (mq_des, new_attr, old_attr); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_setattr"); 
	}

	return (lib_ret); 
}

int x_mq_send (mqd_t mq_des, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, ...)
{
	int lib_ret; 
	FETCH (msg_prio); 

	lib_ret = mq_send (mq_des, msg_ptr, msg_len, msg_prio); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_send"); 
	}

	return (lib_ret); 
}

int x_mq_timedsend (mqd_t mq_des, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, 
		       const struct timespec *abs_timeout, ...)
{
	int lib_ret; 
	FETCH (abs_timeout); 

	lib_ret = mq_timedsend (mq_des, msg_ptr, msg_len, msg_prio, abs_timeout); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_timedsend"); 
	}

	return (lib_ret); 
}

ssize_t x_mq_receive (mqd_t mq_des, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, ...)
{
	ssize_t lib_ret; 
	FETCH (msg_prio); 

	lib_ret = mq_receive (mq_des, msg_ptr, msg_len, msg_prio); 

	if ((int) lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_receive"); 
	}

	return (lib_ret); 
}

ssize_t x_mq_timedreceive (mqd_t mq_des, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, 
                          const struct timespec *abs_timeout, ...)
{
	ssize_t lib_ret; 
	FETCH (abs_timeout); 

	lib_ret = mq_timedreceive (mq_des, msg_ptr, msg_len, msg_prio, abs_timeout); 

	if ((int) lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_timedreceive"); 
	}

	return (lib_ret); 
}

int x_mq_notify (mqd_t mq_des, const struct sigevent *sevp, ...)
{
	int lib_ret; 
	FETCH (sevp); 

	lib_ret = mq_notify (mq_des, sevp); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("mq_notify"); 
	}

	return (lib_ret);
}

int x_shm_open(const char *name, int oflag, mode_t mode, ...)
{
	int lib_ret; 
	FETCH (mode); 

	lib_ret = shm_open (name, oflag, mode); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("shm_open"); 
	}

	return (lib_ret); 
}

int x_shm_unlink(const char *name, ...)
{
	int lib_ret; 
	FETCH (name); 

	lib_ret = shm_unlink (name); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("shm_unlink"); 
	}

	return (lib_ret); 
}

sem_t *x_sem_open (const char *name, int oflag, mode_t mode, unsigned int value, ...)
{
	sem_t *lib_ret; 
	FETCH (value); 

	lib_ret = sem_open (name, oflag, mode, value); 

	if (lib_ret == NULL)
	{
		HANDLE_LIB_ERROR1 ("sem_open"); 
	}

	return (lib_ret); 
}

int x_sem_close (sem_t *sem, ...)
{
	int lib_ret;
	FETCH (sem); 

	lib_ret = sem_close (sem); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_close"); 
	}

	return (lib_ret); 
}

int x_sem_unlink (const char *name, ...)
{
	int lib_ret; 
	FETCH (name); 

	lib_ret = sem_unlink (name); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_unlink"); 
	}

	return (lib_ret); 
}

int x_sem_wait (sem_t *sem, ...)
{
	int lib_ret; 
	FETCH (sem); 

	lib_ret = sem_wait (sem); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_wait"); 
	}

	return (lib_ret); 
}

int x_sem_trywait (sem_t *sem, ...)
{
	int lib_ret; 
	FETCH (sem); 

	lib_ret = sem_trywait (sem); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_trywait"); 
	}

	return (lib_ret); 
}

int x_sem_timedwait (sem_t *sem, const struct timespec *abs_timeout, ...)
{
	int lib_ret; 
	FETCH (abs_timeout); 

	lib_ret = sem_timedwait (sem, abs_timeout); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_timedwait"); 
	}

	return (lib_ret); 
}

int x_sem_post (sem_t *sem, ...)
{
	int lib_ret; 
	FETCH (sem); 

	lib_ret = sem_post (sem); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_post"); 
	}

	return (lib_ret); 
}

int x_sem_getvalue (sem_t *sem, int *sval, ...)
{
	int lib_ret; 
	FETCH (sval); 

	lib_ret = sem_getvalue (sem, sval); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_getvalue"); 
	}

	return (lib_ret); 
}

int x_sem_init (sem_t *sem, int pshared, unsigned int value, ...)
{
	int lib_ret; 
	FETCH (value); 

	lib_ret = sem_init (sem, pshared, value); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_init"); 
	}

	return (lib_ret); 
}

int x_sem_destroy (sem_t *sem, ...)
{
	int lib_ret; 
	FETCH (sem); 

	lib_ret = sem_destroy (sem); 

	if (lib_ret == -1) 
	{
		HANDLE_LIB_ERROR1 ("sem_destroy"); 
	}

	return (lib_ret); 
}
