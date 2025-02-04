#ifndef __MLD__
#include <assert.h>
#include <string.h>

#define MAX_STRUCTURE_NAME_SIZE 128
#define MAX_FIELD_NAME_SIZE 128

#define OFFSETOF(struct_name, field_name)\
    (unsigned long)&(((struct_name *)0)->field_name)

#define FIELD_SIZE(struct_name, field_name)\
    sizeof(((struct_name *)0)->field_name)

typedef enum {
    UINT8,
    UINT32,
    INT32,
    CHAR,
    OBJ_PTR,
    VOID_PTR,
    FLOAT,
    DOUBLE,
    OBJ_STRUCT
} data_type_t;

typedef enum{
    MLD_FALSE,
    MLD_TRUE
} mld_boolean_t;

typedef struct _struct_db_rec_ db_rec_t;
typedef struct _field_info_ field_info_t;
typedef struct _db_ db_t;

struct _db_rec_{
    db_rec_t* next;
    char name[MAX_STRUCTURE_NAME_SIZE];
    unsigned int ds_size;
    unsigned int n_fields;
    field_info_t* fields;
};

struct _field_info_{
    char field_name [MAX_FIELD_NAME_SIZE];
    data_type_t dtype;                  
    unsigned int size;                 
    unsigned int offset;                
    char nested_str_name[MAX_STRUCTURE_NAME_SIZE];
};

struct _db_{ //linked list to all records
    db_rec_t *head; 
    unsigned int count;
};

void print_structure_rec (db_rec_t *rec);
void print_structure_db (db_t *db);

#endif 