#ifndef _LSP_DEFS_H 
#define _LSP_DEFS_H 

/* Global TRUE, FALSE */ 
#define TRUE	1
#define FALSE	0

/* used by uint_to_str */ 
#define MAX_DIGITS_32   9
#define START_DIGITS   	48 

/* error_response options */ 
#define ER_RETONLY	 0
#define ER_RET_WITH_MSG  1
#define ER_MSG_WITH_EXIT 2
#define ret_only	 ER_RETONLY
#define ret_msg		 ER_RET_WITH_MSG
#define msg_exit	 ER_MSG_WITH_EXIT

/* Aliases of above macros */ 
#define	E_R	ER_RETONLY 
#define E_MR	ER_RET_WITH_MESSAGE
#define E_ME	ER_MSG_WITH_EXIT

/* __FILE__ & __LINE__ macros */
#define SRC_FILE_NAME	__FILE__
#define SRC_NR_LINE 	__LINE__

typedef void (*sighandler_t) (int); 

struct FTW
{
     int base;     
     int level;
};


#endif /* _LSP_DEFS_H */
