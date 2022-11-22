#include "lsp.h"

void dup_string (int error_response, const char *str, char **target, ...)
{
	int len = strlen (str); 
#ifdef DEBUG 
	DEBUG_VARS(target); 
#endif 
	*target  = (char*) xcalloc (ER_MSG_WITH_EXIT, 1, len+1 
				    #ifdef DEBUG 
					 	,src_file_name, src_nr_line
				    #endif 
				   );  
	strncpy (*target, str, len); 
}

void uint_to_str (int error_response, unsigned int num, char **str_ans, ...) 
{
	int nr_digits; 
	int q, r; 
	int i, mid, index; 
	int len;   
	char tmp; 
	char *str; 
#ifdef DEBUG
	DEBUG_VARS(str_ans);
#endif 
	str = (char*) xcalloc (ER_MSG_WITH_EXIT, 1, MAX_DIGITS_32 
				     	#ifdef DEBUG 
						,src_file_name, src_nr_line 
				     	#endif 
				    ); 
	nr_digits = 0; 
	do 
	{
		q = num / 10; 
		r = num % 10; 
		*(str+nr_digits) = (char)(r+START_DIGITS); 
		nr_digits++; 
		num = num / 10; 
	}while (q != 0); 
	str = xrealloc (ER_MSG_WITH_EXIT, str, nr_digits+1
			#ifdef DEBUG
				,src_file_name, src_nr_line
			#endif
			); 
	len = strlen (str); 
	mid = len/2; 
	index = len-1;
	
	for (i=0; i < mid ; i++) 
	{
		tmp = str[i]; 
		str[i] = str[index-i]; 
		str[index-i] = tmp; 		
	}

	*str_ans = str; 
}

