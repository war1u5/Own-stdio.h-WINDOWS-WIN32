#define _CRT_SECURE_NO_WARNINGS
#if defined(__linux__)
#elif defined(_WIN32)
#include <fileapi.h>
typedef HANDLE SO_HANDLE;

#else
#error "Unknown platform"
#endif

#include <string.h>

//definire valori true/false
#define SO_TRUE 1
#define SO_FALSE 0

//definire buffer
#define BUFF_SIZE 4096

//definire access modes
typedef enum {
	R, R_PLUS, W, W_PLUS, A, A_PLUS
} FILE_ACCESS;

//definire operatii
typedef enum {
	READ_OP, WRITE_OP, DIFF_OP, SEEK_OP
} PREV_OP;

//handle-ul fisierului pe care dorim sa-l deschidem are o structura anume
//see README.md section Structura handle
struct _so_file {
#if defined(__linux__)
#elif defined(_WIN32)
    SO_HANDLE fHandle;
#else
#error "Unknown platform"
#endif
    SO_HANDLE fd;                       
	FILE_ACCESS access_type;
	PREV_OP prev;
	unsigned char buff[BUFF_SIZE];
	int buff_pos;
	int current_buffer_size;
	long current_pos;
	int is_error;
	int is_eof;
	int prev_read_bytes;
	int prev_written_bytes;
	int pid;
};