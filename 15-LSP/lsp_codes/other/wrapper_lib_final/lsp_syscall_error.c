#include "lsp_error.h" 

static const char no_file_name [] = "No File Name"; 

#ifndef F_NAME	
#define F_NAME	((f_name != NULL) ? f_name : no_file_name)
#endif

int x_open (const char *f_name, int flags, ...)
{
	int sys_ret, error_response; 
	mode_t mode; 
	char *err_msg; 
	va_list ap; 
#ifdef DEBUG
	char *src_file_name; 
	int src_nr_line; 
#endif 
	va_start (ap, flags); 
	
	if ((flags & O_CREAT) == O_CREAT)
	{
		mode = va_arg (ap, mode_t); 	
	}

	error_response = va_arg (ap, int); 
#ifdef DEBUG 
	src_file_name  = va_arg (ap, char*); 
	src_nr_line    = va_arg (ap, int); 
#endif
	va_end (ap); 

	if ((flags & O_CREAT) == O_CREAT)
	{
		sys_ret = open (f_name, flags, mode); 
	}
	else
	{
		sys_ret = open (f_name, flags); 
	}

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("open:%s", f_name); 
	}
	
	return (sys_ret); 
}

ssize_t x_read (int fd, void *buffer, size_t size, const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = read (fd, buffer, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("read:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_write (int fd, void *buffer, size_t size, const char *f_name, ...) 
{
	ssize_t sys_ret;
	FETCH (f_name); 

	sys_ret = write (fd, buffer, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("write:%s", F_NAME); 
	}

	return (sys_ret); 
}

off_t x_lseek (int fd, off_t offset, int whence, const char *f_name, ...) 
{
	off_t sys_ret; 
	FETCH (f_name); 

	sys_ret = lseek (fd, offset, whence); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lseek:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_close (int fd, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = close (fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("close:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_pread (int fd, void *buffer, size_t size, off_t offset, const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = pread (fd, buffer, size, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pread:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_pwrite (int fd, void *buffer, size_t size, off_t offset, const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = pwrite (fd, buffer, size, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pwrite:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

ssize_t x_readv (int fd, const struct iovec *iov, int iovcnt, const char *f_name, ...)
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = readv (fd, iov, iovcnt); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("readv:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_writev (int fd, const struct iovec *iov, int iovcnt, const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = writev (fd, iov, iovcnt); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("writev:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_preadv (int fd, const struct iovec *iov, int iovcnt, off_t offset, 
		  const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = preadv (fd, iov, iovcnt, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("preadv:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

ssize_t x_pwritev (int fd, const struct iovec *iov, int iovcnt, off_t offset, 
		  const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = pwritev (fd, iov, iovcnt, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pwritev:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

int x_dup (int old_fd, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = dup (old_fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("dup:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_dup2 (int old_fd, int new_fd, const char *f_name, ...)
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = dup2 (old_fd, new_fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("dup2:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_dup3 (int old_fd, int new_fd, int flags, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = dup3 (old_fd, new_fd, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("dup3:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_truncate (const char *path_name, off_t offset, ...) 
{
	int sys_ret; 
	FETCH (offset); 

	sys_ret = truncate (path_name, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("truncate:%s", path_name); 
	}

	return (sys_ret); 
}

int x_ftruncate (int fd, off_t offset, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = ftruncate (fd, offset); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("ftruncate:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

inline pid_t xi_getpid (void) 
{
	getpid (); 
}

inline pid_t xi_getppid (void)
{
	getppid (); 
}

inline uid_t xi_getuid (void) 
{
	getuid (); 
}

inline gid_t xi_getgid (void) 
{
	getgid (); 
}

inline uid_t xi_geteuid (void) 
{
	geteuid (); 
}

inline gid_t xi_getegid (void) 
{
	getegid (); 
}

int x_getresuid (uid_t *p_ruid, uid_t *p_euid, uid_t *p_suid, ...) 
{
	int sys_ret; 
	FETCH (p_suid); 

	sys_ret = getresuid (p_ruid, p_euid, p_suid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getresuid"); 
	}

	return (sys_ret); 
}

int x_getresgid (gid_t *p_rgid, gid_t *p_egid, gid_t *p_sgid, ...)
{
	int sys_ret; 
	FETCH (p_sgid); 

	sys_ret = getresgid (p_rgid, p_rgid, p_sgid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getresgid"); 
	}
	
	return (sys_ret); 
}

int x_setuid (uid_t uid, ...) 
{
	int sys_ret; 
	FETCH (uid); 

	sys_ret = setuid (uid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setuid"); 
	}

	return (sys_ret); 
}

int x_setgid (gid_t gid, ...) 
{
	int sys_ret; 
	FETCH (gid); 

	sys_ret = setgid (gid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setgid"); 	
	}
	
	return (sys_ret); 
}

int x_seteuid (uid_t euid, ...) 
{
	int sys_ret; 
	FETCH (euid); 

	sys_ret = seteuid (euid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("seteuid"); 
	}

	return (sys_ret); 
}

int x_setegid (gid_t egid, ...)
{
	int sys_ret; 
	FETCH (egid); 

	sys_ret = setegid (egid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setegid"); 
	}
	
	return (sys_ret); 
}

int x_setreuid (uid_t ruid, uid_t euid, ...)
{
	int sys_ret; 
	FETCH (euid); 

	sys_ret = setreuid (ruid, euid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setreuid"); 
	}

	return (sys_ret); 
}

int x_setregid (gid_t rgid, gid_t egid, ...) 
{
	int sys_ret; 
	FETCH (egid); 

	sys_ret = setregid (rgid, egid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setregids"); 
	}
	
	return (sys_ret); 
}

int x_setresuid (uid_t ruid, uid_t euid, uid_t suid, ...) 
{
	int sys_ret; 
	FETCH (suid); 

	sys_ret = setresuid (ruid, euid, suid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setresuid"); 
	}
	
	return (sys_ret); 
}

int x_setresgid (gid_t rgid, gid_t egid, gid_t sgid, ...) 
{
	int sys_ret; 
	FETCH (sgid); 

	sys_ret = setresgid (rgid, egid, sgid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setresgid"); 
	}
	
	return (sys_ret); 
}

int x_getgroups (int size, gid_t list[], ...) 
{
	int sys_ret; 
	FETCH (list); 

	sys_ret = getgroups (size, list); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getgroups"); 
	}

	return (sys_ret); 
}

int x_setgroups (int size, const gid_t *list, ...) 
{
	int sys_ret; 
	FETCH (list); 

	sys_ret = setgroups (size, list); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setgroups"); 
	}

	return (sys_ret); 
}

int x_gettimeofday (struct timeval *tv, struct timezone *tz, ...)
{
	int sys_ret; 
	FETCH (tz); 

	sys_ret = gettimeofday (tv, tz); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("gettimeofday"); 
	}
	
	return (sys_ret); 
}

int x_settimeofday (const struct timeval *tv, const struct timezone *tz, ...) 
{
	int sys_ret; 
	FETCH (tz); 

	sys_ret = settimeofday (tv, tz); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("settimeofday"); 
	}
	
	return (sys_ret); 
}

time_t x_time (time_t *timep, ...) 
{
	time_t sys_ret; 
	FETCH (timep); 

	sys_ret = time (timep); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("time"); 
	}
	
	return (sys_ret); 
}

long x_sysconf (int name, ...) 
{
	long sys_ret; 
	FETCH (name); 

	sys_ret = sysconf (name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sysconf"); 
	}

	return (sys_ret); 
}

long x_pathconf (const char *path_name, int name, ...)
{
	long sys_ret; 
	FETCH (name); 

	sys_ret = pathconf (path_name, name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pathconf:%s", path_name); 
	}

	return (sys_ret); 
}

long x_fpathconf (int fd, int name, char *f_name, ...)
{
	long sys_ret; 
	FETCH (f_name); 

	sys_ret = fpathconf (fd, name);

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fpathconf:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

int x_uname (struct utsname *uts_buffer, ...)
{
	int sys_ret; 
	FETCH (uts_buffer); 

	sys_ret = uname (uts_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("uname"); 
	}
	
	return (sys_ret); 
}

int x_fsync (int fd, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fsync (fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fsync:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_fdatasync (int fd, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fdatasync (fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fdatasync:%s", F_NAME); 
	}

	return (sys_ret); 
}

inline void xi_sync (void) 
{
	sync (); 
}

int x_mount (const char *source, const char *target, const char *fs_type, 
	    unsigned long flags, void *data, ...)
{
	int sys_ret; 
	FETCH (data); 

	sys_ret = mount (source, target, fs_type, flags, data); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mount:%s:%s", source, target); 
	}

	return (sys_ret); 
}

int x_umount (const char *target, ...) 
{
	int sys_ret; 
	FETCH (target); 

	sys_ret = umount (target); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("umount:%s", target); 
	}

	return (sys_ret); 
}

int x_umount2 (const char *target, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = umount2 (target, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("umount2:%s", target); 
	}

	return (sys_ret); 
}

int x_statvfs (const char *path_name, struct statvfs *statvfs_buffer, ...) 
{
	int sys_ret; 
	FETCH (statvfs_buffer); 

	sys_ret = statvfs (path_name, statvfs_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("statvfs:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fstatvfs (int fd, struct statvfs *statvfs_buffer, const char *f_name, ...)
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fstatvfs (fd, statvfs_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fstatvfs:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_stat (const char *path_name, struct stat *stat_buffer, ...)
{
	int sys_ret; 
	FETCH (stat_buffer); 

	sys_ret = stat (path_name, stat_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("stat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_lstat (const char *path_name, struct stat *stat_buffer, ...)
{
	int sys_ret; 
	FETCH (stat_buffer); 

	sys_ret = lstat (path_name, stat_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lstat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fstat (int fd, struct stat *stat_buffer, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fstat (fd, stat_buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fstat:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_utime (const char *path_name, const struct utimbuf *buffer, ...) 
{
	int sys_ret; 
	FETCH (buffer); 

	sys_ret = utime (path_name, buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("utime:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_utimes (const char *path_name, const struct timeval tv[2], ...) 
{
	int sys_ret; 
	FETCH (tv); 

	sys_ret = utimes (path_name, tv); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("utimes:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_lutimes (const char *path_name, const struct timeval tv[2], ...) 
{
	int sys_ret; 
	FETCH (tv); 

	sys_ret = lutimes (path_name, tv); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lutimes:%s", path_name); 
	}

	return (sys_ret); 
}

int x_futimes (int fd, const struct timeval tv[2], const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = futimes (fd, tv); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("futimes:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_chown (const char *f_name, uid_t owner, gid_t group, ...) 
{
	int sys_ret; 
	FETCH (group); 

	sys_ret = chown (f_name, owner, group); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("chown:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_lchown (const char *path_name, uid_t owner, gid_t group, ...) 
{
	int sys_ret; 
	FETCH (group); 

	sys_ret = lchown (path_name, owner, group); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lchown:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fchown (int fd, uid_t owner, gid_t group, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fchown (fd, owner, group); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fchown:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_access (const char *path_name, mode_t mode, ...)
{
	int sys_ret; 
	FETCH (mode); 

	sys_ret = access (path_name, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("access:%s", path_name); 
	}

	return (sys_ret); 
}

inline mode_t xi_umask (mode_t mask)
{
	umask (mask); 
}	

int x_chmod (const char *path_name, mode_t mode, ...)
{
	int sys_ret; 
	FETCH (mode); 

	sys_ret = chmod (path_name, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("path_name:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fchmod (int fd, mode_t mode, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fchmod (fd, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fchmod:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_setxattr (const char *path_name, const char *name, const void *value, 
	      size_t size, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = setxattr (path_name, name, value, size, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("path_name:%s", path_name); 
	}

	return (sys_ret); 
}

int x_lsetxattr (const char *path_name, const char *name, const void *value, 
		size_t size, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = lsetxattr (path_name, name, value, size, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lsetxattr:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_fsetxattr (int fd, const char *name, const void *value, size_t size, 
		int flags, const char *f_name, ...)
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fsetxattr (fd, name, value, size, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fsetxattr:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

int x_getxattr (const char *path_name, const char *name, void *value, size_t size, ...) 
{
	int sys_ret; 
	FETCH (size); 

	sys_ret = getxattr (path_name, name, value, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getxattr:%s", path_name); 
	}

	return (sys_ret); 
}

int x_lgetxattr (const char *path_name, const char *name, void *value, size_t size, ...) 
{
	int sys_ret; 
	FETCH (size); 

	sys_ret = lgetxattr (path_name, name, value, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lgetxattr:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fgetxattr (int fd, const char *name, void *value, size_t size, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fgetxattr (fd, name, value, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fgetxattr:%s", f_name); 
	}

	return (sys_ret); 
}

int x_removexattr (const char *path_name, const char *name, ...) 
{
	int sys_ret; 
	FETCH (name); 

	sys_ret = removexattr (path_name, name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("removexattr:%s", path_name); 
	}

	return (sys_ret); 
}

int x_lremovexattr (const char *path_name, const char *name, ...)
{
	int sys_ret; 
	FETCH (name); 

	sys_ret = lremovexattr (path_name, name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("lremovexattr:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fremovexattr (int fd, const char *name, const char *f_name, ...) 
{
	int sys_ret; 
	FETCH (f_name);

	sys_ret = fremovexattr (fd, name); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fremovexattr:%s", F_NAME); 
	}

	return (sys_ret); 
}

ssize_t x_listxattr (const char *path_name, char *list, size_t size, ...) 
{
	ssize_t sys_ret; 
	FETCH (size); 

	sys_ret = listxattr (path_name, list, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("listxattr:%s", path_name); 
	}

	return (sys_ret); 
}

ssize_t x_llistxattr (const char *path_name, char *list, size_t size, ...) 
{
	ssize_t sys_ret; 
	FETCH (size); 

	sys_ret = llistxattr (path_name, list, size); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("llistxattr:%s", path_name); 
	}
	
	return (sys_ret); 
}

ssize_t x_flistxattr (int fd, char *list, size_t size, const char *f_name, ...) 
{
	ssize_t sys_ret; 
	FETCH (f_name); 

	sys_ret = flistxattr (fd, list, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("flistxattr:%s", F_NAME); 
	}
	
	return (sys_ret); 
}

int x_link (const char *old_path, const char *new_path, ...) 
{
	int sys_ret; 
	FETCH (new_path); 

	sys_ret = link (old_path, new_path); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("link:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

int x_unlink (const char *path_name, ...)
{
	int sys_ret; 
	FETCH (path_name); 

	sys_ret = unlink (path_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("unlink:%s", path_name); 
	}

	return (sys_ret); 
}

int x_rename (const char *old_path, const char *new_path, ...) 
{
	int sys_ret; 
	FETCH (new_path); 

	sys_ret = rename (old_path, new_path); 

	if (sys_ret == -1)
	{
		HANDLE_SYS_ERROR ("rename:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

int x_symlink (const char *old_path, const char *new_path, ...) 
{
	int sys_ret; 
	FETCH (new_path); 

	sys_ret = symlink (old_path, new_path); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("symlink:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

ssize_t x_readlink (const char *path_name, char *buffer, size_t size, ...)
{
	int sys_ret; 
	FETCH (size); 

	sys_ret = readlink (path_name, buffer, size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("readlink:%s", path_name); 
	}

	return (sys_ret); 
}

int x_mkdir (const char *path_name, mode_t mode, ...) 
{
	int sys_ret; 
	FETCH (mode); 

	sys_ret = mkdir (path_name, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mkdir:%s", path_name); 
	}

	return (sys_ret); 
}

int x_rmdir (const char *path_name, ...) 
{
	int sys_ret; 
	FETCH (path_name); 

	sys_ret = rmdir (path_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("rmdir:%s", path_name); 
	}

	return (sys_ret); 
}

int x_remove (const char *path_name, ...)
{
	int sys_ret; 
	FETCH (path_name); 

	sys_ret = remove (path_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("remove:%s", path_name); 
	}

	return (sys_ret); 
}

char *x_getcwd (char *buffer, size_t size, ...) 
{
	char *sys_ret; 
	FETCH (size); 

	sys_ret = getcwd (buffer, size); 

	if (sys_ret == NULL) 
	{
		HANDLE_SYS_ERROR ("getcwd"); 
	}
	
	return (sys_ret); 
}

int x_chdir (const char *path_name, ...) 
{
	int sys_ret; 
	FETCH (path_name); 

	sys_ret = chdir (path_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("chdir:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fchdir (int fd, const char *f_name, ...)
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = fchdir (fd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fchdir:%s", F_NAME); 
	}

	return (sys_ret); 
}

int x_chroot (const char *path_name, ...) 
{
	int sys_ret; 
	FETCH (path_name); 

	sys_ret = chroot (path_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("chroot:%s", path_name); 
	}

	return (sys_ret); 
}

int x_openat (int dir_fd, const char *path_name, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = openat (dir_fd, path_name, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("openat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_faccessat (int dir_fd, const char *path_name, int mode, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = faccessat (dir_fd, path_name, mode, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("faccessat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fchmodat (int dir_fd, const char *path_name, mode_t mode, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = fchmodat (dir_fd, path_name, mode, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("chdmoat:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_fchownat (int dir_fd, const char *path_name, uid_t owner, gid_t group, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = fchownat (dir_fd, path_name, owner, group, flags); 

	if (sys_ret == -1)
	{
		HANDLE_SYS_ERROR ("chownat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_fstatat (int dir_fd, const char *path_name, struct stat *stat_buffer, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = fstatat (dir_fd, path_name, stat_buffer, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fstatat:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_linkat (int dir_fd, const char *old_path, int new_dir_fd, const char *new_path, 
	      int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = linkat (dir_fd, old_path, new_dir_fd, new_path, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("linkat:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

int x_mkdirat (int dir_fd, const char *path_name, mode_t mode, ...)
{
	int sys_ret; 
	FETCH (mode); 

	sys_ret = mkdirat (dir_fd, path_name, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mkdirat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_mknodat (int dir_fd, const char *path_name, mode_t mode, dev_t dev, ...) 
{
	int sys_ret; 
	FETCH (dev); 

	sys_ret = mknodat (dir_fd, path_name, mode, dev); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mknodat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_readlinkat (int dir_fd, const char *path_name, char *buffer, size_t buffer_size, ...) 
{
	int sys_ret; 
	FETCH (buffer_size); 

	sys_ret = readlinkat (dir_fd, path_name, buffer, buffer_size); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("readlinkat:%s", path_name); 
	}
	
	return (sys_ret); 
}

int x_renameat (int old_dir_fd, const char *old_path, int new_dir_fd, const char *new_path, ...) 
{
	int sys_ret; 
	FETCH (new_path); 

	sys_ret = renameat (old_dir_fd, old_path, new_dir_fd, new_path); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("renameat:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

int x_symlinkat (const char *old_path, int new_dir_fd, const char *new_path, ...) 
{
	int sys_ret; 
	FETCH (new_path); 

	sys_ret = symlinkat (old_path, new_dir_fd, new_path); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("symlinkat:%s:%s", old_path, new_path); 
	}

	return (sys_ret); 
}

int x_unlinkat (int dir_fd, const char *path_name, int flags, ...) 
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = unlinkat (dir_fd, path_name, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("unlinkat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_mkfifoat (int dir_fd, const char *path_name, mode_t mode, ...) 
{
	int sys_ret; 
	FETCH (mode); 

	sys_ret = mkfifoat (dir_fd, path_name, mode); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mkfifoat:%s", path_name); 
	}

	return (sys_ret); 
}

int x_inotify_init (int error_response, ...) 
{
	int sys_ret, src_nr_line;
	char *err_msg, *src_file_name; 
	va_list ap; 

	va_start (ap, error_response); 
#ifdef DEBUG 
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
#endif 
	va_end (ap); 

	sys_ret = inotify_init (); 
	if (sys_ret == -1) 
	{
		if (error_response == ER_RETONLY)
		{
			return (sys_ret); 
		}

		err_msg = strerror (errno); 
		if (error_response == ER_MSG_WITH_EXIT)
		{
			exit (EXIT_FAILURE); 
		}
	}

	return (sys_ret); 
}

int x_inotify_init1 (int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = xinotify_init1 (flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("inotify_init1"); 
	}

	return (sys_ret); 
}

int x_inotify_add_watch (int fd, const char *path_name, uint32_t mask, ...)
{
	int sys_ret; 
	FETCH (mask); 
	
	sys_ret = inotify_add_watch (fd, path_name, mask); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("inotify_add_watch:%s", path_name); 
	}

	return (sys_ret); 
}

int x_inotify_rm_watch (int fd, uint32_t wd, const char *f_name, ...)
{
	int sys_ret; 
	FETCH (f_name); 

	sys_ret = inotify_rm_watch (fd, wd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("inotify_rm_watch:%s", F_NAME); 
	}

	return (sys_ret); 
}

sighandler_t x_signal (int signal_number, sighandler_t signal_handler, ...)
{
	
	sighandler_t sys_ret; 
	FETCH (signal_handler); 

	sys_ret = (sighandler_t) signal (signal_number, signal_handler); 

	if ((long)sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("signal"); 
	}

	return (sys_ret); 
}

int x_kill (pid_t pid, int signal_number, ...) 
{
	int sys_ret; 
	FETCH (signal_number); 

	sys_ret = kill (pid, signal_number); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("kill"); 
	}
	
	return (sys_ret); 
}

int x_killpg (int nr_process_group, int signal_number, ...) 
{
	int sys_ret; 
	FETCH (signal_number); 

	sys_ret = killpg (nr_process_group, signal_number); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("killpg"); 
	}
	
	return (sys_ret); 
}


int x_pause (int error_response, ...)
{
     int sys_ret; 
     char *err_msg; 
     va_list ap; 
     
#ifdef DEBUG 
     char *src_file_name; 
     int  src_nr_line; 
#endif
     
     va_start (ap, error_response); 
     
#ifdef DEBUG 
     src_file_name = va_arg (ap, char*); 
     src_nr_line   = va_arg (ap, int); 
#endif 
     va_end (ap); 
     
     sys_ret = pause (); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("pause"); 
     }
     
     return (sys_ret); 
}

int x_sigaction (int signal_number, const struct sigaction *action, 
		 struct sigaction *old_action, ...)
{
     int sys_ret; 
     FETCH (old_action); 
     
     sys_ret = sigaction (signal_number, action, old_action); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigaction"); 
     }
     
     return (sys_ret); 
}

int x_signalfd (int fd, const sigset_t *mask, int flags, ...)
{
     int sys_ret; 
     FETCH (flags); 
     
     sys_ret = signalfd (fd, mask, flags); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("signalfd"); 
     }
     
     return (sys_ret); 
}

int x_sigpending (sigset_t *set, ...)
{
     int sys_ret; 
     FETCH (set); 
     
     sys_ret = sigpending (set); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigpending"); 
     }

     return (sys_ret); 
}

int x_sigprocmask (int how, const sigset_t *new_set, sigset_t *old_set, ...)
{
     int sys_ret; 
     FETCH (old_set); 
     
     sys_ret = sigprocmask (how, new_set, old_set); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigprocmask"); 
     }
     
     return (sys_ret); 
}

int x_sigsuspend (const sigset_t *mask, ...)
{
     int sys_ret; 
     FETCH (mask); 
     
     sys_ret = sigsuspend (mask); 
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigsuspend"); 
     }
     
     return (sys_ret);
}

int x_sigwaitinfo (const sigset_t *set, siginfo_t *info, ...)
{
     int sys_ret; 
     FETCH (info); 
     
     sys_ret = sigwaitinfo (set, info); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigwaitinfo"); 
     }
     
     return (sys_ret);
}

int x_sigtimedwait (const sigset_t *set, siginfo_t *info, 
		   const struct timespec *timeout, ...)
{
     int sys_ret; 
     FETCH (timeout); 
     
     sys_ret = sigtimedwait (set, info, timeout); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("sigtimedwait");
     }
     
     return (sys_ret);
}

/*int xrt_sigqueueinfo(pid_t tgid, int sig, siginfo_t *uinfo, ...)
{
    int sys_ret; 
    FETCH (uinfo); 
    
    sys_ret = rt_sigqueueinfo (tgid, sig, uinfo); 
    
    if (sys_ret == -1) 
    {
	HANDLE_SYS_ERROR ("rt_sigqueueinfo");  
    }
    
    return (sys_ret); 
}

int xrt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, siginfo_t *uinfo, ...)
{
     int sys_ret; 
     FETCH (uinfo); 
     
     sys_ret = rt_tsigqueueinfo (tgid, tid, sig, uinfo); 
     
     if (sys_ret == -1) 
     {
	  HANDLE_SYS_ERROR ("rt_sigqueueinfo"); 
     }
     
     return (sys_ret);
}*/

int x_getitimer (int which, struct itimerval *curr_value, ...) 
{
	int sys_ret; 
	FETCH (curr_value); 

	sys_ret = gettimer (which, curr_value); 

	if(sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("gettimer"); 
	}

	return (sys_ret); 
}

int x_setitimer (int which, const struct itimerval *new_value, struct itimerval *old_value, ...) 
{
	int sys_ret; 
	FETCH (old_value); 

	sys_ret = settimer (which, new_value, old_value); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("settimer"); 
	}

	return (sys_ret); 
}

inline unsigned int xi_alarm (unsigned int seconds)
{
	alarm (seconds); 
}

int x_nanosleep (const struct timespec *req, struct timespec *remaining, ...)
{
	int sys_ret; 
	FETCH (remaining); 

	sys_ret = nanosleep (req, remaining); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("nanosleep"); 
	}

	return (sys_ret); 
}

int x_clock_getres (clockid_t clk_id, struct timespec *res, ...)
{
	int sys_ret; 
	FETCH (res); 

	sys_ret = clock_getres (clk_id, res); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("clock_getrest"); 
	}

	return (sys_ret); 
}

int x_clock_gettime (clockid_t clk_id, struct timespec *tp, ...)
{
	int sys_ret; 
	FETCH (tp); 

	sys_ret = clock_gettime (clk_id, tp); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("clock_gettime"); 
	}

	return (sys_ret); 
}

int x_clock_settime (clockid_t clk_id, const struct timespec *tp, ...)
{
	int sys_ret; 
	FETCH (tp); 

	sys_ret = clock_settime (clk_id, tp); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("clock_settime"); 
	}

	return (sys_ret); 
}

int x_clock_nanosleep (clockid_t clock_id, int flags, const struct timespec *request, 
			  struct timespec *remaining, ...)
{
	int sys_ret; 
	FETCH (remaining); 

	sys_ret = clock_nanosleep (clock_id, flags, request, remaining); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("clock_nanosleep"); 
	}

	return (sys_ret); 

}

int x_timer_create (clockid_t clockid, struct sigevent *sevp, timer_t *timerid, ...)
{
	int sys_ret; 
	FETCH (timerid); 

	sys_ret = timer_create (clockid, sevp, timerid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timer_create"); 
	}

	return (sys_ret); 
}

int x_timer_settime (timer_t timerid, int flags, const struct itimerspec *new_value, 
			struct itimerspec *old_value, ... )
{
	int sys_ret; 
	FETCH (old_value); 

	sys_ret = timer_settime (timerid, flags, new_value, old_value); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timer_settime"); 
	}

	return (sys_ret); 
}

int x_timer_gettime (timer_t timerid, struct itimerspec *current_value, ...)
{
	int sys_ret; 
	FETCH (current_value); 

	sys_ret = timer_gettime (timerid, current_value); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timer_gettime"); 
	}

	return (sys_ret); 
}

int x_timer_getoverrun (timer_t timerid, ...)
{
	int sys_ret; 
	FETCH (timerid); 

	sys_ret = timer_getoverrun (timerid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timer_getoverrun"); 
	}

	return (sys_ret); 
}

int x_timer_delete (timer_t timerid, ...)
{
	int sys_ret; 
	FETCH (timerid); 

	sys_ret = timer_delete (timerid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timer_delete"); 
	}

	return (sys_ret); 
}

int x_timerfd_create (int clockid, int flags, ...) 
{
	int sys_ret;
	FETCH (flags); 

	sys_ret = timerfd_create (clockid, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timerefd_create"); 
	}

	return (sys_ret); 
}

int x_timerfd_settime (int fd, int flags, const struct itimerspec *new_value, 
			  struct itimerspec *old_value, ...)
{
	int sys_ret; 
	FETCH (old_value); 

	sys_ret = timerfd_settime (fd, flags, new_value, old_value); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timerfd_settime"); 
	}

	return (sys_ret); 
}

int x_timerfd_gettime (int fd, struct itimerspec *current_value, ...)
{
	int sys_ret; 
	FETCH (current_value); 

	sys_ret = timerfd_gettime (fd, current_value); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("timerfd_gettime"); 
	}
	
	return (sys_ret); 
}

pid_t x_fork (int error_response, ...)  
{
	pid_t sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = fork (); 

	if ((int)sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("fork"); 
	}

	return (sys_ret); 
}

pid_t x_vfork (int error_response, ...)
{
	pid_t sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = vfork (); 

	if ((int) sys_ret == -1)
	{
		HANDLE_SYS_ERROR ("vfork"); 
	}

	return (sys_ret); 
}

inline void xi__exit (int exit_status)
{
	_exit (exit_status); 
}

pid_t x_wait (int *status, ...) 
{
	pid_t sys_ret; 
	FETCH (status); 

	sys_ret = wait (status); 

	if ((int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("wait"); 
	}

	return (sys_ret); 
}

int x_waitid (idtype_t idtype, id_t id, siginfo_t *infop, int options, ...)
{
	pid_t sys_ret; 
	FETCH (options); 

	sys_ret = waitid (idtype, id, infop, options); 

	if ((int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("waitid"); 
	}

	return (sys_ret); 
}
int x_execve (const char *path_name, char *const argv[], char *const envp[], ...)
{
	int sys_ret; 
	FETCH (envp); 

	sys_ret = execve (path_name, argv, envp); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("execve"); 
	}

	return (sys_ret); 
}

int x_acct (const char *file_name, ...)
{
	int sys_ret; 
	FETCH (file_name); 

	sys_ret = acct (file_name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("acct"); 
	}

	return (sys_ret); 
}

int x_clone (unsigned long flags, void *child_stack, void *ptid, void *ctid, struct pt_regs *regs, ...)
{
	int sys_ret; 
	FETCH (regs); 

	sys_ret = clone (flags, child_stack, ptid, ctid, regs); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("clone"); 
	}

	return (sys_ret); 
}

int x_getpgrp (int error_response, ...)
{
	int sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line   = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = getpgrp (); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getpgrp"); 
	}

	return (sys_ret); 
}

int x_setpgid (pid_t pid, pid_t pgid, ...)
{
	int sys_ret; 
	FETCH (pgid); 

	sys_ret = setpgdi (pid, pgid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setpgid"); 
	}

	return (sys_ret); 
}

pid_t x_getpgid (pid_t pid, ...)
{
	pid_t sys_ret; 
	FETCH (pid); 

	sys_ret = getpgid (pid); 

	if ((int)sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getpgid"); 
	}

	return (sys_ret); 
}

pid_t x_getsid (pid_t pid, ...)
{
	pid_t sys_ret; 
	FETCH (pid); 

	sys_ret = getsid (pid); 

	if ((int)sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getsid"); 
	}

	return (sys_ret); 
}

pid_t x_setsid (int error_response, ...)
{
	pid_t sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = setsid (); 

	if ((int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setsid"); 
	}

	return (sys_ret); 
}

int x_getpriority (int which, int who, ...) 
{
	int sys_ret; 
	FETCH (who); 

	sys_ret = getpriority (which, who); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getpriority"); 
	}

	return (sys_ret); 
}

int x_setpriority (int which, int who, int prio, ...)
{
	int sys_ret; 
	FETCH (prio); 

	sys_ret = setpriority (which, who, prio); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setpriority"); 
	}

	return (sys_ret); 
}

int x_sched_yield (int error_response, ...)
{
	int sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = sched_yield (); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_yield"); 
	}

	return (sys_ret); 
}

int x_sched_setparam (pid_t pid, const struct sched_param *param, ...) 
{
	int sys_ret; 
	FETCH (param); 

	sys_ret = sched_setparam (pid, param); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_setparam"); 
	}

	return (sys_ret); 
}

int x_sched_getparam (pid_t pid, struct sched_param *param, ...)
{
	int sys_ret; 
	FETCH (param); 

	sys_ret = sched_getparam (pid, param); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_getparam"); 
	}

	return (sys_ret); 
}

int x_sched_get_priority_max (int policy, ...)
{
	int sys_ret; 
	FETCH (policy); 

	sys_ret = sched_get_priority_max (policy); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_get_priority_max"); 
	}

	return (sys_ret); 
}

int x_sched_get_priority_min (int policy, ...)
{
	int sys_ret; 
	FETCH (policy); 

	sys_ret = sched_get_priority_min (policy); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_get_priority_min"); 
	}
	
	return (sys_ret); 
}

int x_sched_setaffinity (pid_t pid, size_t cpusetsize, cpu_set_t *mask, ...)
{
	int sys_ret; 
	FETCH (mask); 

	sys_ret = sched_setaffinity (pid, cpusetsize, mask); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_setaffinity"); 
	}

	return (sys_ret); 
}

int x_sched_getaffinity (pid_t pid, size_t cpusetsize, cpu_set_t *mask, ...)
{
	int sys_ret; 
	FETCH (mask); 

	sys_ret = sched_getaffinity (pid, cpusetsize, mask); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_getaffinity"); 
	}

	return (sys_ret); 
}

int x_sched_rr_get_interval (pid_t pid, struct timespec *tp, ...)
{
	int sys_ret; 
	FETCH (tp); 

	sys_ret = sched_rr_get_interval (pid, tp); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_rr_get_interval"); 
	}

	return (sys_ret); 
}

int x_sched_setscheduler(pid_t pid, int policy, const struct sched_param *param, ...)
{
	int sys_ret; 
	FETCH (param); 

	sys_ret = sched_setschedular (pid, policy, param); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_setschedular"); 
	}

	return (sys_ret); 
}

int x_sched_getscheduler(pid_t pid, ...)
{
	int sys_ret; 
	FETCH (pid); 

	sys_ret = sched_getschedular (pid); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sched_getschedular"); 
	}

	return (sys_ret); 
}

int x_getrusage (int who, struct rusage *usage, ...)
{
	int sys_ret; 
	FETCH (usage); 

	sys_ret = getrusage (who, usage); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getrusage"); 
	}

	return (sys_ret); 
}

int x_getrlimit (int resource, struct rlimit *rlimit, ...)
{
	int sys_ret; 
	FETCH (rlimit); 

	sys_ret = getrlimit (resource, rlimit); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getrlimit"); 
	}

	return (sys_ret); 
}

int x_setrlimit (int resource, const struct rlimit *rlimit, ...)
{
	int sys_ret; 
	FETCH (rlimit); 

	sys_ret = setrlimit (resource, rlimit); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("setrlimit"); 
	}

	return (sys_ret); 
}

int x_prlimit (pid_t pid, int resource, const struct rlimit *new_limit, 
		struct rlimit *old_limit, ...)
{
	int sys_ret; 
	FETCH (old_limit); 

	sys_ret = prlimit (pid, resource, new_limit, old_limit); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("prlimit"); 
	}

	return (sys_ret); 
}

int x_pipe (int pipefd[2], ...)
{
	int sys_ret; 
	FETCH (pipefd); 

	sys_ret = pipe (pipefd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pipe"); 
	}

	return (sys_ret); 
}

int x_pipe2 (int pipefd[2], int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = pipe2 (pipefd, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pipe2"); 
	}

	return (sys_ret); 
}

int x_msgget (key_t key, int msg_flag, ...)
{
	int sys_ret; 
	FETCH (msg_flag); 

	sys_ret = msgget (key, msg_flag); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("msgget"); 
	}

	return (sys_ret); 
}

int x_msgsnd (int msgq_id, const void *msg_p, size_t msg_sz, int msg_flag, ...)
{
	int sys_ret; 
	FETCH (msg_flag); 

	sys_ret = msgsnd (msgq_id, msg_p, msg_sz, msg_flag);

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("msgsnd"); 
	}

	return (sys_ret); 
}

int x_msgrcv (int msq_id, void *msg_p, size_t msg_sz, long msg_type, int msg_flag, ...)
{
	int sys_ret; 
	FETCH (msg_flag); 

	sys_ret = msgrcv (msq_id, msg_p, msg_sz, msg_type, msg_flag); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("msgrcv"); 
	}

	return (sys_ret); 
}

int x_msgctl (int msq_id, int cmd, struct msqid_ds *buffer, ...)
{
	int sys_ret; 
	FETCH (buffer); 

	sys_ret = msgctl (msq_id, cmd, buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("msgctl"); 
	}

	return (sys_ret); 
}

int x_semget (key_t key, int nr_sems, int sem_flag, ...)
{
	int sys_ret; 
	FETCH (sem_flag); 

	sys_ret = semget (key, nr_sems, sem_flag); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("semget"); 
	}

	return (sys_ret); 
}

int x_semctl (int sem_id, int sem_num, int cmd, ...)
{
	int sys_ret; 
	FETCH (cmd); 

	sys_ret = semctl (sem_id, sem_num, cmd); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("semctl"); 
	}

	return (sys_ret); 
}

int x_semop (int sem_id, struct sembuf *sops, unsigned int nsops, ...)
{
	int sys_ret; 
	FETCH (nsops); 

	sys_ret = semop (sem_id, sops, nsops); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("semop"); 
	}

	return (sys_ret); 
}

int x_semtimedop (int sem_id, struct sembuf *sops, unsigned int nsops, 
		  struct timespec *timeout, ...)
{
	int sys_ret; 
	FETCH (timeout); 

	sys_ret = semtimedop (sem_id, sops, nsops, timeout); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("semtimedop"); 
	}

	return (sys_ret); 
}

int x_shmget (key_t key, size_t size, int shm_flag, ...)
{
	int sys_ret; 
	FETCH (shm_flag); 

	sys_ret = shmget (key, size, shm_flag); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("shmget"); 
	}

	return (sys_ret); 
}

void *x_shmat (int shm_id, const void *shm_addr, int shm_flag, ...)
{
	void *sys_ret; 
	FETCH (shm_flag); 

	sys_ret = shmat (shm_id, shm_addr, shm_flag); 

	if (sys_ret == NULL) 
	{
		HANDLE_SYS_ERROR ("shmat"); 
	}

	return (sys_ret); 
}

int x_shmdt (const void *shm_addr, ...)
{
	int sys_ret; 
	FETCH (shm_addr); 

	sys_ret = shmdt (shm_addr); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("shmdt"); 
	}

	return (sys_ret); 
}

int x_shmctl (int shm_id, int cmd, struct shmid_ds *buffer, ...)
{
	int sys_ret; 
	FETCH (buffer); 

	sys_ret = shmctl (shm_id, cmd, buffer); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("shmctl"); 
	}

	return (sys_ret); 
}

void *x_mmap (void *addr, size_t length, int prot, int flags, int fd, off_t offset, ...)
{
	void *sys_ret; 
	FETCH (offset); 

	sys_ret = mmap (addr, length, prot, flags, fd, offset); 

	if (sys_ret == NULL) 
	{
		HANDLE_SYS_ERROR ("mmap"); 
	}

	return (sys_ret); 
}

int x_munmap (void *addr, size_t length, ...)
{
	int sys_ret; 
	FETCH (length); 

	sys_ret = munmap (addr, length); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("munmap"); 
	}

	return (sys_ret); 
}

int x_msync (void *addr, size_t length, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = msync (addr, length, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("msync"); 
	}

	return (sys_ret); 
}

int x_mremap (void *old_address, size_t old_size, ...)
{

}

int x_remap_file_pages (void *addr, size_t size, int prot, ssize_t pg_off, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = remap_file_pages (addr, size, prot, pg_off, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("remap_file_pages"); 
	}

	return (sys_ret); 
}

int x_mprotect (void *addr, size_t len, int prot, ...)
{
	int sys_ret; 
	FETCH (prot); 

	sys_ret = mprotect (addr, len, prot); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mprotect"); 
	}

	return (sys_ret); 
}

int x_mlock (const void *addr, size_t len, ...)
{
	int sys_ret; 
	FETCH (len); 

	sys_ret = mlock (addr, len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mlock"); 
	}

	return (sys_ret); 
}

int x_munlock (const void *addr, size_t len, ...)
{
	int sys_ret; 
	FETCH (len); 

	sys_ret = munlock (addr, len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("munlock"); 
	}

	return (sys_ret); 
}

int x_mlockall (int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = mlockall (flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mlockall"); 
	}

	return (sys_ret); 
}

int x_munlockall (int error_response, ...)
{
	int sys_ret; 
#ifdef DEBUG 
	char *src_file_name; 
	int src_nr_line; 
	va_list ap; 
	va_start (ap, error_response); 
	src_file_name = va_arg (ap, char*); 
	src_nr_line = va_arg (ap, int); 
	va_end (ap); 
#endif 

	sys_ret = munlockall (); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("munlockall"); 
	}

	return (sys_ret); 
}

int x_mincore (void *addr, size_t length, unsigned char *vec, ...)
{
	int sys_ret; 
	FETCH (vec); 

	sys_ret = mincore (addr, length, vec); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mincore"); 
	}

	return (sys_ret); 
}

int x_madvise (void *addr, size_t length, int advice, ...)
{
	int sys_ret; 
	FETCH (advice); 

	sys_ret = madvise (addr, length, advice); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("madvise"); 
	}

	return (sys_ret); 
}

mqd_t x_mq_open (const char *name, int oflag, mode_t mode, struct mq_attr *attr, ...) 
{
	mqd_t sys_ret; 
	FETCH (attr); 

	sys_ret = mq_open (name, oflag, mode, attr); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mq_open"); 
	}

	return (sys_ret); 
}

int x_mq_close (mqd_t mqdes, ...)
{
	int sys_ret; 
	FETCH (mqdes); 

	sys_ret = mq_close (mqdes); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mq_close"); 
	}

	return (sys_ret); 
}

int x_mq_unlink (const char *name, ...)
{
	int sys_ret; 
	FETCH (name); 

	sys_ret = mq_unlink (name); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("mq_unlink"); 
	}

	return (sys_ret); 
}



int x_flock (int fd, int operation, ...)
{
	int sys_ret;
	FETCH (operation); 

	sys_ret = flock (fd, operation); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("flock"); 
	}

	return (sys_ret); 
}

int x_socket (int domain, int type, int protocol, ...)
{
	int sys_ret; 
	FETCH (protocol); 

	sys_ret = socket (domain, type, protocol); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("socket"); 
	}

	return (sys_ret); 
}

int x_bind (int sock_fd, const struct sockaddr *addr, socklen_t addr_len, ...)
{
	int sys_ret; 
	FETCH (addr_len); 

	sys_ret = bind (sock_fd, addr, addr_len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("bind"); 
	}

	return (sys_ret); 
}

int x_listen (int sock_fd, int backlog, ...)
{
	int sys_ret; 
	FETCH (backlog); 

	sys_ret = listen (sock_fd, backlog); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("listen"); 
	}

	return (sys_ret); 
}

int x_accept (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...)
{
	int sys_ret; 
	FETCH (addr_len); 

	sys_ret = accept (sock_fd, addr, addr_len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("accept"); 
	}

	return (sys_ret); 
}

int x_accept4 (int sock_fd, struct sockaddr *addr, socklen_t addr_len, int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = accept4 (sock_fd, addr, addr_len, flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("accept4"); 
	}

	return (sys_ret); 
}

int x_connect (int sock_fd, const struct sockaddr *addr, socklen_t addr_len, ...)
{
	int sys_ret; 
	FETCH (addr_len); 

	sys_ret = connect (sock_fd, addr, addr_len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("connect"); 
	}

	return (sys_ret); 
}

ssize_t x_recv (int sock_fd, void *buffer, size_t len, int flags, ...)
{
	ssize_t sys_ret; 
	FETCH (flags); 

	sys_ret = recv (sock_fd, buffer, len, flags); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("recv"); 
	}

	return (sys_ret); 
}

ssize_t x_recfrom (int sock_fd, void *buffer, size_t len, int flags, struct sockaddr *src_addr, 
		  socklen_t *addr_len, ...)
{
	ssize_t sys_ret; 
	FETCH (addr_len); 

	sys_ret = recfrom (sock_fd, buffer, len, flags, src_addr, addr_len); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("recfrom"); 
	}

	return (sys_ret); 
}

ssize_t x_recvmsg (int sock_fd, struct msghdr *msg, int flags, ...)
{
	ssize_t sys_ret; 
	FETCH (flags); 

	sys_ret = recvmsg (sock_fd, msg, flags); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("recvmsg"); 
	}

	return (sys_ret); 
}

ssize_t x_send (int sock_fd, void *buffer, size_t len, int flags, ...)
{
	ssize_t sys_ret; 
	FETCH (flags); 

	sys_ret = send (sock_fd, buffer, len, flags); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("send"); 
	}

	return (sys_ret); 
}

ssize_t x_sendto (int sock_fd, const void *buffer, size_t len, int flags, 
		  const struct sockaddr *dest_addr, socklen_t addr_len, ...)
{
	ssize_t sys_ret; 
	FETCH (addr_len); 

	sys_ret = sendto (sock_fd, buffer, len, flags, dest_addr, addr_len); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sendto"); 
	}

	return (sys_ret); 
}

ssize_t x_sendmsg (int sock_fd, const struct msghdr *msg, int flags, ...)
{
	ssize_t sys_ret; 
	FETCH (flags); 

	sys_ret = sendmsg (sock_fd, msg, flags); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sendmsg"); 
	}

	return (sys_ret); 
}

int x_socketpair (int domain, int type, int protocol, int sv[2], ...)
{
	int sys_ret; 
	FETCH (sv); 

	sys_ret = socketpair (domain, type, protocol, sv); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("socketpair"); 
	}

	return (sys_ret); 
}

int x_getsockname (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...)
{
	int sys_ret; 
	FETCH (addr_len); 

	sys_ret = getsockname (sock_fd, addr, addr_len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getsockname"); 
	}

	return (sys_ret); 
}

int x_getpeername (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...)
{
	int sys_ret; 
	FETCH (addr_len); 

	sys_ret = getpeername (sock_fd, addr, addr_len); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("getpeername"); 
	}

	return (sys_ret); 
}

int x_shutdown (int sock_fd, int how, ...)
{
	int sys_ret; 
	FETCH (how); 

	sys_ret = shutdown (sock_fd, how); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("shutdown"); 
	}

	return (sys_ret); 
}

ssize_t	x_sendfile (int out_fd, int in_fd, off_t *offset, size_t count, ...)
{
	ssize_t sys_ret; 
	FETCH (count); 

	sys_ret = sendfile (out_fd, in_fd, offset, count); 

	if ((long int) sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("sendfile"); 
	}

	return (sys_ret); 
}

int x_select (int nr_fds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds, 
	      struct timeval *timeout, ...)
{
	int sys_ret; 
	FETCH (timeout); 

	sys_ret = select (nr_fds, read_fds, write_fds, except_fds, timeout); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("select"); 
	}

	return (sys_ret); 
}