FILE *xtmpfile (int error_response, ...)
{
	FILE *lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(error_response); 
#endif 
	lib_ret = tmpfile (); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR("tmpfile:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR("tmpfile:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

void *xmalloc (int error_response, size_t n, ...) 
{
	void *lib_ret=NULL; 
	char *err_msg = "fatal:out of memory"; 
#ifdef DEBUG 
	DEBUG_VARS(n); 
#endif 
	lib_ret = malloc (n); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("malloc:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("malloc:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

void *xrealloc (int error_response, void *ptr, size_t n, ...) 
{
	void *lib_ret=NULL; 
	char *err_msg = "realloc:fatal:out of memory"; 
#ifdef DEBUG 
	DEBUG_VARS(n); 
#endif 
	lib_ret = realloc (ptr, n); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("realloc:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("realloc:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

void *xcalloc (int error_response, int nr_elements, int size_per_element, ...)
{
	void *lib_ret=NULL; 
	char *err_msg = "fatal:out of memory"; 
#ifdef DEBUG 
	DEBUG_VARS(size_per_element); 
#endif 
	lib_ret = calloc (nr_elements, size_per_element); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("xcalloc:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("xcalloc:%s\n", err_msg); 
#endif 		
	}
	return (lib_ret); 
}



void xfree (void *ptr) 
{
	if (ptr != NULL) 
	{
		free (ptr); 
	}
}

void xfree2 (int nr_ptrs, ...) 
{
	int i; 
	void *ptr; 
	va_list ap; 
	va_start (ap, nr_ptrs); 

	for (i=0; i < nr_ptrs; i++) 
	{
		ptr = va_arg (ap, void*); 
		if (ptr != NULL) 
		{
			free (ptr); 
		}
	}
	va_end (ap); 
}

void xfree3 (void *ptrs[], int nr_size) 
{
	int i; 

	for (i=0; i < nr_size; i++) 
	{
		xfree (ptrs[i]); 
	}
}

char *xgetenv (int error_response, const char *name, ...) 
{
	char *lib_ret, *err_msg="No match found"; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	lib_ret = getenv (name); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG
		HANDLE_LIB_ERROR ("getenv:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getenv:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
} 

int xsetenv (int error_response, const char *name, const char *value, int overwrite, ...) 
{
	int lib_ret; 
	char *err_msg="Not enouogh space"; 
#ifdef DEBUG 
	DEBUG_VARS(overwrite); 
#endif 
	lib_ret = setenv (name, value, overwrite); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("setenv:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("setenv:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

int xunsetenv (int error_response, const char *name, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	lib_ret = unsetenv (name); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("unsetenv:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("unsetenv:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

int xputenv (int error_response, char *string, ...) 
{
	int lib_ret; 
	char *err_msg="Not enough space"; 
#ifdef DEBUG
	DEBUG_VARS(string); 
#endif 
	lib_ret = putenv (string); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("putenv:%s:%d:%s\n", src_file_name, src_nr_line, string); 
#else
		HANDLE_LIB_ERROR ("putenv:%s\n", string); 
#endif 
	}
	return (lib_ret); 
}

int xclearenv (int error_response, ...) 
{
	int lib_ret; 
	char *err_msg="Error in clearing variables"; 
#ifdef DEBUG 
	DEBUG_VARS(error_response); 
#endif 
	lib_ret = clearenv ();
	if (lib_ret != 0) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("clearenv:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("clearenv:%s\n", err_msg); 
#endif 
	}
	return (lib_ret);
}

struct passwd *xgetpwnam (int error_response, const char *name, ...) 
{
	struct passwd *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	lib_ret = getpwnam (name); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getpwnam:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getpwnam:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

struct passwd *xgetpwuid (int error_response, uid_t uid, ...)
{
	struct passwd *lib_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(uid); 
#endif 
	lib_ret = getpwuid (uid); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getpwuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getpwuid:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

struct group *xgetgrnam (int error_response, const char *name, ...) 
{
	struct group *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	lib_ret = getgrnam (name); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getgrnam:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getgrnam:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

struct group *xgetgrgid (int error_response, gid_t gid, ...) 
{
	struct group *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(gid); 
#endif 
	lib_ret = getgrgid (gid); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getgrgid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getgrgid:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}	

int xgetpwnam_r (int error_response, const char *name, struct passwd *pwd, char *buffer, 
		 size_t buffer_len, struct passwd **result, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(result); 
#endif 
	lib_ret = getpwnam_r (name, pwd, buffer, buffer_len, result); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getpwnam_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getpwnam_r:%s\n", err_msg); 
#endif
	}
	return (lib_ret); 
}

int xgetpwuid_r (int error_response, uid_t uid, struct passwd *pwd, char *buffer, 
		 size_t buffer_len, struct passwd **result, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(result); 
#endif 
	lib_ret = getpwuid_r (uid, pwd, buffer, buffer_len, result); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getpwuid_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getpwuid_r:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

int xgetgrnam_r (int error_response, const char *name, struct group *grp, char *buffer, 
	       size_t buffer_len, struct group **result, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(result); 
#endif 
	lib_ret = getgrnam_r (name, grp, buffer, buffer_len, result); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getgrnam_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getgrnam_r:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

int xgetgrgid_r (int error_response, gid_t gid, struct group *grp, char *buffer, size_t buffer_len, 
		 struct group **result, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(result); 
#endif 
	lib_ret = getgrgid_r (gid, grp, buffer, buffer_len, result); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getgrgid_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getgrgid_r:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

void xsetpwent (void) 
{
	setpwent (); 
}

void xendpwent (void) 
{
	endpwent (); 
}

char *xcrypt (int error_response, const char *key, const char *salt, ...) 
{
	char *lib_ret, *err_msg="Error";
#ifdef DEBUG 
	DEBUG_VARS(salt); 
#endif 
	lib_ret = crypt (key, salt); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("crypt:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("crypt:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

/*char *xcrypt_r (int error_response, const char *key, const char *salt, struct crypt_data *data, ...)
{
	char *lib_ret, *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(data); 
#endif 
	lib_ret = crypt_r (key, salt, data); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG
		HANDLE_LIB_ERROR ("crypt_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("crypt_r:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}*/ 

char *xgetpass (int error_response, const char *prompt, ...)
{
	char *lib_ret, *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(prompt); 
#endif 
	lib_ret = getpass (prompt); 
	if (lib_ret == NULL) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("getpass:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("getpass:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

int xinitgroups (int error_response, const char *user, gid_t groups, ...) 
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(groups); 
#endif 
	lib_ret = initgroups (user, groups); 
	if (lib_ret == -1) 
	{
#ifdef DEBUG 
		HANDLE_LIB_ERROR ("initgroups:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
		HANDLE_LIB_ERROR ("initgroups:%s\n", err_msg); 
#endif 
	}
	return (lib_ret); 
}

char *xctime (int error_response, const time_t *timep, ...)
{
	char *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(timep); 
#endif 
	lib_ret = ctime (timep); 
	if (lib_ret == NULL)
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("ctime:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("ctime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

char *xctime_r (int error_response, const time_t *timep, char *buffer, ...) 
{
	char *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(buffer);
#endif 
	if (lib_ret == NULL) 
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("ctime_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("ctime_r:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

char *xasctime (int error_response, const struct tm *tm, ...) 
{
	char *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(tm); 
#endif 
	lib_ret = asctime (tm); 
	if (lib_ret == NULL) 
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("asctime:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("asctime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

char *xasctime_r (int error_response, const struct tm *tm, char *buffer, ...) 
{
	char *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(buffer); 
#endif 
	lib_ret = asctime_r (tm, buffer); 
	if (lib_ret == NULL)
	{
	#ifdef DEBUG
		HANDLE_LIB_ERROR ("asctime_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("asctime_r:%s\n", err_msg); 
	#endif
	}
	return (lib_ret); 
}

struct tm *xgmtime (int error_response, const time_t *timep, ...)
{
	struct tm *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(timep);
#endif 
	lib_ret = gmtime (timep); 
	if (lib_ret == NULL)
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("gmtime:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("gmtime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

struct tm *xgmtime_r (int error_response, const time_t *timep, struct tm *result, ...) 
{
	struct tm *lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(result); 
#endif 
	lib_ret  = gmtime_r (timep, result); 
	if (lib_ret == NULL)
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("gmtime_r:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("gmtime_r:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 	
}

time_t xmktime (int error_response, struct tm *tm, ...) 
{
	time_t lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(tm); 
#endif 
	lib_ret = mktime (tm); 
	if (lib_ret == -1) 
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("mktime:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("mktime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

size_t xstrftime (char *s, size_t max, const char *format, const struct tm *tm) 
{
	return (strftime (s, max, format, tm)); 	
}

char *xstrptime (int error_response, const char *s, const char *format, struct tm *tm, ...) 
{
	char *lib_ret;
       	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(tm); 
#endif 
	lib_ret = (char*)strptime (s, format, tm); 
	if (lib_ret == NULL)
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR("strptime:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("strptime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

clock_t xclock (int error_response, ...)
{
	clock_t lib_ret; 
	char *err_msg="Error"; 
#ifdef DEBUG 
	DEBUG_VARS(error_response); 
#endif 
	lib_ret = clock (); 
	if (lib_ret == -1) 
	{
	#ifdef DEBUG
		HANDLE_LIB_ERROR ("clock:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("clock:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}

int xadjtime (int error_response, const struct timeval *delta, struct timeval *olddelta, ...)
{
	int lib_ret; 
	char *err_msg=NULL; 
#ifdef DEBUG 
	DEBUG_VARS(olddelta); 
#endif 
	lib_ret = adjtime (delta, olddelta); 
	if (lib_ret == -1) 
	{
	#ifdef DEBUG 
		HANDLE_LIB_ERROR ("adjtime:%s:%d:s\n", src_file_name, src_nr_line, err_msg); 
	#else
		HANDLE_LIB_ERROR ("adjtime:%s\n", err_msg); 
	#endif 
	}
	return (lib_ret); 
}


