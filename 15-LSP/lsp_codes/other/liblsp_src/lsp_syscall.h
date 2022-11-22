#ifndef _LSP_SYSCALL_H 
#define _LSP_SYSCALL_H 

#include "lsp_common.h" 

 /* Low level file handling system call wrappers */
int 	xopen (int error_response, int is_o_creat, const char *path_name, int flags, ...); 

ssize_t xread  (int error_response, const char *f_name, int fd, 
	        void *buffer, size_t size, ...);
ssize_t xwrite (int error_response, const char *f_name, int fd, 
		void *buffer, size_t size, ...);

off_t   xlseek (int error_response, const char *f_name, int fd, 
		off_t offset, int whence, ...); 

int     xclose (int error_response, const char *f_name, int fd, ...); 
void 	xclose2 (int nr_fds, ...); 

int 	xdup   (int error_response, const char *f_name, int fd, ...); 
int 	xdup2  (int error_response, const char *f_name, int old_fd, int new_fd, ...); 
int 	xdup3  (int error_response, const char *f_name, int old_fd, int new_fd, 
		int flag, ...); 

ssize_t xpread (int error_response, const char *f_name, int fd, void *buffer, 
		size_t size, off_t offset, ...); 
ssize_t xpwrite (int error_response, const char *f_name, int fd, void *buffer, 
		 size_t size, off_t offset, ...); 
ssize_t xreadv (int error_response, const char *f_name, int fd, const struct iovec *iov, 
		int iovcnt, ...); 
ssize_t xwritev (int error_response, const char *f_name, int fd, const struct iovec *iov, 
		 int iovcnt, ...); 
ssize_t xpreadv (int error_response, const char *f_name, int fd, const struct iovec *iov, 
		 int iovcnt, off_t offset, ...); 
ssize_t xpwritev (int error_response, const char *f_name, int fd, const struct iovec *iov, 
		  int iovcnt, off_t offset, ...); 

int 	xtruncate (int error_response, const char *path_name, off_t length, ...); 
int 	xftruncate (int error_response, const char *f_name, int fd, off_t length, ...); 

pid_t 	xgetpid (void); 
pid_t 	xgetppid (void); 

uid_t 	xgetuid (void); 
gid_t 	xgetgid (void); 
uid_t 	xgeteuid (void); 
gid_t 	xgetegid (void); 

int 	xgetresuid (int error_response, uid_t *p_ruid, uid_t *p_euid, uid_t *p_suid, ...); 
int	xgetresgid (int error_response, gid_t *p_rgid, gid_t *p_egid, gid_t *p_sgid, ...); 

int	xsetuid (int error_response, uid_t uid, ...); 
int 	xsetgid (int error_response, gid_t gid, ...); 
int 	xsetreuid (int error_response, uid_t ruid, uid_t euid, ...); 
int	xsetregid (int error_response, gid_t rgid, gid_t egid, ...); 
int 	xsetresuid (int error_response, uid_t ruid, uid_t euid, uid_t suid, ...); 
int 	xsetresgid (int error_response, gid_t rgid, gid_t egid, gid_t sgid, ...); 
int	xgetgroups (int error_response, size_t size, gid_t list[], ...); 
int	xsetgroups (int error_response, size_t size, const gid_t *list); 

int 	xgettimeofday (int error_response, struct timeval *tv, struct timezone *tz, ...); 
int	xsettimeofday (int error_response, const struct timeval *tv, const struct timezone *tz, ...); 
time_t  xtime (int error_response, time_t *timep, ...); 
int	xadjtimex (int error_response, struct timex *buffer, ...);  

long    xsysconf (int error_response, int name, ...); 
long    xpathconf (int error_response, const char *path_name, int name, ...); 
long 	xfpathconf (int error_response, const char *path_name, int fd, int name, ...);  
int 	xuname (int error_response, struct utsname *uts_buffer, ...); 

int	xfsync (int error_response, const char *f_name, int fd, ...); 
int 	xfdatasync (int error_response, const char *f_name, int fd, ...); 
void 	xsync (void); 

int     xmount (int error_response, const char *source, const char *target, 
		const char *fs_type, unsigned long flags, void *data, ...);              
int 	xumount (int error_response, const char *target, ...);
int 	xumount2 (int error_response, const char *target, int flags, ...); 

int 	xstatvfs (int error_response, const char *path_name, struct statvfs *statvfs_buffer, ...); 
int 	xfstatvfs (int error_response, const char *path_name, int fd, struct statvfs *statvfs_buffer, ...); 

int 	xstat (int error_response, const char *path_name, struct stat *stat_buffer, ...); 
int 	xlstat (int error_response, const char *path_name, struct stat *stat_buffer, ...); 
int 	xfstat (int error_response, const char *path_name, int fd, struct stat *stat_buffer, ...); 

