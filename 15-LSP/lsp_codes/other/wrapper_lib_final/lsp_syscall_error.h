#ifndef _LSP_SYSCALL_ERROR_H 
#define _LSP_SYSCALL_ERROR_H 

#include "lsp_common.h" 

 /* Low level file handling system call wrappers */
int 	x_open (const char *path_name, int flags, ...); 
ssize_t x_read  (int fd, void *buffer, size_t size, const char *f_name, ...);
ssize_t x_write (int fd, void *buffer, size_t size, const char *f_name, ...);
off_t   x_lseek (int fd, off_t offset, int whence, const char *f_name, ...); 
int     x_close (int fd, const char *f_name, ...); 
void 	x_close2 (int nr_fds, ...); 
int 	x_dup   (int fd, const char *f_name, ...); 
int 	x_dup2  (int old_fd, int new_fd, const char *f_name, ...); 
int 	x_dup3  (int old_fd, int new_fd, int flag, const char *f_name, ...); 
ssize_t x_pread (int fd, void *buffer, size_t size, off_t offset, const char *f_name, ...); 
ssize_t x_pwrite (int fd, void *buffer, size_t size, off_t offset, const char *f_name, ...); 
ssize_t x_readv (int fd, const struct iovec *iov, int iovcnt, const char *f_name, ...); 
ssize_t x_writev (int fd, const struct iovec *iov, int iovcnt, const char *f_name, ...); 
ssize_t x_preadv (int fd, const struct iovec *iov, int iovcnt, off_t offset, const char *f_name,...); 
ssize_t x_pwritev (int fd, const struct iovec *iov, int iovcnt, off_t offset, 
		   const char *f_name, ...); 
int 	x_truncate (const char *path_name, off_t length, ...); 
int 	x_ftruncate (int fd, off_t length, const char *f_name, ...); 
inline 	pid_t 	xi_getpid (void); 
inline  pid_t 	xi_getppid (void); 
inline	uid_t 	xi_getuid (void); 
inline	gid_t 	xi_getgid (void); 
inline	uid_t 	xi_geteuid (void); 
inline	gid_t 	xi_getegid (void); 
int 	x_getresuid (uid_t *p_ruid, uid_t *p_euid, uid_t *p_suid, ...); 
int	x_getresgid (gid_t *p_rgid, gid_t *p_egid, gid_t *p_sgid, ...); 
int	x_setuid (uid_t uid, ...); 
int 	x_setgid (gid_t gid, ...); 
int 	x_setreuid (uid_t ruid, uid_t euid, ...); 
int	x_setregid (gid_t rgid, gid_t egid, ...); 
int 	x_setresuid (uid_t ruid, uid_t euid, uid_t suid, ...); 
int 	x_setresgid (gid_t rgid, gid_t egid, gid_t sgid, ...); 
int 	x_getgroups (int size, gid_t list[], ...); 
int	x_setgroups (int size, const gid_t *list, ...); 
int 	x_gettimeofday (struct timeval *tv, struct timezone *tz, ...); 
int	x_settimeofday (const struct timeval *tv, const struct timezone *tz, ...); 
time_t  x_time (time_t *timep, ...); 
long    x_sysconf (int name, ...); 
long    x_pathconf (const char *path_name, int name, ...); 
long 	x_fpathconf (int fd, int name, char *f_name, ...);  
int 	x_uname (struct utsname *uts_buffer, ...); 
int	x_fsync (int fd, const char *f_name, ...); 
int 	x_fdatasync (int fd, const char *f_name, ...); 
inline 	void xi_sync (void); 
int     x_mount (const char *source, const char *target, const char *fs_type, 
		 unsigned long flags, void *data, ...);
int 	x_umount (const char *target, ...);
int 	x_umount2 (const char *target, int flags, ...); 
int 	x_statvfs (const char *path_name, struct statvfs *statvfs_buffer, ...); 
int 	x_fstatvfs (int fd, struct statvfs *statvfs_buffer, const char *f_name, ...); 
int 	x_stat (const char *path_name, struct stat *stat_buffer, ...); 
int 	x_lstat (const char *path_name, struct stat *stat_buffer, ...); 
int 	x_fstat (int fd, struct stat *stat_buffer, const char *f_name, ...); 
int 	x_utime (const char *path_name, const struct utimbuf *buffer, ...); 
int	x_utimes (const char *path_name, const struct timeval tv[2], ...); 
int 	x_lutimes (const char *path_name, const struct timeval tv[2], ...); 
int	x_futimes (int fd, const struct timeval tv[2], const char *f_name, ...); 
int	x_utimensat (int dir_fd, const char *f_name, const struct timespec times[2], 
		     int flags, ...); 
