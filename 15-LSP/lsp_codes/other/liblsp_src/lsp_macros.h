#ifndef _LSP_MACROS_H 
#define _LSP_MACROS_H 

/* Mandatory variables */ 
#ifndef	DEFINE_VARS
#define DEFINE_VARS(x,y)	int x;  char* y 
#endif /* DEFINE_VARS */ 


/* Macro for fetching source file name and 
 * line number */ 
#ifndef	DEBUG_VARS 
#define DEBUG_VARS(last)	char *src_file_name;				\
				int src_nr_line;				\
				va_list ap;					\
				do{					    	\
					va_start (ap, last);			\
					src_file_name = va_arg (ap, char*);	\
					src_nr_line   = va_arg (ap, int);	\
					va_end (ap); 				\
				}while (0)				
#endif /* DEBUG_VARS */ 

/* Common error handling response for system calls*/ 
#ifndef HANDLE_SYS_ERROR
#define HANDLE_SYS_ERROR(fmt,...)							\
				do {							\
					if (sys_ret == -1)				\
					{			  			\
						if (error_response == ER_RETONLY)	\
						{				 	\
							return (sys_ret); 		\
						}					\
						err_msg = strerror (errno); 		\
						fprintf (stderr, fmt, __VA_ARGS__);	\
				        	if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE); 		\
						}					\
				          }						\
				}while (0)					
#endif /* HANDLE_SYS_ERROR */ 

/* Common error handling response for library functions
 * Note that library function may or may not set errno 
 * upon error. This is unlike system call behaviour where 
 * errno is always set. We will initialize err_msg with   
 * custom error message where strerror (errno) is not 
 * available otherwise it will be set to NULL. By checking 
 * err_msg for NULL, we will decide whether to call for 
 * strerror (errno) or not. fprintf will receive it's variadic 
 * actual arguments from the macro. Caller will be aware 
 * whether err_msg is applicable to a particular function 
 * or not and likewise it will be sent (or not sent). */ 

#ifndef HANDLE_LIB_ERROR 
#define HANDLE_LIB_ERROR(fmt, ...)							\
						do						\
					   	{						\
							if (error_response == ER_RETONLY)	\
							{					\
								return (lib_ret); 		\
							}					\
							if (err_msg == NULL)			\
							{					\
								err_msg = strerror (errno);	\
							}					\
							fprintf (stderr, fmt, __VA_ARGS__);	\
							if (error_response == ER_MSG_WITH_EXIT)	\
							{					\
								exit (EXIT_FAILURE);		\
							}					\
						}while (0)	
#endif /* HANDLE_LIB_ERROR */  

#endif /* _LSP_MACROS_H */
