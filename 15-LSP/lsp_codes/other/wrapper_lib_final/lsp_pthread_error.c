#include "lsp_error.h"

int x_pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void*), void *arg, ...)
{
	int lib_ret; 
	FETCH (arg);


	lib_ret = pthread_create (thread, attr, start_routine, arg); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_create");
	}

	retrun (lib_ret);
}

inline void xi_pthread_exit (void *ret_val)
{
	pthread_exit (ret_val);
}

int	x_pthread_join (pthread_t thread, void **ret_val, ...)
{
	int lib_ret; 
	FETCH (ret_val); 

	lib_ret = pthread_join (thread, ret_val); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_join");
	}

	retrun (lib_ret);
}

int	x_pthread_tryjoin_np (pthread_t thread, void **ret_val, ...)
{
	int lib_ret; 
	FETCH (ret_val); 

	lib_ret = pthread_tryjoin_np (thread, ret_val); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_tryjoin_np");
	}

	return (lib_ret);
}

int	x_pthread_timedjoin_np (pthread_t thread, void **ret_val, const struct timespec *abs_time, ...)
{
	int lib_ret; 
	FETCH (abs_time);

	lib_ret = pthread_timedjoin_np (thread, ret_val, abs_time);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_timedjoin_np");
	}

	return (lib_ret);
}

int	x_pthread_detach (pthread_t thread, ...)
{
	int lib_ret; 
	FETCH (thread);

	lib_ret = pthread_detach (thread);

	if (lib_ret != 0)
	{
		lib_ret = errno;
		HANDLE_LIB_ERROR1 ("pthread_detach");
	}

	return (lib_ret);
}

inline pthread_t xi_pthread_self (void)
{
	pthread_self ();
}

inline	int	xi_pthread_equal (pthread_t thread_one, pthread_t thread_two)
{
	pthread_equal (thread_one, thread_two);
}

int	x_pthread_attr_init (pthread_attr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_attr_init (attr); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_init");
	}

	return (lib_ret);
}

int x_pthread_attr_destroy (pthread_attr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_attr_destroy (attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_destroy");
	}

	return (lib_ret);
}

int x_pthread_attr_getdetachstate (pthread_attr_t *attr, int *detachstate, ...)
{
	int lib_ret; 
	FETCH (detachstate); 

	lib_ret = pthread_attr_getdetachstate (attr, detachstate);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getdetachstate");
	}

	return (lib_ret);
}

int x_pthread_attr_setdetachstate (pthread_attr_t *attr, int detachstate, ...)
{
	int lib_ret; 
	FETCH (detachstate); 

	lib_ret = pthread_attr_setdetachstate (attr, detachstate);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_attr_setdetachstate"); 
	}

	return (lib_ret);
}

int x_pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize, ...)
{
	int lib_ret; 
	FETCH (guardsize); 

	lib_ret = pthread_attr_setguardsize (attr, guardsize);
	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setguardsize");
	}

	return (lib_ret);
}

int x_pthread_attr_getguardsize(pthread_attr_t *attr, size_t *guardsize, ...)
{
	int lib_ret; 
	FETCH (guardsize);

	lib_ret = pthread_attr_getguardsize (attr, guardsize);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getguardsize");
	}

	return (lib_ret);
}

int x_pthread_attr_setschedparam (pthread_attr_t *attr, const struct sched_param *param, ...)
{
	int lib_ret; 
	FETCH (param); 

	lib_ret = pthread_attr_setschedparam (attr, param); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setschedparam");
	}

	return (lib_ret);
}

int x_pthread_attr_getschedparam (pthread_attr_t *attr, const struct sched_param *param, ...)
{
	int lib_ret; 
	FETCH (param);

	lib_ret = pthread_attr_getschedparam (attr, param);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_attr_getschedparam");
	}

	return (lib_ret);
}

int x_pthread_attr_getschedpolicy (pthread_attr_t *attr, int *policy, ...) 
{
	int lib_ret; 
	FETCH (policy);

	lib_ret = pthread_attr_getschedpolicy (attr, policy);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getschedpolicy");
	}

	return (lib_ret);
}

int x_pthread_attr_setschedpolicy (pthread_attr_t *attr, int policy, ...) 
{
	int lib_ret; 
	FETCH (policy);

	lib_ret = pthread_attr_setschedpolicy (attr, policy);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setschedpolicy");
	}

	return (lib_ret);
}