int 	x_futimens (int fd, const struct timespec times[2], const char *f_name, ...); 
int 	x_chown (const char *f_name, uid_t owner, gid_t group, ...); 
int	x_lchown (const char *f_name, uid_t owner, gid_t group, ...); 
int	x_fchown (int fd, uid_t owner, gid_t group, const char *f_name, ...); 
int	xaccess (const char *path_name, mode_t mode, ...); 
inline  mode_t  xi_umask (mode_t mask); 
int	x_chmod (const char *path_name, mode_t mode, ...); 
int	x_fchmod (int fd, mode_t mode, const char *f_name, ...); 
int 	x_setxattr (const char *path_name, const char *name, const void *value, 
		    size_t size, int flags, ...); 
int 	x_lsetxattr (const char *path_name, const char *name, const void *value, 
		     size_t size, int flags, ...); 
int 	x_fsetxattr (int fd, const char *name, const void *value, size_t size, int flags, 
		     const char *f_name, ...); 
int 	x_getxattr (const char *path_name, const char *name, void *value, size_t size, ...); 
int 	x_lgetxattr (const char *path_name, const char *name, void *value, size_t size, ...); 
int 	x_fgetxattr (int fd, const char *name, void *value, size_t size, const char *f_name, ...);
int	x_removexattr (const char *path_name, const char *name, ...); 
int 	x_lremovexattr (const char *path_name, const char *name, ...); 
int	x_fremovexattr (int fd, const char *name, const char *f_name, ...); 
ssize_t x_listxattr (const char *path_name, char *list, size_t size, ...); 
ssize_t x_llistxattr (const char *path_name, char *list, size_t size, ...); 
ssize_t x_flistxattr (int fd,  char *list, size_t size, const char *f_name, ...); 
int 	x_link (const char *old_path, const char *new_path, ...); 
int 	x_unlink (const char *path_name, ...); 
int 	x_rename (const char *old_path, const char *new_path, ...); 
int	x_symlink (const char *old_path, const char *new_path, ...); 
ssize_t x_readlink (const char *path_name, char *buffer, size_t size, ...); 
int	x_mkdir (const char *path_name, mode_t mode, ...); 
int	x_rmdir (const char *path_name, ...); 
int	x_remove (const char *path_name, ...); 
char 	*x_getcwd (char *buffer, size_t size, ...); 
int	x_chdir (const char *path_name, ...); 
int 	x_fchdir (int fd, const char *f_name, ...); 
int 	x_chroot (const char *path_name, ...); 
int 	x_openat (int dir_fd, const char *path_name, int flags, ...); 
int	x_faccessat (int dir_fd, const char *path_name, int mode, int flags, ...); 
int 	x_fchmodat (int dir_fd, const char *path_name, mode_t mode, int flags, ...); 
int 	x_fchownat (int dir_fd, const char *path_name, uid_t owner, gid_t group, int flags, ...); 
int 	x_fstatat (int dir_fd, const char *path_name, struct stat *stat_buffer, int flags, ...); 
int 	x_linkat (int old_dir_fd, const char *old_path, int new_dir_fd, 
		  const char *new_path, int flags, ...); 
int 	x_mkdirat (int dir_fd, const char *path_name, mode_t mode, ...); 
int	x_mknodat (int dir_fd, const char *path_name, mode_t mode, dev_t dev, ...); 
int 	x_readlinkat (int dir_fd, const char *path_name, char *buffer, size_t buffer_size, ...); 
int 	x_renameat (int old_dir_fd, const char *old_path, int new_dir_fd, 
		    const char *new_path, ...); 
int 	x_symlinkat (const char *old_path, int new_dir_fd, const char *new_path, ...); 
int 	x_unlinkat (int dir_fd, const char *path_name, int flags, ...); 
int 	x_mkfifoat (int dir_fd, const char *path_name, mode_t mode, ...); 
int	x_inotify_init (int error_respone, ...); 
int	x_inotify_init1 (int flags, ...); 
int 	x_inotify_add_watch (int fd, const char *path_name, uint32_t mask, ...); 
int 	x_inotify_rm_watch (int fd, uint32_t wd, const char *f_name, ...); 
void	(*x_signal (int signal_num, void (*signal_desposition) (int), ...))(int); 
int 	x_kill (pid_t pid, int signal_number, ...); 
int	x_killpg (int nr_process_group, int signal_number, ...); 
int	x_pause (int error_respone, ...); 
int	x_sigaction (int signal_number, const struct sigaction *action, 
		     struct sigaction *old_action, ...); 