int 	xutime (int error_response, const char *path_name, const struct utimbuf *buffer, ...); 
int	xutimes (int error_response, const char *path_name, const struct timeval tv[2], ...); 
int 	xlutimes (int error_response, const char *path_name, const struct timeval tv[2], ...); 
int	xfutimes (int error_response, const char *path_name, int fd, const struct timeval tv[2], ...); 
int	xutimensat (int error_response, int dir_fd, const char *f_name, 
		    const struct timespec times[2], int flags, ...); 
int 	xfutimens (int error_response, const char *f_name, int fd, const struct timespec times[2], ...); 

int 	xchown (int error_response, const char *f_name, uid_t owner, gid_t group, ...); 
int	xlchown (int error_response, const char *f_name, uid_t owner, gid_t group, ...); 
int	xfchown (int error_response, const char *f_name, int fd, uid_t owner, gid_t group, ...); 
int	xaccess (int error_response, const char *path_name, mode_t mode, ...); 
mode_t  xumask (mode_t mask); 
int	xchmod (int error_response, const char *path_name, mode_t mode, ...); 
int	xfchmod (int error_response, const char *path_name, int fd, mode_t mode, ...); 

int 	xsetxattr (int error_response, const char *path_name, const char *name, const void *value, 
		   size_t size, int flags, ...); 
int 	xlsetxattr (int error_response, const char *path_name, const char *name, const void *value, 
		    size_t size, int flags, ...); 
int 	xfsetxattr (int error_response, const char *path_name, int fd, const char *name, 
		    const void *value, size_t size, int flags, ...); 

int 	xgetxattr (int error_response, const char *path_name, const char *name, 
		   void *value, size_t size, ...); 
int 	xlgetxattr (int error_response, const char *path_name, const char *name, 
		    void *value, size_t size, ...); 
int 	xfgetxattr (int error_response, const char *path_name, int fd, const char *name, 
		    void *value, size_t size, ...);

int	xremovexattr (int error_response, const char *path_name, const char *name, ...); 
int 	xlremovexattr (int error_response, const char *path_name, const char *name, ...); 
int	xfremovexattr (int error_response, const char *path_name, const char *name, ...); 

ssize_t xlistxattr (int error_response, const char *path_name, char *list, size_t size, ...); 
ssize_t xllistxattr (int error_response, const char *path_name, char *list, size_t size, ...); 
ssize_t xflistxattr (int error_response, const char *path_name, char *list, size_t size, ...); 

int 	xlink (int error_response, const char *old_path, const char *new_path, ...); 
int 	xunlink (int error_response, const char *path_name, ...); 
int 	xrename (int error_response, const char *old_path, const char *new_path, ...); 
int	xsymlink (int error_response, const char *old_path, const char *new_path, ...); 
ssize_t xreadlink (int error_response, const char *path_name, char *buffer, size_t size, ...); 
int	xmkdir (int error_response, const char *path_name, mode_t mode, ...); 
int	xrmdir (int error_response, const char *path_name, ...); 
int	xremove (int error_response, const char *path_name, ...); 
char 	*xgetcwd (int error_response, char *buffer, size_t size, ...); 
int	xchdir (int error_response, const char *path_name, ...); 
int 	xfchdir (int error_response, const char *path_name, int fd, ...); 
int 	xchroot (int error_response, const char *path_name, ...); 
int 	xopenat (int error_response, int is_o_create, int dir_fd, const char *path_name, int flags, ...); 
int	xfaccessat (int error_response, int dir_fd, const char *path_name, int mode, int flags, ...); 
int 	xfchmodat (int error_response, int dir_fd, const char *path_name, mode_t mode, int flags, ...); 
int 	xfchownat (int error_response, int dir_fd, const char *path_name, uid_t owner, gid_t group, 
		  int flags, ...); 
int 	xfstatat (int error_response, int dir_fd, const char *path_name, struct stat *stat_buffer, 
		  int flags, ...); 
int 	xlinkat (int error_response, int old_dir_fd, const char *old_path, int new_dir_fd, 
		 const char *new_path, int flags, ...); 
int 	xmkdirat (int error_response, int dir_fd, const char *path_name, mode_t mode, ...); 
int	xmknodat (int error_response, int dir_fd, const char *path_name, mode_t mode, dev_t dev, ...); 
int 	xreadlinkat (int error_response, int dir_fd, const char *path_name, 
		     char *buffer, size_t buffer_size, ...); 
int 	xrenameat (int error_response, int old_dir_fd, const char *old_path, int new_dir_fd, 
		   const char *new_path, ...); 
int 	xsymlinkat (int error_response, const char *old_path, int new_dir_fd, const char *new_path, ...); 
int 	xunlinkat (int error_response, int dir_fd, const char *path_name, int flags, ...); 
int 	xmkfifoat (int error_response, int dir_fd, const char *path_name, mode_t mode, ...); 
int	xinotify_init (int error_response, ...); 
int	xinotify_init1 (int error_response, int flags, ...); 
int 	xinotify_add_watch (int error_response, int fd, const char *path_name, uint32_t mask, ...); 
int 	xinotify_rm_watch (int error_response, const char *path_name, int fd, uint32_t wd, ...); 
#endif /* _LSP_SYSCALL_H */ 