int x_pthread_attr_getinheritsched (pthread_attr_t *attr, int *inheritsched, ...)
{
	int lib_ret; 
	FETCH (inheritsched);

	lib_ret = pthread_attr_getinhertisched (attr, inheritsched);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getinhertisched");
	}

	return (lib_ret);
}

int x_pthread_attr_setinheritsched (pthread_attr_t *attr, int inheritsched, ...)
{
	int lib_ret;
	FETCH (inheritsched);

	lib_ret = pthread_attr_setinheritsched (attr, inheritsched);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_attr_setinheritsched");
	}

	return (lib_ret);
}

int x_pthread_attr_getscope (pthread_attr_t *attr, int *scope, ...)
{
	int lib_ret; 
	FETCH (scope); 

	lib_ret = pthread_attr_getscope (attr, scope);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getscope");
	}

	return (lib_ret);
}

int x_pthread_attr_setscope (pthread_attr_t *attr, int scope, ...)
{
	int lib_ret; 
	FETCH (scope);

	lib_ret = pthread_attr_setscope (attr, scope);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_attr_setscope");
	}

	return (lib_ret);
}

int x_pthread_attr_getstackaddr (pthread_attr_t *attr, void **address, ...)
{
	int lib_ret; 
	FETCH (address); 

	lib_ret = pthread_attr_getstackaddr (attr, address); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getstackaddr"); 
	}

	return (lib_ret);
}

int x_pthread_attr_setstackaddr (pthread_attr_t *attr, void *address, ...)
{
	int lib_ret; 
	FETCH (address); 

	lib_ret = pthread_attr_setstackaddr (attr, address);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setstackaddr");
	}

	return (lib_ret);
}

int x_pthread_attr_getstack (pthread_attr_t *attr, void *stack_address, size_t stack_size, ...)
{
	int lib_ret; 
	FETCH (stack_size); 

	lib_ret = pthread_attr_getstack (attr, stack_address, stack_size);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getstack");
	}

	return (lib_ret);
}

int x_pthread_attr_setstack (pthread_attr_t *attr, void **stack_address, size_t *stack, ...)
{
	int lib_ret; 
	FETCH (stack);

	lib_ret = pthread_attr_setstack (attr, stack_address, stack);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setstack");
	}

	return (lib_ret);
}

int x_pthread_attr_getaffinity_np (pthread_attr_t *attr, size_t cpusetsize, const cpu_set_t *cpuset, ...)
{
	int lib_ret; 
	FETCH (cpuset); 

	lib_ret = pthread_attr_getaffinity_np (attr, cpusetsize, cpuset);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_getaffinity_np");
	}

	return (lib_ret);
}

int x_pthread_attr_setaffinity_np (pthread_attr_t *attr, size_t cpusetsize, const cpu_set_t *cpuset, ...)
{
	int lib_ret; 
	FETCH (cpuset); 

	lib_ret = pthread_attr_setaffinity_np (attr, cpusetsize, cpuset);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setaffinity_np");
	}

	return (lib_ret);
}

int x_pthread_getattr_default_np (pthread_attr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr);

	lib_ret = pthread_getattr_default_np (attr);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_getattr_default_np");
	}

	return (lib_ret);
}

int x_pthread_setattr_default_np (pthread_attr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr);

	lib_ret = pthread_setattr_default_np (attr); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setattr_default_np"); 
	}

	return (lib_ret);
}

int x_pthread_getattr_np (pthread_t thread, pthread_attr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr);

	lib_ret = pthread_getattr_np (thread, attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_getattr_np");
	}

	return (lib_ret);
}

int x_pthread_getschedparam (pthread_t thread, int *policy, struct sched_param *param, ...)
{
	int lib_ret; 
	FETCH (param);

	lib_ret = pthread_getschedparam (thread, policy, param);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_getschedparam");
	}

	return (lib_ret);
}

int x_pthread_setschedparam (pthread_t thread, int policy, const struct sched_param *param, ...)
{
	int lib_ret;
	FETCH (param);

	lib_ret = pthread_setschedparam (thread, policy, param);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setschedparam");
	}

	return (lib_ret);
}

int x_pthread_setshcedprio (pthread_t thread, int priority, ...)
{
	int lib_ret; 
	FETCH (priority);

	lib_ret = pthread_setschedprio (thread, priority);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setschedprio");
	}

	return (lib_ret);
}