int 	x_signalfd (int fd, const sigset_t *mask, int flags, ...); 
int	x_sigpending (sigset_t *set, ...); 
int	x_sigprocmask (int how, const sigset_t *new_set, sigset_t *old_set, ...); 
int	x_signsuspend (const sigset_t *mask, ...); 
int	x_sigwaitinfo (const sigset_t *set, siginfo_t *info, ...); 
int	x_sigtimedwait (const sigset_t *set, siginfo_t *info, const struct timespec *timeout, ...); 
int 	x_rt_sigqueueinfo(pid_t tgid, int sig, siginfo_t *uinfo, ...);
int 	x_rt_tgsigqueueinfo(pid_t tgid, pid_t tid, int sig, siginfo_t *uinfo, ...);
int	x_getitimer (int which, struct itimerval *curr_value, ...); 
int	x_setitimer (int which, const struct itimerval *new_value, 
		     struct itimerval *old_value, ...); 
inline	unsigned int xi_alarm (unsigned int seconds);
int	x_nanosleep (const struct timespec *req, struct timespec *remaining, ...);
int	x_clock_getres (clockid_t clk_id, struct timespec *res, ...); 
int	x_clock_gettime (clockid_t clk_id, struct timespec *tp, ...); 
int	x_clock_settime (clockid_t clk_id, const struct timespec *tp, ...);
int	x_clock_nanosleep (clockid_t clock_id, int flags, const struct timespec *request, 
		           struct timespec *remaining, ...); 
int	x_timer_create (clockid_t clockid, struct sigevent *sevp, timer_t *timerid, ...); 
int	x_timer_settime (timer_t timerid, int flags, const struct itimerspec *new_value, 
		         struct itimerspec *old_value, ... ); 
int	x_timer_gettime (timer_t timerid, struct itimerspec *current_value, ...); 
int	x_timer_getoverrun (timer_t timerid, ...); 
int	x_timer_delete (timer_t timerid, ...);
int	x_timerfd_create (int clockid, int flags, ...); 
int	x_timerfd_settime (int fd, int flags, const struct itimerspec *new_value, 
		           struct itimerspec *old_value, ...);
int	x_timerfd_gettime (int fd, struct itimerspec *current_value, ...);
int	x_fork (int error_response, ...);  
int	x_vfork (int error_response, ...);
inline	void xi__exit (int exit_status); 
pid_t	x_wait (int *status, ...); 
int	x_waitid (idtype_t idtype, id_t id, siginfo_t *infop, int options, ...);
int	x_execve (const char *path_name, char *const argv[], char *const envp[], ...);
int	x_acct (const char *file_name, ...); 
int	x_clone (unsigned long flags, void *child_stack, void *ptid, void *ctid, 
		 struct pt_regs *regs, ...);
int	x_getpgrp (int error_response, ...); 
int	x_setpgid (pid_t pid, pid_t pgid, ...); 
pid_t	x_getpgid (pid_t pid, ...);
pid_t	x_getsid (pid_t pid, ...);
pid_t	x_setsid (int error_response, ...);
int	x_getpriority (int which, int who, ...); 
int	x_setpriority (int which, int who, int prio, ...); 
int	x_sched_yield (int error_response, ...); 
int	x_sched_setparam (pid_t pid, const struct sched_param *param, ...); 
int	x_sched_getparam (pid_t pid, struct sched_param *param, ...);
int	x_sched_get_priority_max (int policy, ...); 
int	x_sched_get_priority_min (int policy, ...);
int	x_sched_setaffinity (pid_t pid, size_t cpusetsize, cpu_set_t *mask, ...);
int	x_sched_getaffinity (pid_t pid, size_t cpusetsize, cpu_set_t *mask, ...);
int	x_sched_rr_get_interval (pid_t pid, struct timespec *tp, ...);
int 	x_sched_setscheduler(pid_t pid, int policy, const struct sched_param *param, ...);
int 	x_sched_getscheduler(pid_t pid, ...);
int	x_getrusage (int who, struct rusage *usage, ...); 
int	x_getrlimit (int resource, struct rlimit *rlimit, ...); 
int	x_setrlimit (int resource, const struct rlimit *rlimit, ...); 
int	x_prlimit (pid_t pid, int resource, const struct rlimit *new_limit, 
		   struct rlimit *old_limit, ...);