int x_pselect (int nr_fds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds, 
	       const struct timespec *timeout, const sigset_t *sigmask, ...)
{
	int sys_ret; 
	FETCH (sigmask); 

	sys_ret = pselect (nr_fds, read_fds, write_fds, except_fds, timeout, sigmask); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("pselect"); 
	}

	return (sys_ret); 
}

int x_poll (struct pollfd *fds, nfds_t nfds, int timeout, ...)
{
	int sys_ret; 
	FETCH (timeout); 

	sys_ret = poll (fds, nfds, timeout); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("poll"); 
	}

	return (sys_ret); 
}

int x_epoll_create (int size, ...)
{
	int sys_ret; 
	FETCH (size); 
	
	sys_ret = epoll_create (size); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("epoll_create"); 
	}

	return (sys_ret); 
}

int x_epoll_create1 (int flags, ...)
{
	int sys_ret; 
	FETCH (flags); 

	sys_ret = epoll_create1 (flags); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("epoll_create1"); 
	}

	return (sys_ret); 
}

int x_epoll_ctl (int ep_fd, int op, int fd, struct epoll_event *event, ...)
{
	int sys_ret; 
	FETCH (event); 

	sys_ret = epoll_ctl (ep_fd, op, fd, event); 

	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("epoll_ctl"); 
	}

	return (sys_ret); 
}

int x_epoll_wait (int ep_fd, struct epoll_event *events, int max_events, int timeout, ...)
{
	int sys_ret; 
	FETCH (timeout); 

	sys_ret = epoll_wait (ep_fd, events, max_events, timeout); 
	
	if (sys_ret == -1) 
	{
		HANDLE_SYS_ERROR ("epoll_wait"); 
	}

	return (sys_ret); 
}