int x_pthread_getname_np (pthread_t thread, char *name, size_t len, ...)
{
	int lib_ret;
	FETCH (len);

	lib_ret = pthraed_getname_np (thread, name, len);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_getname_np");
	}

	return (lib_ret);
}

int x_pthread_setname_np (pthread_t thread, const char *name, ...)
{
	int lib_ret; 
	FETCH (name);

	lib_ret = pthread_setname_np (thread, name);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setname_np");
	}

	return (lib_ret);
}

int x_pthread_getconcurrency (int error_response, ...)
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

	lib_ret = pthread_getconcurrency ();

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_getconcurrency");
	}

	return (lib_ret);
}

int x_pthread_setconcurrency (int level, ...)
{
	int lib_ret; 
	FETCH (level);

	lib_ret = pthread_setconcurrency (level);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setconcurrency");
	}

	return (lib_ret);
}

int x_pthread_yield (int error_response, ...)
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

	lib_ret = pthread_yield (); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_yield");
	}

	return (lib_ret);
}

int x_pthread_setaffinity_np(pthread_t thread, size_t cpusetsize, const cpu_set_t *cpuset, ...)
{
	int lib_ret; 
	FETCH (cpuset);

	lib_ret = pthread_setaffinity_np (thread, cpusetsize, cpuset);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_attr_setaffinity_np");
	}

	return (lib_ret);
}

int x_pthraed_getaffinity_np (pthread_t thread, size_t cpusetsize, cpu_set_t *cpuset, ...)
{
	int lib_ret; 
	FETCH (cpuset);

	lib_ret = pthread_getaffinity_np (thread, cpusetsize, cpuset);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_attr_getaffinity_np");
	}

	return (lib_ret);
}

int x_pthread_once (pthread_once_t *once_control, void (*init_routine)(void), ...)
{
	int lib_ret; 
	FETCH (init_routine);

	lib_ret = pthread_once (once_control, init_routine);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_once");
	}

	return (lib_ret);
}

int x_pthread_secancelstate (int state, int *old_state, ...)
{
	int lib_ret; 
	FETCH (old_state); 

	lib_ret = pthread_setcancelstate (state, old_state);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setcancelstate");
	}

	return (lib_ret);
}

int x_pthread_setcanceltype (int type, int *old_type, ...)
{
	int lib_ret; 
	FETCH (old_type);

	lib_ret = pthread_setcanceltype (type, old_type);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setcanceltype");
	}

	return (lib_ret);
}

int x_pthread_cancel (pthread_t thread, ...)
{
	int lib_ret;
	FETCH (thread);

	lib_ret = pthread_cancel (thread);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cancel");
	}

	return (lib_ret);
}

inline void xi_pthread_testcancel (void)
{
	pthread_testcancel ();
}

int x_pthread_mutex_init (pthread_mutex_t *mutex, pthread_mutexattr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr);

	lib_ret = pthread_mutex_init (mutex, attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_init");
	}

	return (lib_ret);
}

int x_pthread_mutex_destroy (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex);

	lib_ret = pthread_mutex_destroy (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_destroy");
	}

	return (lib_ret);
}

int x_pthread_mutex_lock (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex);

	lib_ret = pthread_mutex_lock (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_lock");
	}

	return (lib_ret);
}

int x_pthread_mutex_trylock (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex);

	lib_ret = pthread_mutex_trylock (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_trylock");
	}

	return (lib_ret);
}

int x_pthread_mutex_timedlock (pthread_mutex_t *mutex, const struct timespec *abs_time, ...)
{
	int lib_ret;
	FETCH (abs_time);

	lib_ret	= pthread_mutex_timedlock (mutex, abs_time);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_mutex_timedlock");
	}

	return (lib_ret);
}

int x_pthread_mutex_unlock (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex);

	lib_ret = pthread_mutex_unlock (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_unlock");
	}

	return (lib_ret);
}

int x_pthread_mutex_getprioceiling (const pthread_mutex_t *mutex, int *prioceiling, ...)
{
	int lib_ret; 
	FETCH (prioceiling); 

	lib_ret = pthread_mutex_getprioceiling (mutex, prioceiling);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_getprioceiling");
	}

	return (lib_ret);
}

int x_pthread_mutex_setprioceiling (pthread_mutex_t *mutex, int prioceiling, int *old_prio_ceiling, ...)
{
	int lib_ret;
	FETCH (old_prio_ceiling);

	lib_ret = pthread_mutex_setprioceiling (mutex, prioceiling, old_prio_ceiling);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_setprioceiling");
	}

	return (lib_ret);
}