int	x_pipe (int pipefd[2], ...); 
int	x_pipe2 (int pipefd[2], int flags, ...);
int	x_msgget (key_t key, int msg_flag, ...);
int	x_msgsnd (int msgq_id, const void *msg_p, size_t msg_sz, int msg_flag, ...); 
int	x_msgrcv (int msq_id, void *msg_p, size_t msg_sz, long msg_type, int msg_flag, ...); 
int	x_msgctl (int msq_id, int cmd, struct msqid_ds *buffer, ...); 
int	x_semget (key_t key, int nr_sems, int sem_flag, ...); 
int	x_semctl (int sem_id, int sem_num, int cmd, ...);
int	x_semop (int sem_id, struct sembuf *sops, unsigned int nsops, ...); 
int	x_semtimedop (int sem_id, struct sembuf *sops, unsigned int nsops, 
		      struct timespec *timeout, ...); 
int	x_shmget (key_t key, size_t size, int shm_flag, ...); 
void	*x_shmat (int shm_id, const void *shm_addr, int shm_flag, ...); 
int	x_shmdt (const void *shm_addr, ...); 
int	x_shmctl (int shm_id, int cmd, struct shmid_ds *buffer, ...); 
void	*x_mmap (void *addr, size_t length, int prot, int flags, int fd, off_t offset, ...); 
int	x_munmap (void *addr, size_t length, ...);
int	x_msync (void *addr, size_t length, int flags, ...); 
int 	x_mremap (void *old_address, size_t old_size, ...);  
int	x_remap_file_pages (void *addr, size_t size, int prot, ssize_t pg_off, int flags, ...); 
int	x_mprotect (void *addr, size_t len, int prot, ...); 
int	x_mlock (const void *addr, size_t len, ...); 
int	x_munlock (const void *addr, size_t len, ...); 
int	x_mlockall (int flags, ...); 
int	x_munlockall (int error_response, ...); 
int	x_mincore (void *addr, size_t length, unsigned char *vec, ...); 
int	x_madvise (void *addr, size_t length, int advice, ...); 
mqd_t 	x_mq_open (const char *name, int oflag, mode_t mode, struct mq_attr *attr, ...); 
int	x_mq_close (mqd_t mqdes, ...); 
int	x_mq_unlink (const char *name, ...); 
int	x_flock (int fd, int operation, ...); 
int	x_socket (int domain, int type, int protocol, ...); 
int	x_bind (int sock_fd, const struct sockaddr *addr, socklen_t addr_len, ...); 
int	x_listen (int sock_fd, int backlog, ...); 
int	x_accept (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...); 
int	x_accept4 (int sock_fd, struct sockaddr *addr, socklen_t addr_len, int flags, ...); 
int	x_connect (int sock_fd, const struct sockaddr *addr, socklen_t addr_len, ...); 
ssize_t x_recv (int sock_fd, void *buffer, size_t len, int flags, ...); 
ssize_t x_recfrom (int sock_fd, void *buffer, size_t len, int flags, 
		   struct sockaddr *src_addr, socklen_t *addr_len, ...); 
ssize_t x_recvmsg (int sock_fd, struct msghdr *msg, int flags, ...); 
ssize_t x_send (int sock_fd, void *buffer, size_t len, int flags, ...); 
ssize_t x_sendto (int sock_fd, const void *buffer, size_t len, int flags, 
		  const struct sockaddr *dest_addr, socklen_t addr_len, ...); 
ssize_t x_sendmsg (int sock_fd, const struct msghdr *msg, int flags, ...); 
int	x_socketpair (int domain, int type, int protocol, int sv[2], ...); 
int	x_getsockname (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...); 
int	x_getpeername (int sock_fd, struct sockaddr *addr, socklen_t *addr_len, ...); 
int	x_shutdown (int sock_fd, int how, ...); 
ssize_t	x_sendfile (int out_fd, int in_fd, off_t *offset, size_t count, ...); 
int	x_select (int nr_fds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds, 
		  struct timeval *timeout, ...); 
int	x_pselect (int nr_fds, fd_set *read_fds, fd_set *write_fds, fd_set *except_fds, 
		   const struct timespec *timeout, const sigset_t *sigmask, ...); 
int	x_poll (struct pollfd *fds, nfds_t nfds, int timeout, ...); 
int	x_epoll_create (int size, ...); 
int	x_epoll_create1 (int flags, ...); 
int	x_epoll_ctl (int ep_fd, int op, int fd, struct epoll_event *event, ...); 
int	x_epoll_wait (int ep_fd, struct epoll_event *events, int max_events, int timeout, ...); 

#endif /* _LSP_SYSCALL_H */ 
