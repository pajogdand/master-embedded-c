#ifndef _LSP_MACROS_H 
#define _LSP_MACROS_H 

#ifdef DEBUG
#define RESPONSE(error_response)	error_response, __FILE__, __LINE__
#else
#define RESPONSE(error_response)	error_response
#endif /* RESPONSE */ 

#ifdef DEBUG
#define dbg(error_response)	error_response, __FILE__, __LINE__
#else
#define dbg(error_response)	error_response
#endif /* dbg */


#ifdef DEBUG
#define FETCH(last)		int error_response, src_nr_line;		\
				char *src_file_name; 				\
				va_list ap;					\
				do 						\
				{						\
					va_start (ap, last); 			\
					error_response  = va_arg (ap, int);	\
					src_file_name 	= va_arg (ap, char*); 	\
					src_nr_line 	= va_arg (ap, int); 	\
					va_end (ap);				\
				}while(0)		
#else
#define FETCH(last)	        int error_response;				\
				va_list ap;					\
				do 						\
				{						\
					va_start (ap, last); 			\
					error_response  = va_arg (ap, int);	\
					va_end (ap);				\
				}while(0)	
#endif /* FETCH */ 


#ifdef DEBUG
#define HANDLE_SYS_ERROR(...)		do						\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (sys_ret); 		\
						}					\
						fprintf (stderr, "%s:%d:", 		\
							 src_file_name, src_nr_line);	\
						fprintf (stderr, __VA_ARGS__);		\
						fprintf (stderr, ":%s\n", 		\
							 strerror (errno)); 		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#else
#define HANDLE_SYS_ERROR(...)		do						\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (sys_ret); 		\
						}					\
						fprintf (stderr, __VA_ARGS__);		\
						fprintf (stderr, ":%s\n", 		\
							 strerror (errno)); 		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#endif /* HANDLE_SYS_ERROR */ 

#ifdef DEBUG 
#define HANDLE_LIB_ERROR1(...)	do							\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (lib_ret); 		\
						}					\
						fprintf (stderr, "%s:%d:", 		\
							 src_file_name, src_nr_line);	\
						fprintf (stderr, __VA_ARGS__);		\
						fprintf (stderr, ":%s\n",		\
							 strerror (errno));		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#else
#define HANDLE_LIB_ERROR1(...)		do						\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (lib_ret); 		\
						}					\
						fprintf (stderr, __VA_ARGS__);		\
						fprintf (stderr, ":%s\n", 		\
							 strerror (errno)); 		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#endif 

#ifdef DEBUG 
#define HANDLE_LIB_ERROR2(...)		do						\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (lib_ret); 		\
						}					\
						fprintf (stderr, "%s:%d:", 		\
							 src_file_name, src_nr_line);	\
						fprintf (stderr, __VA_ARGS__);		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#else
#define HANDLE_LIB_ERROR2(...)		do						\
					{						\
						if (error_response == ER_RETONLY)	\
						{					\
							return (lib_ret); 		\
						}					\
						fprintf (stderr, __VA_ARGS__);		\
						if (error_response == ER_MSG_WITH_EXIT) \
						{					\
							exit (EXIT_FAILURE);		\
						}					\
					}while (0)
#endif 

#endif /* _LSP_MACROS_H */
