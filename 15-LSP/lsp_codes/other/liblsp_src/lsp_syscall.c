#include "lsp.h" 

const char no_file_name [] = "No FileName"; 

/* Optionally xopen receives : 
 * 1. permission mode of newly created file  (mode_t mode)
 * 2. source file name (char *__FILE__)
 * 3. line number in source file (int __LINE__)
 */ 

int xopen (int error_response, int is_o_creat, const char *path_name, int flags, ...)
{
	int sys_ret; 
	char *err_msg; 
	mode_t mode; 
	va_list ap; 
	va_start (ap, flags); 
#ifdef DEBUG 
	char *src_file_name; 
	int  src_nr_line;  
	if (is_o_creat == TRUE)
	{
		mode = va_arg (ap, mode_t); 		
	}
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
#else 
	if (is_o_creat == TRUE)
	{
		mode = va_arg (ap, mode_t); 		
	}	
#endif 	
	va_end (ap); 

	if (is_o_creat == TRUE) 
	{
		sys_ret = open (path_name, flags, mode); 
	}
	else 
	{
		sys_ret = open (path_name, flags); 
	}

#ifdef DEBUG 
	HANDLE_SYS_ERROR("open:%s:%d:%s:%s\n", src_file_name, 
			 src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR("open:%s:%s\n", path_name, err_msg); 
#endif 
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}


/* xread optionally receives 
 * 1. source file name (char *__FILE__)
 * 2. line number in source file (int __LINE__)
 */ 
ssize_t xread (int error_response, const char *f_name, int fd, 
	       void *buffer, size_t size, ...)
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(size);  
#endif 
	sys_ret = read (fd, buffer, size); 	
#ifdef DEBUG
	HANDLE_SYS_ERROR ("read:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		      f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("read:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 	
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}
/* xwrite optionally receives : 
 * 1. source file name (char *__FILE__)
 * 2. line number in source file name (int __LINE__)
 */ 
ssize_t xwrite (int error_response, const char *f_name, int fd, 
		void *buffer, size_t size, ...) 
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(size); 
#endif 
	sys_ret = write (fd, buffer, size); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("write:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		       f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("write:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif	
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

/* xlseek optionally receives : 
 * 1. source file name (char *__FILE__)
 * 2. line number is source file (int __LINE__)
 */ 
off_t xlseek (int error_response, const char *f_name, int fd, 
	      off_t offset, int whence, ...)
{
	off_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(whence); 
#endif 	
	sys_ret = lseek (fd, offset, whence); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("lseek:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		       f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("lseek:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

/* xclose optionally receives: 
 * 1. source file name (char *__FILE__)
 * 2. line number is source file (int __LINE__)
 */ 
int xclose (int error_response, const char *f_name, int fd, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(fd); 
#endif 
	sys_ret = close (fd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("close:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		      f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("close:%s:%s\n", 
		      f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

/* xclose2 optionally receives: 
 * 'nr_fds' number of pairs of f_name & fds 
 * f_name can be NULL in general case */ 
void xclose2 (int nr_fds, ...) 
{
	int fd, i; 
	char *f_name; 
	va_list ap; 
	va_start (ap, nr_fds); 
	
	for (i=0; i < nr_fds; i++)
	{
		f_name = va_arg (ap, char*); 
		fd     = va_arg (ap, int); 
#ifdef DEBUG
		xclose (ER_RET_WITH_MSG, f_name, fd, SRC_FILE_NAME, SRC_NR_LINE); 
#else
		xclose (ER_RET_WITH_MSG, f_name, fd); 
#endif 
	}
	va_end (ap); 
}

/* xdup optionally receives 
 * 1. source file name (char *__FILE__)
 * 2. line number in source file (int __LINE__) 
 */ 
int xdup (int error_response, const char *f_name, int fd, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(fd); 
#endif 
	sys_ret = dup (fd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("dup:%s:%d:%s\n", src_file_name, src_nr_line, 
		       f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("dup:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

int xdup2 (int error_response, const char *f_name, int old_fd, int new_fd, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(new_fd);
#endif 	
	sys_ret = dup2 (old_fd, new_fd); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("dup2:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		       f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("dup2:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

int xdup3 (int error_response, const char *f_name, int old_fd, 
	   int new_fd, int flags, ...)	
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(flags); 
#endif 	
	sys_ret = dup3 (old_fd, new_fd, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("dup3:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		      f_name != NULL ? f_name : no_file_name, err_msg); 	
#else
	HANDLE_SYS_ERROR ("dup3:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	/* Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

ssize_t xpread (int error_response, const char *f_name, int fd, void *buffer, 
	        size_t size, off_t offset, ...)
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(offset); 
#endif 
	sys_ret = pread (fd, buffer, size, offset); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("pread:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("pread:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	/* Either success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

ssize_t xpwrite (int error_response, const char *f_name, int fd, void *buffer, 
	     size_t size, off_t offset, ...) 
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(offset); 
#endif 
	sys_ret = pwrite (fd, buffer, size, offset); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("pwrite:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("pwrite:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	/* Either Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

ssize_t xreadv (int error_response, const char *f_name, int fd, const struct iovec *iov, 
	        int iovcnt, ...)
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(iovcnt);
#endif	
	sys_ret = readv (fd, iov, iovcnt); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("readv:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		       f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("readv:%s:%s\n", f_name != NULL ? f_name : no_file_name); 
#endif
	/* Either Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

ssize_t xwritev (int error_response, const char *f_name, int fd, const struct iovec *iov, 
	         int iovcnt, ...)
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(iovcnt); 
#endif 
	sys_ret = writev (fd, iov, iovcnt); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("writev:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("writev:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	return (sys_ret); 
}	


ssize_t xpreadv (int error_response, const char *f_name, int fd, const struct iovec *iov, 
	         int iovcnt, off_t offset, ...) 
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(offset); 
#endif 
	sys_ret = preadv (fd, iov, iovcnt, offset); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("preadv:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("preadv:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	return (sys_ret); 
}

ssize_t xpwritev (int error_response, const char *f_name, int fd, const struct iovec *iov, 
	          int iovcnt, off_t offset, ...) 
{
	ssize_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG
	DEBUG_VARS(offset); 
#endif 
	sys_ret = pwritev (fd, iov, iovcnt, offset); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("pwritev:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("pwritev:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xtruncate (int error_response, const char *path_name, off_t off, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(off); 
#endif 
	sys_ret = truncate (path_name, off); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("truncate:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("truncate:%s:%s\n", path_name, err_msg); 
#endif	
	return (sys_ret); 
}

int xftruncate (int error_response, const char *f_name ,int fd, off_t off, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(off); 
#endif 
	sys_ret = ftruncate (fd, off); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("ftruncate:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("ftruncate:%s:%s\n",
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	return (sys_ret); 
}

int xbrk (int error_response, void *addr, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(addr); 
#endif 
	sys_ret = brk (addr); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("brk:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("brk:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

	

pid_t xgetpid (void) 
{
	return (getpid ()); 
}

pid_t xgetppid (void) 
{
	return (getppid ()); 
}

uid_t xgetuid (void) 
{
	return (getuid ()); 
}

gid_t xgetgid (void) 
{
	return (getgid ()); 
}

uid_t xgeteuid (void) 
{
	return (geteuid ()); 
}

gid_t xgetegid (void) 
{
	return (getegid ()); 
}

int xgetresuid (int error_response, uid_t *p_ruid, uid_t *p_euid, uid_t *p_suid, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(p_suid); 
#endif 
	sys_ret = getresuid (p_ruid, p_euid, p_suid); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("getresuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("getresuid:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xgetresgid (int error_response, gid_t *p_rgid, gid_t *p_egid, gid_t *p_sgid, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(p_sgid); 
#endif 
	sys_ret = getresgid (p_rgid, p_egid, p_sgid); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("getresgid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("getresgid:%s\n", err_msg); 
#endif
	return (sys_ret); 
}

int xsetuid (int error_response, uid_t uid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(uid); 
#endif 
	sys_ret = setuid (uid); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("setuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else	
	HANDLE_SYS_ERROR ("setuid:%s\n", err_msg); 
#endif
	return (sys_ret); 
}

int xsetgid (int error_response, gid_t gid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(gid); 
#endif 
	sys_ret = setgid (gid); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setgid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setgid:%s\n", err_msg);
#endif
	return (sys_ret); 
}

int xseteuid (int error_response, uid_t euid, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(euid); 
#endif 
	sys_ret = seteuid (euid); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("seteuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("seteuid:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xsetegid (int error_response, gid_t egid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(egid); 
#endif 
	sys_ret = setegid (egid); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setegid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setegid:%s\n", err_msg);
#endif
	return (sys_ret); 
}

int xsetreuid (int error_response, uid_t ruid, uid_t euid, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(euid); 
#endif 
	sys_ret = setreuid (ruid, euid); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setreuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setreuid:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xsetregid (int error_response, uid_t rgid, uid_t egid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(egid); 
#endif 
	sys_ret = setregid (rgid, egid);
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setregid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setregid:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}	

int xsetresuid (int error_response, uid_t ruid, uid_t euid, uid_t suid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(suid); 
#endif 
	sys_ret = setresuid (ruid, euid, suid); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setresuid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setresuid:%s\n", err_msg); 
#endif
	return (sys_ret); 
}

int xsetresgid (int error_response, gid_t rgid, gid_t egid, gid_t sgid, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(sgid); 
#endif 
	sys_ret = setresgid (rgid, egid, sgid); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("setresgid:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setresgid:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}	

int xgetgroups (int error_response, size_t size, gid_t *list[], ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(list); 
#endif 
	sys_ret = getgroups (size, list); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("getgroups:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("getgroups:%s\n", err_msg); 
#endif
	return (sys_ret); 	
}

int xsetgroups (int error_response, size_t size, const gid_t *list, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(list); 
#endif 
	sys_ret = setgroups (size, list); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("setgroups:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("setgroups:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xgetgettimeofday (int error_response, struct timeval *tv, struct timezone *tz, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(tz); 
#endif 	
	sys_ret = gettimeofday (tv, tz); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("gettimeofday:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("gettimeofday:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xsettimeofday (int error_response, const struct timeval *tv, const struct timezone *tz, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(tz); 
#endif 
	sys_ret = settimeofday (tv, tz); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("settimeofday:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("settimeofday:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

time_t xtime (int error_response, time_t *timep, ...)
{
	time_t sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(timep); 
#endif 
	sys_ret = time (timep); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("time:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("time:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

long xsysconf (int error_response, int name, ...) 
{
	long sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	sys_ret = sysconf (name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("sysconf:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("sysconf:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

long xpathconf (int error_response, const char *path_name, int name, ...)
{
	long sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	sys_ret = pathconf (path_name, name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("pathconf:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("pathconf:%s\n", err_msg); 
#endif
	return (sys_ret); 
}

long xfpathconf (int error_response, const char *path_name, int fd, int name, ...) 
{
	long sys_ret; 
	char *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(name); 
#endif 
	sys_ret = fpathconf (fd, name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fpathconf:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fpathconf:%s:%s\n", path_name != NULL ? path_name : no_file_name, 
			   err_msg); 
#endif 
	return (sys_ret); 
}

int xuname (int error_response, struct utsname *uts_buffer, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(uts_buffer); 
#endif 
	sys_ret = uname (uts_buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("uname:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("uname:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xfsync (int error_response, const char *f_name, int fd, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(fd); 
#endif 
	sys_ret = fsync (fd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fsync:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fsync:%s:%s\n", 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#endif
	return (sys_ret); 	
}

int xfdatasync (int error_response, const char *f_name, int fd, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(fd); 
#endif 
	sys_ret = fdatasync (fd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fdatasync:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fdatasync:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg);
#endif 
	return (sys_ret); 
}

void xsync (void) 
{
	sync (); 
}

int xmount (int error_response, const char *source, const char *target, 
	    const char *fs_type, unsigned long flags, void *data, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(data); 
#endif 
	sys_ret = mount (source, target, fs_type, flags, data); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("mount:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, 
		       source, target, err_msg); 
#else
	HANDLE_SYS_ERROR ("mount:%s:%s:%s\n", source, target, err_msg); 
#endif
	return (sys_ret); 
}
 
int xumount (int error_response, const char *target, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(target); 
#endif 
	sys_ret = umount (target); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("umount:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   target, err_msg); 
#else
	HANDLE_SYS_ERROR ("umount:%s:%s\n", target, err_msg); 
#endif
	/* Either Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

int xumount2 (int error_response, const char *target, int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = umount2 (target, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("umount2:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			  target, err_msg); 
#else
	HANDLE_SYS_ERROR ("umount2:%s:%s\n", target, err_msg); 
#endif 
	/* Either Success or ER_RET_WITH_MSG */ 
	return (sys_ret); 
}

int xstatvfs (int error_response, const char *path_name, struct statvfs *statvfs_buffer, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(statvfs_buffer); 
#endif 
	sys_ret = statvfs (path_name, statvfs_buffer); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("statvfs:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			  path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("statvfs:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfstatvfs (int error_response, const char *path_name, int fd,  
	       struct statvfs *statvfs_buffer, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(statvfs_buffer); 
#endif 
	sys_ret = fstatvfs (fd, statvfs_buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fstatvfs:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fstatvfs:%s:%s\n", path_name != NULL ? path_name : no_file_name, 
			   err_msg); 
#endif 
	return (sys_ret); 	
}

int xstat (int error_response, const char *path_name, struct stat *stat_buffer, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(stat_buffer); 
#endif 
	sys_ret = stat (path_name, stat_buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("stat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("stat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlstat (int error_response, const char *path_name, struct stat *stat_buffer, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(stat_buffer); 
#endif 
	sys_ret = lstat (path_name, stat_buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("lstat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("lstat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfstat (int error_response, const char *path_name, int fd, struct stat *stat_buffer, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(stat_buffer); 
#endif 
	sys_ret = fstat (fd, stat_buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fstat:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("stat:%s:%s\n", path_name != NULL ? path_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xutime (int error_response, const char *path_name, const struct utimbuf *buffer, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(buffer); 
#endif 
	sys_ret = utime (path_name, buffer); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("utime:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("utime:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xutimes (int error_response, const char *path_name, const struct timeval tv[2], ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(tv); 
#endif 
	sys_ret = utimes (path_name, tv); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("utimes:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("utimes:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlutimes (int error_response, const char *path_name, const struct timeval tv[2], ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(tv); 
#endif 
	sys_ret = lutimes (path_name, tv); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("lutimes:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("lutimes:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfutimes (int error_response, const char *path_name, int fd, const struct timeval tv[2], ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(tv); 
#endif 
	sys_ret = futimes (fd, tv); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("futimes:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("utime:%s:%s\n", path_name != NULL ? path_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xutimensat (int error_response, int dir_fd, const char *f_name, 
		const struct timespec times[2], int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = utimensat (dir_fd, f_name, times, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("utimensat:%s:%d:%s:%s\n", src_file_name, src_nr_line, f_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("utimensat:%s:%s\n", f_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfutimens (int error_response, const char *f_name, int fd, const struct timespec times[2], ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(times); 
#endif 
	sys_ret = futimens (fd, times); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("futimens:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   f_name != NULL ? f_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("futimens:%s:%s\n", f_name != NULL ? f_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xchown (int error_response, const char *path_name, uid_t owner, gid_t group, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS (group); 
#endif 
	sys_ret = chown (path_name, owner, group); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("chown:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("chown:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlchown (int error_response, const char *path_name, uid_t owner, gid_t group, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS (group); 
#endif 
	sys_ret = lchown (path_name, owner, group); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("lchown:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("lchown:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfchown (int error_response, const char *path_name, int fd, uid_t owner, gid_t group, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS (group); 
#endif 
	sys_ret = fchown (fd, owner, group); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fchown:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fchown:%s:%s\n", path_name != NULL ? path_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xaccess (int error_response, const char *path_name, mode_t mode, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = access (path_name, mode); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("access:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("access:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

mode_t xumask (mode_t mode) 
{
	return (umask (mode)); 
}

int xchmod (int error_response, const char *path_name, mode_t mode, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = chmod (path_name, mode); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("chmod:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("chmod:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfchmod (int error_response, const char *path_name, int fd, mode_t mode, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = fchmod (fd, mode); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fchmod:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fchmod:%s:%s\n", path_name != NULL ? path_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}


int xsetxattr (int error_response, const char *path_name, const char *name, const void *value, 
	       size_t size, int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = setxattr (path_name, name, value, size, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("setxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("setxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlsetxattr (int error_response, const char *path_name, const char *name, const void *value, 
		size_t size, int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = lsetxattr (path_name, name, value, size, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("lsetxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("lsetxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfsetxattr (int error_response, const char *path_name, int fd, const char *name, const void *value, 
		size_t size, int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = fsetxattr (fd, name, value, size, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fsetxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		           path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fsetxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xgetxattr (int error_response, const char *path_name, const char *name, 
	       void *value, size_t size, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(size); 
#endif 
	sys_ret = getxattr (path_name, name, value, size); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR("getxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR("getxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlgetxattr (int error_response, const char *path_name, const char *name, 
		void *value, size_t size, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(size); 
#endif 
	sys_ret = lgetxattr (path_name, name, value, size); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR("lgetxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR("lgetxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 

}

int xfgetxattr (int error_response, const char *path_name, int fd, const char *name, 
		void *value, size_t size, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(size); 
#endif 
	sys_ret = fgetxattr (fd, name, value, size); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR("getxattr:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
		          path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR("getxattr:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlink (int error_response, const char *old_path, const char *new_path, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(new_path); 
#endif 
	sys_ret = link (old_path, new_path); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("link:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, old_path, new_path, 
			   err_msg); 
#else
	HANDLE_SYS_ERROR ("link:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

int xunlink (int error_response, const char *path_name, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(path_name); 
#endif 
	sys_ret = unlink (path_name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("unlink:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("unlink:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xrename (int error_response, const char *old_path, const char *new_path, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(new_path); 
#endif 
	sys_ret = rename (old_path, new_path); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("rename:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, old_path, 
			   new_path, err_msg); 
#else
	HANDLE_SYS_ERROR ("rename:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

int xsymlink (int error_response, const char *old_path, const char *new_path, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(new_path); 
#endif 
	sys_ret = symlink (old_path, new_path); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("symlink:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, old_path, new_path, 
			   err_msg); 
#else
	HANDLE_SYS_ERROR ("symlink:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

ssize_t xreadlink (int error_response, const char *path_name, char *buffer, size_t size, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(size);
#endif 
	sys_ret = readlink (path_name, buffer, size); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("readlink:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("readlink:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xmkdir (int error_response, const char *path_name, mode_t mode, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = mkdir (path_name, mode); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("mkdir:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("mkdir:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xrmdir (int error_response, const char *path_name, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(path_name); 
#endif 
	sys_ret = rmdir (path_name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("rmdir:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("rmdir:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xremove (int error_response, const char *path_name, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG
	DEBUG_VARS(path_name); 
#endif 
	sys_ret = remove (path_name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("remove:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("remove:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

char *xgetcwd (int error_response, char *buffer, size_t size, ...) 
{
	char *sys_ret, *err_msg; 
#ifdef DEBUG 
	DEBUG_VARS(size); 
#endif 
	sys_ret = getcwd (buffer, size); 
	if (sys_ret == NULL)
	{
		if (error_response == ER_RETONLY) 
		{
			return (sys_ret); 
		}	
		err_msg = strerror (errno); 
#ifdef DEBUG 
		fprintf (stderr, "getcwd:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else	
		fprintf (stderr, "getcwd:%s\n", err_msg); 
#endif 
		if (error_response == ER_MSG_WITH_EXIT)
		{
			exit (EXIT_FAILURE); 
		}
	}

	return (sys_ret); 
}

int xchdir (int error_response, const char *path_name, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(path_name); 
#endif 
	sys_ret = chdir (path_name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("chdir:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("chdir:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfchdir (int error_response, const char *path_name, int fd, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(fd); 
#endif 
	sys_ret = fchdir (fd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fchdir:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fchdir:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xchroot (int error_response, const char *path_name, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(path_name); 
#endif 
	sys_ret = chroot (path_name); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("chroot:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("chroot:%s:%s\n", path_name, err_msg);
#endif 
	return (sys_ret); 
}

int xopenat (int error_response, int is_o_create, int dir_fd, const char *path_name, int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
	mode_t mode; 
	va_list ap; 
	va_start (ap, flags); 
#ifdef DEBUG
	char *src_file_name; 
	int src_nr_line; 
		if (is_o_create == TRUE) 
	{
		mode = va_arg (ap, mode_t); 
	}	
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
#endif 
	if (is_o_create == TRUE)
	{
		mode = va_arg (ap, mode_t); 
		sys_ret = openat (dir_fd, path_name, flags, mode); 
	}
	else 
	{
		sys_ret = openat (dir_fd, path_name, flags); 
	}

#ifdef DEBUG 
	HANDLE_SYS_ERROR ("opeat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("openat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfaccessat (int error_response, int dir_fd, const char *path_name, int mode, int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = faccessat (dir_fd, path_name, mode, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("faccessat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("faccessat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfchmodat (int error_response, int dir_fd, const char *path_name, mode_t mode, int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = fchmodat (dir_fd, path_name, mode, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fchmodat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fchmodat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfchownat (int error_response, int dir_fd, const char *path_name, uid_t owner, gid_t group, 
	      int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = fchownat (dir_fd, path_name, owner, group, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fchownat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fchownat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xfstatat (int error_response, int dir_fd, const char *path_name, struct stat *stat_buffer, 
	      int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = fstatat (dir_fd, path_name, stat_buffer, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("fstatat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("fstatat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xlinkat (int error_response, int old_dir_fd, const char *old_path, int new_dir_fd, 
	     const char *new_path, int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = linkat (old_dir_fd, old_path, new_dir_fd, new_path, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("linkat:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, 
			   old_path, new_path, err_msg); 
#else
	HANDLE_SYS_ERROR ("linkat:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

int xmkdirat (int error_response, int dir_fd, const char *path_name, mode_t mode, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = mkdirat (dir_fd, path_name, mode); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("mkdirat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("mkdirat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xmknodat (int error_response, int dir_fd, const char *path_name, mode_t mode, dev_t dev, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(dev); 
#endif 
	sys_ret = mknodat (dir_fd, path_name, mode, dev); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("mknodat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("mknodat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xreadlinkat (int error_response, int dir_fd, const char *path_name, 
		 char *buffer, size_t buffer_size, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(buffer_size); 
#endif 
	sys_ret = readlinkat (dir_fd, path_name, buffer, buffer_size); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("readlinkat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("readlinkat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xrenameat (int error_response, int old_dir_fd, const char *old_path, 
	       int new_dir_fd, const char *new_path, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(new_path); 
#endif 
	sys_ret = renameat (old_dir_fd, old_path, new_dir_fd, new_path); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("renameat:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, 
			   old_path, new_path, err_msg); 
#else
	HANDLE_SYS_ERROR ("renameat:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

int xsymlinkat (int error_response, const char *old_path, int new_dir_fd, const char *new_path, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(new_path); 
#endif 
	sys_ret = symlinkat (old_path, new_dir_fd, new_path); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("symlinkat:%s:%d:%s:%s:%s\n", src_file_name, src_nr_line, 
			   old_path, new_path, err_msg); 
#else
	HANDLE_SYS_ERROR ("symlinkat:%s:%s:%s\n", old_path, new_path, err_msg); 
#endif 
	return (sys_ret); 
}

int xunlinkat (int error_response, int dir_fd, const char *path_name, int flags, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = unlinkat (dir_fd, path_name, flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("unlinkat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg);
#else
	HANDLE_SYS_ERROR ("unlinkat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xmkfifoat (int error_response, int dir_fd, const char *path_name, mode_t mode, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mode); 
#endif 
	sys_ret = mkfifoat (dir_fd, path_name, mode); 
#ifdef DEBUG
	HANDLE_SYS_ERROR ("mkfifoat:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("mkfifoat:%s:%s\n", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xinotify_init (int error_response, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(error_response); 
#endif 
	sys_ret = inotify_init (); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("inotify_init:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("inotify_init:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xinotify_init1 (int error_response, int flags, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(flags); 
#endif 
	sys_ret = inotify_init1 (flags); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("inotify_init1:%s:%d:%s\n", src_file_name, src_nr_line, err_msg); 
#else
	HANDLE_SYS_ERROR ("inotify_init1:%s\n", err_msg); 
#endif 
	return (sys_ret); 
}

int xinotify_add_watch (int error_response, int fd, const char *path_name, uint32_t mask, ...)
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(mask); 
#endif 
	sys_ret = inotify_add_watch (fd, path_name, mask); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("inotify_add_watch:%s:%d:%s:%s\n", src_file_name, src_nr_line, path_name, 
			   err_msg); 
#else
	HANDLE_SYS_ERROR ("inotify_add_watch:%s:%s", path_name, err_msg); 
#endif 
	return (sys_ret); 
}

int xinotify_rm_watch (int error_response, const char *path_name, int fd, uint32_t wd, ...) 
{
	DEFINE_VARS(sys_ret, err_msg); 
#ifdef DEBUG 
	DEBUG_VARS(wd); 
#endif 
	sys_ret = inotify_rm_watch (fd, wd); 
#ifdef DEBUG 
	HANDLE_SYS_ERROR ("inotify_rm_watch:%s:%d:%s:%s\n", src_file_name, src_nr_line, 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#else
	HANDLE_SYS_ERROR ("inotify_rm_watch:%s:%s\n", 
			   path_name != NULL ? path_name : no_file_name, err_msg); 
#endif 
	return (sys_ret); 
}
