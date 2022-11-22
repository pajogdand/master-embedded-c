#ifndef _LSP_LIBC_ERROR_H
#define _LSP_LIBC_ERROR_H 

#include "lsp_common.h" 

void 	*x_malloc (size_t size, ...); 
void 	*x_calloc (size_t nr_elements, size_t size_per_element, ...); 
void 	*x_realloc (void* ptr, size_t new_size, ...);
void 	*x_aligned_alloc (size_t alignment, size_t size, ...);
void	*x_memalign (size_t alignment, size_t size, ...); 
int 	x_posix_memalign (void **memptr, size_t alignment, size_t size, ...);
void 	*x_valloc (size_t size, ...); 
inline	void *xi_alloca (size_t size, ...); 
void 	x_free (void *ptr); 
void 	x_free2 (int nr_ptrs, ...); 
void	x_free3 (void *ptr_arr[], int nr_elements); 
inline	void xi_cfree (void *ptr); 
int 	x_mallopt (int param, int value, ...);
int 	x_mcheck (void (*abort_function) (enum mcheck_status status), ...);
int 	x_mcheck_pedantic (void (*abort_function) (enum mcheck_status status), ...);
inline	void xi_mcheck_check_all (void);
inline  enum mcheck_status xi_mprobe (void *ptr);
inline	void xi_mtrace (void); 
inline	void xi_muntrace (void);
inline 	struct mallinfo xi_mallinfo (void);
inline	void  xi_obstack_init (struct obstack *obstack_ptr); 
inline	void *xi_obstack_alloc (struct obstack *obstack_ptr, int size); 
inline	void *xi_obstack_copy (struct obstack *obstack_ptr, void *address, int size); 
inline 	void *xi_obstack_copy0 (struct obstack *obstack_ptr, void *address, int size);
inline	void xi_obstack_free (struct obstack *obstack_ptr, void *object); 
inline	void xi_obstack_blank (struct obstack *obstack_ptr, int size); 
inline 	void xi_obstack_grow (struct obstack *obstack_ptr, void *data, int size); 
inline	void xi_obstack_grow0 (struct obstack *obstack_ptr, void *data, int size); 
inline	void xi_obstack_1grow (struct obstack *obstack_ptr, char c);
inline	void xi_obstack_ptr_grow (struct obstack *obstack_ptr, void *data); 
inline	void xi_obstack_int_grow (struct obstack *obstack_ptr, int data); 
inline	void xi_obstack_finish (struct obstack *obstack_ptr); 
inline	int  xi_obstack_object_size (struct obstack *obstack_ptr);
inline	int  xi_obstack_room (struct obstack *obstack_ptr);
inline	void xi_1grow_fast (struct obstack *obstack_ptr, char c);
inline	void xi_obstack_ptr_grow_fast (struct obstack *obstack_ptr, void *data); 
inline	void xi_obstack_int_grow_fast (struct obstack *obstack_ptr, int data);
inline	void xi_obstack_blank_fast (struct obstack *obstack_ptr, int size);
inline	int  xi_obstack_alignment_mask (struct obstack *obstack_ptr); 
inline	int  xi_obstack_chunk_size (struct obstack * obstack_ptr);
inline	int xi_islower (int c);
inline	int xi_isupper (int c);
inline	int xi_isalpha (int c);
inline	int xi_isdigit (int c);
inline	int xi_isalnum (int c);
inline	int xi_isxdigit (int c);
inline	int xi_ispunct (int c);
inline	int xi_isspace (int c);
inline	int xi_isblank (int c);
inline	int xi_isgraph (int c);
inline	int xi_isprint (int c);
inline	int xi_iscntrl (int c);
inline	int xi_isascii (int c);
inline	int xi_toupper (int c);
inline	int xi_tolower (int c);
inline	int xi_toascii (int c);
inline	int xi__tolower (int c);
inline	int xi__toupper (int c);
inline	wctype_t wctype (const char *property); 
inline	int xi_iswalpha (wint_t wc);
inline	int xi_iswcntrl (wint_t wc);
inline	int xi_iswdigit (wint_t wc);
inline	int xi_iswalnum (wint_t wc);
inline	int xi_iswalpha (wint_t wc);
inline	int xi_iswcntrl (wint_t wc);
inline	int xi_iswdigit (wint_t wc);
inline	int xi_iswgraph (wint_t wc);
inline	int xi_iswlower (wint_t wc);
inline	int xi_iswprint (wint_t wc);
inline	int xi_iswpunct (wint_t wc);
inline	int xi_iswspace (wint_t wc);
inline	int xi_iswupper (wint_t wc);
inline	int xi_iswxdigit (wint_t wc);
inline	int xi_iswblank (wint_t wc);
inline	wctrans_t xi_wctrans (const char * property); 
inline	wint_t xi_towctrans (wint_t wc, wctrans_t desc);
inline	wint_t xi_towlower (wint_t wc); 
inline	wint_t xi_towupper (wint_t wc); 
size_t	x_strlen (const char *str, ...); 
size_t 	x_wcslen (const wchar_t *ws, ...); 
size_t	x_strnlen (const char *str, size_t max_len, ...); 
size_t 	x_wcsnlen (const wchar_t *ws, size_t max_len, ...);
void	*x_memcpy (void *dest, const void *src, size_t n, ...); 
wchar_t *x_wmemcpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
void 	*x_mempcpy (void *to, const void *from, size_t size, ...);
void	*mempcpy (void *dest, const void *src, size_t size);
wchar_t *x_wmempcpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
void	*x_memmove (void *dest, const void *src, size_t n, ...); 
wchar_t *x_wmemmove (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
void	*x_memccpy (void *dest, const void *src, int c, size_t n, ...); 
void	*x_memset (void *src, int c, size_t n, ...); 
wchar_t *x_wmemset (wchar_t *block, wchar_t wc, size_t size, ...);
char	*x_strcpy (char *dest, const char *src, ...); 
wchar_t *x_wcscpy (wchar_t *wto, wchar_t *from, ...);
char	*x_strncpy (char *dest, const char *src, size_t n, ...);
wchar_t *x_wcsncpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
char 	*x_strdup (const char *string, ...); 
wchar_t *x_wcsdup (const wchar_t *ws, ...);
char 	*x_strndup (const char *string, size_t size, ...); 
char	*x_stpcpy (char *dest, const char *src, ...); 
wchar_t *x_wcpcpy (wchar_t *wto, const wchar_t *wfrom, ...);
char	*x_stpncpy (char *dest, const char *src, size_t n, ...); 
wchar_t *x_wcpncpy (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
char 	*x_strdupa (const char *string, ...);
char 	*x_strndupa (const char *string, size_t size, ...);
char 	*x_strcat (char *to, const char *from, ...);
wchar_t *x_wcscat (wchar_t *wto, wchar_t *wfrom, ...);
char 	*x_strncat (char *to, const char *from, size_t size, ...); 
wchar_t *x_wcsncat (wchar_t *wto, const wchar_t *wfrom, size_t size, ...);
inline	void xi_bcopy (const void *src, void *dest, size_t n); 
inline	void xi_bzero (void *s, size_t n);
inline	int xi_memcmp (const void *data_one, const void *data_two, size_t size); 
inline	int xi_wmemcmp (const wchar_t *string_one, const wchar_t *string_two, size_t size); 
inline	int xi_strcmp (const char *string_one, const char *string_two); 
inline	int xi_wcscmp (const wchar_t *string_one, const wchar_t *string_two);
inline	int xi_strcasecmp (const char *string_one, const char *string_two); 
inline	int xi_wcscasecmp (const wchar_t *string_one, const wchar_t *string_two); 
inline	int xi_strncmp (const char *string_one, const char *string_two, size_t size); 
inline	int xi_wcsncmp (const wchar_t *string_one, const wchar_t *string_two, size_t size);
inline	int xi_strncasecmp (const char *string_one, const char *string_two, size_t size); 
inline	int xi_wcsncasecmp (const wchar_t *string_one, const wchar_t *string_two, size_t size);
inline 	int xi_strverscmp (const char *string_one, const char *string_two);
inline 	int xi_bcmp (const void *data_one, const void *data_two, size_t size);
inline 	int xi_strcoll (const char *string_one, const char *string_two); 
inline 	int xi_wcscoll (const wchar_t *string_one, const wchar_t *string_two);
inline 	size_t xi_strxfrm (char *to, const char *from, size_t n); 
inline 	size_t xi_wcsxfrm (wchar_t *to, const wchar_t *from, size_t n);
void 	*x_memchr (const void *block, int c, size_t size, ...);
wchar_t *x_wmemchr (const wchar_t *block, wchar_t wc, size_t size, ...);
void 	*x_rawmemchr (const void *block, int c, ...);
void 	*x_memrchr (const void *block, int c, size_t size, ...);
char 	*x_strchr (const char *string, int c, ...);
wchar_t *x_wcschr (const wchar_t *wstring, int wc, ...);
char 	*x_strchrnul (const char *string, int c, ...);
wchar_t *x_wcschrnul (const char *string, int c, ...); 
char	*x_strrchr (const char *string, int c, ...); 
wchar_t *x_wcsrstr (const wchar_t *string, wchar_t wc, ...);
wchar_t *x_wcswcs (const wchar_t *haytack, const wchar_t *needle, ...); 
char 	*x_strcasestr (const char *haystack, const char *needle, ...);
void 	*x_memmem (const void *haystack, size_t haystack_len, const void *needle, 
		   size_t needle_len, ...);
inline 	size_t xi_strspn (const char *string, const char *skip_set); 
inline 	size_t xi_wcsspn (const wchar_t *string, const wchar_t *skip_set); 
inline 	size_t xi_strcspn (const char *string, const char *stop_set); 
inline 	size_t xi_wcscspn (const wchar_t *string, const wchar_t *stop_set);
char 	*x_strpbrk (const char *string, const char *stop_set, ...); 
wchar_t *x_wcspbrk (const wchar_t *string, const wchar_t *stop_set, ...); 
char	*x_index (const char *string, int c, ...); 
char	*x_rindex (const char *string, int c, ...); 
char 	*x_strtok (char *new_string, const char *delimiters, ...); 
wchar_t *x_wcstok (wchar_t *string, const wchar_t *delimiters, wchar_t **save_ptr, ...); 
char 	*x_strtok_r (char *new_string, const char *delimiters, char **save_ptr, ...);
char	*x_strsep (char **string_ptr, const char *delimiters, ...);
char 	*x_strfry (char *string, ...);
void 	*x_memfrob (void *mem, size_t length, ...);
inline 	long xi_a64l (char *str64); 
inline char *xi_l64a (long int value);
error_t x_argz_create (char *const argv[], char **argz, size_t *argz_len, ...); 
error_t x_argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len, ...); 
error_t	x_argz_count (const char *argz, size_t arg_len, ...); 
inline	void xi_argz_extract (const char *argz, size_t argz_len, char **argv, ...); 
inline	void xi_argz_stringify (char *argz, size_t len, int sep); 
error_t	x_argz_add (char **argz, size_t *argz_len, const char *str, ...); 
error_t x_argz_add_sep (char **argz, size_t *argz_len, const char *string, int delim, ...);
error_t x_argz_append (char **argz, size_t *argz_len, const char *buffer, size_t buffer_len, ...); 
inline	void xi_argz_delete (char **argz, size_t *argz_len, char *entry); 
error_t x_argz_insert (char **argz, size_t *argz_len, char *before, const char *entry, ...); 
char	*x_argz_next (const char *argz, size_t argz_len, const char *entry, ...); 
error_t	x_argz_replace (char **argz, size_t *argz_len, const char *string, const char *width, unsigned int *replace_count, ...); 
char 	*x_envz_entry (const char *envz, size_t envz_len, const char *name, ...);
char 	*x_envz_get (const char *envz, size_t envz_len, const char *name, ...); 
error_t	x_envz_add (char **envz, size_t *envz_len, const char *name, const char *value, ...); 
error_t	x_envz_merge (char **envz, size_t *envz_len, const char *envz2, size_t envz2_ln, int override, ...);
inline	void xi_envz_strip (char **envz, size_t *envz_len, ...); 
inline 	int xi_atoi (const char *nptr); 
inline	long xi_atol (const char *nptr); 
inline	long long xi_atoll (const char *nptr); 
FILE	*x_tmpfile (int error_response, ...); 
char 	*x_getenv (const char *name, ...); 
int	x_setenv (const char *name, const char *value, int overwrite, ...); 
int	x_unsetenv (const char *name, ...); 
inline	int xi_setjmp (jmp_buf env); 
inline 	void xi_exit (int status); 
struct 	passwd *x_getpwnam (const char *name, ...); 
struct 	passwd *x_getpwuid (uid_t uid, ...); 
int	x_getpwnam_r (const char *name, struct passwd *pwd, char *buffer, 
		      size_t buffer_len, struct passwd **result, ...); 
int 	x_getpwuid_r (uid_t uid, struct passwd *pwd, char *buffer, size_t buffer_len, 
		      struct passwd **result, ...); 
struct 	group *x_getgrnam (const char *name, ...); 
struct 	group *x_getgrgid (gid_t gid, ...); 
int	x_getgrnam_r (const char *name, struct group *grp, char *buffer, size_t buffer_len, 
		      struct group **result, ...); 
int	x_getgrgid_r (gid_t gid, struct group *grp, char *buffer, size_t buffer_len, 
		      struct group **result, ...); 
struct 	passwd *x_getpwent (int error_response, ...); 
inline 	void xi_setpwent (void); 
inline 	void xi_endpwent (void); 
struct 	spwd *x_getspnam (const char *name, ...); 
struct 	spwd *x_getspent (int error_response, ...); 
inline 	void xi_setspent (void); 
inline 	void xi_endspent (void); 
struct 	spwd *x_fgetspent (FILE *fp, ...); 
struct 	spwd *x_sgetspent (const char *s, ...); 
int	x_putspent (struct spwd *spw, FILE *fp, ...); 
int 	x_lckpwdf (int error_response, ...); 
int 	x_ulckpwdf (int error_response, ...); 
int 	x_getspent_r (struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		      struct spwd **result, ...); 
int 	x_getspnam_r (const char *name, struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		      struct spwd **result, ...); 
int 	x_fgetspent_r (FILE *fp, struct spwd *sp_buffer, char *buffer, size_t buffer_len, 
		       struct spwd **result, ...); 
int 	x_sgetspent_r (const char *s, struct spwd *sp_buffer, char *buffer, 
		       size_t buffer_len, struct spwd **result, ...); 
char 	*x_crypt (const char *key, const char *salt, ...); 
char	*x_getpass (const char *prompt, ...); 
int 	x_initgroups (const char *user, gid_t group, ...); 
char 	*x_asctime (const struct tm *tm, ...); 
char 	*x_asctime_r (const struct tm *tm, char *buffer, ...); 
char	*x_ctime (const time_t *timep, ...); 
char 	*x_ctime_r (const time_t *timep, char *buffer, ...); 
struct 	tm *x_gmtime (const time_t *timep, ...); 
struct 	tm *x_gmtime_r (const time_t *timep, struct tm *result, ...); 
struct 	tm *x_localtime (const time_t *timep, ...); 
struct 	tm *x_localtime_r (const time_t *timep, struct tm *result, ...); 
time_t	x_mktime (struct tm *tm, ...); 
size_t 	x_strftime (char *buffer, size_t buffer_len, const char *format, struct tm *tm, ...); 
char	*x_strptime (const char *buffer, const char *format, struct tm *tm, ...); 
char 	*x_setlocale (int category, const char *locale, ...); 
int 	x_adjtime (const struct timeval *delta, struct timeval *old_delta, ...); 
clock_t x_clock (int error_response, ...); 
inline	void xi_setbuf (FILE *fp, char *buffer); 
inline  void xi_setbuffer (FILE *fp, char *buffer, size_t buffer_len); 
inline 	void xi_setlinebuf (FILE *fp); 
int 	x_setvbuf (FILE *fp, char *buffer, int mode, size_t size, ...); 
int	x_flush (FILE *stream, ...); 
int 	x_fileno (FILE *stream, ...); 
FILE	*x_fdopen (int fd, const char *mode, ...); 
acl_t 	x_acl_init(int count, ...);
acl_t 	x_acl_dup(acl_t acl, ...);
int 	x_acl_free(void *obj_p, ...);
int 	x_acl_valid(acl_t acl, ...);
int 	x_acl_copy_entry(acl_entry_t dest_d, acl_entry_t src_d, ...);
int 	x_acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p, ...);
int 	x_acl_delete_entry(acl_t acl, acl_entry_t entry_d, ...);
int 	x_acl_get_entry(acl_t acl, int entry_id, acl_entry_t *entry_p, ...);
int 	x_acl_add_perm(acl_permset_t permset_d, acl_perm_t perm, ...);
int 	x_acl_calc_mask(acl_t *acl_p, ...);
int 	x_acl_clear_perms(acl_permset_t permset_d, ...);
int 	x_acl_delete_perm(acl_permset_t permset_d, acl_perm_t perm, ...);
int 	x_acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p, ...);
int 	x_acl_set_permset(acl_entry_t entry_d, acl_permset_t permset_d, ...);
void 	*x_acl_get_qualifier(acl_entry_t entry_d, ...);
int 	x_acl_get_tag_type(acl_entry_t entry_d, acl_tag_t *tag_type_p, ...);
int 	x_acl_set_qualifier(acl_entry_t entry_d, const void *tag_qualifier_p, ...);
int 	x_acl_set_tag_type(acl_entry_t entry_d, acl_tag_t tag_type, ...);
ssize_t x_acl_copy_ext(void *buf_p, acl_t acl, ssize_t size, ...);
acl_t 	x_acl_copy_int(const void *buf_p, ...);
acl_t 	x_acl_from_text(const char *buf_p, ...);
ssize_t x_acl_size(acl_t acl, ...);
char 	*x_acl_to_text(acl_t acl, ssize_t *len_p, ...);
int 	x_acl_delete_def_file(const char *path_p, ...);
acl_t 	x_acl_get_fd(int fd, ...);
acl_t 	x_acl_get_file(const char *path_p, acl_type_t type, ...);
int 	x_acl_set_fd(int fd, acl_t acl, ...);
int 	x_acl_set_file(const char *path_p, acl_type_t type, acl_t acl, ...);
DIR	*x_opendir (const char *name, ...); 
DIR	*x_fdopendir (int fd, ...);
struct 	dirent *x_readdir (DIR *dirp, ...); 
int 	x_readdir_r (DIR *dirp, struct dirent *entry, struct dirent **result, ...);
inline 	void xi_rewinddir (DIR *dirp);
inline 	void x_seekdir (DIR *dirp, long int loc);
long 	int x_telldir (DIR *dirp, ...);
int	x_closedir (DIR *dirp, ...);
int	x_dirfd (DIR *dirp, ...);
char	*x_realpath (const char *path, char *resolved_path, ...);
char 	*x_basename (char *path, ...); 
char	*x_dirname (char *path, ...);
int 	x_raise (int signal_number, ...); 
int 	x_siginterrupt (int signal_number, int flag, ...);
int	x_sigwait (const sigset_t *set, int *sig, ...);
int	x_sigqueue (pid_t pid, int signal_number, const union sigval value, ...); 
int	x_sigemptyset (sigset_t *set, ...); 
int 	x_sigfillset (sigset_t *set, ...); 
int 	x_sigaddset (sigset_t *set, int signal_number, ...); 
int 	x_sigdelset (sigset_t *set, int signal_number, ...); 
int 	x_sigismember (sigset_t *set, int signal_number, ...);
int 	x_sigisemptyset (sigset_t *set, ...);
int 	x_sigorset (sigset_t *dest, sigset_t *left, sigset_t *right, ...);
int 	x_sigandset (sigset_t *dest, sigset_t *left, sigset_t *right, ...);
inline 	char *xi_strsignal (int signal_number); 
inline 	void xi_psignal (int signal_number, const char *str); 
inline	void xi_psiginfo (const siginfo_t *pinfo, const char *str);
inline	unsigned int xi_sleep (unsigned int seconds); 
int	x_clock_getcpuclockid (pid_t pid, clockid_t *clock_id, ...);  
int	x_atexit (void (*exit_handler)(void), ...); 
int	x_on_exit (void (*exit_handler) (int, void*), void *arg, ...); 
pid_t	x_waitpid (pid_t pid, int *status, int options, ...); 
char	*x_ctermid (char *str, ...); 
pid_t	x_tcgetpgrp (int fd, ...); 
int	x_tcsetpgrp (int fd, pid_t pgrp, ...); 
inline	void xi_openlog (const char *indent, int option, int facility); 
inline	void xi_closelog (void); 
inline	int xi_setlogmask (int mask); 
struct 	utmp *x_getutent (int error_response, ...); 
struct  utmp *x_getutid (struct utmp *ut, ...); 
struct 	utmp *x_getutline (struct utmp *ut, ...); 
struct 	utmp *x_pututline (struct utmp *ut, ...); 
inline	void xi_setutent (void); 
inline	void xi_endutent (void); 
int	x_utmpname (const char *file, ...);
char 	*x_getlogin(int error_response, ...);
int 	x_getlogin_r(char *buf, size_t bufsize, ...);
inline	void xi_updwtmp(const char *wtmp_file, const struct utmp *ut);
inline	void xi_logwtmp(const char *line, const char *name, const char *host);
void 	*x_dlopen(const char *filename, int flag, ...);
char 	*x_dlerror(void);
void 	*x_dlsym(void *handle, const char *symbol, ...);
int 	x_dlclose(void *handle, ...);
FILE 	*x_popen (const char *command, const char *type, ...); 
int	x_pclose (FILE *stream, ...); 
int	x_mkfifo (const char *path_name, mode_t mode, ...); 
key_t	x_ftok (const char *path_name, int proj_id, ...); 
int	x_mq_getattr (mqd_t mq_des, struct mq_attr *attr, ...); 
int	x_mq_setattr (mqd_t mq_des, struct mq_attr *new_attr, struct mq_attr *old_attr, ...); 
int	x_mq_send (mqd_t mq_des, const char *msg_ptr, size_t msg_len, unsigned int msg_prio, ...); 
int	x_mq_timedsend (mqd_t mq_des, const char *msg_ptr, size_t msg_len, 
		        unsigned int msg_prio, const struct timespec *abs_timeout, ...);