int x_pthread_mutex_consistent (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex);

	lib_ret = pthread_mutex_consistent (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_consistent");
	}

	return (lib_ret);
}

int x_pthread_mutex_consistent_np (pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex); 

	lib_ret = pthread_mutex_consistent_np (mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_mutex_consistent_np");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_init (pthread_mutexattr_t *mutex_attr, ...)
{
	int lib_ret; 
	FETCH (mutex_attr);

	lib_ret = pthread_mutexattr_init (mutex_attr);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_init");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_destroy (pthread_mutexattr_t *mutex_attr, ...)
{
	int lib_ret; 
	FETCH (mutex_attr); 

	lib_ret = pthread_mutexattr_destroy (mutex_attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_destroy");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_getpshared (const pthread_mutexattr_t *mutex_attr, int *pshared, ...)
{
	int lib_ret; 
	FETCH (pshared);

	lib_ret = pthread_mutexattr_getpshared (mutex_attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_getpshared");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_setpshared (pthread_mutexattr_t *mutex_attr, int pshared, ...)
{
	int lib_ret; 
	FETCH (pshared);

	lib_ret = pthread_mutexattr_setpshared (mutex_attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_setpshared");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_gettype (const pthread_mutexattr_t * mutex_attr, int *kind, ...)
{
	int lib_ret; 
	FETCH (kind); 

	lib_ret = pthread_mutexattr_gettype (mutex_attr, kind); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_gettype");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_settype (pthread_mutexattr_t *mutex_attr, int kind, ...)
{
	int lib_ret; 
	FETCH (kind); 

	lib_ret = pthread_mutexattr_settype (mutex_attr, kind); 

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_settype");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_getprotocol (const pthread_mutexattr_t *mutex_attr, int *protocol, ...)
{
	int lib_ret; 
	FETCH (protocol);

	lib_ret = pthread_mutexattr_getprotocol (mutex_attr, protocol);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_getprotocol");
	}

	return (lib_ret);
}

int x_pthread_mutex_setprotocol (pthread_mutexattr_t *mutex_attr, int protocol, ...)
{
	int lib_ret; 
	FETCH (protocol); 

	lib_ret = pthread_mutex_setprotocol (mutex_attr, protocol);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutex_setprotocol"); 
	}

	return (lib_ret);
}

int x_pthread_mutexattr_getprioceiling (const pthread_mutexattr_t *mutex_attr, int *prioceiling, ...)
{
	int lib_ret; 
	FETCH (prioceiling);

	lib_ret = pthread_mutexattr_getprioceiling (mutex_attr, prioceiling);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_getprioceiling");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_setprioceiling (pthread_mutexattr_t *mutex_attr, int prioceiling, ...)
{
	int lib_ret; 
	FETCH (prioceiling);

	lib_ret = pthread_mutexattr_setprioceiling (mutex_attr, prioceiling);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_setprioceiling");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_getrobust (const pthread_mutexattr_t *mutex_attr, int *robustness, ...)
{
	int lib_ret; 
	FETCH (robustness);

	lib_ret = pthread_mutexattr_getrobus (mutex_attr, robustness);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_getrobust");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_setrobust (pthread_mutexattr_t *mutex_attr, int robustness, ...)
{
	int lib_ret; 
	FETCH (robustness); 

	lib_ret = pthread_mutexattr_setrobus (mutex_attr, robustness);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_setrobust");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_getrobust_np (const pthread_mutexattr_t *mutex_attr, int *robustness, ...)
{
	int lib_ret; 
	FETCH (robustness); 

	lib_ret = pthread_mutexattr_getrobust_np (mutex_attr, robustness);

	if (lib_ret != 0)
	{
		errno = lib_ret;
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_getrobust_np");
	}

	return (lib_ret);
}

int x_pthread_mutexattr_setrobust_np (pthread_mutexattr_t *mutex_attr, int robustness, ...)
{
	int lib_ret; 
	FETCH (robustness);

	lib_ret = pthread_mutexattr_setrobust_np (mutex_attr, robustness);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_mutexattr_setrobust_np");
	}

	return (lib_ret);
}

int x_pthread_rwlock_init (pthread_rwlock_t *rwlock, pthread_rwlockattr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_rwlock_init (rwlock, attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_init"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_destroy (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_destroy (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_destroy"); 
	}

	return (lib_ret);

}

int x_pthread_rwlock_rdlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_rdlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_rdlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_tryrdlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_tryrdlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_tryrdlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_timedrdlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthraed_rwlock_timerdlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_timerdlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_wrlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_wrlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_wrlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_trywrlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_trywrlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_trywrlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_timedwrlock (pthread_rwlock_t *rwlock, const struct timespec *abs_time, ...)
{
	int lib_ret; 
	FETCH (abs_time); 

	lib_ret = pthread_rwlock_timedwrlock (rwlock, abs_time);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_timedwrlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlock_unlock (pthread_rwlock_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlock_unlock (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlock_unlock"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_init (pthread_rwlockattr_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlockattr_init (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlockattr_init"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_destroy (pthread_rwlockattr_t *rwlock, ...)
{
	int lib_ret; 
	FETCH (rwlock); 

	lib_ret = pthread_rwlockattr_destroy (rwlock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_wrlockattr_destroy"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_getpshared (pthread_rwlockattr_t *attr, int *pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_rwlockattr_getpshared (attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlockattr_getpshared"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_setpshared (pthread_rwlockattr_t *attr, int pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_rwlockattr_setpshared (attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlockattr_setpshared"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_getkind_np (pthread_rwlockattr_t *attr, int *pref, ...)
{
	int lib_ret; 
	FETCH (pref); 

	lib_ret = pthread_rwlockattr_getkind_np (attr, pref);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_rwlockattr_getkind_np"); 
	}

	return (lib_ret);
}

int x_pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *attr, int pref, ...)
{
	int lib_ret; 
	FETCH (pref); 

	lib_ret = pthread_rwlockattr_setkind_np (attr, pref);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthraed_rwlock_setkind_np"); 
	}

	return (lib_ret);
}

int x_pthread_cond_init (pthread_cond_t *cond, pthread_condattr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_cond_init (cond, attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_init"); 
	}

	return (lib_ret);
}

int x_pthread_cond_destroy (pthread_cond_t *cond, ...)
{
	int lib_ret; 
	FETCH (cond); 

	lib_ret = pthread_cond_destroy (cond);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_destroy"); 
	}

	return (lib_ret);
}

int x_pthread_cond_signal (pthread_cond_t *cond, ...)
{
	int lib_ret; 
	FETCH (cond); 

	lib_ret = pthread_cond_signal (cond);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_signal"); 
	}

	return (lib_ret);
}

int x_pthread_cond_broadcast (pthread_cond_t *cond, ...)
{
	int lib_ret; 
	FETCH (cond); 

	lib_ret = pthread_cond_broadcast (cond);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_broadcast"); 
	}

	return (lib_ret);
}

int x_pthread_cond_wait (pthread_cond_t *cond, pthread_mutex_t *mutex, ...)
{
	int lib_ret; 
	FETCH (mutex); 

	lib_ret = pthread_cond_wait (cond, mutex);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_wait"); 
	}

	return (lib_ret);
}

int x_pthread_cond_timedwait (pthread_cond_t *cond, pthread_mutex_t *mutex, const struct timespec *abs_time, ...)
{
	int lib_ret; 
	FETCH (abs_time); 

	lib_ret = pthread_cond_timedwait (cond, mutex, abs_time);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_cond_timedwait"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_init (pthread_condattr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_condattr_init (attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_init"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_destroy (pthread_condattr_t *attr, ...)
{
	int lib_ret; 
	FETCH (attr); 

	lib_ret = pthread_condattr_destroy (attr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_destroy"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_getpshared (pthread_condattr_t *attr, int *pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_condattr_getpshared (attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_getpshared"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_setpshared (pthread_condattr_t *attr, int pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_condattr_setpshared (attr, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_setpshared"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_getclock (pthread_condattr_t *attr, clockid_t *clock_id, ...)
{
	int lib_ret; 
	FETCH (clock_id); 

	lib_ret = pthread_condattr_getclock (attr, clock_id);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_getclock"); 
	}

	return (lib_ret);
}

int x_pthread_condattr_setclock (pthread_condattr_t *attr, clockid_t *clock_id, ...)
{
	int lib_ret; 
	FETCH (clock_id); 

	lib_ret = pthread_condattr_setclokc (attr, clock_id);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_condattr_setclock"); 
	}

	return (lib_ret);
}

int x_pthread_spin_init (pthread_spinlock_t *lock, int pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_spin_init (lock, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_spin_init");
	}

	return (lib_ret);
}

int x_pthread_spin_destroy (pthread_spinlock_t *lock, ...)
{
	int lib_ret; 
	FETCH (lock); 

	lib_ret = pthread_spin_destroy (lock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_spin_destroy");
	}

	return (lib_ret);
} 

int x_pthread_spin_lock (pthread_spinlock_t *lock, ...)
{
	int lib_ret; 
	FETCH (lock); 

	lib_ret = pthread_spin_lock (lock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_spin_lock");
	}

	return (lib_ret);
}

int x_pthread_spin_trylock (pthread_spinlock_t *lock, ...)
{
	int lib_ret; 
	FETCH (lock); 

	lib_ret = pthread_spin_trylock (lock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_spin_trylock");
	}

	return (lib_ret);
}

int x_pthread_spin_unlock (pthread_spinlock_t *lock, ...)
{
	int lib_ret; 
	FETCH (lock); 

	lib_ret = pthread_spin_unlock (lock);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_spin_unlock");
	}

	return (lib_ret);
}

int x_pthread_barrier_init (pthread_barrier_t *barrier, pthread_barrierattr_t *attr, unsigned int count, ...)
{
	int lib_ret; 
	FETCH (count); 

	lib_ret = pthread_barrier_init (barrier, attr, count);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrier_init");
	}

	return (lib_ret);
}

int x_pthread_barrier_destroy (pthread_barrier_t *barrier, ...)
{
	int lib_ret; 
	FETCH (barrier); 

	lib_ret = pthread_barrier_destroy (barrier);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrier_destroy");
	}

	return (lib_ret);
}

int x_pthread_barrier_wait (pthread_barrier_t *barrier, ...)
{
	int lib_ret; 
	FETCH (barrier); 

	lib_ret = pthread_barrier_wait (barrier);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrier_wait");
	}

	return (lib_ret);
}

int x_pthread_barrierattr_init (pthread_barrier_t *barrier, ...)
{
	int lib_ret; 
	FETCH (barrier); 

	lib_ret = pthread_barrierattr_init (barrier);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrierinit_init");
	}

	return (lib_ret);
}

int x_pthread_barrierattr_destroy (pthread_barrier_t *barrier, ...)
{
	int lib_ret; 
	FETCH (barrier); 

	lib_ret = pthread_barrierattr_destroy (barrier);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrierattr_destroy");
	}

	return (lib_ret);
}

int x_pthread_barrierattr_getpshared (pthread_barrier_t *barrier, int *pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_barrierattr_getpshared (barrier, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrierattr_getpshared");
	}

	return (lib_ret);
}

int x_pthread_barrierattr_setpshared (pthread_barrier_t *barrier, int pshared, ...)
{
	int lib_ret; 
	FETCH (pshared); 

	lib_ret = pthread_barrierattr_setpshared (barrier, pshared);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_barrierattr_setpshared");
	}

	return (lib_ret);
}

int x_pthread_key_create (pthread_key_t *key, void (*destructor_function) (void*), ...)
{
	int lib_ret; 
	FETCH (destructor_function); 

	lib_ret = pthread_key_create (key, destructor_function);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_key_create");
	}

	return (lib_ret);
}

int x_pthread_key_delete (pthread_key_t key, ...)
{
	int lib_ret; 
	FETCH (key); 

	lib_ret = pthread_key_delete (key);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_key_delete");
	}

	return (lib_ret);
}

inline void *xi_pthread_getspecific (pthread_key_t key, ...)
{
	pthread_getspecific (key);
}

int x_pthread_setspecific (pthread_key_t key, const void *ptr, ...)
{
	int lib_ret; 
	FETCH (ptr); 

	lib_ret = pthread_setspecific (key, ptr);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_setspecific");
	}

	return (lib_ret);
}

int x_pthread_getcpuclockid (pthread_t thread_id, clockid_t *clock_id, ...)
{
	int lib_ret; 
	FETCH (clock_id); 

	lib_ret = pthread_getcpulockid (thread_id, clock_id);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_getcpulockid");
	}

	return (lib_ret);
}

int x_pthread_atfork (void (*prepare)(void), void (*parent) (void), void (*child)(void), ...)
{
	int lib_ret; 
	FETCH (child); 

	lib_ret = pthread_atfork (prepare, parent, child);

	if (lib_ret != 0)
	{
		errno = lib_ret; 
		HANDLE_LIB_ERROR1 ("pthread_atfork");
	}

	return (lib_ret);	
}
