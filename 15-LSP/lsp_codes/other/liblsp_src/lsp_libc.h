#ifndef _LSP_LIBC_H
#define _LSP_LIBC_H 

#include "lsp_common.h" 

/* General utilities and wrappers around C library functions which are not 
 * system calls */
void dup_string (int error_response, const char *str, char **target, ...); 
void uint_to_str (int error_response, unsigned int num, char **str_ans, ...);


FILE 		*xtmpfile (int error_response, ...); 

/* Memory allocation and deallocation API's */ 
void 		*xmalloc (int error_response, size_t size, ...); 
void 		*xcalloc (int error_response, int nr_elements, int size_per_element, ...); 
void 		*xrealloc (int error_response, void* ptr, size_t new_size, ...);
void 		xfree (void *ptr); 
void 		xfree2 (int nr_ptrs, ...); 
void 		xfree3 (void *ptr_arr[], int nr_elements); 

/* Environmental API's */ 
char 		*xgetenv (int error_response, const char *name, ...); 
int 		xsetenv (int error_response, const char *name, const char *value, int overwrite, ...); 
int 		xunsetenv (int error_response, const char *name, ...); 
int 		xputenv (int error_response, char *string, ...); 
int 		xclearenv (int error_response, ...); 

/* User and Groups API's */ 
struct passwd 	*xgetpwnam (int error_response, const char *name, ...); 
struct passwd 	*xgetpwuid (int error_response, uid_t uid, ...); 
int 		xgetpwnam_r (int error_response, const char *name, struct passwd *pwd, char *buffer, 
			     size_t buffer_len, struct passwd **result, ...); 
int 		xgetpwuid_r (int error_response, uid_t uid, struct passwd *pwd, char *buffer, 
			     size_t buffer_len, struct passwd **result, ...); 
struct group 	*xgetgrnam (int error_response, const char *name, ...); 
struct group 	*xgetgrguid (int error_response, gid_t gid, ...); 
int 		xgetgrnam_r (int error_response, const char *name, struct group *grp, char *buffer, 
			     size_t buffer_len, struct group **result, ...); 
int 		xgetgrgid_t (int error_response, gid_t gid, struct group *grp, char *buffer, 
			     size_t buffer_len, struct group **result, ...); 
struct passwd 	*xgetpwdent (int error_response, ...); 
void		xsetpwent (void); 
void		xendpwent (void); 

char 		*xcrypt (int error_response, const char *key, const char *salt, ...); 
/* char 		*xcrypt_r (int error_response, const char *key, const char *salt, 
		           struct crypt_data *data, ...); */
char 		*xgetpass (int error_response, const char *prompt, ...); 
int		xinitgroups (int error_response, const char *user, gid_t groups, ...); 

/* Timing API's */ 
char 		*xctime (int error_response, const time_t *timep, ...); 
char		*xctime_r (int error_response, const time_t *timep, char *buffer, ...); 
char		*xasctime (int error_response, const struct tm *tm, ...); 
char		*xasctime_r (int error_response, const struct tm *tm, char *buffer, ...); 
struct tm	*xgmtime (int error_response, const time_t *timep, ...); 
struct tm	*xgmtime_r (int error_response, const time_t *timep, struct tm *result, ...); 
struct tm	*xlocaltime (int error_response, const time_t *timep, ...); 
struct tm	*xlocaltime_r (int error_response, const time_t *timep, struct tm *result, ...); 
time_t		xmktime (int error_response, struct tm *tm, ...);
size_t 		xstrftime (char *s, size_t max, const char *format, const struct tm *tm); 
char		*xstrptime (int error_response, const char *s, const char *format, struct tm *tm, ...); 
clock_t		xclock (int error_response, ...); 
int		xadjtime (int error_response, const struct timeval *delta, struct timeval *olddelta, ...); 



#endif /* _LSP_LIBC_H */ 