ssize_t	x_mq_receive (mqd_t mq_des, char *msg_ptr, size_t msg_len, unsigned int *msg_prio, ...); 
ssize_t x_mq_timedreceive (mqd_t mq_des, char *msg_ptr, size_t msg_len, 
		           unsigned int *msg_prio, const struct timespec *abs_timeout, ...); 
int	x_mq_notify (mqd_t mq_des, const struct sigevent *sevp, ...); 
int 	x_shm_open(const char *name, int oflag, mode_t mode, ...);
int 	x_shm_unlink(const char *name, ...);
sem_t 	*x_sem_open (const char *name, int oflag, mode_t mode, unsigned int value, ...); 
int	x_sem_close (sem_t *sem, ...); 
int 	x_sem_unlink (const char *name, ...); 
int	x_sem_wait (sem_t *sem, ...); 
int	x_sem_trywait (sem_t *sem, ...); 
int	x_sem_timedwait (sem_t *sem, const struct timespec *abs_timeout, ...); 
int	x_sem_post (sem_t *sem, ...); 
int	x_sem_getvalue (sem_t *sem, int *sval, ...); 
int	x_sem_init (sem_t *sem, int pshared, unsigned int value, ...); 
int	x_sem_destroy (sem_t *sem, ...); 

#endif /* _LSP_LIBC_H */ 
